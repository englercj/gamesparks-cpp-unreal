#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGetLeaderboardEntriesRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetLeaderboardEntriesRequest_Response, FGSGetLeaderboardEntriesResponse, GetLeaderboardEntriesResponse, bool, hasErrors);

UCLASS()
class UGSGetLeaderboardEntriesRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetLeaderboardEntriesRequest_Response OnResponse;
	
	/**
	Get the leaderboard entry data for the current player or a given player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetLeaderboardEntriesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSGetLeaderboardEntriesRequest* SendGetLeaderboardEntriesRequest(UGameSparksRequestArray* Challenges = nullptr, bool InverseSocial = false, UGameSparksRequestArray* Leaderboards = nullptr, FString Player = "", bool Social = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	UGameSparksRequestArray* challenges;
	bool inverseSocial;
	UGameSparksRequestArray* leaderboards;
	FString player;

	bool social;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

