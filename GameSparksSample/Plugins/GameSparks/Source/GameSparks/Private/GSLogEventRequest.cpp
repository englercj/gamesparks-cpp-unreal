#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksLogEventData.h"
#include "GSLogEventRequest.h"

void LogEventRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LogEventResponse& response){
    
    FGSLogEventResponse unreal_response = FGSLogEventResponse(response.GetBaseData());
    
    UGSLogEventRequest* g_UGSLogEventRequest = static_cast<UGSLogEventRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSLogEventRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLogEventRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLogEventRequest* UGSLogEventRequest::SendLogEventRequest(FString EventKey,  UGameSparksLogEventData* LogEventData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSLogEventRequest* proxy = NewObject<UGSLogEventRequest>();
	proxy->eventKey = EventKey;
	proxy->logEventData = LogEventData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSLogEventRequest::Activate()
{
	GameSparks::Api::Requests::LogEventRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(LogEventRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(LogEventRequestResponseCallback);
    }
	
	
	
}

UGSLogEventRequest::UGSLogEventRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

