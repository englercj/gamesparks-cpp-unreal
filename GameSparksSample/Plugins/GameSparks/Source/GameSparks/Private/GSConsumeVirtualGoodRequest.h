#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSConsumeVirtualGoodRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConsumeVirtualGoodRequest_Response, FGSConsumeVirtualGoodResponse, ConsumeVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSConsumeVirtualGoodRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnConsumeVirtualGoodRequest_Response OnResponse;
	
	/**
	Consumes a given amount of the specified virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ConsumeVirtualGoodRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSConsumeVirtualGoodRequest* SendConsumeVirtualGoodRequest(int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	int32 quantity;

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

