#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSViberConnectRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnViberConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSViberConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnViberConnectRequest_Response OnResponse;
	
	/**
	Allows a Viber account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Viber platform and store them within GameSparks.
	A successful authentication will also register the player to receive Viber push notifications.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Viber user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Viber user is not already registered with the game, the Viber user will be linked to the current player.
	If the current player has not authenticated and the Viber user is not known, a new player will be created using the Viber details and the session will be authenticated against the new player.
	If the Viber user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ViberConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSViberConnectRequest* SendViberConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSViberConnectRequest();

private:
	FString accessToken;
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;

	UGameSparksScriptData* segments;
	bool switchIfPossible;
	bool syncDisplayName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

