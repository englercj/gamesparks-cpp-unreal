#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSJoinChallengeRequest.h"

void JoinChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::JoinChallengeResponse& response){
    
    FGSJoinChallengeResponse unreal_response = FGSJoinChallengeResponse(response.GetBaseData());
    
    UGSJoinChallengeRequest* g_UGSJoinChallengeRequest = static_cast<UGSJoinChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSJoinChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSJoinChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSJoinChallengeRequest* UGSJoinChallengeRequest::SendJoinChallengeRequest(FString ChallengeInstanceId, UGameSparksScriptData* Eligibility, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSJoinChallengeRequest* proxy = NewObject<UGSJoinChallengeRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->eligibility = Eligibility;
	proxy->message = Message;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSJoinChallengeRequest::Activate()
{
	GameSparks::Api::Requests::JoinChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(challengeInstanceId != ""){
		gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
	}
	if(eligibility != nullptr){
		gsRequest.SetEligibility(eligibility->ToRequestData());
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
    	gsRequest.Send(JoinChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(JoinChallengeRequestResponseCallback);
    }
	
	
	
}

UGSJoinChallengeRequest::UGSJoinChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

