#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSEndSessionRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEndSessionRequest_Response, FGSEndSessionResponse, EndSessionResponse, bool, hasErrors);

UCLASS()
class UGSEndSessionRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnEndSessionRequest_Response OnResponse;
	
	/**
	Records the end of the current player's active session.
	The SDK will automatically create a new session ID when the application is started, this method can be useful to call when the app goes into the background to allow reporting on player session length.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS EndSessionRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Analytics")
	static UGSEndSessionRequest* SendEndSessionRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

