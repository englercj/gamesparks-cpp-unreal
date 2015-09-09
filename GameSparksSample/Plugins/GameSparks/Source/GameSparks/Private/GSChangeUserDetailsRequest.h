#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSChangeUserDetailsRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangeUserDetailsRequest_Response, FGSChangeUserDetailsResponse, ChangeUserDetailsResponse, bool, hasErrors);

UCLASS()
class UGSChangeUserDetailsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnChangeUserDetailsRequest_Response OnResponse;
	
	/**
	Change the display name of the currently signed in Player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ChangeUserDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSChangeUserDetailsRequest* SendChangeUserDetailsRequest(FString DisplayName = "", FString Language = "", FString NewPassword = "", FString OldPassword = "", FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString displayName;
	FString language;
	FString newPassword;
	FString oldPassword;

	FString userName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

