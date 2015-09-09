#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSSendTeamChatMessageRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSendTeamChatMessageRequest_Response, FGSSendTeamChatMessageResponse, SendTeamChatMessageResponse, bool, hasErrors);

UCLASS()
class UGSSendTeamChatMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSendTeamChatMessageRequest_Response OnResponse;
	
	/**
	Send a message to all the players who are member of the given team
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendTeamChatMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSSendTeamChatMessageRequest* SendSendTeamChatMessageRequest(FString Message = "", FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString message;
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

