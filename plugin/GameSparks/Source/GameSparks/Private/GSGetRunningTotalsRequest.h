#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetRunningTotalsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetRunningTotalsRequest_Response, FGSGetRunningTotalsResponse, GetRunningTotalsResponse, bool, hasErrors);

UCLASS()
class UGSGetRunningTotalsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetRunningTotalsRequest_Response OnResponse;
	
	/**
	Get the aggregation data for a group of the player's friends given running total specified by short code.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetRunningTotalsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetRunningTotalsRequest* SendGetRunningTotalsRequest(UGameSparksRequestArray* FriendIds = nullptr, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	UGameSparksRequestArray* friendIds;

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

