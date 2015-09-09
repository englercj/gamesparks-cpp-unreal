#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSSocialLeaderboardDataRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSocialLeaderboardDataRequest_Response, FGSLeaderboardDataResponse, LeaderboardDataResponse, bool, hasErrors);

UCLASS()
class UGSSocialLeaderboardDataRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSocialLeaderboardDataRequest_Response OnResponse;
	
	/**
	Returns leaderboard data that only contains entries of players that are game friends with the current player.
	The GameSparks platform will attempt to return players both ahead and behind the current player, where data is available.
	The entry count defines how many player should be returned both ahead and behind. The numer of results may vary if there are not enough friends either ahead or behind.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialLeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSSocialLeaderboardDataRequest* SendSocialLeaderboardDataRequest(FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
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

