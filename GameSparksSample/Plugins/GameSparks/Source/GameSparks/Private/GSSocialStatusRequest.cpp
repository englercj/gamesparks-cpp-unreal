#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSSocialStatusRequest.h"

void SocialStatusRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SocialStatusResponse& response){
    
    FGSSocialStatusResponse unreal_response = FGSSocialStatusResponse(response.GetBaseData());
    
    UGSSocialStatusRequest* g_UGSSocialStatusRequest = static_cast<UGSSocialStatusRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSSocialStatusRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSocialStatusRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSocialStatusRequest* UGSSocialStatusRequest::SendSocialStatusRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSSocialStatusRequest* proxy = NewObject<UGSSocialStatusRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSSocialStatusRequest::Activate()
{
	GameSparks::Api::Requests::SocialStatusRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(SocialStatusRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(SocialStatusRequestResponseCallback);
    }
	
	
	
}

UGSSocialStatusRequest::UGSSocialStatusRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

