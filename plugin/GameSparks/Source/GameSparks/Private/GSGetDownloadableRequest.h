#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetDownloadableRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetDownloadableRequest_Response, FGSGetDownloadableResponse, GetDownloadableResponse, bool, hasErrors);

UCLASS()
class UGSGetDownloadableRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetDownloadableRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive url to allow the game to download a piece of downloadable content stored in the GameSparks platform.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetDownloadableRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetDownloadableRequest* SendGetDownloadableRequest(FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

