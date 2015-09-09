#ifdef _WIN32
#   if defined(_MSC_VER)
#       pragma warning(disable : 4996)
#   endif
#   if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
#       define _CRT_SECURE_NO_WARNINGS // _CRT_SECURE_NO_WARNINGS for sscanf errors in MSVC2013 Express
#   endif
#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN
#   endif
#   define _WINSOCK_DEPRECATED_NO_WARNINGS
#   if !defined(UNREAL)
#       include <WinSock2.h>
#       include <WS2tcpip.h>
#       pragma comment( lib, "ws2_32" )
#   endif
#   include <fcntl.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <string.h>
#   include <sys/types.h>
#   include <io.h>
#   ifndef _SSIZE_T_DEFINED
        typedef long ssize_t;
#       define _SSIZE_T_DEFINED
#   endif
#   ifndef _SOCKET_T_DEFINED
        typedef SOCKET socket_t;
#       define _SOCKET_T_DEFINED
#   endif
#   ifndef snprintf
#       define snprintf _snprintf_s
#   endif
#   if _MSC_VER >=1600
    // vs2010 or later
#       include <stdint.h>
#   else
        typedef __int8 int8_t;
        typedef unsigned __int8 uint8_t;
        typedef __int32 int32_t;
        typedef unsigned __int32 uint32_t;
        typedef __int64 int64_t;
        typedef unsigned __int64 uint64_t;
#   endif
#   define socketerrno WSAGetLastError()
#   define SOCKET_EAGAIN_EINPROGRESS WSAEINPROGRESS
#   define SOCKET_EWOULDBLOCK WSAEWOULDBLOCK
#else
#   include <fcntl.h>
#   include <netdb.h>
#   include <netinet/tcp.h>
#   include <netinet/in.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <string.h>
#   include <sys/socket.h>
#   include <sys/time.h>
#   include <sys/types.h>
#   include <unistd.h>
#   include <stdint.h>
#   ifndef _SOCKET_T_DEFINED
        typedef int socket_t;
#       define _SOCKET_T_DEFINED
#   endif
#   ifndef INVALID_SOCKET
#       define INVALID_SOCKET (-1)
#   endif
#   ifndef SOCKET_ERROR
#       define SOCKET_ERROR   (-1)
#   endif
#   define closesocket(s) ::close(s)
#   include <errno.h>
#   define socketerrno errno
#   define SOCKET_EAGAIN_EINPROGRESS EAGAIN
#   define SOCKET_EWOULDBLOCK EWOULDBLOCK
#endif

#include <GameSparks/gsstl.h>

#include "easywsclient.hpp"
#include <cassert>

#ifdef SSL_SUPPORT
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/crypto.h>
#endif

// use std::thread in MSVC11 (2012) or newer
#if _MSC_VER >= 1700 && !defined(MARMALADE)
#	include <thread>
#	include <mutex>
#	define USE_STD_THREAD 1
#else
#	include <pthread.h>    /* POSIX Threads */
#	undef USE_STD_THREAD
#endif /* WIN32 */


#ifdef GS_TESTING
namespace gs_testing
{
	// variabled for messing with the socket during the tests
	bool close_websocket = false;
}
#endif /* GS_TESTING */

inline void closesocket_safe(socket_t& sockfd)
{
    if ( sockfd == INVALID_SOCKET )
        return;

    closesocket(sockfd);
    sockfd = INVALID_SOCKET;
}

namespace { // private module-only namespace

	namespace threading
	{
		typedef void *(*start_routine) (void *);

		#ifdef USE_STD_THREAD
			typedef std::mutex mutex;

			void mutex_init(mutex&)
			{
				// nothing to do here
			}

			void mutex_lock(mutex& mtx)
			{
				mtx.lock();
			}

			void mutex_unlock(mutex& mtx)
			{
				mtx.unlock();
			}

			typedef std::thread thread;

			void thread_create(thread& t, start_routine f, void* arg)
			{
				t = thread(f, arg);
			}

			void thread_exit(thread&)
			{
				// nothing to do
			}

			void thread_join(thread& t)
			{
				t.join();
			}

			bool thread_is_joinable(const thread& t)
			{
				return t.joinable();
			}
		#else
			typedef pthread_mutex_t mutex;

