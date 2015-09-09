#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSListInviteFriendsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListInviteFriendsRequest_Response, FGSListInviteFriendsResponse, ListInviteFriendsResponse, bool, hasErrors);

UCLASS()
class UGSListInviteFriendsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListInviteFriendsRequest_Response OnResponse;
	
	/**
	Returns a list of non game friends.
	A non game friend is someone in their social network who does not play the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListInviteFriendsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListInviteFriendsRequest* SendListInviteFriendsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

