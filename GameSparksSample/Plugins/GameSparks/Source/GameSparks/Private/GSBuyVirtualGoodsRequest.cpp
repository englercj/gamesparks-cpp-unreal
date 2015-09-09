#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSBuyVirtualGoodsRequest.h"

void BuyVirtualGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSBuyVirtualGoodsRequest* g_UGSBuyVirtualGoodsRequest = static_cast<UGSBuyVirtualGoodsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSBuyVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSBuyVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSBuyVirtualGoodsRequest* UGSBuyVirtualGoodsRequest::SendBuyVirtualGoodsRequest(int32 CurrencyType, int32 Quantity, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSBuyVirtualGoodsRequest* proxy = NewObject<UGSBuyVirtualGoodsRequest>();
	proxy->currencyType = CurrencyType;
	proxy->quantity = Quantity;
	proxy->shortCode = ShortCode;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSBuyVirtualGoodsRequest::Activate()
{
	GameSparks::Api::Requests::BuyVirtualGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(currencyType != 0){
		gsRequest.SetCurrencyType(currencyType);
	}
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
    	gsRequest.Send(BuyVirtualGoodsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(BuyVirtualGoodsRequestResponseCallback);
    }
	
	
	
}

UGSBuyVirtualGoodsRequest::UGSBuyVirtualGoodsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

