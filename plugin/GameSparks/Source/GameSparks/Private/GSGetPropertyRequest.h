#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetPropertyRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetPropertyRequest_Response, FGSGetPropertyResponse, GetPropertyResponse, bool, hasErrors);

UCLASS()
class UGSGetPropertyRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetPropertyRequest_Response OnResponse;
	
	/**
	Get the property for the given short Code.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetPropertyRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetPropertyRequest* SendGetPropertyRequest(FString PropertyShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString propertyShortCode;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

