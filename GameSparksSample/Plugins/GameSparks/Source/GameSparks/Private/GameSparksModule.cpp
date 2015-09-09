

#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

#include "GameSparksModule.h"
#include "ModuleManager.h"
#include "Runtime/Core/Public/Features/IModularFeatures.h"
#include "Runtime/Core/Public/Stats/Stats2.h"

#include "GameSparksComponent.h"

#include "GameSparks/generated/GSMessages.h"
#include "GameSparksUnrealPlatform.h"
#include "GSMessageListeners.h"
#include <functional>

using namespace GameSparks::Core;
using namespace GameSparks::UnrealEngineSDK;


//DEFINE_LOG_CATEGORY(FGameSparks);
IMPLEMENT_MODULE(UGameSparksModule, GameSparks);
#define LOCTEXT_NAMESPACE "GameSparksPlugin"

DEFINE_LOG_CATEGORY(UGameSparksModuleLog);

void GameSparksAvailable_Static(GameSparks::Core::GS& gsInstance, bool available)
{
    UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::GameSparksAvailable_Static"));
	UGameSparksModule::GetModulePtr()->SendGameSparksAvailableToComponents(available);
}

void UGameSparksModule::StartupModule()
{
    UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::StartupModule"));
	GS.GameSparksAvailable = GameSparksAvailable_Static;
    UGSMessageListeners::RegisterListeners(GS);
    
}

void UGameSparksModule::ShutdownModule()
{
	GS.ShutDown();
    isInitialised = false;
}

bool UGameSparksModule::IsTickableWhenPaused() const
{
	return true;
}

bool UGameSparksModule::IsTickableInEditor() const
{
	return false;
}

void UGameSparksModule::Tick(float DeltaTime)
{
	GS.Update(DeltaTime);
}

bool UGameSparksModule::IsTickable() const
{
	return true;
}

TStatId UGameSparksModule::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGameSparksModule, STATGROUP_Tickables);
}

void UGameSparksModule::Initialize(FString apikey, FString secret, bool previewServer, bool clearCachedAuthentication)
{
    if(!isInitialised){
        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::Initialize"));
        GameSparksUnrealPlatform* platform = new GameSparksUnrealPlatform(TCHAR_TO_ANSI(*apikey), TCHAR_TO_ANSI(*secret), previewServer);
        if(clearCachedAuthentication){
            platform->SetAuthToken("0");
            platform->SetUserId("");
        }
        GS.Initialise(platform);
        isInitialised = true;
    }
}

void UGameSparksModule::Shutdown()
{
    if(isInitialised){
        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::Shutdown"));
        GS.ShutDown();
        isInitialised = false;
    }
}

void UGameSparksModule::Logout()
{
    if(isInitialised){
        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::Logout"));
        GS.Reset();
    }
}

UGameSparksModule* UGameSparksModule::GetModulePtr()
{
	return FModuleManager::GetModulePtr<UGameSparksModule>("GameSparks");
}

void UGameSparksModule::SendGameSparksAvailableToComponents(bool available)
{
    for ( TObjectIterator<UGameSparksComponent> Itr; Itr; ++Itr )
    {
        if(UGameSparksModuleNS::WorldList.Contains(Itr->GetWorld())){
            Itr->OnGameSparksAvailableDelegate.Broadcast(available);
        }
    }
}

void UGameSparksModule::SendDebugLogToComponents(const gsstl::string& message)
{
    FString str = FString(message.c_str());
    
    UE_LOG(UGameSparksModuleLog, Log, TEXT("%s"), *str);

	if (GEngine != NULL)
	{
        for ( TObjectIterator<UGameSparksComponent> Itr; Itr; ++Itr )
        {
            if(UGameSparksModuleNS::WorldList.Contains(Itr->GetWorld())){
                Itr->OnGameSparksDebugLog.Broadcast(str);
            }
        }
	}
}


void UGameSparksModule::OnWorldConnected(UWorld* World)
{
	UGameSparksModuleNS::WorldList.AddUnique(World);
}

void UGameSparksModule::OnWorldDisconnected(UWorld* World)
{
	UGameSparksModuleNS::WorldList.Remove(World);
}