			void mutex_init(mutex& mutex)
			{
				pthread_mutex_init(&mutex, NULL);
			}

			void mutex_lock(mutex& mutex)
			{
				pthread_mutex_lock(&mutex);
			}

			void mutex_unlock(mutex& mutex)
			{
				pthread_mutex_unlock(&mutex);
			}

			typedef pthread_t thread;

			void thread_create(thread& thread, start_routine f, void* arg)
			{
				pthread_create(&thread, NULL, f, arg);		
			}

			void thread_exit(thread&)
			{
				pthread_exit(0);
			}

			void thread_join(thread& t)
			{
				pthread_join(t, NULL);
			}

			bool thread_is_joinable(const thread&)
			{
				// http://pubs.opengroup.org/onlinepubs/007908799/xsh/pthread_join.html
				// calling pthread_join twice is apparently ok
				return true;
			}
		#endif
	}


	class _RealWebSocket : public easywsclient::WebSocket
	{
	public:
		// http://tools.ietf.org/html/rfc6455#section-5.2  Base Framing Protocol
		//
		//  0                   1                   2                   3
		//  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
		// +-+-+-+-+-------+-+-------------+-------------------------------+
		// |F|R|R|R| opcode|M| Payload len |    Extended payload length    |
		// |I|S|S|S|  (4)  |A|     (7)     |             (16/64)           |
		// |N|V|V|V|       |S|             |   (if payload len==126/127)   |
		// | |1|2|3|       |K|             |                               |
		// +-+-+-+-+-------+-+-------------+ - - - - - - - - - - - - - - - +
		// |     Extended payload length continued, if payload len == 127  |
		// + - - - - - - - - - - - - - - - +-------------------------------+
		// |                               |Masking-key, if MASK set to 1  |
		// +-------------------------------+-------------------------------+
		// | Masking-key (continued)       |          Payload Data         |
		// +-------------------------------- - - - - - - - - - - - - - - - +
		// :                     Payload Data continued ...                :
		// + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
		// |                     Payload Data continued ...                |
		// +---------------------------------------------------------------+
		struct wsheader_type {
			unsigned header_size;
			bool fin;
			bool mask;
			enum opcode_type {
				CONTINUATION = 0x0,
				TEXT_FRAME = 0x1,
				BINARY_FRAME = 0x2,
				CLOSE = 8,
				PING = 9,
				PONG = 0xa
			} opcode;
			int N0;
			uint64_t N;
			uint8_t masking_key[4];
		};

		gsstl::vector<char> rxbuf;
		gsstl::vector<char> txbuf;

        socket_t sockfd;
		readyStateValues readyState;
        bool useMask;
        bool useSSL;
        
		threading::mutex lock;
        
        sockaddr_in result;
        
#ifdef SSL_SUPPORT
		SSL *sslHandle;
		SSL_CTX *sslContext;

        _RealWebSocket(gsstl::string host, gsstl::string path, int port, gsstl::string url, gsstl::string origin, bool _useMask, bool _useSSL)
        {
            m_host = host;
            m_path = path;
            m_port = port;
            m_url = url;
            m_origin = origin;
            
            useMask = _useMask;
            useSSL = _useSSL;
            
            sslContext = 0;
            sslHandle = 0;
            
            readyState = CONNECTING;
            ipLookup = keNone;

            sockfd = INVALID_SOCKET;
        }
        
		_RealWebSocket(socket_t sockfd_, bool useMask_, SSL* ssl, SSL_CTX* sslctx) : sockfd(sockfd_),readyState(CLOSED), useMask(useMask_),  sslHandle(ssl), sslContext(sslctx)
        {
            ipLookup = keNone;
		}
#endif
		_RealWebSocket(socket_t sockfd_, bool useMask_) : sockfd(sockfd_), readyState(CLOSED), useMask(useMask_)
        {
            ipLookup = keNone;
		}
        
        virtual ~_RealWebSocket()
        {
            if(sslContext) SSL_CTX_free(sslContext);
            if(sslHandle) SSL_free(sslHandle);

			if (threading::thread_is_joinable(dns_thread))
			{
				threading::thread_join(dns_thread);
			}
        }

