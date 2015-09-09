#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSLogEventRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLogEventRequest_Response, FGSLogEventResponse, LogEventResponse, bool, hasErrors);

UCLASS()
class UGSLogEventRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLogEventRequest_Response OnResponse;
	
	/**
	Allows a user defined event to be triggered.
	This call differs from most as it does not have a fixed format. The @class and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.
	The example below shows a request to an event with a short code of HS with 2 attributes, 'HS' & 'GL'.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSLogEventRequest* SendLogEventRequest(FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString eventKey;

	
	UGameSparksLogEventData* logEventData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

