#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListLeaderboardsRequest.h"

void ListLeaderboardsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListLeaderboardsResponse& response){
    
    FGSListLeaderboardsResponse unreal_response = FGSListLeaderboardsResponse(response.GetBaseData());
    
    UGSListLeaderboardsRequest* g_UGSListLeaderboardsRequest = static_cast<UGSListLeaderboardsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListLeaderboardsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListLeaderboardsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListLeaderboardsRequest* UGSListLeaderboardsRequest::SendListLeaderboardsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListLeaderboardsRequest* proxy = NewObject<UGSListLeaderboardsRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListLeaderboardsRequest::Activate()
{
	GameSparks::Api::Requests::ListLeaderboardsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListLeaderboardsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListLeaderboardsRequestResponseCallback);
    }
	
	
	
}

UGSListLeaderboardsRequest::UGSListLeaderboardsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

