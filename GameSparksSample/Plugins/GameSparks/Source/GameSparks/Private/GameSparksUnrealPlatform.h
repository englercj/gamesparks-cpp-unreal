#pragma once

#include "Platform.h"
#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#endif
#include <GameSparks/IGSPlatform.h>
#include <GameSparks/GSPlatformDeduction.h>
#if PLATFORM_WINDOWS
#include "HideWindowsPlatformTypes.h"
#endif
#include "GameSparksModule.h"

namespace GameSparks
{
	namespace UnrealEngineSDK
	{
		class GameSparksUnrealPlatform : public GameSparks::Core::IGSPlatform
		{
		public:
			GameSparksUnrealPlatform(const gsstl::string& apikey, const gsstl::string& secret, bool previewServer)
				: GameSparks::Core::IGSPlatform(apikey, secret, previewServer)
			{
			}

			virtual gsstl::string GetDeviceId() const
			{
				return TCHAR_TO_ANSI(*FPlatformMisc::GetUniqueDeviceId());
			}

			virtual gsstl::string GetDeviceOS() const
			{
				return FPlatformProperties::IniPlatformName();
			}

			virtual gsstl::string GetPlatform() const
			{
				return FPlatformProperties::PlatformName();
			}

			virtual gsstl::string GetSDK() const
			{
				return "GameSparks Unreal Engine SDK";
			}

			virtual gsstl::string GetDeviceType() const
			{
#if PLATFORM_DESKTOP
				return "Desktop";
#else
				return "Handheld";
#endif	
			}

			virtual bool GetExtraDebug() const
			{
				return true;
			}

			virtual gsstl::string GetPreviewServiceUrl() const
			{
				return "wss://preview.gamesparks.net/ws/" + m_apiKey;
			}

			virtual gsstl::string GetLiveServiceUrl() const
			{
				return "wss://preview.gamesparks.net/ws/" + m_apiKey;
			}

			virtual void DebugMsg(const gsstl::string& message) const
			{
				if (UGameSparksModule::GetModulePtr())
					UGameSparksModule::GetModulePtr()->SendDebugLogToComponents(message);
			}

            virtual Path ToWritableLocation(gsstl::string desired_name) const{
                #if PLATFORM_IOS || PLATFORM_ANDROID
					// Conditional since ConvertRelativePathToFull does not work on mobile devices.
					// see https://answers.unrealengine.com/questions/120796/adding-custom-files-to-the-android-content.html
					return GameSparks::Core::IGSPlatform::ToWritableLocation(desired_name);
                #else
                    FString writeableLocation = FPaths::ConvertRelativePathToFull(FPaths::GameSavedDir());
                    writeableLocation += "gamesparks_";
                    writeableLocation += desired_name.c_str();
                    #if defined(WIN32) && defined(UNICODE)
                    	return *writeableLocation;
                    #else
	                    return TCHAR_TO_UTF8(*writeableLocation);
    	            #endif
	            #endif
            }
		};
	}
}
