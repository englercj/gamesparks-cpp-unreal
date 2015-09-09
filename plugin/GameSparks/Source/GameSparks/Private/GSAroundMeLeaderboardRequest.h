#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSAroundMeLeaderboardRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAroundMeLeaderboardRequest_Response, FGSAroundMeLeaderboardResponse, AroundMeLeaderboardResponse, bool, hasErrors);

UCLASS()
class UGSAroundMeLeaderboardRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAroundMeLeaderboardRequest_Response OnResponse;
	
	/**
	Returns leaderboard data that is adjacent to the currently signed in player's position within the given leaderboard.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AroundMeLeaderboardRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSAroundMeLeaderboardRequest* SendAroundMeLeaderboardRequest(FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
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

	bool social;
	UGameSparksRequestArray* teamIds;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

