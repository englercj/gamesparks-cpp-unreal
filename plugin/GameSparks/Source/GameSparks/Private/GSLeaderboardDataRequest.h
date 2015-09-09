#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSLeaderboardDataRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaderboardDataRequest_Response, FGSLeaderboardDataResponse, LeaderboardDataResponse, bool, hasErrors);

UCLASS()
class UGSLeaderboardDataRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaderboardDataRequest_Response OnResponse;
	
	/**
	Returns the top data for either the specified global leaderboard or the specified challenges leaderboard. The data is sorted as defined in the rules specified in the leaderboard configuration.
	The response contains the top of the leaderboard, and returns the number of entries as defined in the entryCount parameter.
	If a shortCode is supplied, the response will contain the global leaderboard data. If a challengeInstanceId is supplied, the response will contain the leaderboard data for the challenge.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSLeaderboardDataRequest* SendLeaderboardDataRequest(FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString challengeInstanceId;
	bool dontErrorOnNotSocial;
	int32 entryCount;
	UGameSparksRequestArray* friendIds;
	int32 includeFirst;
	int32 includeLast;
	bool inverseSocial;
	FString leaderboardShortCode;
	int32 offset;

	bool social;
	UGameSparksRequestArray* teamIds;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

