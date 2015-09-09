#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGameCenterConnectRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameCenterConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSGameCenterConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGameCenterConnectRequest_Response OnResponse;
	
	/**
	Allows an Apple account that has GameCenter to be used as an authentication mechanism.
	The request must supply the GameCenter user details, such as the player id and username.
	If the GameCenter user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the GameCenter user is not already registered with the game, the GameCenter user will be linked to the current player.
	If the current player has not authenticated and the GameCenter user is not known, a new player will be created using the GameCenter details and the session will be authenticated against the new player.
	If the GameCenter user is already known, the session will switch to being the previously created user.
	This API call requires the output details from GKLocalPlayer.generateIdentityVerificationSignatureWithCompletionHandler on your iOS device
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GameCenterConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSGameCenterConnectRequest* SendGameCenterConnectRequest(FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString ExternalPlayerId = "", FString PublicKeyUrl = "", FString Salt = "", UGameSparksScriptData* Segments = nullptr, FString Signature = "", bool SwitchIfPossible = false, bool SyncDisplayName = false, int32 Timestamp = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString displayName;
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;
	FString externalPlayerId;
	FString publicKeyUrl;

	FString salt;
	UGameSparksScriptData* segments;
	FString signature;
	bool switchIfPossible;
	bool syncDisplayName;
	int32 timestamp;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

