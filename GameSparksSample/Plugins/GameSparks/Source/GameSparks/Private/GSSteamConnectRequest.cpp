#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSSteamConnectRequest.h"

void SteamConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSSteamConnectRequest* g_UGSSteamConnectRequest = static_cast<UGSSteamConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSSteamConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSteamConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSteamConnectRequest* UGSSteamConnectRequest::SendSteamConnectRequest(bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, FString SessionTicket, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSSteamConnectRequest* proxy = NewObject<UGSSteamConnectRequest>();
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->segments = Segments;
	proxy->sessionTicket = SessionTicket;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSSteamConnectRequest::Activate()
{
	GameSparks::Api::Requests::SteamConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
	}
	if(segments != nullptr){
		gsRequest.SetSegments(segments->ToRequestData());
	}
	if(sessionTicket != ""){
		gsRequest.SetSessionTicket(TCHAR_TO_UTF8(*sessionTicket));
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
    	gsRequest.Send(SteamConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(SteamConnectRequestResponseCallback);
    }
	
	
	
}

UGSSteamConnectRequest::UGSSteamConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

