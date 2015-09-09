#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetMessageRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetMessageRequest_Response, FGSGetMessageResponse, GetMessageResponse, bool, hasErrors);

UCLASS()
class UGSGetMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetMessageRequest_Response OnResponse;
	
	/**
	Returns the full details of a message.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSGetMessageRequest* SendGetMessageRequest(FString MessageId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString messageId;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

