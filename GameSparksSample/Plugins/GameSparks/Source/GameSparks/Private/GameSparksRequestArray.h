#pragma once

#include "GameSparksRequestArray.generated.h"

UCLASS(BlueprintType)
class UGameSparksRequestArray : public UObject
{
	GENERATED_UCLASS_BODY()

public:

    UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Request Params")
    TArray<FString> StringArray;
};