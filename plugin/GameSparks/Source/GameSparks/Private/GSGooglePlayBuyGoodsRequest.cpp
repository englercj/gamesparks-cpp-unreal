#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGooglePlayBuyGoodsRequest.h"

void GooglePlayBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSGooglePlayBuyGoodsRequest* g_UGSGooglePlayBuyGoodsRequest = static_cast<UGSGooglePlayBuyGoodsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGooglePlayBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGooglePlayBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGooglePlayBuyGoodsRequest* UGSGooglePlayBuyGoodsRequest::SendGooglePlayBuyGoodsRequest(FString Signature, FString SignedData, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGooglePlayBuyGoodsRequest* proxy = NewObject<UGSGooglePlayBuyGoodsRequest>();
	proxy->signature = Signature;
	proxy->signedData = SignedData;
	proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGooglePlayBuyGoodsRequest::Activate()
{
	GameSparks::Api::Requests::GooglePlayBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(signature != ""){
		gsRequest.SetSignature(TCHAR_TO_UTF8(*signature));
	}
	if(signedData != ""){
		gsRequest.SetSignedData(TCHAR_TO_UTF8(*signedData));
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
    	gsRequest.Send(GooglePlayBuyGoodsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GooglePlayBuyGoodsRequestResponseCallback);
    }
	
	
	
}

UGSGooglePlayBuyGoodsRequest::UGSGooglePlayBuyGoodsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

