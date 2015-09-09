#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSMatchDetailsRequest.h"

void MatchDetailsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::MatchDetailsResponse& response){
    
    FGSMatchDetailsResponse unreal_response = FGSMatchDetailsResponse(response.GetBaseData());
    
    UGSMatchDetailsRequest* g_UGSMatchDetailsRequest = static_cast<UGSMatchDetailsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSMatchDetailsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSMatchDetailsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSMatchDetailsRequest* UGSMatchDetailsRequest::SendMatchDetailsRequest(FString MatchId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSMatchDetailsRequest* proxy = NewObject<UGSMatchDetailsRequest>();
	proxy->matchId = MatchId;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSMatchDetailsRequest::Activate()
{
	GameSparks::Api::Requests::MatchDetailsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(matchId != ""){
		gsRequest.SetMatchId(TCHAR_TO_UTF8(*matchId));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(MatchDetailsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(MatchDetailsRequestResponseCallback);
    }
	
	
	
}

UGSMatchDetailsRequest::UGSMatchDetailsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

