#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSMatchDetailsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchDetailsRequest_Response, FGSMatchDetailsResponse, MatchDetailsResponse, bool, hasErrors);

UCLASS()
class UGSMatchDetailsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnMatchDetailsRequest_Response OnResponse;
	
	/**
	Find the details of an existing match this player belongs to, using the matchId
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS MatchDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSMatchDetailsRequest* SendMatchDetailsRequest(FString MatchId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString matchId;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

