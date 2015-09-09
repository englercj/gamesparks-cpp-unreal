#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSListTeamChatRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListTeamChatRequest_Response, FGSListTeamChatResponse, ListTeamChatResponse, bool, hasErrors);

UCLASS()
class UGSListTeamChatRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListTeamChatRequest_Response OnResponse;
	
	/**
	Get a list of the messages sent to the team (by players using SendTeamChatMessageRequest).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTeamChatRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSListTeamChatRequest* SendListTeamChatRequest(int32 EntryCount = 0, int32 Offset = 0, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	int32 entryCount;
	int32 offset;
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

