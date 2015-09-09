#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListMessageRequest.h"

void ListMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListMessageResponse& response){
    
    FGSListMessageResponse unreal_response = FGSListMessageResponse(response.GetBaseData());
    
    UGSListMessageRequest* g_UGSListMessageRequest = static_cast<UGSListMessageRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListMessageRequest* UGSListMessageRequest::SendListMessageRequest(int32 EntryCount, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListMessageRequest* proxy = NewObject<UGSListMessageRequest>();
	proxy->entryCount = EntryCount;
	proxy->offset = Offset;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListMessageRequest::Activate()
{
	GameSparks::Api::Requests::ListMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(entryCount != 0){
		gsRequest.SetEntryCount(entryCount);
	}
	if(offset != 0){
		gsRequest.SetOffset(offset);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListMessageRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListMessageRequestResponseCallback);
    }
	
	
	
}

UGSListMessageRequest::UGSListMessageRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

