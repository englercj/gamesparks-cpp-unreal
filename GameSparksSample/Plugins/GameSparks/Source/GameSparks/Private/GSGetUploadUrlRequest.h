#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetUploadUrlRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetUploadUrlRequest_Response, FGSGetUploadUrlResponse, GetUploadUrlResponse, bool, hasErrors);

UCLASS()
class UGSGetUploadUrlRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetUploadUrlRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive URL to allow the game to upload a piece of player content to the GameSparks platform.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadUrlRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetUploadUrlRequest* SendGetUploadUrlRequest(UGameSparksScriptData* UploadData = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	UGameSparksScriptData* uploadData;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

