#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSEndSessionRequest.h"

void EndSessionRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::EndSessionResponse& response){
    
    FGSEndSessionResponse unreal_response = FGSEndSessionResponse(response.GetBaseData());
    
    UGSEndSessionRequest* g_UGSEndSessionRequest = static_cast<UGSEndSessionRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSEndSessionRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSEndSessionRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSEndSessionRequest* UGSEndSessionRequest::SendEndSessionRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSEndSessionRequest* proxy = NewObject<UGSEndSessionRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSEndSessionRequest::Activate()
{
	GameSparks::Api::Requests::EndSessionRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(EndSessionRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(EndSessionRequestResponseCallback);
    }
	
	
	
}

UGSEndSessionRequest::UGSEndSessionRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

