#if defined(WINAPI_FAMILY)
#define __STDC_WANT_SECURE_LIB__ 0
#define sprintf_s(buf, size, fmt, ...) sprintf(buf, fmt, __VA_ARGS__)
#define swprintf_s(buf, size, fmt, ...) swprintf(buf, size, fmt, __VA_ARGS__)
#endif

#include <GameSparks/IGSPlatform.h>

#if GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
#	include <sys/types.h>
#	include <unistd.h>
#	include <fstream>
#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
#if WINAPI_FAMILY_DESKTOP_APP == WINAPI_FAMILY
#	include <locale>
#	include <shlwapi.h>
#	include <shlobj.h>
#	pragma comment(lib,"shlwapi.lib")
#	define GS_WINDOWS_DESKTOP
#else
#	include <Objbase.h>
//#	include <wrl.h>
#	undef nullptr
#	include <wrl.h>
#	include <windows.storage.h>
#	include <codecvt>
#	define GS_WINDOWS_APP
extern "C" int _getch(void) { return 0; }

#endif
#	pragma comment(lib, "Rpcrt4.lib")
#	include <Rpc.h>
#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC
#   include "TargetConditionals.h"
#   include <sys/stat.h> // for mkdir

	/* works like mkdir(1) used as "mkdir -p" */
	static void mkdirp(const char *dir) {
	    char tmp[PATH_MAX];
	    char *p = NULL;
	    size_t len;
	    
	    snprintf(tmp, sizeof(tmp),"%s",dir);
	    len = strlen(tmp);
	    if(tmp[len - 1] == '/')
	        tmp[len - 1] = 0;
	    for(p = tmp + 1; *p; p++)
	        if(*p == '/') {
	            *p = 0;
	            mkdir(tmp, S_IRWXU | S_IRWXG);
	            *p = '/';
	        }
	    mkdir(tmp, S_IRWXU | S_IRWXG);
	}

	gsstl::string get_osx_device_id();
#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
    gsstl::string gs_ios_get_writeable_base_path();
    gsstl::string get_ios_device_id();
#else
//#	include <uuid/uuid.h>
#endif

namespace GameSparks { namespace Core {


// trim from start
static inline gsstl::string &ltrim(gsstl::string &s) {
        s.erase(s.begin(), gsstl::find_if(s.begin(), s.end(), gsstl::not1(gsstl::ptr_fun<int, int>(isspace))));
        return s;
}

// trim from end
static inline gsstl::string &rtrim(gsstl::string &s) {
        s.erase(gsstl::find_if(s.rbegin(), s.rend(), gsstl::not1(gsstl::ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline gsstl::string &trim(gsstl::string &s) {
        return ltrim(rtrim(s));
}

#if GS_TARGET_PLATFORM != GS_PLATFORM_MAC && GS_TARGET_PLATFORM != GS_PLATFORM_IOS
static gsstl::string generate_guid()
{
	gsstl::string ret = "NO-UUID-SUPPORT-FOR-THIS-PLATFORM";

	#ifdef WIN32
		#if defined(GS_WINDOWS_DESKTOP)
			UUID uuid;
			UuidCreate(&uuid);

			unsigned char * str;
			UuidToStringA(&uuid, &str);

			ret = gsstl::string((char*)str);

			RpcStringFreeA(&str);
		#else
			GUID guid;
			if (S_OK != CoCreateGuid(&guid))
				return "GUID-CREATION-FAILED";

			OLECHAR* bstrGuid;
			StringFromCLSID(guid, &bstrGuid);

			typedef std::codecvt_utf8<wchar_t> convert_type;
			std::wstring_convert<convert_type, wchar_t> converter;

			ret = converter.to_bytes(bstrGuid);

			// ensure memory is freed
			::CoTaskMemFree(bstrGuid);
		#endif
	#elif defined(ANDROID)
		gsstl::ifstream ifs("/proc/sys/kernel/random/uuid");
		ifs >> ret;
	#endif
	/*#else
		uuid_t uuid;
		uuid_generate_random(uuid);
		char s[37];
		uuid_unparse(uuid, s);
		ret = s;
	#endif
		return ret;
	*/
	//assert(false);
	return trim(ret);
}
#endif


gsstl::string IGSPlatform::GetDeviceId() const
{
	static gsstl::string device_id;

	if (device_id.empty())
	{
		#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
			device_id = get_osx_device_id();
		#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
			device_id = get_ios_device_id();
		#else
			device_id = generate_guid();
			StoreValue("device_id", device_id);
		#endif

		device_id = trim(device_id);
	}

	return device_id;
}



gsstl::string IGSPlatform::GetDeviceOS() const
{
	#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
		return "OSX";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
		return "IOS";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
		return "Android";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
		return "W8";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_LINUX
		return "Linux";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE
		return "Marmelade";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_BADA
		return "Bada";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_BLACKBERRY
		return "Blackberry";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_NACL
		return "NaCl";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_EMSCRIPTEN
		return "emscripten";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_TIZEN
		return "Tizen";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_QT5
		return "QTS";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WINRT
		return "W8";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WP8
		return "WP8";
	#else
	#   error "Unsupported platform"
		return "Unknown";
	#endif
}


gsstl::string IGSPlatform::GetPlatform() const
{
	return GetDeviceOS();
}

gsstl::string concat(const gsstl::string& a, const gsstl::string& b)
{
	return a + b;
}

#if defined(WIN32) && defined(UNICODE)
static gsstl::wstring s2ws(const gsstl::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);

	wchar_t* tmp = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, tmp, len);
	gsstl::wstring r = tmp;
	delete[] tmp;
	return r;
}

static gsstl::wstring concat(const gsstl::wstring& a, const gsstl::string& b)
{
	return a + s2ws(b);
}

static FILE* fopen(const wchar_t* path, const char* mode_)
{
	gsstl::wstring mode = s2ws(mode_);
	return _wfopen(path, mode.c_str());
}
#endif

void IGSPlatform::StoreValue(const gsstl::string& key, const gsstl::string& value) const
{
	// TODO: port to all the platforms
	FILE* f = fopen(ToWritableLocation(key).c_str(), "wb");
	assert(f);
	if (!f)
	{
    	DebugMsg("**** Failed to store value to '" + key + "'");
    	return;
	}
	size_t written = fwrite(value.c_str(), 1, value.size(), f);
    (void)(written);
    assert(written == value.size());
	fclose(f);
}


gsstl::string IGSPlatform::LoadValue(const gsstl::string& key) const
{
	// TODO: port to all the platforms
	FILE *f = fopen(ToWritableLocation(key).c_str(), "rb");
	
    if(!f)
    {
    	//DebugMsg("**** Failed to load value from '" + ToWritableLocation(key) + "'");
        return "";
    }
    
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	if (fsize <= 0)
	{
		fclose(f);
		return "";
	}
	fseek(f, 0, SEEK_SET);
    gsstl::vector<char> bytes(static_cast<gsstl::vector<char>::size_type>(fsize));
	size_t read_bytes = fread(&bytes.front(), 1, fsize, f);
    (void)(read_bytes);
	assert(read_bytes == static_cast<size_t>(fsize));
	fclose(f);
	return gsstl::string( bytes.begin(), bytes.end() );
}



IGSPlatform::Path IGSPlatform::ToWritableLocation(gsstl::string desired_name) const
{
	desired_name = "gamesparks_" + desired_name;

	#if GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE || defined(GS_OVERRIDE_TOWRITABLELOCATION) // marmalade || windows; Note, that windows is for testing only. You should not put the files into the working directoy
    // http://docs.madewithmarmalade.com/display/MD/S3E+File+overview
	// This should work on marmalade
	return desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
		#if defined(GS_WINDOWS_DESKTOP)
			static Path base_path;

			if (base_path.empty())
			{
				TCHAR szPath[MAX_PATH];
				if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, szPath)))
				{
					base_path = szPath;
				}
				else
				{
					DebugMsg("Failed to get CSIDL_APPDATA path.");
					base_path = Path();
					base_path = concat(base_path, "./");
					assert(false);
				}

				base_path = concat(base_path, "\\GameSparks\\");
				base_path = concat(base_path, m_apiKey);
				base_path = concat(base_path, "\\");

				int result = SHCreateDirectoryEx(NULL, base_path.c_str(), NULL);

				if (
					result != ERROR_SUCCESS &&
					result != ERROR_FILE_EXISTS &&
					result != ERROR_ALREADY_EXISTS
					)
				{
					DebugMsg("Failed to create directory.");
					// if you end up here, you probably forgot to set-up your credentials.
					// The default credentials in the sample contain characters that are not valid in windows paths ('<' and '>')
					assert(false);
				}
			}

