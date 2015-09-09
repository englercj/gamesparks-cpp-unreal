#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetUploadedRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetUploadedRequest_Response, FGSGetUploadedResponse, GetUploadedResponse, bool, hasErrors);

UCLASS()
class UGSGetUploadedRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetUploadedRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive URL to a piece of content that was previously uploaded to the GameSparks platform by a player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadedRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetUploadedRequest* SendGetUploadedRequest(FString UploadId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	FString uploadId;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

