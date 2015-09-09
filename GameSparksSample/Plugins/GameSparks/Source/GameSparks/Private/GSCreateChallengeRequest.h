#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSCreateChallengeRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreateChallengeRequest_Response, FGSCreateChallengeResponse, CreateChallengeResponse, bool, hasErrors);

UCLASS()
class UGSCreateChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnCreateChallengeRequest_Response OnResponse;
	
	/**
	Issues a challenge to a group of players from the currently signed in player.
	The endTime field must be present unless the challenge template has an achievement set in the 'First to Achievement' field.
	The usersToChallenge field must be present for this request if the acessType is PRIVATE (which is the default).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSCreateChallengeRequest* SendCreateChallengeRequest(FString AccessType = "", bool AutoStartJoinedChallengeOnMaxPlayers = false, FString ChallengeMessage = "", FString ChallengeShortCode = "", int32 Currency1Wager = 0, int32 Currency2Wager = 0, int32 Currency3Wager = 0, int32 Currency4Wager = 0, int32 Currency5Wager = 0, int32 Currency6Wager = 0, UGameSparksScriptData* EligibilityCriteria = nullptr, FString EndTime = "", FString ExpiryTime = "", int32 MaxAttempts = 0, int32 MaxPlayers = 0, int32 MinPlayers = 0, bool Silent = false, FString StartTime = "", UGameSparksRequestArray* UsersToChallenge = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString accessType;
	bool autoStartJoinedChallengeOnMaxPlayers;
	FString challengeMessage;
	FString challengeShortCode;
	int32 currency1Wager;
	int32 currency2Wager;
	int32 currency3Wager;
	int32 currency4Wager;
	int32 currency5Wager;
	int32 currency6Wager;
	UGameSparksScriptData* eligibilityCriteria;
	FString endTime;
	FString expiryTime;
	int32 maxAttempts;
	int32 maxPlayers;
	int32 minPlayers;

	bool silent;
	FString startTime;
	UGameSparksRequestArray* usersToChallenge;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

