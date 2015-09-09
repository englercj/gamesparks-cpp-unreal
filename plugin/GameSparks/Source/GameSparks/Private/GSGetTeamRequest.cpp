#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetTeamRequest.h"

void GetTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetTeamResponse& response){
    
    FGSGetTeamResponse unreal_response = FGSGetTeamResponse(response.GetBaseData());
    
    UGSGetTeamRequest* g_UGSGetTeamRequest = static_cast<UGSGetTeamRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetTeamRequest* UGSGetTeamRequest::SendGetTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetTeamRequest* proxy = NewObject<UGSGetTeamRequest>();
	proxy->ownerId = OwnerId;
	proxy->teamId = TeamId;
	proxy->teamType = TeamType;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetTeamRequest::Activate()
{
	GameSparks::Api::Requests::GetTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(ownerId != ""){
		gsRequest.SetOwnerId(TCHAR_TO_UTF8(*ownerId));
	}
	if(teamId != ""){
		gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
	}
	if(teamType != ""){
		gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetTeamRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetTeamRequestResponseCallback);
    }
	
	
	
}

UGSGetTeamRequest::UGSGetTeamRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

