#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListAchievementsRequest.h"

void ListAchievementsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListAchievementsResponse& response){
    
    FGSListAchievementsResponse unreal_response = FGSListAchievementsResponse(response.GetBaseData());
    
    UGSListAchievementsRequest* g_UGSListAchievementsRequest = static_cast<UGSListAchievementsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListAchievementsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListAchievementsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListAchievementsRequest* UGSListAchievementsRequest::SendListAchievementsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListAchievementsRequest* proxy = NewObject<UGSListAchievementsRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListAchievementsRequest::Activate()
{
	GameSparks::Api::Requests::ListAchievementsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListAchievementsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListAchievementsRequestResponseCallback);
    }
	
	
	
}

UGSListAchievementsRequest::UGSListAchievementsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

