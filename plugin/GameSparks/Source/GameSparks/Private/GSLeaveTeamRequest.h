#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSLeaveTeamRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaveTeamRequest_Response, FGSLeaveTeamResponse, LeaveTeamResponse, bool, hasErrors);

UCLASS()
class UGSLeaveTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaveTeamRequest_Response OnResponse;
	
	/**
	Allows a player to leave a team.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaveTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSLeaveTeamRequest* SendLeaveTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

