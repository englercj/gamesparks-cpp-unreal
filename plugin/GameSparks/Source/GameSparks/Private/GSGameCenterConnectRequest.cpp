#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGameCenterConnectRequest.h"

void GameCenterConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSGameCenterConnectRequest* g_UGSGameCenterConnectRequest = static_cast<UGSGameCenterConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGameCenterConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGameCenterConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGameCenterConnectRequest* UGSGameCenterConnectRequest::SendGameCenterConnectRequest(FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString ExternalPlayerId, FString PublicKeyUrl, FString Salt, UGameSparksScriptData* Segments, FString Signature, bool SwitchIfPossible, bool SyncDisplayName, int32 Timestamp,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGameCenterConnectRequest* proxy = NewObject<UGSGameCenterConnectRequest>();
	proxy->displayName = DisplayName;
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->externalPlayerId = ExternalPlayerId;
	proxy->publicKeyUrl = PublicKeyUrl;
	proxy->salt = Salt;
	proxy->segments = Segments;
	proxy->signature = Signature;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->timestamp = Timestamp;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGameCenterConnectRequest::Activate()
{
	GameSparks::Api::Requests::GameCenterConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(displayName != ""){
		gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
	}
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
	}
	if(externalPlayerId != ""){
		gsRequest.SetExternalPlayerId(TCHAR_TO_UTF8(*externalPlayerId));
	}
	if(publicKeyUrl != ""){
		gsRequest.SetPublicKeyUrl(TCHAR_TO_UTF8(*publicKeyUrl));
	}
	if(salt != ""){
		gsRequest.SetSalt(TCHAR_TO_UTF8(*salt));
	}
	if(segments != nullptr){
		gsRequest.SetSegments(segments->ToRequestData());
	}
	if(signature != ""){
		gsRequest.SetSignature(TCHAR_TO_UTF8(*signature));
	}
	if(switchIfPossible != false){
		gsRequest.SetSwitchIfPossible(switchIfPossible);
	}
	if(syncDisplayName != false){
		gsRequest.SetSyncDisplayName(syncDisplayName);
	}
	if(timestamp != 0){
		gsRequest.SetTimestamp(timestamp);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GameCenterConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GameCenterConnectRequestResponseCallback);
    }
	
	
	
}

UGSGameCenterConnectRequest::UGSGameCenterConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

