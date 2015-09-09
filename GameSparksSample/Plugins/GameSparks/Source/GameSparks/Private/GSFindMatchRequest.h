#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSFindMatchRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindMatchRequest_Response, FGSFindMatchResponse, FindMatchResponse, bool, hasErrors);

UCLASS()
class UGSFindMatchRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFindMatchRequest_Response OnResponse;
	
	/**
	Find a match for this player, using the given skill and matchShortCode.
	Players looking for a match using the same matchShortCode will be considered for a match, based on the matchConfig.
	The mathConfig can be overridden in this request.
	Each player must match the other for the match to be found.
	The matchConfig contains an array of thresholds that determine what constitutes an acceptable match.
	Each threshold specifies a period in seconds from when that threshold will be considered when matching this player.
	Thresholds contain a min and max value that determine the range that the other player's skill must lie within for a match to be found.
	The range calculation can be one of PERCENT, RELATIVE or ABSOLUTE.  PERCENT and RELATIVE both start from the current player's skill and look between min and max (subtracting min and adding max to calculate the range) for a suitable match.  ABSOLUTE looks for a player with skill that lies between the provided min and max values.  In all cases we will attempt to match a player with the nearest skill to the current player, as long as they are within range.
	Optionally, the threshold can specify a maxDistance in metres as well.  If specified, we will only match this player with players who are within maxDistance of the current player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindMatchRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSFindMatchRequest* SendFindMatchRequest(FString Action = "", FString MatchGroup = "", FString MatchShortCode = "", int32 Skill = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString action;
	FString matchGroup;
	FString matchShortCode;

	int32 skill;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

