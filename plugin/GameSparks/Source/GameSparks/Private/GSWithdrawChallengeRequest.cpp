#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSWithdrawChallengeRequest.h"

void WithdrawChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::WithdrawChallengeResponse& response){
    
    FGSWithdrawChallengeResponse unreal_response = FGSWithdrawChallengeResponse(response.GetBaseData());
    
    UGSWithdrawChallengeRequest* g_UGSWithdrawChallengeRequest = static_cast<UGSWithdrawChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSWithdrawChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSWithdrawChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSWithdrawChallengeRequest* UGSWithdrawChallengeRequest::SendWithdrawChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSWithdrawChallengeRequest* proxy = NewObject<UGSWithdrawChallengeRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->message = Message;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSWithdrawChallengeRequest::Activate()
{
	GameSparks::Api::Requests::WithdrawChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(WithdrawChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(WithdrawChallengeRequestResponseCallback);
    }
	
	
	
}

UGSWithdrawChallengeRequest::UGSWithdrawChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

