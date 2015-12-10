#pragma once

#include "GameSparksRequestArray.generated.h"

UCLASS(BlueprintType)
class UGameSparksRequestArray : public UObject
{
	GENERATED_UCLASS_BODY()

public:

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create GameSparksRequestArray", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameSparks|Data")
	static UGameSparksRequestArray* CreateGameSparksRequestArray(UObject* WorldContextObject){
		return NewObject<UGameSparksRequestArray>();
	}


    UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Request Params")
    TArray<FString> StringArray;
};