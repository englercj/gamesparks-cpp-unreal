#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSListChallengeRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListChallengeRequest_Response, FGSListChallengeResponse, ListChallengeResponse, bool, hasErrors);

UCLASS()
class UGSListChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListChallengeRequest_Response OnResponse;
	
	/**
	Returns a list of challenges in the state defined in the 'state' field.
	The response can be further filtered by passing a shortCode field which will limit the returned lists to challenges of that short code.
	Valid states are:
	WAITING : The challenge has been issued and accepted and is waiting for the start date.
	RUNNING : The challenge is active.
	ISSUED : The challenge has been issued by the current player and is waiting to be accepted.
	RECEIVED : The challenge has been issued to the current player and is waiting to be accepted.
	COMPLETE : The challenge has completed.
	DECLINED : The challenge has been issued by the current player and has been declined.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSListChallengeRequest* SendListChallengeRequest(int32 EntryCount = 0, int32 Offset = 0, FString ShortCode = "", FString State = "", UGameSparksRequestArray* States = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	int32 entryCount;
	int32 offset;

	FString shortCode;
	FString state;
	UGameSparksRequestArray* states;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

