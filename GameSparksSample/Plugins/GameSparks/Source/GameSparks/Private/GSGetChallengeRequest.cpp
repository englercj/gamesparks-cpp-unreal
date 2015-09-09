#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetChallengeRequest.h"

void GetChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetChallengeResponse& response){
    
    FGSGetChallengeResponse unreal_response = FGSGetChallengeResponse(response.GetBaseData());
    
    UGSGetChallengeRequest* g_UGSGetChallengeRequest = static_cast<UGSGetChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetChallengeRequest* UGSGetChallengeRequest::SendGetChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetChallengeRequest* proxy = NewObject<UGSGetChallengeRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->message = Message;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetChallengeRequest::Activate()
{
	GameSparks::Api::Requests::GetChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(challengeInstanceId != ""){
		gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
	}
	if(message != ""){
		gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetChallengeRequestResponseCallback);
    }
	
	
	
}

UGSGetChallengeRequest::UGSGetChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