		readyStateValues getReadyState() const {
			return readyState;
		}
       
		void poll(int timeout, WSErrorCallback errorCallback, void* userData)  // timeout in milliseconds
        {
			using namespace easywsclient;

            if(readyState == CONNECTING)
            {
                if(ipLookup == keComplete)
                {
					// join the dns_thread
					threading::thread_join(dns_thread);

					if (!doConnect2(errorCallback, userData))
                    {
                        forceClose();
                    }
                    else
                    {
                        readyState = OPEN;
                    }
                }
                else if( ipLookup == keFailed )
                {
					threading::thread_join(dns_thread);
                    forceClose();
					using namespace easywsclient;
					errorCallback(WSError(WSError::DNS_LOOKUP_FAILED, "DNS Lookup failed"), userData);
                }
            }
            else if(ipLookup == keComplete)
            {
                #ifdef GS_TESTING
                if (gs_testing::close_websocket)
                {
                    forceClose();
                    gs_testing::close_websocket = false;
                }
                #endif

                
                if (readyState == CLOSED)
                {
                    if (timeout > 0)
                    {
                        timeval tv = { timeout/1000, (timeout%1000) * 1000 };
                        select(0, NULL, NULL, NULL, &tv);
                    }
                    return;
                }
                if (timeout > 0)
                {
                    fd_set rfds;
                    fd_set wfds;
                    timeval tv = { timeout/1000, (timeout%1000) * 1000 };
                    FD_ZERO(&rfds);
                    FD_ZERO(&wfds);
                    FD_SET(sockfd, &rfds);
                    if (txbuf.size()) { FD_SET(sockfd, &wfds); }
                    // http://stackoverflow.com/questions/8695678/what-is-the-nfds-from-select-used-for
                    select(int(sockfd + 1), &rfds, &wfds, NULL, &tv);
                }

				using namespace easywsclient;

                for(;;) // while(true), but without a warning about constant expression
                {
                    // FD_ISSET(0, &rfds) will be true
                    gsstl::vector<char>::size_type N = rxbuf.size();
                    ssize_t ret;
                    rxbuf.resize(N + 1500);

                    #ifdef SSL_SUPPORT
                        ret = SSL_read(sslHandle, (char*)&rxbuf[0] + N, 1500);
                    #else
                        ret = recv(sockfd, (char*)&rxbuf[0] + N, 1500, 0);
                    #endif

                    if (ret < 0 && (socketerrno == SOCKET_EWOULDBLOCK || socketerrno == SOCKET_EAGAIN_EINPROGRESS))
                    {
                        rxbuf.resize(N);
                        break;
                    }
                    else if (ret <= 0)
                    {
                        rxbuf.resize(N);
                        closesocket_safe(sockfd);
                        readyState = CLOSED;
						if (ret < 0)
						{
							fputs("Connection error!\n", stderr);
							errorCallback(WSError(WSError::RECV_FAILED, "recv or SSL_read failed"), userData);
						}
						else
						{
							fputs("Connection closed!\n", stderr);
							errorCallback(WSError(WSError::CONNECTION_CLOSED, "Connection closed"), userData);
						}
                        break;
                    }
                    else
                    {
                        rxbuf.resize(static_cast<gsstl::vector<char>::size_type>(N + ret));
                    }
                }
                while (txbuf.size())
                {
                    #ifdef SSL_SUPPORT
                        int ret = SSL_write(sslHandle, &txbuf[0], static_cast<int>(txbuf.size()));
                    #else
                        int ret = ::send(sockfd, (char*)&txbuf[0], txbuf.size(), 0);
                    #endif

                    if (ret < 0 && (socketerrno == SOCKET_EWOULDBLOCK || socketerrno == SOCKET_EAGAIN_EINPROGRESS))
                    {
                        break;
                    }
                    else if (ret <= 0)
                    {
                        closesocket_safe(sockfd);
                        readyState = CLOSED;
						if (ret < 0)
						{
							fputs("Connection error!\n", stderr);
							errorCallback(WSError(WSError::SEND_FAILED, "send or SSL_write failed"), userData);
						}
						else
						{
							fputs("Connection closed!\n", stderr);
							errorCallback(WSError(WSError::CONNECTION_CLOSED, "Connection closed"), userData);
						}
                        break;
                    }
                    else
                    {
                        assert(ret <= (int)txbuf.size());
                        txbuf.erase(txbuf.begin(), txbuf.begin() + ret);
                    }
                }
            }
            
            if (!txbuf.size() && readyState == CLOSING)
            {
                closesocket_safe(sockfd);
                readyState = CLOSED;
				errorCallback(WSError(WSError::CONNECTION_CLOSED, "Connection closed"), userData);
            }
		}

