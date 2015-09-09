#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSSocialStatusRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSocialStatusRequest_Response, FGSSocialStatusResponse, SocialStatusResponse, bool, hasErrors);

UCLASS()
class UGSSocialStatusRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSocialStatusRequest_Response OnResponse;
	
	/**
	Returns detials of the current social connections of this player. Each connection .
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialStatusRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSSocialStatusRequest* SendSocialStatusRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

