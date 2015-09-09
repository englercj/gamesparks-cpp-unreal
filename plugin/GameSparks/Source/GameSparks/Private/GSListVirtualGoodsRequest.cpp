#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListVirtualGoodsRequest.h"

void ListVirtualGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListVirtualGoodsResponse& response){
    
    FGSListVirtualGoodsResponse unreal_response = FGSListVirtualGoodsResponse(response.GetBaseData());
    
    UGSListVirtualGoodsRequest* g_UGSListVirtualGoodsRequest = static_cast<UGSListVirtualGoodsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListVirtualGoodsRequest* UGSListVirtualGoodsRequest::SendListVirtualGoodsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListVirtualGoodsRequest* proxy = NewObject<UGSListVirtualGoodsRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListVirtualGoodsRequest::Activate()
{
	GameSparks::Api::Requests::ListVirtualGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListVirtualGoodsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListVirtualGoodsRequestResponseCallback);
    }
	
	
	
}

UGSListVirtualGoodsRequest::UGSListVirtualGoodsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

