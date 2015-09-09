#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSLogChallengeEventRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLogChallengeEventRequest_Response, FGSLogChallengeEventResponse, LogChallengeEventResponse, bool, hasErrors);

UCLASS()
class UGSLogChallengeEventRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLogChallengeEventRequest_Response OnResponse;
	
	/**
	Allows a user defined event to be triggered. The event will be posted to the challenge specified.
	This call differs from most as it does not have a fixed format. The @class, challengeInstanceId and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.
	The example below shows a request to en event with a short code of HS with 2 attributes, 'HS' & 'GL'.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogChallengeEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSLogChallengeEventRequest* SendLogChallengeEventRequest(FString ChallengeInstanceId = "", FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString challengeInstanceId;
	FString eventKey;

	
	UGameSparksLogEventData* logEventData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

