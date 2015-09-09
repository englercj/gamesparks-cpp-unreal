#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListChallengeTypeRequest.h"

void ListChallengeTypeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListChallengeTypeResponse& response){
    
    FGSListChallengeTypeResponse unreal_response = FGSListChallengeTypeResponse(response.GetBaseData());
    
    UGSListChallengeTypeRequest* g_UGSListChallengeTypeRequest = static_cast<UGSListChallengeTypeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListChallengeTypeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListChallengeTypeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListChallengeTypeRequest* UGSListChallengeTypeRequest::SendListChallengeTypeRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListChallengeTypeRequest* proxy = NewObject<UGSListChallengeTypeRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListChallengeTypeRequest::Activate()
{
	GameSparks::Api::Requests::ListChallengeTypeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListChallengeTypeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListChallengeTypeRequestResponseCallback);
    }
	
	
	
}

UGSListChallengeTypeRequest::UGSListChallengeTypeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

