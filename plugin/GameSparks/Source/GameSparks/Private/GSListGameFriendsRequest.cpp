#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListGameFriendsRequest.h"

void ListGameFriendsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListGameFriendsResponse& response){
    
    FGSListGameFriendsResponse unreal_response = FGSListGameFriendsResponse(response.GetBaseData());
    
    UGSListGameFriendsRequest* g_UGSListGameFriendsRequest = static_cast<UGSListGameFriendsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListGameFriendsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListGameFriendsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListGameFriendsRequest* UGSListGameFriendsRequest::SendListGameFriendsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListGameFriendsRequest* proxy = NewObject<UGSListGameFriendsRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListGameFriendsRequest::Activate()
{
	GameSparks::Api::Requests::ListGameFriendsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListGameFriendsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListGameFriendsRequestResponseCallback);
    }
	
	
	
}

UGSListGameFriendsRequest::UGSListGameFriendsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

