#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGooglePlayBuyGoodsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGooglePlayBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSGooglePlayBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGooglePlayBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes the response from a Google Play in app purchase flow.
	The GameSparks platform will validate the signature and signed data with the Google Play Public Key configured against the game.
	The orderId in the data will be recorded and the request will be rejected if the orderId has previously been processed, this prevents replay attacks.
	Once verfied, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the signed data with the 'Google Product ID' configured against the virtual good.
	It is critical that the signedData is sent exactly as it is returned form google, including any whitespace. Any modification of the signedData will cause the verification process to fail.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlayBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSGooglePlayBuyGoodsRequest* SendGooglePlayBuyGoodsRequest(FString Signature = "", FString SignedData = "", bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	FString signature;
	FString signedData;
	bool uniqueTransactionByPlayer;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

