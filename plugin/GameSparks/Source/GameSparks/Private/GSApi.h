#pragma once
#include "GameSparksLogEventData.h"
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSApi.generated.h"


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAcceptChallengeRequest_Response, FGSAcceptChallengeResponse, AcceptChallengeResponse, bool, hasErrors);

UCLASS()
class UGSAcceptChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAcceptChallengeRequest_Response OnResponse;
	
	/**
	Accepts a challenge that has been issued to the current player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AcceptChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSAcceptChallengeRequest* SendAcceptChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAcceptChallengeRequest();

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAccountDetailsRequest_Response, FGSAccountDetailsResponse, AccountDetailsResponse, bool, hasErrors);

UCLASS()
class UGSAccountDetailsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAccountDetailsRequest_Response OnResponse;
	
	/**
	Retrieves the details of the current authenticated player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AccountDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSAccountDetailsRequest* SendAccountDetailsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAccountDetailsRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmazonBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSAmazonBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAmazonBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes the receipt from an Amazon in app purchase.
	The GameSparks platform will validate the amazonUserId and receiptId with Amazon using the Amazon Purchase Secret configured against the game.
	The receiptId in the data will be recorded and the request will be rejected if the receiptId has previously been processed, this prevents replay attacks.
	Once verfied, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the receipt with the 'Amazon Product Id' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AmazonBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSAmazonBuyGoodsRequest* SendAmazonBuyGoodsRequest(FString AmazonUserId = "", FString ReceiptId = "", bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAmazonBuyGoodsRequest();

private:
	FString amazonUserId;
	FString receiptId;

	bool uniqueTransactionByPlayer;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmazonConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSAmazonConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAmazonConnectRequest_Response OnResponse;
	
	/**
	Allows an Amazon access token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Amazon platform and store them within GameSparks.
	If the Amazon user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Amazon user is not already registered with the game, the Amazon user will be linked to the current player.
	If the current player has not authenticated and the Amazon user is not known, a new player will be created using the Amazon details and the session will be authenticated against the new player.
	If the Amazon user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AmazonConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSAmazonConnectRequest* SendAmazonConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAmazonConnectRequest();

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


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnalyticsRequest_Response, FGSAnalyticsResponse, AnalyticsResponse, bool, hasErrors);

UCLASS()
class UGSAnalyticsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAnalyticsRequest_Response OnResponse;
	
	/**
	Records some custom analytical data.
	Simple analytics, where you just need to track the number of times something happened, just take a key parameter. We'll record the players id against the data to allow you to report on averages per user
	Timed analytics allow you to send start and end timer requests, and with this data GameSparks can track the length of time something takes.
	If an end request is sent without a matching start timer the request will fail silently and your analytics data might not contain what you expect.
	If both start and end are supplied, the request will be treated as a start timer.
	An additional data payload can be attached to the event for advanced reporting. This data can be a string, number or JSON object.
	If a second start timer is created using a key that has already had a start timer created without an end, the previous one will be marked as abandoned.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AnalyticsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Analytics")
	static UGSAnalyticsRequest* SendAnalyticsRequest(UGameSparksScriptData* Data = nullptr, bool End = false, FString Key = "", bool Start = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAnalyticsRequest();

private:
	UGameSparksScriptData* data;
	bool end;
	FString key;

	bool start;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAroundMeLeaderboardRequest_Response, FGSAroundMeLeaderboardResponse, AroundMeLeaderboardResponse, bool, hasErrors);

UCLASS()
class UGSAroundMeLeaderboardRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAroundMeLeaderboardRequest_Response OnResponse;
	
	/**
	Returns leaderboard data that is adjacent to the currently signed in player's position within the given leaderboard.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AroundMeLeaderboardRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSAroundMeLeaderboardRequest* SendAroundMeLeaderboardRequest(FString ChallengeInstanceId = "", UGameSparksScriptData* CustomIdFilter = nullptr, bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAroundMeLeaderboardRequest();

private:
	FString challengeInstanceId;
	UGameSparksScriptData* customIdFilter;
	bool dontErrorOnNotSocial;
	int32 entryCount;
	UGameSparksRequestArray* friendIds;
	int32 includeFirst;
	int32 includeLast;
	bool inverseSocial;
	FString leaderboardShortCode;

	bool social;
	UGameSparksRequestArray* teamIds;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAuthenticationRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSAuthenticationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAuthenticationRequest_Response OnResponse;
	
	/**
	Provides authentication using a username/password combination.
	The username will have been previously created using a RegistrationRequest.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AuthenticationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSAuthenticationRequest* SendAuthenticationRequest(FString Password = "", FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAuthenticationRequest();

private:
	FString password;

	FString userName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBuyVirtualGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSBuyVirtualGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnBuyVirtualGoodsRequest_Response OnResponse;
	
	/**
	Purchases a virtual good with an in game currency. Once purchased the virtual good will be added to the players account.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS BuyVirtualGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSBuyVirtualGoodsRequest* SendBuyVirtualGoodsRequest(int32 CurrencyType = 0, int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSBuyVirtualGoodsRequest();

private:
	int32 currencyType;
	int32 quantity;

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


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
	
	~UGSChangeUserDetailsRequest();

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


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChatOnChallengeRequest_Response, FGSChatOnChallengeResponse, ChatOnChallengeResponse, bool, hasErrors);

UCLASS()
class UGSChatOnChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnChatOnChallengeRequest_Response OnResponse;
	
	/**
	Sends a message to all players involved in the challenge. The current player must be involved in the challenge for the message to be sent.
	As the message is sent to all players, the current player will also see details of the message in the response. Read the section on response message aggregation for a description of this.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ChatOnChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSChatOnChallengeRequest* SendChatOnChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSChatOnChallengeRequest();

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConsumeVirtualGoodRequest_Response, FGSConsumeVirtualGoodResponse, ConsumeVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSConsumeVirtualGoodRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnConsumeVirtualGoodRequest_Response OnResponse;
	
	/**
	Consumes a given amount of the specified virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ConsumeVirtualGoodRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSConsumeVirtualGoodRequest* SendConsumeVirtualGoodRequest(int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSConsumeVirtualGoodRequest();

private:
	int32 quantity;

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreateChallengeRequest_Response, FGSCreateChallengeResponse, CreateChallengeResponse, bool, hasErrors);

UCLASS()
class UGSCreateChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnCreateChallengeRequest_Response OnResponse;
	
	/**
	Issues a challenge to a group of players from the currently signed in player.
	The endTime field must be present unless the challenge template has an achievement set in the 'First to Achievement' field.
	The usersToChallenge field must be present for this request if the acessType is PRIVATE (which is the default).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSCreateChallengeRequest* SendCreateChallengeRequest(FString AccessType = "", bool AutoStartJoinedChallengeOnMaxPlayers = false, FString ChallengeMessage = "", FString ChallengeShortCode = "", int32 Currency1Wager = 0, int32 Currency2Wager = 0, int32 Currency3Wager = 0, int32 Currency4Wager = 0, int32 Currency5Wager = 0, int32 Currency6Wager = 0, UGameSparksScriptData* EligibilityCriteria = nullptr, FString EndTime = "", FString ExpiryTime = "", int32 MaxAttempts = 0, int32 MaxPlayers = 0, int32 MinPlayers = 0, bool Silent = false, FString StartTime = "", UGameSparksRequestArray* UsersToChallenge = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSCreateChallengeRequest();

private:
	FString accessType;
	bool autoStartJoinedChallengeOnMaxPlayers;
	FString challengeMessage;
	FString challengeShortCode;
	int32 currency1Wager;
	int32 currency2Wager;
	int32 currency3Wager;
	int32 currency4Wager;
	int32 currency5Wager;
	int32 currency6Wager;
	UGameSparksScriptData* eligibilityCriteria;
	FString endTime;
	FString expiryTime;
	int32 maxAttempts;
	int32 maxPlayers;
	int32 minPlayers;

	bool silent;
	FString startTime;
	UGameSparksRequestArray* usersToChallenge;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreateTeamRequest_Response, FGSCreateTeamResponse, CreateTeamResponse, bool, hasErrors);

UCLASS()
class UGSCreateTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnCreateTeamRequest_Response OnResponse;
	
	/**
	Allows a new team to be created.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSCreateTeamRequest* SendCreateTeamRequest(FString TeamId = "", FString TeamName = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSCreateTeamRequest();

private:

	FString teamId;
	FString teamName;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeclineChallengeRequest_Response, FGSDeclineChallengeResponse, DeclineChallengeResponse, bool, hasErrors);

UCLASS()
class UGSDeclineChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDeclineChallengeRequest_Response OnResponse;
	
	/**
	Declines a challenge that has been issued to the current player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DeclineChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSDeclineChallengeRequest* SendDeclineChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDeclineChallengeRequest();

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


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
	
	~UGSDeviceAuthenticationRequest();

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


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDismissMessageRequest_Response, FGSDismissMessageResponse, DismissMessageResponse, bool, hasErrors);

UCLASS()
class UGSDismissMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDismissMessageRequest_Response OnResponse;
	
	/**
	Allows a message to be dismissed. Once dismissed the message will no longer appear in either ListMessageResponse or ListMessageSummaryResponse.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DismissMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSDismissMessageRequest* SendDismissMessageRequest(FString MessageId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDismissMessageRequest();

private:
	FString messageId;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDropTeamRequest_Response, FGSDropTeamResponse, DropTeamResponse, bool, hasErrors);

UCLASS()
class UGSDropTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDropTeamRequest_Response OnResponse;
	
	/**
	Allows a player to drop a team.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DropTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSDropTeamRequest* SendDropTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDropTeamRequest();

private:
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


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
	
	~UGSEndSessionRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFacebookConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSFacebookConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFacebookConnectRequest_Response OnResponse;
	
	/**
	Allows either a Facebook access token, or a Facebook authorization code to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Facebook platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Facebook user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the Facebook user is not already registered with the game, the Facebook user will be linked to the current player.
	If the current player has not authenticated and the Facebook user is not known, a new player will be created using the Facebook details and the session will be authenticated against the new player.
	If the Facebook user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FacebookConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSFacebookConnectRequest* SendFacebookConnectRequest(FString AccessToken = "", FString Code = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSFacebookConnectRequest();

private:
	FString accessToken;
	FString code;
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;

	UGameSparksScriptData* segments;
	bool switchIfPossible;
	bool syncDisplayName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindChallengeRequest_Response, FGSFindChallengeResponse, FindChallengeResponse, bool, hasErrors);

UCLASS()
class UGSFindChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFindChallengeRequest_Response OnResponse;
	
	/**
	Allows a player to find challenges that they are eligible to join.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSFindChallengeRequest* SendFindChallengeRequest(FString AccessType = "", int32 Count = 0, UGameSparksScriptData* Eligibility = nullptr, int32 Offset = 0, UGameSparksRequestArray* ShortCode = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSFindChallengeRequest();

private:
	FString accessType;
	int32 count;
	UGameSparksScriptData* eligibility;
	int32 offset;

	UGameSparksRequestArray* shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindMatchRequest_Response, FGSFindMatchResponse, FindMatchResponse, bool, hasErrors);

UCLASS()
class UGSFindMatchRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFindMatchRequest_Response OnResponse;
	
	/**
	Find a match for this player, using the given skill and matchShortCode.
	Players looking for a match using the same matchShortCode will be considered for a match, based on the matchConfig.
	Each player must match the other for the match to be found.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindMatchRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSFindMatchRequest* SendFindMatchRequest(FString Action = "", FString MatchGroup = "", FString MatchShortCode = "", int32 Skill = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSFindMatchRequest();

private:
	FString action;
	FString matchGroup;
	FString matchShortCode;

	int32 skill;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


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
	
	~UGSGameCenterConnectRequest();

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


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetChallengeRequest_Response, FGSGetChallengeResponse, GetChallengeResponse, bool, hasErrors);

UCLASS()
class UGSGetChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetChallengeRequest_Response OnResponse;
	
	/**
	Gets the details of a challenge. The current player must be involved in the challenge for the request to succeed.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSGetChallengeRequest* SendGetChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetChallengeRequest();

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetDownloadableRequest_Response, FGSGetDownloadableResponse, GetDownloadableResponse, bool, hasErrors);

UCLASS()
class UGSGetDownloadableRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetDownloadableRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive url to allow the game to download a piece of downloadable content stored in the GameSparks platform.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetDownloadableRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetDownloadableRequest* SendGetDownloadableRequest(FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetDownloadableRequest();

private:

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetLeaderboardEntriesRequest_Response, FGSGetLeaderboardEntriesResponse, GetLeaderboardEntriesResponse, bool, hasErrors);

UCLASS()
class UGSGetLeaderboardEntriesRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetLeaderboardEntriesRequest_Response OnResponse;
	
	/**
	Get the leaderboard entry data for the current player or a given player. 
	For each leaderboard it returns the hichest score the player has
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetLeaderboardEntriesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSGetLeaderboardEntriesRequest* SendGetLeaderboardEntriesRequest(UGameSparksRequestArray* Challenges = nullptr, bool InverseSocial = false, UGameSparksRequestArray* Leaderboards = nullptr, FString Player = "", bool Social = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetLeaderboardEntriesRequest();

private:
	UGameSparksRequestArray* challenges;
	bool inverseSocial;
	UGameSparksRequestArray* leaderboards;
	FString player;

	bool social;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetMessageRequest_Response, FGSGetMessageResponse, GetMessageResponse, bool, hasErrors);

UCLASS()
class UGSGetMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetMessageRequest_Response OnResponse;
	
	/**
	Returns the full details of a message.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSGetMessageRequest* SendGetMessageRequest(FString MessageId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetMessageRequest();

private:
	FString messageId;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetMyTeamsRequest_Response, FGSGetMyTeamsResponse, GetMyTeamsResponse, bool, hasErrors);

UCLASS()
class UGSGetMyTeamsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetMyTeamsRequest_Response OnResponse;
	
	/**
	Get the teams that the player is in. Can be filtered on team type and also on those teams that the player owns.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMyTeamsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSGetMyTeamsRequest* SendGetMyTeamsRequest(bool OwnedOnly = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetMyTeamsRequest();

private:
	bool ownedOnly;

	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetPropertyRequest_Response, FGSGetPropertyResponse, GetPropertyResponse, bool, hasErrors);

UCLASS()
class UGSGetPropertyRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetPropertyRequest_Response OnResponse;
	
	/**
	Get the property for the given short Code.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetPropertyRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetPropertyRequest* SendGetPropertyRequest(FString PropertyShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetPropertyRequest();

private:
	FString propertyShortCode;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetPropertySetRequest_Response, FGSGetPropertySetResponse, GetPropertySetResponse, bool, hasErrors);

UCLASS()
class UGSGetPropertySetRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetPropertySetRequest_Response OnResponse;
	
	/**
	Get the property set for the given short Code.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetPropertySetRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetPropertySetRequest* SendGetPropertySetRequest(FString PropertySetShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetPropertySetRequest();

private:
	FString propertySetShortCode;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetRunningTotalsRequest_Response, FGSGetRunningTotalsResponse, GetRunningTotalsResponse, bool, hasErrors);

UCLASS()
class UGSGetRunningTotalsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetRunningTotalsRequest_Response OnResponse;
	
	/**
	Get the aggregation data for a group of the player's friends given running total specified by short code.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetRunningTotalsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetRunningTotalsRequest* SendGetRunningTotalsRequest(UGameSparksRequestArray* FriendIds = nullptr, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetRunningTotalsRequest();

private:
	UGameSparksRequestArray* friendIds;

	FString shortCode;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetTeamRequest_Response, FGSGetTeamResponse, GetTeamResponse, bool, hasErrors);

UCLASS()
class UGSGetTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetTeamRequest_Response OnResponse;
	
	/**
	Allows the details of a team to be retrieved.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSGetTeamRequest* SendGetTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetTeamRequest();

private:
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetUploadUrlRequest_Response, FGSGetUploadUrlResponse, GetUploadUrlResponse, bool, hasErrors);

UCLASS()
class UGSGetUploadUrlRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetUploadUrlRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive URL to allow the game to upload a piece of player content to the GameSparks platform.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadUrlRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetUploadUrlRequest* SendGetUploadUrlRequest(UGameSparksScriptData* UploadData = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetUploadUrlRequest();

private:

	UGameSparksScriptData* uploadData;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetUploadedRequest_Response, FGSGetUploadedResponse, GetUploadedResponse, bool, hasErrors);

UCLASS()
class UGSGetUploadedRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetUploadedRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive URL to a piece of content that was previously uploaded to the GameSparks platform by a player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadedRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetUploadedRequest* SendGetUploadedRequest(FString UploadId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetUploadedRequest();

private:

	FString uploadId;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGooglePlayBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSGooglePlayBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGooglePlayBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes the response from a Google Play in app purchase flow.
	The GameSparks platform will validate the signature and signed data with the Google Play Public Key configured against the game.
	The orderId in the data will be recorded and the request will be rejected if the orderId has previously been processed, this prevents replay attacks.
	Once verfied, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the signed data with the 'Google Product ID' configured against the virtual good.
	It is critical that the signedData is sent exactly as it is returned form google, including any whitespace. Any modification of the signedData will cause the verification process to fail.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlayBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSGooglePlayBuyGoodsRequest* SendGooglePlayBuyGoodsRequest(FString Signature = "", FString SignedData = "", bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGooglePlayBuyGoodsRequest();

private:

	FString signature;
	FString signedData;
	bool uniqueTransactionByPlayer;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


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
	
	~UGSGooglePlusConnectRequest();

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


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIOSBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSIOSBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnIOSBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes a transaction receipt from an App Store in app purchase.
	The GameSparks platform will validate the receipt with Apple and process the response. The transaction_id in the response will be recorded and the request will be rejected if the transaction_id has previously been processed, this prevents replay attacks.
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the product_id in the response with the 'IOS Product ID' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS IOSBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSIOSBuyGoodsRequest* SendIOSBuyGoodsRequest(FString Receipt = "", bool Sandbox = false, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSIOSBuyGoodsRequest();

private:
	FString receipt;

	bool sandbox;
	bool uniqueTransactionByPlayer;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJoinChallengeRequest_Response, FGSJoinChallengeResponse, JoinChallengeResponse, bool, hasErrors);

UCLASS()
class UGSJoinChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnJoinChallengeRequest_Response OnResponse;
	
	/**
	Allows a player to join an open challenge.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSJoinChallengeRequest* SendJoinChallengeRequest(FString ChallengeInstanceId = "", UGameSparksScriptData* Eligibility = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSJoinChallengeRequest();

private:
	FString challengeInstanceId;
	UGameSparksScriptData* eligibility;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJoinTeamRequest_Response, FGSJoinTeamResponse, JoinTeamResponse, bool, hasErrors);

UCLASS()
class UGSJoinTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnJoinTeamRequest_Response OnResponse;
	
	/**
	Allows a player to join a team of a team to be retrieved.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSJoinTeamRequest* SendJoinTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSJoinTeamRequest();

private:
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnKongregateConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSKongregateConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnKongregateConnectRequest_Response OnResponse;
	
	/**
	Allows a Kongregate account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Kongregate platform and store them within GameSparks.
	If the Kongregate user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Kongregate user is not already registered with the game, the Kongregate user will be linked to the current player.
	If the current player has not authenticated and the Kongregate user is not known, a new player will be created using the Kongregate details and the session will be authenticated against the new player.
	If the Kongregate user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS KongregateConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSKongregateConnectRequest* SendKongregateConnectRequest(bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString GameAuthToken = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false, FString UserId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSKongregateConnectRequest();

private:
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;
	FString gameAuthToken;

	UGameSparksScriptData* segments;
	bool switchIfPossible;
	bool syncDisplayName;
	FString userId;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaderboardDataRequest_Response, FGSLeaderboardDataResponse, LeaderboardDataResponse, bool, hasErrors);

UCLASS()
class UGSLeaderboardDataRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaderboardDataRequest_Response OnResponse;
	
	/**
	Returns the top data for either the specified global leaderboard or the specified challenges leaderboard. The data is sorted as defined in the rules specified in the leaderboard configuration.
	The response contains the top of the leaderboard, and returns the number of entries as defined in the entryCount parameter.
	If a shortCode is supplied, the response will contain the global leaderboard data. If a challengeInstanceId is supplied, the response will contain the leaderboard data for the challenge.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSLeaderboardDataRequest* SendLeaderboardDataRequest(FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLeaderboardDataRequest();

private:
	FString challengeInstanceId;
	bool dontErrorOnNotSocial;
	int32 entryCount;
	UGameSparksRequestArray* friendIds;
	int32 includeFirst;
	int32 includeLast;
	bool inverseSocial;
	FString leaderboardShortCode;
	int32 offset;

	bool social;
	UGameSparksRequestArray* teamIds;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaderboardsEntriesRequest_Response, FGSLeaderboardsEntriesResponse, LeaderboardsEntriesResponse, bool, hasErrors);

UCLASS()
class UGSLeaderboardsEntriesRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaderboardsEntriesRequest_Response OnResponse;
	
	/**
	Get the leaderboard entry data for the current player or a given player.
	For each leaderboard it returns the array of leaderboard entries that the player has.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaderboardsEntriesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSLeaderboardsEntriesRequest* SendLeaderboardsEntriesRequest(UGameSparksRequestArray* Challenges = nullptr, bool InverseSocial = false, UGameSparksRequestArray* Leaderboards = nullptr, FString Player = "", bool Social = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLeaderboardsEntriesRequest();

private:
	UGameSparksRequestArray* challenges;
	bool inverseSocial;
	UGameSparksRequestArray* leaderboards;
	FString player;

	bool social;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaveTeamRequest_Response, FGSLeaveTeamResponse, LeaveTeamResponse, bool, hasErrors);

UCLASS()
class UGSLeaveTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaveTeamRequest_Response OnResponse;
	
	/**
	Allows a player to leave a team.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaveTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSLeaveTeamRequest* SendLeaveTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLeaveTeamRequest();

private:
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListAchievementsRequest_Response, FGSListAchievementsResponse, ListAchievementsResponse, bool, hasErrors);

UCLASS()
class UGSListAchievementsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListAchievementsRequest_Response OnResponse;
	
	/**
	Retrieves a list of the configured achievements in the game, along with whether the current player has earned the achievement.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListAchievementsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListAchievementsRequest* SendListAchievementsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListAchievementsRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListChallengeRequest_Response, FGSListChallengeResponse, ListChallengeResponse, bool, hasErrors);

UCLASS()
class UGSListChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListChallengeRequest_Response OnResponse;
	
	/**
	Returns a list of challenges in the state defined in the 'state' field.
	The response can be further filtered by passing a shortCode field which will limit the returned lists to challenges of that short code.
	Valid states are:
	WAITING : The challenge has been issued and accepted and is waiting for the start date.
	RUNNING : The challenge is active.
	ISSUED : The challenge has been issued by the current player and is waiting to be accepted.
	RECEIVED : The challenge has been issued to the current player and is waiting to be accepted.
	COMPLETE : The challenge has completed.
	DECLINED : The challenge has been issued by the current player and has been declined.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSListChallengeRequest* SendListChallengeRequest(int32 EntryCount = 0, int32 Offset = 0, FString ShortCode = "", FString State = "", UGameSparksRequestArray* States = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListChallengeRequest();

private:
	int32 entryCount;
	int32 offset;

	FString shortCode;
	FString state;
	UGameSparksRequestArray* states;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListChallengeTypeRequest_Response, FGSListChallengeTypeResponse, ListChallengeTypeResponse, bool, hasErrors);

UCLASS()
class UGSListChallengeTypeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListChallengeTypeRequest_Response OnResponse;
	
	/**
	Returns the list of configured challenge types.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListChallengeTypeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSListChallengeTypeRequest* SendListChallengeTypeRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListChallengeTypeRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListGameFriendsRequest_Response, FGSListGameFriendsResponse, ListGameFriendsResponse, bool, hasErrors);

UCLASS()
class UGSListGameFriendsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListGameFriendsRequest_Response OnResponse;
	
	/**
	Returns the list of the current players game friends.
	A Game friend is someone in their social network who also plays the game.
	Against each friend, and indicator is supplied to show whether the friend is currently connected to the GameSparks service
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListGameFriendsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListGameFriendsRequest* SendListGameFriendsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListGameFriendsRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListLeaderboardsRequest_Response, FGSListLeaderboardsResponse, ListLeaderboardsResponse, bool, hasErrors);

UCLASS()
class UGSListLeaderboardsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListLeaderboardsRequest_Response OnResponse;
	
	/**
	Returns a list of all leaderboards configured in the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListLeaderboardsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSListLeaderboardsRequest* SendListLeaderboardsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListLeaderboardsRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListMessageRequest_Response, FGSListMessageResponse, ListMessageResponse, bool, hasErrors);

UCLASS()
class UGSListMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListMessageRequest_Response OnResponse;
	
	/**
	Returns the list of the current players messages / notifications.
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest Read the section on Messages to the the complete list of messages and their meaning.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListMessageRequest* SendListMessageRequest(int32 EntryCount = 0, FString Include = "", int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListMessageRequest();

private:
	int32 entryCount;
	FString include;
	int32 offset;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListMessageSummaryRequest_Response, FGSListMessageSummaryResponse, ListMessageSummaryResponse, bool, hasErrors);

UCLASS()
class UGSListMessageSummaryRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListMessageSummaryRequest_Response OnResponse;
	
	/**
	Returns a summary of the list of the current players messages / notifications.
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest.
	The full message can be retrieved using GetMessageRequest Read the section on Messages to see the complete list of messages and their meanings.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageSummaryRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListMessageSummaryRequest* SendListMessageSummaryRequest(int32 EntryCount = 0, int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListMessageSummaryRequest();

private:
	int32 entryCount;
	int32 offset;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListTeamChatRequest_Response, FGSListTeamChatResponse, ListTeamChatResponse, bool, hasErrors);

UCLASS()
class UGSListTeamChatRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListTeamChatRequest_Response OnResponse;
	
	/**
	Get a list of the messages sent to the team (by players using SendTeamChatMessageRequest).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTeamChatRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSListTeamChatRequest* SendListTeamChatRequest(int32 EntryCount = 0, int32 Offset = 0, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListTeamChatRequest();

private:
	int32 entryCount;
	int32 offset;
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListVirtualGoodsRequest_Response, FGSListVirtualGoodsResponse, ListVirtualGoodsResponse, bool, hasErrors);

UCLASS()
class UGSListVirtualGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListVirtualGoodsRequest_Response OnResponse;
	
	/**
	Returns the list of configured virtual goods.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListVirtualGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSListVirtualGoodsRequest* SendListVirtualGoodsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListVirtualGoodsRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLogChallengeEventRequest_Response, FGSLogChallengeEventResponse, LogChallengeEventResponse, bool, hasErrors);

UCLASS()
class UGSLogChallengeEventRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLogChallengeEventRequest_Response OnResponse;
	
	/**
	Allows a user defined event to be triggered. The event will be posted to the challenge specified.
	This call differs from most as it does not have a fixed format. The @class, challengeInstanceId and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.
	The example below shows a request to en event with a short code of HS with 2 attributes, 'HS' & 'GL'.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogChallengeEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSLogChallengeEventRequest* SendLogChallengeEventRequest(FString ChallengeInstanceId = "", FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLogChallengeEventRequest();

private:
	FString challengeInstanceId;
	FString eventKey;

	
	UGameSparksLogEventData* logEventData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLogEventRequest_Response, FGSLogEventResponse, LogEventResponse, bool, hasErrors);

UCLASS()
class UGSLogEventRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLogEventRequest_Response OnResponse;
	
	/**
	Allows a user defined event to be triggered.
	This call differs from most as it does not have a fixed format. The @class and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.
	The example below shows a request to an event with a short code of HS with 2 attributes, 'HS' & 'GL'.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSLogEventRequest* SendLogEventRequest(FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLogEventRequest();

private:
	FString eventKey;

	
	UGameSparksLogEventData* logEventData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchDetailsRequest_Response, FGSMatchDetailsResponse, MatchDetailsResponse, bool, hasErrors);

UCLASS()
class UGSMatchDetailsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnMatchDetailsRequest_Response OnResponse;
	
	/**
	Find the details of an existing match this player belongs to, using the matchId
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS MatchDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSMatchDetailsRequest* SendMatchDetailsRequest(FString MatchId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSMatchDetailsRequest();

private:
	FString matchId;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchmakingRequest_Response, FGSMatchmakingResponse, MatchmakingResponse, bool, hasErrors);

UCLASS()
class UGSMatchmakingRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnMatchmakingRequest_Response OnResponse;
	
	/**
	Register this player for matchmaking, using the given skill and matchShortCode.
	Players looking for a match using the same matchShortCode will be considered for a match, based on the matchConfig.
	Each player must match the other for the match to be found.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS MatchmakingRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSMatchmakingRequest* SendMatchmakingRequest(FString Action = "", FString MatchGroup = "", FString MatchShortCode = "", int32 Skill = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSMatchmakingRequest();

private:
	FString action;
	FString matchGroup;
	FString matchShortCode;

	int32 skill;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPSNConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSPSNConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnPSNConnectRequest_Response OnResponse;
	
	/**
	Allows a PSN account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the PSN platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the PSN user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the PSN user is not already registered with the game, the PSN user will be linked to the current player.
	If the current player has not authenticated and the PSN user is not known, a new player will be created using the PSN details and the session will be authenticated against the new player.
	If the PSN user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PSNConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSPSNConnectRequest* SendPSNConnectRequest(FString AuthorizationCode = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSPSNConnectRequest();

private:
	FString authorizationCode;
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
	
	~UGSPushRegistrationRequest();

private:
	FString deviceOS;
	FString pushId;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQQConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSQQConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnQQConnectRequest_Response OnResponse;
	
	/**
	Allows a QQ access token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the QQ platform and store them within GameSparks.
	If the QQ user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the QQ user is not already registered with the game, the QQ user will be linked to the current player.
	If the current player has not authenticated and the QQ user is not known, a new player will be created using the QQ details and the session will be authenticated against the new player.
	If the QQ user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS QQConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSQQConnectRequest* SendQQConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSQQConnectRequest();

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
	
	~UGSRegistrationRequest();

private:
	FString displayName;
	FString password;

	UGameSparksScriptData* segments;
	FString userName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSendFriendMessageRequest_Response, FGSSendFriendMessageResponse, SendFriendMessageResponse, bool, hasErrors);

UCLASS()
class UGSSendFriendMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSendFriendMessageRequest_Response OnResponse;
	
	/**
	Sends a message to one or more game friend(s). A game friend is someone in the players social network who also plays the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendFriendMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSSendFriendMessageRequest* SendSendFriendMessageRequest(UGameSparksRequestArray* FriendIds = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSendFriendMessageRequest();

private:
	UGameSparksRequestArray* friendIds;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSendTeamChatMessageRequest_Response, FGSSendTeamChatMessageResponse, SendTeamChatMessageResponse, bool, hasErrors);

UCLASS()
class UGSSendTeamChatMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSendTeamChatMessageRequest_Response OnResponse;
	
	/**
	Send a message to all the players who are member of the given team
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendTeamChatMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSSendTeamChatMessageRequest* SendSendTeamChatMessageRequest(FString Message = "", FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSendTeamChatMessageRequest();

private:
	FString message;
	FString ownerId;

	FString teamId;
	FString teamType;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSocialDisconnectRequest_Response, FGSSocialDisconnectResponse, SocialDisconnectResponse, bool, hasErrors);

UCLASS()
class UGSSocialDisconnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSocialDisconnectRequest_Response OnResponse;
	
	/**
	Allows a player's internal profile to be disconnected from an external system to which it is linked.  Any friends linked as result of this connection will be removed.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialDisconnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSSocialDisconnectRequest* SendSocialDisconnectRequest(FString SystemId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSocialDisconnectRequest();

private:

	FString systemId;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSocialLeaderboardDataRequest_Response, FGSLeaderboardDataResponse, LeaderboardDataResponse, bool, hasErrors);

UCLASS()
class UGSSocialLeaderboardDataRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSocialLeaderboardDataRequest_Response OnResponse;
	
	/**
	Returns leaderboard data that only contains entries of players that are game friends with the current player.
	The GameSparks platform will attempt to return players both ahead and behind the current player, where data is available.
	The entry count defines how many player should be returned both ahead and behind. The numer of results may vary if there are not enough friends either ahead or behind.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialLeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSSocialLeaderboardDataRequest* SendSocialLeaderboardDataRequest(FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSocialLeaderboardDataRequest();

private:
	FString challengeInstanceId;
	bool dontErrorOnNotSocial;
	int32 entryCount;
	UGameSparksRequestArray* friendIds;
	int32 includeFirst;
	int32 includeLast;
	bool inverseSocial;
	FString leaderboardShortCode;
	int32 offset;

	bool social;
	UGameSparksRequestArray* teamIds;
	UGameSparksRequestArray* teamTypes;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


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
	
	~UGSSocialStatusRequest();

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSteamConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSSteamConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSteamConnectRequest_Response OnResponse;
	
	/**
	Allows a Steam sessionTicket to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Steam platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Steam user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Steam user is not already registered with the game, the Steam user will be linked to the current player.
	If the current player has not authenticated and the Steam user is not known, a new player will be created using the Steam details and the session will be authenticated against the new player.
	If the Steam user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SteamConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSSteamConnectRequest* SendSteamConnectRequest(bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, FString SessionTicket = "", bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSteamConnectRequest();

private:
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;

	UGameSparksScriptData* segments;
	FString sessionTicket;
	bool switchIfPossible;
	bool syncDisplayName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTwitchConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSTwitchConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnTwitchConnectRequest_Response OnResponse;
	
	/**
	Allows a Twitch account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Twitch platform and store them within GameSparks.
	If the Twitch user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Twitch user is not already registered with the game, the Twitch user will be linked to the current player.
	If the current player has not authenticated and the Twitch user is not known, a new player will be created using the Twitch details and the session will be authenticated against the new player.
	If the Twitch user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS TwitchConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSTwitchConnectRequest* SendTwitchConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSTwitchConnectRequest();

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


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTwitterConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSTwitterConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnTwitterConnectRequest_Response OnResponse;
	
	/**
	Allows a Twitter account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Twitter platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Twitter user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Twitter user is not already registered with the game, the Twitter user will be linked to the current player.
	If the current player has not authenticated and the Twitter user is not known, a new player will be created using the Twitter details and the session will be authenticated against the new player.
	If the Twitter user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS TwitterConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSTwitterConnectRequest* SendTwitterConnectRequest(FString AccessSecret = "", FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSTwitterConnectRequest();

private:
	FString accessSecret;
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


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWindowsBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class UGSWindowsBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWindowsBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes a transaction receipt from a windows store purchase.
	The GameSparks platform will validate the receipt using the signature embedded in the xml. The Id in the xml will be recorded and the request will be rejected if the Id has previously been processed, this prevents replay attacks.
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the xml with the 'WP8 Product ID' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WindowsBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSWindowsBuyGoodsRequest* SendWindowsBuyGoodsRequest(FString Platform = "", FString Receipt = "", bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSWindowsBuyGoodsRequest();

private:
	FString platform;
	FString receipt;

	bool uniqueTransactionByPlayer;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWithdrawChallengeRequest_Response, FGSWithdrawChallengeResponse, WithdrawChallengeResponse, bool, hasErrors);

UCLASS()
class UGSWithdrawChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWithdrawChallengeRequest_Response OnResponse;
	
	/**
	Withdraws a challenge previously issued by the current player.
	This can only be done while the challenge is in the ISSUED state. Once it's been accepted the challenge can not be withdrawn.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WithdrawChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Challenges")
	static UGSWithdrawChallengeRequest* SendWithdrawChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSWithdrawChallengeRequest();

private:
	FString challengeInstanceId;
	FString message;

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnXBOXLiveConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class UGSXBOXLiveConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnXBOXLiveConnectRequest_Response OnResponse;
	
	/**
	Allows an Xbox Live Shared Token String to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Xbox Live and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Xbox user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Xbox user is not already registered with the game, the Xbox user will be linked to the current player.
	If the current player has not authenticated and the Xbox user is not known, a new player will be created using the Xbox details and the session will be authenticated against the new player.
	If the Xbox user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS XBOXLiveConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSXBOXLiveConnectRequest* SendXBOXLiveConnectRequest(bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, FString StsTokenString = "", bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSXBOXLiveConnectRequest();

private:
	bool doNotLinkToCurrentPlayer;
	bool errorOnSwitch;

	UGameSparksScriptData* segments;
	FString stsTokenString;
	bool switchIfPossible;
	bool syncDisplayName;
	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};


