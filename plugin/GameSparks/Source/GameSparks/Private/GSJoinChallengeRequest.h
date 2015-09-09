#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSJoinChallengeRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJoinChallengeRequest_Response, FGSJoinChallengeResponse, JoinChallengeResponse, bool, hasErrors);

UCLASS()
class UGSJoinChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnJoinChallengeRequest_Response OnResponse;
	
	/**
	Allows a player to join an open challenge.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSJoinChallengeRequest* SendJoinChallengeRequest(FString ChallengeInstanceId = "", UGameSparksScriptData* Eligibility = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString challengeInstanceId;
	UGameSparksScriptData* eligibility;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

