#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSFindChallengeRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindChallengeRequest_Response, FGSFindChallengeResponse, FindChallengeResponse, bool, hasErrors);

UCLASS()
class UGSFindChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFindChallengeRequest_Response OnResponse;
	
	/**
	Allows a player to find challenges that they are eligible to join.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSFindChallengeRequest* SendFindChallengeRequest(FString AccessType = "", int32 Count = 0, UGameSparksScriptData* Eligibility = nullptr, int32 Offset = 0, UGameSparksRequestArray* ShortCode = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString accessType;
	int32 count;
	UGameSparksScriptData* eligibility;
	int32 offset;

	UGameSparksRequestArray* shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