		// Callable must have signature: void(const gsstl::string & message).
		// Should work with C functions, C++ functors, and C++11 std::function and
		// lambda:
		//template<class Callable>
		//void dispatch(Callable callable)
		virtual void _dispatch(WSMessageCallback messageCallback, WSErrorCallback errorCallback, void* userData)
        {
            if(readyState == CONNECTING) return;
            
			// TODO: consider acquiring a lock on rxbuf...
			for(;;) // while (true) withoput warning about constant expression
            {
                
                wsheader_type ws;
                {
                    if (rxbuf.size() < 2) { return; /* Need at least 2 */ }
                    const uint8_t * data = (uint8_t *) &rxbuf[0]; // peek, but don't consume
                    ws.fin = (data[0] & 0x80) == 0x80;
                    ws.opcode = (wsheader_type::opcode_type) (data[0] & 0x0f);
                    ws.mask = (data[1] & 0x80) == 0x80;
                    ws.N0 = (data[1] & 0x7f);
                    ws.header_size = 2 + (ws.N0 == 126? 2 : 0) + (ws.N0 == 127? 8 : 0) + (ws.mask? 4 : 0);
                    if (rxbuf.size() < ws.header_size) { return; /* Need: ws.header_size - rxbuf.size() */ }
                    int data_offset = -1;
                    if (ws.N0 < 126) {
                        ws.N = ws.N0;
                        data_offset = 2;
                    }
                    else if (ws.N0 == 126) {
                        ws.N = 0;
                        ws.N |= ((uint64_t) data[2]) << 8;
                        ws.N |= ((uint64_t) data[3]) << 0;
                        data_offset = 4;
                    }
                    else if (ws.N0 == 127) {
                        ws.N = 0;
                        ws.N |= ((uint64_t) data[2]) << 56;
                        ws.N |= ((uint64_t) data[3]) << 48;
                        ws.N |= ((uint64_t) data[4]) << 40;
                        ws.N |= ((uint64_t) data[5]) << 32;
                        ws.N |= ((uint64_t) data[6]) << 24;
                        ws.N |= ((uint64_t) data[7]) << 16;
                        ws.N |= ((uint64_t) data[8]) << 8;
                        ws.N |= ((uint64_t) data[9]) << 0;
                        data_offset = 10;
                    }
                    if (ws.mask) {
                        assert(data_offset != -1);
                        ws.masking_key[0] = ((uint8_t) data[data_offset+0]) << 0;
                        ws.masking_key[1] = ((uint8_t) data[data_offset+1]) << 0;
                        ws.masking_key[2] = ((uint8_t) data[data_offset+2]) << 0;
                        ws.masking_key[3] = ((uint8_t) data[data_offset+3]) << 0;
                    }
                    else {
                        ws.masking_key[0] = 0;
                        ws.masking_key[1] = 0;
                        ws.masking_key[2] = 0;
                        ws.masking_key[3] = 0;
                    }
                    if (rxbuf.size() < ws.header_size+ws.N) { return; /* Need: ws.header_size+ws.N - rxbuf.size() */ }
                }


				// We got a whole message, now do something with it:
				if (ws.opcode == wsheader_type::TEXT_FRAME && ws.fin) {
					if (ws.mask) { for (size_t i = 0; i != ws.N; ++i) { rxbuf[static_cast<gsstl::vector<char>::size_type>(i+ws.header_size)] ^= ws.masking_key[i&0x3]; } }
					gsstl::string data(rxbuf.begin()+ws.header_size, rxbuf.begin()+ws.header_size+(size_t)ws.N);
					messageCallback((const gsstl::string) data, userData);
				}
				else if (ws.opcode == wsheader_type::PING) {
					if (ws.mask) { for (size_t i = 0; i != ws.N; ++i) { rxbuf[static_cast<gsstl::vector<char>::size_type>(i+ws.header_size)] ^= ws.masking_key[i&0x3]; } }
					gsstl::string data(rxbuf.begin()+ws.header_size, rxbuf.begin()+ws.header_size+(size_t)ws.N);
					sendData(wsheader_type::PONG, data);
				}
				else if (ws.opcode == wsheader_type::PONG)
                {
					messageCallback((const gsstl::string) "{ \"@class\" : \".pong\" }", userData);
                }
				else if (ws.opcode == wsheader_type::CLOSE)
                {
                    close();
                }
				else
                {
                    fprintf(stderr, "ERROR: Got unexpected WebSocket message.\n");
					using namespace easywsclient;
					errorCallback(WSError(WSError::UNEXPECTED_MESSAGE, "Got unexpected WebSocket message."), userData);
                    close();
                }

				rxbuf.erase(rxbuf.begin(), rxbuf.begin() + ws.header_size+(size_t)ws.N);
			}
		}

