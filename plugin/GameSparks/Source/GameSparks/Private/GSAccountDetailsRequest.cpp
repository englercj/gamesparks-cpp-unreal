#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSAccountDetailsRequest.h"

void AccountDetailsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AccountDetailsResponse& response){
    
    FGSAccountDetailsResponse unreal_response = FGSAccountDetailsResponse(response.GetBaseData());
    
    UGSAccountDetailsRequest* g_UGSAccountDetailsRequest = static_cast<UGSAccountDetailsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSAccountDetailsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAccountDetailsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAccountDetailsRequest* UGSAccountDetailsRequest::SendAccountDetailsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSAccountDetailsRequest* proxy = NewObject<UGSAccountDetailsRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSAccountDetailsRequest::Activate()
{
	GameSparks::Api::Requests::AccountDetailsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(AccountDetailsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(AccountDetailsRequestResponseCallback);
    }
	
	
	
}

UGSAccountDetailsRequest::UGSAccountDetailsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

