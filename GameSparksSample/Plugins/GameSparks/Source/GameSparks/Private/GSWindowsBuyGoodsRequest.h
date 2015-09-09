#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSWindowsBuyGoodsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWindowsBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSWindowsBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWindowsBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes a transaction receipt from a windows store purchase.
	The GameSparks platform will validate the receipt using the signature embedded in the xml. The Id in the xml will be recorded and the request will be rejected if the Id has previously been processed, this prevents replay attacks.
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the xml with the 'WP8 Product ID' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WindowsBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSWindowsBuyGoodsRequest* SendWindowsBuyGoodsRequest(FString Platform = "", FString Receipt = "", bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString platform;
	FString receipt;

	bool uniqueTransactionByPlayer;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