		void sendPing()
        {
            if(readyState == CONNECTING) return;
        	sendData(wsheader_type::PING, gsstl::string());
		}

		void send(const gsstl::string& message)
        {
            if(readyState == CONNECTING) return;
			sendData(wsheader_type::TEXT_FRAME, message);
		}

		void sendData(wsheader_type::opcode_type type, const gsstl::string& message)
        {
			// TODO:
			// Masking key should (must) be derived from a high quality random
			// number generator, to mitigate attacks on non-WebSocket friendly
			// middleware:
			const uint8_t masking_key[4] = { 0x12, 0x34, 0x56, 0x78 };
			// TODO: consider acquiring a lock on txbuf...
			if (readyState == CLOSING || readyState == CLOSED || readyState == CONNECTING) { return; }
			gsstl::vector<uint8_t> header;
			uint64_t message_size = message.size();
			header.assign(2 + (message_size >= 126 ? 2 : 0) + (message_size >= 65536 ? 6 : 0) + (useMask ? 4 : 0), 0);
			header[0] = uint8_t(0x80 | type);

			if (message_size < 126) {
				header[1] = (message_size & 0xff) | (useMask ? 0x80 : 0);
				if (useMask) {
					header[2] = masking_key[0];
					header[3] = masking_key[1];
					header[4] = masking_key[2];
					header[5] = masking_key[3];
				}
			}
			else if (message_size < 65536) {
				header[1] = 126 | (useMask ? 0x80 : 0);
				header[2] = (message_size >> 8) & 0xff;
				header[3] = (message_size >> 0) & 0xff;
				if (useMask) {
					header[4] = masking_key[0];
					header[5] = masking_key[1];
					header[6] = masking_key[2];
					header[7] = masking_key[3];
				}
			}
			else { // TODO: run coverage testing here
				header[1] = 127 | (useMask ? 0x80 : 0);
				header[2] = (message_size >> 56) & 0xff;
				header[3] = (message_size >> 48) & 0xff;
				header[4] = (message_size >> 40) & 0xff;
				header[5] = (message_size >> 32) & 0xff;
				header[6] = (message_size >> 24) & 0xff;
				header[7] = (message_size >> 16) & 0xff;
				header[8] = (message_size >>  8) & 0xff;
				header[9] = (message_size >>  0) & 0xff;
				if (useMask) {
					header[10] = masking_key[0];
					header[11] = masking_key[1];
					header[12] = masking_key[2];
					header[13] = masking_key[3];
				}
			}
			// N.B. - txbuf will keep growing until it can be transmitted over the socket:
			txbuf.insert(txbuf.end(), header.begin(), header.end());
			txbuf.insert(txbuf.end(), message.begin(), message.end());
			if (useMask) {
				for (size_t i = 0; i != message.size(); ++i) { *(txbuf.end() - message.size() + i) ^= masking_key[i&0x3]; }
			}
		}

		void close() {
			if(readyState == CLOSING || readyState == CLOSED) { return; }
			readyState = CLOSING;
			uint8_t closeFrame[6] = {0x88, 0x80, 0x00, 0x00, 0x00, 0x00}; // last 4 bytes are a masking key
			gsstl::vector<uint8_t> header(closeFrame, closeFrame+6);
			txbuf.insert(txbuf.end(), header.begin(), header.end());
		}
        
