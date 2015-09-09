#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksLogEventData.h"
#include "GSLogChallengeEventRequest.h"

void LogChallengeEventRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LogChallengeEventResponse& response){
    
    FGSLogChallengeEventResponse unreal_response = FGSLogChallengeEventResponse(response.GetBaseData());
    
    UGSLogChallengeEventRequest* g_UGSLogChallengeEventRequest = static_cast<UGSLogChallengeEventRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSLogChallengeEventRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLogChallengeEventRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLogChallengeEventRequest* UGSLogChallengeEventRequest::SendLogChallengeEventRequest(FString ChallengeInstanceId, FString EventKey,  UGameSparksLogEventData* LogEventData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSLogChallengeEventRequest* proxy = NewObject<UGSLogChallengeEventRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->eventKey = EventKey;
	proxy->logEventData = LogEventData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSLogChallengeEventRequest::Activate()
{
	GameSparks::Api::Requests::LogChallengeEventRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(challengeInstanceId != ""){
		gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
	}
	if(eventKey != ""){
		gsRequest.SetEventKey(TCHAR_TO_UTF8(*eventKey));
	}
	if(logEventData != nullptr){
		logEventData->AddToLogEvent(&gsRequest);
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(LogChallengeEventRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(LogChallengeEventRequestResponseCallback);
    }
	
	
	
}

UGSLogChallengeEventRequest::UGSLogChallengeEventRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

