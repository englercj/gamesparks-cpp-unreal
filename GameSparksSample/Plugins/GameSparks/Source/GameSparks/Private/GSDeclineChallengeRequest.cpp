#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSDeclineChallengeRequest.h"

void DeclineChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::DeclineChallengeResponse& response){
    
    FGSDeclineChallengeResponse unreal_response = FGSDeclineChallengeResponse(response.GetBaseData());
    
    UGSDeclineChallengeRequest* g_UGSDeclineChallengeRequest = static_cast<UGSDeclineChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSDeclineChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDeclineChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDeclineChallengeRequest* UGSDeclineChallengeRequest::SendDeclineChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSDeclineChallengeRequest* proxy = NewObject<UGSDeclineChallengeRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->message = Message;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSDeclineChallengeRequest::Activate()
{
	GameSparks::Api::Requests::DeclineChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(DeclineChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(DeclineChallengeRequestResponseCallback);
    }
	
	
	
}

UGSDeclineChallengeRequest::UGSDeclineChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

