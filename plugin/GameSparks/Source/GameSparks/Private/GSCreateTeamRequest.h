#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSCreateTeamRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreateTeamRequest_Response, FGSCreateTeamResponse, CreateTeamResponse, bool, hasErrors);

UCLASS()
class UGSCreateTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnCreateTeamRequest_Response OnResponse;
	
	/**
	Allows a new team to be created.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSCreateTeamRequest* SendCreateTeamRequest(FString TeamId = "", FString TeamName = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	FString teamId;
	FString teamName;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