        void forceClose()
        {
            if(readyState == CLOSING || readyState == CLOSED) { return; }
            readyState = CLOSING;
            txbuf.clear();
        }
        
        static void* _s_dns_Lookup(void *ptr)
        {
            _RealWebSocket *self = (_RealWebSocket*)ptr;
           
            struct hostent *server_hostent = gethostbyname(self->m_host.c_str());
            
			threading::mutex_lock(self->lock);
            if (!server_hostent)
            {
                self->ipLookup = keFailed;
            }
            else
            {
                memset(&self->result, 0, sizeof(self->result));
                self->result.sin_family = AF_INET;
                self->result.sin_port = htons((uint16_t)self->m_port);
                self->result.sin_addr = *( (struct in_addr *)server_hostent->h_addr );
                self->ipLookup = keComplete;
            }
            
			threading::mutex_unlock(self->lock);
            
			threading::thread_exit(self->dns_thread);

            /*#if defined (WINDOWS_32) || defined(WIN_32)
                return 0;
            #else
                pthread_exit(0); // An implicit call to pthread_exit() is made when a thread other than the thread in which main() was first invoked returns from the start routine that was used to create it. 
            #endif*/

			return 0;
        }
        
		threading::thread dns_thread;

        bool doConnect()
        {
            readyState = CONNECTING;
            ipLookup = keInprogress;
            
			threading::mutex_init(lock);
			threading::thread_create(dns_thread, _s_dns_Lookup, (void*)this);

            return true;
        }
        
		bool doConnect2(WSErrorCallback errorCallback, void* userData)
        {
			using namespace easywsclient;

            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == INVALID_SOCKET)
            {
                closesocket_safe(sockfd);
                sockfd = INVALID_SOCKET;
				errorCallback(WSError(WSError::SOCKET_CREATION_FAILED, "Socket creation failed"), userData);
				return false;
            }

			if (connect(sockfd, (sockaddr*)&result, sizeof(struct sockaddr)) == SOCKET_ERROR)
			{
				closesocket_safe(sockfd);
				sockfd = INVALID_SOCKET;
				errorCallback(WSError(WSError::CONNECT_FAILED, "connect() failed."), userData);
				return false;
			}

            #ifdef SSL_SUPPORT
                static bool ssl_initialized = false;
            
                #ifdef USE_CYASSL
                    InitCyaSSL();
                #else
                    sslContext = new SSL_CTX;
                    sslHandle = new SSL;
                #endif
            
                if (!ssl_initialized)
                {
                    SSL_load_error_strings();
                    SSL_library_init();
                    ssl_initialized = true;
                }
    
				#define SEND(buf)  SSL_write(sslHandle, buf, (int)strlen(buf))
				#define RECV(buf)  SSL_read(sslHandle, buf, 1)
    
