#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListMessageSummaryRequest.h"

void ListMessageSummaryRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListMessageSummaryResponse& response){
    
    FGSListMessageSummaryResponse unreal_response = FGSListMessageSummaryResponse(response.GetBaseData());
    
    UGSListMessageSummaryRequest* g_UGSListMessageSummaryRequest = static_cast<UGSListMessageSummaryRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListMessageSummaryRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListMessageSummaryRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListMessageSummaryRequest* UGSListMessageSummaryRequest::SendListMessageSummaryRequest(int32 EntryCount, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListMessageSummaryRequest* proxy = NewObject<UGSListMessageSummaryRequest>();
	proxy->entryCount = EntryCount;
	proxy->offset = Offset;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListMessageSummaryRequest::Activate()
{
	GameSparks::Api::Requests::ListMessageSummaryRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(ListMessageSummaryRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListMessageSummaryRequestResponseCallback);
    }
	
	
	
}

UGSListMessageSummaryRequest::UGSListMessageSummaryRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

