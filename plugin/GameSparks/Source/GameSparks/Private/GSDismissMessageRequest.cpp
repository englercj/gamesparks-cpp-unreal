#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSDismissMessageRequest.h"

void DismissMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::DismissMessageResponse& response){
    
    FGSDismissMessageResponse unreal_response = FGSDismissMessageResponse(response.GetBaseData());
    
    UGSDismissMessageRequest* g_UGSDismissMessageRequest = static_cast<UGSDismissMessageRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSDismissMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDismissMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDismissMessageRequest* UGSDismissMessageRequest::SendDismissMessageRequest(FString MessageId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSDismissMessageRequest* proxy = NewObject<UGSDismissMessageRequest>();
	proxy->messageId = MessageId;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSDismissMessageRequest::Activate()
{
	GameSparks::Api::Requests::DismissMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(DismissMessageRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(DismissMessageRequestResponseCallback);
    }
	
	
	
}

UGSDismissMessageRequest::UGSDismissMessageRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

