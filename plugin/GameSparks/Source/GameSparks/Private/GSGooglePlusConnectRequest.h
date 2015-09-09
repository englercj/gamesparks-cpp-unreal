#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSGooglePlusConnectRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGooglePlusConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSGooglePlusConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGooglePlusConnectRequest_Response OnResponse;
	
	/**
	Allows either a Google Plus access code to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Google Plus platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Google Plus user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Google Plus user is not already registered with the game, the Google Plus user will be linked to the current player.
	If the current player has not authenticated and the Google Plus user is not known, a new player will be created using the Google Plus details and the session will be authenticated against the new player.
	If the Google Plus user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlusConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSGooglePlusConnectRequest* SendGooglePlusConnectRequest(FString AccessToken = "", FString Code = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;

private:
	FString accessToken;
	FString code;
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;
	FString redirectUri;

	UGameSparksScriptData* segments;
	bool switchIfPossible;
	bool syncDisplayName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

