#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSAmazonBuyGoodsRequest.h"

void AmazonBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSAmazonBuyGoodsRequest* g_UGSAmazonBuyGoodsRequest = static_cast<UGSAmazonBuyGoodsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSAmazonBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAmazonBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAmazonBuyGoodsRequest* UGSAmazonBuyGoodsRequest::SendAmazonBuyGoodsRequest(FString AmazonUserId, FString ReceiptId, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSAmazonBuyGoodsRequest* proxy = NewObject<UGSAmazonBuyGoodsRequest>();
	proxy->amazonUserId = AmazonUserId;
	proxy->receiptId = ReceiptId;
	proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSAmazonBuyGoodsRequest::Activate()
{
	GameSparks::Api::Requests::AmazonBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(amazonUserId != ""){
		gsRequest.SetAmazonUserId(TCHAR_TO_UTF8(*amazonUserId));
	}
	if(receiptId != ""){
		gsRequest.SetReceiptId(TCHAR_TO_UTF8(*receiptId));
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
    	gsRequest.Send(AmazonBuyGoodsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(AmazonBuyGoodsRequestResponseCallback);
    }
	
	
	
}

UGSAmazonBuyGoodsRequest::UGSAmazonBuyGoodsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

