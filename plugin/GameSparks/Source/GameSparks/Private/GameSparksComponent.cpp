#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

#include "GameSparksComponent.h"
#include "GameSparksModule.h"

// Sets default values for this component's properties
UGameSparksComponent::UGameSparksComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    bWantsInitializeComponent = true;
    PrimaryComponentTick.bCanEverTick = false;
}

void UGameSparksComponent::Connect(FString apikey, FString secret, bool previewServer, bool clearCachedAuthentication)
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
		UGameSparksModule::GetModulePtr()->Initialize(apikey, secret, previewServer, clearCachedAuthentication);
    }
}

void UGameSparksComponent::Disconnect()
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->Shutdown();
    }
		
}

void UGameSparksComponent::Logout()
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->Logout();
    }
}


bool UGameSparksComponent::IsAuthenticated(){
    return
        UGameSparksModule::GetModulePtr() != nullptr &&
        UGameSparksModule::GetModulePtr()->GetGSInstance().GetAuthenticated();
}

bool UGameSparksComponent::IsAvailable(){
    return
        UGameSparksModule::GetModulePtr() != nullptr &&
        UGameSparksModule::GetModulePtr()->GetGSInstance().GetAvailable();
}
