#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSWindowsBuyGoodsRequest.h"

void WindowsBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSWindowsBuyGoodsRequest* g_UGSWindowsBuyGoodsRequest = static_cast<UGSWindowsBuyGoodsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSWindowsBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSWindowsBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSWindowsBuyGoodsRequest* UGSWindowsBuyGoodsRequest::SendWindowsBuyGoodsRequest(FString Platform, FString Receipt, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSWindowsBuyGoodsRequest* proxy = NewObject<UGSWindowsBuyGoodsRequest>();
	proxy->platform = Platform;
	proxy->receipt = Receipt;
	proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSWindowsBuyGoodsRequest::Activate()
{
	GameSparks::Api::Requests::WindowsBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(platform != ""){
		gsRequest.SetPlatform(TCHAR_TO_UTF8(*platform));
	}
	if(receipt != ""){
		gsRequest.SetReceipt(TCHAR_TO_UTF8(*receipt));
	}
	if(uniqueTransactionByPlayer != false){
		gsRequest.SetUniqueTransactionByPlayer(uniqueTransactionByPlayer);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(WindowsBuyGoodsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(WindowsBuyGoodsRequestResponseCallback);
    }
	
	
	
}

UGSWindowsBuyGoodsRequest::UGSWindowsBuyGoodsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

