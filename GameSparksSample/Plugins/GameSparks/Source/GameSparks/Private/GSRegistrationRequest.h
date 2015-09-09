#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSRegistrationRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRegistrationRequest_Response, FGSRegistrationResponse, RegistrationResponse, bool, hasErrors);

UCLASS()
class UGSRegistrationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnRegistrationRequest_Response OnResponse;
	
	/**
	Allows a new player to be created using a username, password display name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS RegistrationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSRegistrationRequest* SendRegistrationRequest(FString DisplayName = "", FString Password = "", UGameSparksScriptData* Segments = nullptr, FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString displayName;
	FString password;

	UGameSparksScriptData* segments;
	FString userName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

