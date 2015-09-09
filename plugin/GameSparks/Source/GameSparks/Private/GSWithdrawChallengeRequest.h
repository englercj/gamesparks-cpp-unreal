#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSWithdrawChallengeRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWithdrawChallengeRequest_Response, FGSWithdrawChallengeResponse, WithdrawChallengeResponse, bool, hasErrors);

UCLASS()
class UGSWithdrawChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWithdrawChallengeRequest_Response OnResponse;
	
	/**
	Withdraws a challenge previously issued by the current player.
	This can only be done while the challenge is in the ISSUED state. Once it's been accepted the challenge can not be withdrawn.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WithdrawChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSWithdrawChallengeRequest* SendWithdrawChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

