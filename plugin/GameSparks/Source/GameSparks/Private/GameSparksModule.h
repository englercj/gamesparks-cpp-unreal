#pragma once

#include "GameSparks/gsstl.h"
#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#endif
#include "GameSparks/GS.h"
#if PLATFORM_WINDOWS
#include "HideWindowsPlatformTypes.h"
#endif
#include "GSMessageListeners.h"
#include "IGameSparks.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "GameSparksComponent.h"


DECLARE_LOG_CATEGORY_EXTERN(UGameSparksModuleLog, Log, All);

class UGameSparksModule : public IGameSparks, public FTickableGameObject
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule();
	virtual void ShutdownModule();

	/** FTickableGameObject implementation */
    virtual bool IsTickableWhenPaused() const;
    virtual bool IsTickableInEditor() const;
    virtual void Tick(float DeltaTime);
	virtual bool IsTickable() const;
	virtual TStatId GetStatId() const;

	/* Initialization and destruction of gamesparks */
	void Initialize(FString apikey, FString secret, bool previewServer, bool clearCachedAuthentication);
	void Shutdown();
    void Logout();

	static UGameSparksModule* GetModulePtr();

	void SendGameSparksAvailableToComponents(bool available);
	void SendDebugLogToComponents(const gsstl::string& message);

    GameSparks::Core::GS& GetGSInstance() { return GS; }
    const GameSparks::Core::GS& GetGSInstance() const { return GS; }
    
    void RegisterListeners();
    
	/// returns true, iff the GameSparks instance is ready to be used
	bool IsInitialized() const;

private:

    
    GameSparks::Core::GS GS;
    
    bool isInitialised = false;
    

};
