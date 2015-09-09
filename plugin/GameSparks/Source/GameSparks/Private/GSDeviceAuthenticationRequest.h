#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSDeviceAuthenticationRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeviceAuthenticationRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSDeviceAuthenticationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDeviceAuthenticationRequest_Response OnResponse;
	
	/**
	Allows a device id to be used to create an anonymous profile in the game.
	This allows the player to be tracked and have data stored against them before using FacebookConnectRequest to create a full profile.
	DeviceAuthenticationRequest should not be used in conjunction with RegistrationRequest as the two accounts will not be merged.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DeviceAuthenticationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSDeviceAuthenticationRequest* SendDeviceAuthenticationRequest(FString DeviceId = "", FString DeviceModel = "", FString DeviceName = "", FString DeviceOS = "", FString DeviceType = "", FString DisplayName = "", FString OperatingSystem = "", UGameSparksScriptData* Segments = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString deviceId;
	FString deviceModel;
	FString deviceName;
	FString deviceOS;
	FString deviceType;
	FString displayName;
	FString operatingSystem;

	UGameSparksScriptData* segments;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

