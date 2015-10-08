#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSWeChatConnectRequest.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeChatConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSWeChatConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWeChatConnectRequest_Response OnResponse;
	
	/**
	Allows a WeChat access token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the WeChat platform and store them within GameSparks.
	If the WeChat user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the WeChat user is not already registered with the game, the WeChat user will be linked to the current player.
	If the current player has not authenticated and the WeChat user is not known, a new player will be created using the WeChat details and the session will be authenticated against the new player.
	If the WeChat user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WeChatConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSWeChatConnectRequest* SendWeChatConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString OpenId = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSWeChatConnectRequest();

private:
	FString accessToken;
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;
	FString openId;

	UGameSparksScriptData* segments;
	bool switchIfPossible;
	bool syncDisplayName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

