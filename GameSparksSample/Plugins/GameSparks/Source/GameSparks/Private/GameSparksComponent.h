#pragma once

#include "GSTypes.h"
#include "Components/SceneComponent.h"
#include "GameSparksComponent.generated.h"

UCLASS(ClassGroup=(GameSparks), meta = (BlueprintSpawnableComponent))
class GAMESPARKS_API UGameSparksComponent : public USceneComponent
{
	GENERATED_BODY()

public:

    UGameSparksComponent();
    
    // Connects to the GameSparks service with the supplied details
    // * apiKey - The API Key of the game to connect to
    // * secret - The API Secret of the game to connect to
    // * apiKey - Whether to connect to the live, or preview servers
    // * clearCachedAuthentication - Forgets any cached authentication details before connecting
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Connect(FString apikey, FString secret, bool previewServer, bool clearCachedAuthentication);

    // Disconnects the socket, clears cached authentication details, and reconnects
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Logout();
    
    // Disconnects the from GameSparks
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Disconnect();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksAvailable, bool, available);

	// Called by GameSparks when the availability changed
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksAvailable OnGameSparksAvailableDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksLogEvent, FString, logMessage);

	// Called by GameSparks when a new log message was generated, useful for debugging
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksLogEvent OnGameSparksDebugLog;

    // Indicates if the current socket is connected and has an associated player
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    bool IsAuthenticated();

    // Indicates if the current socket is connected
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    bool IsAvailable();

};