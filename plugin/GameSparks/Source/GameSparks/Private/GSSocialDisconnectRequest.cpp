#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSSocialDisconnectRequest.h"

void SocialDisconnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SocialDisconnectResponse& response){
    
    FGSSocialDisconnectResponse unreal_response = FGSSocialDisconnectResponse(response.GetBaseData());
    
    UGSSocialDisconnectRequest* g_UGSSocialDisconnectRequest = static_cast<UGSSocialDisconnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSSocialDisconnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSocialDisconnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSocialDisconnectRequest* UGSSocialDisconnectRequest::SendSocialDisconnectRequest(FString SystemId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSSocialDisconnectRequest* proxy = NewObject<UGSSocialDisconnectRequest>();
	proxy->systemId = SystemId;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSSocialDisconnectRequest::Activate()
{
	GameSparks::Api::Requests::SocialDisconnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(systemId != ""){
		gsRequest.SetSystemId(TCHAR_TO_UTF8(*systemId));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(SocialDisconnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(SocialDisconnectRequestResponseCallback);
    }
	
	
	
}

UGSSocialDisconnectRequest::UGSSocialDisconnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

