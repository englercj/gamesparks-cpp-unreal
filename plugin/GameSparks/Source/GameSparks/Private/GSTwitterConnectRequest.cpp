#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSTwitterConnectRequest.h"

void TwitterConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSTwitterConnectRequest* g_UGSTwitterConnectRequest = static_cast<UGSTwitterConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSTwitterConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSTwitterConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSTwitterConnectRequest* UGSTwitterConnectRequest::SendTwitterConnectRequest(FString AccessSecret, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSTwitterConnectRequest* proxy = NewObject<UGSTwitterConnectRequest>();
	proxy->accessSecret = AccessSecret;
	proxy->accessToken = AccessToken;
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->segments = Segments;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSTwitterConnectRequest::Activate()
{
	GameSparks::Api::Requests::TwitterConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(accessSecret != ""){
		gsRequest.SetAccessSecret(TCHAR_TO_UTF8(*accessSecret));
	}
	if(accessToken != ""){
		gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
	}
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
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
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(TwitterConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(TwitterConnectRequestResponseCallback);
    }
	
	
	
}

UGSTwitterConnectRequest::UGSTwitterConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

