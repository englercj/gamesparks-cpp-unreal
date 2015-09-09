#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetTeamRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetTeamRequest_Response, FGSGetTeamResponse, GetTeamResponse, bool, hasErrors);

UCLASS()
class UGSGetTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetTeamRequest_Response OnResponse;
	
	/**
	Allows the details of a team to be retrieved.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSGetTeamRequest* SendGetTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