                if ( sockfd != INVALID_SOCKET && useSSL )
                {
					sslContext = SSL_CTX_new (TLSv1_client_method());
                    if (sslContext == NULL)
                    {
                        #ifndef USE_CYASSL
                            ERR_print_errors_fp (stderr);
						#else
							fprintf(stderr, "failed to create SSL Context\n");
						#endif

						errorCallback(WSError(WSError::SSL_CTX_NEW_FAILED, "Failed to create SSL Context."), userData);

						return false;
                    }
                    
					// this is probably not a good idea in terms of privacy.
                    SSL_CTX_set_verify(sslContext, SSL_VERIFY_NONE, NULL);
                    
                    sslHandle = SSL_new (sslContext);
                    if (sslHandle == NULL)
                    {
                        #ifndef USE_CYASSL
                            ERR_print_errors_fp (stderr);
						#else
							fprintf(stderr, "failed to create SSL Handle\n");
						#endif

						SSL_CTX_free(sslContext);
                        sslContext = 0;

						errorCallback(WSError(WSError::SSL_NEW_FAILED, "Failed to create SSL handle."), userData);

						return false;
					}
                    
                    if (!SSL_set_fd (sslHandle, (int)sockfd))
                    {
                        #ifndef USE_CYASSL
                            ERR_print_errors_fp (stderr);
						#else
							fprintf(stderr, "failed to set SSL file descriptor\n");
						#endif

						SSL_CTX_free(sslContext);
                        sslContext = 0;
						SSL_free(sslHandle);
                        sslHandle = 0;

						errorCallback(WSError(WSError::SSL_SET_FD_FAILED, "Failed to set SSL file descriptor."), userData);

						return false;
                    }
                    
                    if (SSL_connect (sslHandle) != 1)
                    {
                        #ifndef USE_CYASSL
                            ERR_print_errors_fp (stderr);
						#else
							fprintf(stderr, "failed to SSL-Connect\n");
						#endif

						SSL_CTX_free(sslContext);
                        sslContext = 0;
						SSL_free(sslHandle);
                        sslHandle = 0;

						errorCallback(WSError(WSError::SSL_CONNECT_FAILED, "SSL_connect failed."), userData);

						return false;
                    }
                    fprintf(stderr, "SSL handshake success with: %s\n", m_url.c_str());
                }
                else
                {
					// I don't think that we'll ever end up here, because we're returning at the to in case sockfd == INVALID_SOCKET
                    fprintf(stderr, "Unable to connect to %s:%d\n", m_host.c_str(), m_port);
                    return false;
                }
            #else
            #define SEND(buf)  ::send(sockfd, buf, strlen(buf), 0)
            #define RECV(buf)  ::recv(sockfd, buf, 1, 0)
    
                if (sockfd == INVALID_SOCKET) {
                    fprintf(stderr, "Unable to connect to %s:%d\n", host, port);
                    return false;
                }
            #endif
    
    
            {
                // XXX: this should be done non-blocking,
                char line[256];
                int status;
                int i;
                snprintf(line, 256, "GET /%s HTTP/1.1\r\n", m_path.c_str()); SEND(line);
                if (m_port == 80) {
                    snprintf(line, 256, "Host: %s\r\n", m_host.c_str()); SEND(line);
                }
                else {
                    snprintf(line, 256, "Host: %s:%d\r\n", m_host.c_str(), m_port); SEND(line);
                }
                snprintf(line, 256, "Authorization: 15db07114504480519240fcc892fcd25e357cedf\r\n"); SEND(line);
                snprintf(line, 256, "Upgrade: websocket\r\n"); SEND(line);
                snprintf(line, 256, "Connection: Upgrade\r\n"); SEND(line);
                if (!m_origin.empty()) {
                    snprintf(line, 256, "Origin: %s\r\n", m_origin.c_str()); SEND(line);
                }
                snprintf(line, 256, "Sec-WebSocket-Key: x3JJHMbDL1EzLkh9GBhXDw==\r\n"); SEND(line);
                snprintf(line, 256, "Sec-WebSocket-Version: 13\r\n"); SEND(line);
                snprintf(line, 256, "\r\n"); SEND(line);
                for (i = 0; i < 2 || (i < 255 && line[i-2] != '\r' && line[i-1] != '\n'); ++i)
				{
					if (RECV(line+i) == 0)
					{
						errorCallback(WSError(WSError::CLOSED_DURING_WS_HANDSHAKE, "The connection was closed while the websocket handshake was in progress."), userData);
						return false;
					}
				}
                line[i] = 0;
				if (i == 255)
				{
					fprintf(stderr, "ERROR: Got invalid status line connecting to: %s\n", m_url.c_str());
					errorCallback(WSError(WSError::INVALID_STATUS_LINE_DURING_WS_HANDSHAKE, "Got invalid status line connecting to : " + m_url), userData);
					return false;
				}
				if (sscanf(line, "HTTP/1.1 %d", &status) != 1 || status != 101)
				{
					fprintf(stderr, "ERROR: Got bad status connecting to %s: %s", m_url.c_str(), line);
					errorCallback(WSError(WSError::BAD_STATUS_CODE, "Got bad status connecting to : " + m_url), userData);
					return false;
				}
                // TODO: verify response headers,
                for(;;) // while (true)
				{
                    for (i = 0; i < 2 || (i < 255 && line[i-2] != '\r' && line[i-1] != '\n'); ++i)
					{
						if (RECV(line+i) == 0)
						{
							errorCallback(WSError(WSError::CLOSED_DURING_WS_HANDSHAKE, "The connection was closed while the websocket handshake was in progress."), userData);
							return false;
						}
					}
                    if (line[0] == '\r' && line[1] == '\n')
					{
						break;
					}
                }
            }
            int flag = 1;
            
