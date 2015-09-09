#pragma once
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSListVirtualGoodsRequest.generated.h"

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

private:

	
	UGameSparksScriptData* scriptData;
	
	bool durable;
	int32 requestTimeoutSeconds; 
	
};

