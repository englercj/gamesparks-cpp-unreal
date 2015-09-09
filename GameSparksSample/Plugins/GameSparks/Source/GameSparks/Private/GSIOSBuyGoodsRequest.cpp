#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSIOSBuyGoodsRequest.h"

void IOSBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSIOSBuyGoodsRequest* g_UGSIOSBuyGoodsRequest = static_cast<UGSIOSBuyGoodsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSIOSBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSIOSBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSIOSBuyGoodsRequest* UGSIOSBuyGoodsRequest::SendIOSBuyGoodsRequest(FString Receipt, bool Sandbox, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSIOSBuyGoodsRequest* proxy = NewObject<UGSIOSBuyGoodsRequest>();
	proxy->receipt = Receipt;
	proxy->sandbox = Sandbox;
	proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSIOSBuyGoodsRequest::Activate()
{
	GameSparks::Api::Requests::IOSBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(receipt != ""){
		gsRequest.SetReceipt(TCHAR_TO_UTF8(*receipt));
	}
	if(sandbox != false){
		gsRequest.SetSandbox(sandbox);
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
    	gsRequest.Send(IOSBuyGoodsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(IOSBuyGoodsRequestResponseCallback);
    }
	
	
	
}

UGSIOSBuyGoodsRequest::UGSIOSBuyGoodsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

