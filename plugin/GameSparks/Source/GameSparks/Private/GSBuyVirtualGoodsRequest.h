#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSBuyVirtualGoodsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBuyVirtualGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSBuyVirtualGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnBuyVirtualGoodsRequest_Response OnResponse;
	
	/**
	Purchases a virtual good with an in game currency. Once purchased the virtual good will be added to the players account.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS BuyVirtualGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSBuyVirtualGoodsRequest* SendBuyVirtualGoodsRequest(int32 CurrencyType = 0, int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	int32 currencyType;
	int32 quantity;

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

