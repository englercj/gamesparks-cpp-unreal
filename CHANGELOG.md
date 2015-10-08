# ChangeLog

## rc11 (2015-10-01)

### base SDK (affects all platforms)
- cleaner structure for sources and headers for easier project setup
  - all .c/.cpp/.mm files are not in base/src
  - all headers are in base/include
  - so you only need to add one include directory when setting up a new project and add the sources to the project

### UE4
- fixed a crash that occured when the editor was closed without starting the game once

## rc10 (2015-09-20)

### UE4

- UE 4.9.1 Support
- GameMode transitions no longer require a call to connect in each world
- Default Connect BP node to use the preview servers

## rc9 (2015-09-07)

The SDKs are now released into one repository per engine:

[Generic C++ SDK](https://bitbucket.org/gamesparks/gamesparks-cpp-base.git)
[Unreal Engine Plugin](https://bitbucket.org/gamesparks/gamesparks-cpp-unreal.git)
[Marmalade](https://bitbucket.org/gamesparks/gamesparks-cpp-marmalade.git)
[Cocos2d-x](https://bitbucket.org/gamesparks/gamesparks-cpp-cocos2dx.git)
[WinRT](https://bitbucket.org/gamesparks/gamesparks-cpp-winrt.git)

- added support for Universal Windows RT Apps

### base SDK (affects all platforms)
- fixed a bug in cJSONs parse_number that caused results being off on ARM
- fixed cJSONs serialisations and deserialisation, when a locale other than "C" was set.
- fixed a few warnings
- improved compatibility with older compilers
- fixed a bug on windows that might have caused persistence to fail if the logged in user had non-ASCII characters in his username

### WinRT
- fixed a crash that was caused by calling close() on an already closed socket
- fixed getting the storage location for durable queue
- provided a sample project for Windows universal apps


## rc8 (2015-08-24)

### base SDK (affects all platforms)
- fixed callbacks sometimes not called in case of errors or timeouts
- fixed a crash when the contacted wss:// server was replying with HTTP:// responses. This could happen if the service provider injects responses to inform the user about insufficient founds.

### Marmalade
- fixed a compile error on Marmalade/Windows

### UE4
- Implement implement token clearing and logout


## rc7-p1 (2015-08-05)

### Unreal Engine
- fixed a bug that caused IsAuthenticated() and IsAvailable() to always return false

## rc7 (2015-07-30)

### base SDK (affects all platforms)
- implemented GetDeviceId() for iOS, Android, OSX and Windows. Details documented at IGSPlatform.h iGSPlatform::GetDeviceId()
	- note: there are separate implementations for Marmalade and Unreal that use the device-id provided by the engines
- re-compiled OpenSSL 1.0.2d for android, iOS and OSX
- extended compatibility with the iOS Simulator
- renamed the "GS_" class to "GS". There's a typedef, so that your code still compiles, but it's marked deprecated and will be removed in future versions.
- reanmed the "Optional_" template class to "Optional"
- changed the return type of GSTypedRequest::Send() to void, because it's interface was suggesting, that the SDK supports blocking calls
- renamed samples and tests so that it's easier to get the working on iOS
- implemented tests for GetDeviceId()
- implemented tests for socket disconnects
- fixed warnings

### Unreal Engine
- The SDK Sources are now included in the Plugin. This enables better deployment and easier debugging.
- fixed warnings

## patch rc6-p4 (2015-07-09)
- fixed an unitialized valiable (GS_::GameSparksAuthenticated) when SDK was compiled without support for std::function<>

## patch rc6-p3 (2015-07-06)
- Fix OS X build remove unused blueprints from GameSparksSample

## patch rc6-p2 (2015-07-06)
- Wrap with AllowWindowsPlatformTypes and HideWindowsPlatformTypes in GameSparksUnrealPlatform and GameSparksModule.h Remove warnings regarding FPostConstructInitializeProperties in request constructors

## patch rc6-p1 (2015-07-05)

### Unreal Engine
- Fix incorrect boolean HasErrors in response events
- Add BP Node access to response errors as GameSparksScriptData
- Add Get/Set Float and FloatList in GameSparksScriptData
- JSONString property on GameSparksScriptData for debugging
- Remove some unused classes from previous SDK version

## rc6 (2015-07-03)

### base SDK (affects all platforms)
- support for durable requests
  - GS_ now has GetDurableQueue
  - added HasCalbacks and SetCallbacks to GSRequest. If you're using durable requests, make sure to re-attach your callbacks via OnPersistentQueueLoadedCallback
  - fixed a missing return in WebSocket error handling
  - request and response objects now have HasUserData and GetUserData respectively SetUserData - User data also needs to be re-attached via OnPersistentQueueLoadedCallback, because it is a void* and will not be persisted
- fixed message callbacks
- IGSPlatform now has LoadValue and StoreValue so that the SDK can store persistent data.
  - We have implementations for Windows / OS X / iOS / Android / Marmalade in the base class
  - If you need to customize the behaviour, you can either override gsstl::string ToWritableLocation(gsstl::string desired_name) and/or IGSPlatform::StoreValue() IGSPlatform::LoadValue()
- format of request-ids now match the ones from the .NET SDK
- updated openssl binaries for iOS
- the samples and tests now also run in the iOS simulator
- If you want to run the samples on a device, you might have to change PRODUCT_NAME and the provisioning profile in the Xcode settings


### Unreal Engine
- Blueprint support!
- works with UE 4.7 and 4.8


## rc5 (2015-06-16)

### base SDK (affects all platforms)
- documentation tweaks
- added documentation for compile options
- compile option USE_CYASSL (enabled by default on Marmalade)
  - The SDK now works with OpenSSL and CYA_SSL
- Request id's now start at zero
- fixed a possible crash when a web-socket is closed
- increaed minimum required CMake version (fixes error about target_include_directories)

### Marmalade
- edits in documentation

### Cocos2d-x
- added qick start guide

## rc4 (2015-04-22)

### base SDK (affects all platforms)
- added documentation (execute docs/make.py for a preview)
- fixed a bug that caused update calls to connection to skipped
- fixed DeviceAuthenticationRequest (the getters and setters where missing)
- made some not yet implemented methods private 


## rc3 (2015-03-27)

### base SDK (affects all platforms)
- also building libs for the iOS-Simmulator (x86 and x64)
- fixed a crash on disconnect
- added hint about wrong credentials if connecting fails
- fixed timing logic for backing off and timeouts
- fixed looking up with the wrong key in the auto-generated code
- fixed cleanup if a GS_-object goes out of scope
- It's now possible to send the same GSRequest twice
- better socket-error handling
- fixed leaking the platform-object in the samples
- fixed the live-service URL
- minor cleanups
- fixed a bug that caused the creation of invalid JSON-Objects (keys where added multiple times instead of replaced)
- fixed samples to pass the correct time units (seconds) to update() 
- if the connection fails, the SDK now backs off for five seconds
- fixed a crash when a websocket timed out
- fixed a crash that occured if the websocket was destructed after a failed DNS-Lookup attempt
- added a stress-test sample
- added some tests
- improved continious integration (building for more platforms, running tests, etc.)

### Cocos2d-x
- removed cocos 2d from the repository
- added instruction on how to build the cocos sample
- added build-scripts to download cocos and build the sample
- added on-screen loggin to the cocos sample
- sample project now also supports the iOS-simmulator

### marmalade
- fixed error handling in websocket-code
- fixed cleanup in websocket code
- fixed samples to pass seconds to update()
- fixed a compile error in GSPlatformDeduction.h


## beta 2 (2015-01-24)

- Added support for Marmalade
- Changed SSL-Method to TLS1
- Fixed all memory leaks
- Interface Changes:
	- The global GameSparks::Core::GS instance has been removed. If you find it convinient to have a global GS instance, you're still free to create one yourself.
	- GameSparks::Core::GS::GameSparksAvailable(bool available) => GameSparks::Core::GS::GameSparksAvailable(GameSparks::Core::GS/ gsInstance, bool available)
		The callback gets the current GS-instance passed as the first argument
	- GameSparks::Api::Requests::*Request: constructor now expects a GS-instance as the first argument
	- The callbacks passed to request.Send() now expect a GS-instance as their first argument
	- The method to register message handlers has changed: you used to write:
		GameSparks::Api::Messages::*Message::SetListener(MyListener); now you write:
		GS.SetMessageListerner<TheMessageType>(MyMessageListener). You can register one MessageListener for each message-type. Also MyMessageListener gets the
		GS-instance passed as the first argument.

		An example:
```cpp
			using namespace GameSparks::Api::Messages;


			/* OLD */
			void OnAchievementEarnedMessage(const AchievementEarnedMessage& message)
			{
				// do stuff with message
			}

			…

			AchievementEarnedMessage::SetListener(OnAchievementEarnedMessage);


			/* NEW */
			void OnAchievementEarnedMessage(GameSparks::Core::GS_& gsInstance, const AchievementEarnedMessage& message)
			{
				// do stuff with message	    
			}

			…

			// Message-type deduction works for c-style callbacks
			GS.SetMessageListener(OnAchievementEarnedMessage);


			/* If you want to better document the the message type the handler is registered for or you're using c++11, you can also write: */
			GS.SetMessageListener<AchievementEarnedMessage>(OnAchievementEarnedMessage)

			/* C++11 lambdas also work, if your compiler and standard library supports it: */
			GS.SetMessageListener<AchievementEarnedMessage>([](GameSparks::Core::GS_& gsInstance, const AchievementEarnedMessage& message){
				// do stuff with message
			});
```
These changes where necessary for the leak-free shutdown of the SDK. 



## Initial

- Initial C++ SDK with support for plain C++, Unreal and Cocos2d-x
