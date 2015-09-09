#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSChatOnChallengeRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChatOnChallengeRequest_Response, FGSChatOnChallengeResponse, ChatOnChallengeResponse, bool, hasErrors);

UCLASS()
class UGSChatOnChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnChatOnChallengeRequest_Response OnResponse;
	
	/**
	Sends a message to all players involved in the challenge. The current player must be involved in the challenge for the message to be sent.
	As the message is sent to all players, the current player will also see details of the message in the response. Read the section on response message aggregation for a description of this.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ChatOnChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSChatOnChallengeRequest* SendChatOnChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

