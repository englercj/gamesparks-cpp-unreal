#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSKongregateConnectRequest.h"

void KongregateConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSKongregateConnectRequest* g_UGSKongregateConnectRequest = static_cast<UGSKongregateConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSKongregateConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSKongregateConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSKongregateConnectRequest* UGSKongregateConnectRequest::SendKongregateConnectRequest(bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString GameAuthToken, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName, FString UserId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSKongregateConnectRequest* proxy = NewObject<UGSKongregateConnectRequest>();
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->gameAuthToken = GameAuthToken;
	proxy->segments = Segments;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->userId = UserId;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSKongregateConnectRequest::Activate()
{
	GameSparks::Api::Requests::KongregateConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
	}
	if(gameAuthToken != ""){
		gsRequest.SetGameAuthToken(TCHAR_TO_UTF8(*gameAuthToken));
	}
	if(segments != nullptr){
		gsRequest.SetSegments(segments->ToRequestData());
	}
	if(switchIfPossible != false){
		gsRequest.SetSwitchIfPossible(switchIfPossible);
	}
	if(syncDisplayName != false){
		gsRequest.SetSyncDisplayName(syncDisplayName);
	}
	if(userId != ""){
		gsRequest.SetUserId(TCHAR_TO_UTF8(*userId));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(KongregateConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(KongregateConnectRequestResponseCallback);
    }
	
	
	
}

UGSKongregateConnectRequest::UGSKongregateConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

