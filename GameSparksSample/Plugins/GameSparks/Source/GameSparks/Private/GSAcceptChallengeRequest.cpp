#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSAcceptChallengeRequest.h"

void AcceptChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AcceptChallengeResponse& response){
    
    FGSAcceptChallengeResponse unreal_response = FGSAcceptChallengeResponse(response.GetBaseData());
    
    UGSAcceptChallengeRequest* g_UGSAcceptChallengeRequest = static_cast<UGSAcceptChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSAcceptChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAcceptChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAcceptChallengeRequest* UGSAcceptChallengeRequest::SendAcceptChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSAcceptChallengeRequest* proxy = NewObject<UGSAcceptChallengeRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->message = Message;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSAcceptChallengeRequest::Activate()
{
	GameSparks::Api::Requests::AcceptChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(AcceptChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(AcceptChallengeRequestResponseCallback);
    }
	
	
	
}

UGSAcceptChallengeRequest::UGSAcceptChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

