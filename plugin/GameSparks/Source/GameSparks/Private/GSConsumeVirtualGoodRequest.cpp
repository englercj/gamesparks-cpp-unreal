#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSConsumeVirtualGoodRequest.h"

void ConsumeVirtualGoodRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ConsumeVirtualGoodResponse& response){
    
    FGSConsumeVirtualGoodResponse unreal_response = FGSConsumeVirtualGoodResponse(response.GetBaseData());
    
    UGSConsumeVirtualGoodRequest* g_UGSConsumeVirtualGoodRequest = static_cast<UGSConsumeVirtualGoodRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSConsumeVirtualGoodRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSConsumeVirtualGoodRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSConsumeVirtualGoodRequest* UGSConsumeVirtualGoodRequest::SendConsumeVirtualGoodRequest(int32 Quantity, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSConsumeVirtualGoodRequest* proxy = NewObject<UGSConsumeVirtualGoodRequest>();
	proxy->quantity = Quantity;
	proxy->shortCode = ShortCode;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSConsumeVirtualGoodRequest::Activate()
{
	GameSparks::Api::Requests::ConsumeVirtualGoodRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(quantity != 0){
		gsRequest.SetQuantity(quantity);
	}
	if(shortCode != ""){
		gsRequest.SetShortCode(TCHAR_TO_UTF8(*shortCode));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ConsumeVirtualGoodRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ConsumeVirtualGoodRequestResponseCallback);
    }
	
	
	
}

UGSConsumeVirtualGoodRequest::UGSConsumeVirtualGoodRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