			assert(!base_path.empty());

			return concat(base_path, desired_name);
		#else
			std::wstring wbase_path = Windows::Storage::ApplicationData::Current->LocalFolder->Path->Data();
			typedef std::codecvt_utf8<wchar_t> convert_type;
			std::wstring_convert<convert_type, wchar_t> converter;
			auto base_path = converter.to_bytes(wbase_path);
			return base_path + "\\" + desired_name;
		#endif /* defined(GS_WINDOWS_DESKTOP) */


	#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC

    ////////////////// OS X
    static gsstl::string base_path;
    if (base_path.empty())
    {
		// the environment might not be correctly setup, then we store data in /tmp
        gsstl::string writable_path("/tmp/GameSparks");

		if(char* homedir = getenv("HOME"))
			writable_path = homedir;

		writable_path += "/Library/Application Support/GameSparks/" + m_apiKey + "/";
        
        struct stat s;// = {0};
        
        if (0 != stat(writable_path.c_str(), &s) ) // Check if directory exists
        {
            mkdirp(writable_path.c_str());
        }
    
        base_path = writable_path;
    }
    
    return base_path + desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID

	//////////////////////////////// Android
	// http://stackoverflow.com/questions/6276933/getfilesdir-from-ndk
	static gsstl::string base_path = "";
	if (base_path.empty())
	{
		char buf[200]; // 64bit int can be 20 digits at most
		sprintf(buf, "/proc/%i/cmdline", (int)getpid());

		FILE* f = fopen(buf, "rb");
		if (!f)
		{
			DebugMsg("Failed to get writable path");
			return desired_name;
		}
		fread(buf, 1, sizeof(buf), f);
		fclose(f);

		// bytes not contains the list of null separated command line arguments, the string constructor below will copy until the first null byte
		base_path = "/data/data/" + gsstl::string(buf) + "/";
	}
	return base_path + desired_name;

    #elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
    static gsstl::string base_path = gs_ios_get_writeable_base_path();
    return base_path + "/" + desired_name;
	#else
    #   error "ToWritableLocation not implemented for this platform. If you're planing on overriding it yourself, please define GS_OVERRIDE_TOWRITABLELOCATION"
	#endif
}

}} // namespace GameSparks { namespace Core {
