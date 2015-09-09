#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSListMessageRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListMessageRequest_Response, FGSListMessageResponse, ListMessageResponse, bool, hasErrors);

UCLASS()
class UGSListMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListMessageRequest_Response OnResponse;
	
	/**
	Returns the list of the current players messages / notifications.
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest Read the section on Messages to the the complete list of messages and their meaning.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListMessageRequest* SendListMessageRequest(int32 EntryCount = 0, int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	int32 entryCount;
	int32 offset;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

