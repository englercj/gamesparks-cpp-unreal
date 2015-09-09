#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSAnalyticsRequest.h"

void AnalyticsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AnalyticsResponse& response){
    
    FGSAnalyticsResponse unreal_response = FGSAnalyticsResponse(response.GetBaseData());
    
    UGSAnalyticsRequest* g_UGSAnalyticsRequest = static_cast<UGSAnalyticsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSAnalyticsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAnalyticsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAnalyticsRequest* UGSAnalyticsRequest::SendAnalyticsRequest(UGameSparksScriptData* Data, bool End, FString Key, bool Start,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSAnalyticsRequest* proxy = NewObject<UGSAnalyticsRequest>();
	proxy->data = Data;
	proxy->end = End;
	proxy->key = Key;
	proxy->start = Start;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSAnalyticsRequest::Activate()
{
	GameSparks::Api::Requests::AnalyticsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(data != nullptr){
		gsRequest.SetData(data->ToRequestData());
	}
	if(end != false){
		gsRequest.SetEnd(end);
	}
	if(key != ""){
		gsRequest.SetKey(TCHAR_TO_UTF8(*key));
	}
	if(start != false){
		gsRequest.SetStart(start);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(AnalyticsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(AnalyticsRequestResponseCallback);
    }
	
	
	
}

UGSAnalyticsRequest::UGSAnalyticsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

