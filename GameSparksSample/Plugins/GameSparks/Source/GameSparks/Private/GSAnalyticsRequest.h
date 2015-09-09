#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSAnalyticsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnalyticsRequest_Response, FGSAnalyticsResponse, AnalyticsResponse, bool, hasErrors);

UCLASS()
class UGSAnalyticsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAnalyticsRequest_Response OnResponse;
	
	/**
	Records some custom analytical data.
	Simple analytics, where you just need to track the number of times something happened, just take a key parameter. We'll record the players id against the data to allow you to report on averages per user
	Timed analytics allow you to send start and end timer requests, and with this data GameSparks can track the length of time something takes.
	If an end request is sent without a matching start timer the request will fail silently and your analytics data might not contain what you expect.
	If both start and end are supplied, the request will be treated as a start timer.
	An additional data payload can be attached to the event for advanced reporting. This data can be a string, number or JSON object.
	If a second start timer is created using a key that has already had a start timer created without an end, the previous one will be marked as abandoned.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AnalyticsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Analytics")
	static UGSAnalyticsRequest* SendAnalyticsRequest(UGameSparksScriptData* Data = nullptr, bool End = false, FString Key = "", bool Start = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	UGameSparksScriptData* data;
	bool end;
	FString key;

	bool start;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

