#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSDeclineChallengeRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeclineChallengeRequest_Response, FGSDeclineChallengeResponse, DeclineChallengeResponse, bool, hasErrors);

UCLASS()
class UGSDeclineChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDeclineChallengeRequest_Response OnResponse;
	
	/**
	Declines a challenge that has been issued to the current player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DeclineChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSDeclineChallengeRequest* SendDeclineChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

