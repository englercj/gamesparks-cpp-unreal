#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

#include "GameSparks/GSDateTime.h"
#include "GameSparks/GSData.h"
#include "GameSparks/GSRequestData.h"
#include "GameSparksScriptData.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UGameSparksScriptData : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	void SetGSData(const GameSparks::Core::GSData& data);
    
    /* Create a new GS Data object. */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Create GS Data", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameSparks|Data")
    static UGameSparksScriptData* CreateGameSparksScriptData(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    FString JSONString();
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasString(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    FString GetString(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetString(const FString& name, const FString& value);

    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasStringArray(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    TArray<FString> GetStringArray(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetStringArray(const FString& name, const TArray<FString> value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasFloat(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    float GetFloat(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetFloat(const FString& name, const float value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasFloatArray(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    TArray<float> GetFloatArray(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetFloatArray(const FString& name, const TArray<float> value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasNumber(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    int32 GetNumber(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetNumber(const FString& name, const int32 value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasNumberArray(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    TArray<int32> GetNumberArray(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetNumberArray(const FString& name, const TArray<int32> value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasBoolean(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool GetBoolean(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetBoolean(const FString& name, const bool value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    bool HasGSData(const FString& name);

    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* GetGSData(const FString& name);

    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetGSData(const FString& name,  UGameSparksScriptData* value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    TArray<UGameSparksScriptData*> GetGSDataArray(const FString& name);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksScriptData* SetGSDataArray(const FString& name,  TArray<UGameSparksScriptData*> value);
    
    GameSparks::Core::GSRequestData ToRequestData();
    
    void Keys(){

    }

protected:
	GameSparks::Core::GSRequestData* m_Data;

};
