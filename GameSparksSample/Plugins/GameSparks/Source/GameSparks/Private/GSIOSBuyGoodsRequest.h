#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSIOSBuyGoodsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIOSBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSIOSBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnIOSBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes a transaction receipt from an App Store in app purchase.
	The GameSparks platform will validate the receipt with Apple and process the response. The transaction_id in the response will be recorded and the request will be rejected if the transaction_id has previously been processed, this prevents replay attacks.
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the product_id in the response with the 'IOS Product ID' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS IOSBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSIOSBuyGoodsRequest* SendIOSBuyGoodsRequest(FString Receipt = "", bool Sandbox = false, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString receipt;

	bool sandbox;
	bool uniqueTransactionByPlayer;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

