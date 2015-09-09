#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetMessageRequest.h"

void GetMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetMessageResponse& response){
    
    FGSGetMessageResponse unreal_response = FGSGetMessageResponse(response.GetBaseData());
    
    UGSGetMessageRequest* g_UGSGetMessageRequest = static_cast<UGSGetMessageRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetMessageRequest* UGSGetMessageRequest::SendGetMessageRequest(FString MessageId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetMessageRequest* proxy = NewObject<UGSGetMessageRequest>();
	proxy->messageId = MessageId;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetMessageRequest::Activate()
{
	GameSparks::Api::Requests::GetMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(messageId != ""){
		gsRequest.SetMessageId(TCHAR_TO_UTF8(*messageId));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetMessageRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetMessageRequestResponseCallback);
    }
	
	
	
}

UGSGetMessageRequest::UGSGetMessageRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

