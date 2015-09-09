#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSListGameFriendsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListGameFriendsRequest_Response, FGSListGameFriendsResponse, ListGameFriendsResponse, bool, hasErrors);

UCLASS()
class UGSListGameFriendsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListGameFriendsRequest_Response OnResponse;
	
	/**
	Returns the list of the current players game friends.
	A Game friend is someone in their social network who also plays the game.
	Against each friend, and indicator is supplied to show whether the friend is currently connected to the GameSparks service
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListGameFriendsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListGameFriendsRequest* SendListGameFriendsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

