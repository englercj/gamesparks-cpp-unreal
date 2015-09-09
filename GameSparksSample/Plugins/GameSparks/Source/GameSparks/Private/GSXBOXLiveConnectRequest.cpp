#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSXBOXLiveConnectRequest.h"

void XBOXLiveConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSXBOXLiveConnectRequest* g_UGSXBOXLiveConnectRequest = static_cast<UGSXBOXLiveConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSXBOXLiveConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSXBOXLiveConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSXBOXLiveConnectRequest* UGSXBOXLiveConnectRequest::SendXBOXLiveConnectRequest(bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, FString StsTokenString, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSXBOXLiveConnectRequest* proxy = NewObject<UGSXBOXLiveConnectRequest>();
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->segments = Segments;
	proxy->stsTokenString = StsTokenString;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSXBOXLiveConnectRequest::Activate()
{
	GameSparks::Api::Requests::XBOXLiveConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
	}
	if(segments != nullptr){
		gsRequest.SetSegments(segments->ToRequestData());
	}
	if(stsTokenString != ""){
		gsRequest.SetStsTokenString(TCHAR_TO_UTF8(*stsTokenString));
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
    	gsRequest.Send(XBOXLiveConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(XBOXLiveConnectRequestResponseCallback);
    }
	
	
	
}

UGSXBOXLiveConnectRequest::UGSXBOXLiveConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

