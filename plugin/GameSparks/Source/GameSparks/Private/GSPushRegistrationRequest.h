#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSPushRegistrationRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPushRegistrationRequest_Response, FGSPushRegistrationResponse, PushRegistrationResponse, bool, hasErrors);

UCLASS()
class UGSPushRegistrationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnPushRegistrationRequest_Response OnResponse;
	
	/**
	Registers the current device for push notifications. Currently GameSparks supports iOS, GCM & Microsoft Push notifications.
	Supply the device type, and the push notification identifier for the device.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PushRegistrationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSPushRegistrationRequest* SendPushRegistrationRequest(FString DeviceOS = "", FString PushId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString deviceOS;
	FString pushId;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

