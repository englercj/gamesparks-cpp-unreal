#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGooglePlusConnectRequest.h"

void GooglePlusConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSGooglePlusConnectRequest* g_UGSGooglePlusConnectRequest = static_cast<UGSGooglePlusConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGooglePlusConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGooglePlusConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGooglePlusConnectRequest* UGSGooglePlusConnectRequest::SendGooglePlusConnectRequest(FString AccessToken, FString Code, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString RedirectUri, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGooglePlusConnectRequest* proxy = NewObject<UGSGooglePlusConnectRequest>();
	proxy->accessToken = AccessToken;
	proxy->code = Code;
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->redirectUri = RedirectUri;
	proxy->segments = Segments;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGooglePlusConnectRequest::Activate()
{
	GameSparks::Api::Requests::GooglePlusConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(accessToken != ""){
		gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
	}
	if(code != ""){
		gsRequest.SetCode(TCHAR_TO_UTF8(*code));
	}
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
	}
	if(redirectUri != ""){
		gsRequest.SetRedirectUri(TCHAR_TO_UTF8(*redirectUri));
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
    	gsRequest.Send(GooglePlusConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GooglePlusConnectRequestResponseCallback);
    }
	
	
	
}

UGSGooglePlusConnectRequest::UGSGooglePlusConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