            #ifndef MARMALADE
                setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char*) &flag, sizeof(flag)); // Disable Nagle's algorithm
            #endif
            
            #ifdef _WIN32
                u_long on = 1;
                ioctlsocket(sockfd, FIONBIO, &on);
            #else
                fcntl(sockfd, F_SETFL, O_NONBLOCK);
            #endif
                fprintf(stderr, "Connected to: %s\n", m_url.c_str());
            
            return true;
        }
	};

	easywsclient::WebSocket::pointer from_url(const gsstl::string& url, bool useMask, const gsstl::string& origin)
    {
		char host[128];
		int port;
		char path[128];

        #ifdef SSL_SUPPORT
            bool secure_connection = false;
        #endif
		
        if (url.size() >= 128) {
			fprintf(stderr, "ERROR: url size limit exceeded: %s\n", url.c_str());
			return NULL;
		}
		if (origin.size() >= 200) {
			fprintf(stderr, "ERROR: origin size limit exceeded: %s\n", origin.c_str());
			return NULL;
		}

		if (sscanf(url.c_str(), "ws://%[^:/]:%d/%s", host, &port, path) == 3) {
		}
		else if (sscanf(url.c_str(), "ws://%[^:/]/%s", host, path) == 2) {
			port = 80;
		}
		else if (sscanf(url.c_str(), "ws://%[^:/]:%d", host, &port) == 2) {
			path[0] = '\0';
		}
		else if (sscanf(url.c_str(), "ws://%[^:/]", host) == 1) {
			port = 80;
			path[0] = '\0';
		}
#ifdef SSL_SUPPORT
		else if (sscanf(url.c_str(), "wss://%[^:/]:%d/%s", host, &port, path) == 3) {
			secure_connection = true;
		}
		else if (sscanf(url.c_str(), "wss://%[^:/]/%s", host, path) == 2) {
			port = 443;
			secure_connection = true;
		}
		else if (sscanf(url.c_str(), "wss://%[^:/]:%d", host, &port) == 2) {
			path[0] = '\0';
			secure_connection = true;
		}
		else if (sscanf(url.c_str(), "wss://%[^:/]", host) == 1) {
			port = 443;
			path[0] = '\0';
			secure_connection = true;
		}
#endif
		else
        {
			fprintf(stderr, "ERROR: Could not parse WebSocket url: %s\n", url.c_str());
			return NULL;
		}
		fprintf(stderr, "easywsclient: connecting: host=%s port=%d path=/%s\n", host, port, path);
        
        
        _RealWebSocket *nWebsocket = new _RealWebSocket(host, path, port, url, origin, useMask, secure_connection);
        if (!nWebsocket->doConnect())
        {
            nWebsocket = NULL;
        }
        
        return easywsclient::WebSocket::pointer(nWebsocket);

        //#ifdef SSL_SUPPORT
        //		return easywsclient::WebSocket::pointer(new _RealWebSocket(sockfd, useMask, sslHandle, sslContext));
        //#else
        //		return easywsclient::WebSocket::pointer(new _RealWebSocket(sockfd, useMask));
        //#endif
	}
} // end of module-only namespace



namespace easywsclient {
	WebSocket::pointer WebSocket::from_url(const gsstl::string& url, const gsstl::string& origin) {
		return ::from_url(url, true, origin);
	}

	WebSocket::pointer WebSocket::from_url_no_mask(const gsstl::string& url, const gsstl::string& origin) {
		return ::from_url(url, false, origin);
	}

	bool initEasyWSClient ()
	{
#if defined(_WIN32) || defined(WINAPI_FAMILY)
		INT rc;
		WSADATA wsaData;

		rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (rc) {
			printf("WSAStartup Failed.\n");
			return false;
		}
#endif

		return true;
	}

	void cleanupEasyWSClient ()
	{
#if defined(_WIN32) || defined(WINAPI_FAMILY)
		WSACleanup();
#endif
	}
} // namespace easywsclient
