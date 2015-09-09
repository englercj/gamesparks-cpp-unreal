#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetMyTeamsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetMyTeamsRequest_Response, FGSGetMyTeamsResponse, GetMyTeamsResponse, bool, hasErrors);

UCLASS()
class UGSGetMyTeamsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetMyTeamsRequest_Response OnResponse;
	
	/**
	Get the teams that the player is in. Can be filtered on team type and also on those teams that the player owns.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMyTeamsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSGetMyTeamsRequest* SendGetMyTeamsRequest(bool OwnedOnly = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	bool ownedOnly;

	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

