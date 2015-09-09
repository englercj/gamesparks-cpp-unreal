#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSSendFriendMessageRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSendFriendMessageRequest_Response, FGSSendFriendMessageResponse, SendFriendMessageResponse, bool, hasErrors);

UCLASS()
class UGSSendFriendMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSendFriendMessageRequest_Response OnResponse;
	
	/**
	Sends a message to one or more game friend(s). A game friend is someone in the players social network who also plays the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendFriendMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSSendFriendMessageRequest* SendSendFriendMessageRequest(UGameSparksRequestArray* FriendIds = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	UGameSparksRequestArray* friendIds;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

