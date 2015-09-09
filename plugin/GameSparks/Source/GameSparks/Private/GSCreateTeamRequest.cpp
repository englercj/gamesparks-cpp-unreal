#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSCreateTeamRequest.h"

void CreateTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::CreateTeamResponse& response){
    
    FGSCreateTeamResponse unreal_response = FGSCreateTeamResponse(response.GetBaseData());
    
    UGSCreateTeamRequest* g_UGSCreateTeamRequest = static_cast<UGSCreateTeamRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSCreateTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSCreateTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSCreateTeamRequest* UGSCreateTeamRequest::SendCreateTeamRequest(FString TeamId, FString TeamName, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSCreateTeamRequest* proxy = NewObject<UGSCreateTeamRequest>();
	proxy->teamId = TeamId;
	proxy->teamName = TeamName;
	proxy->teamType = TeamType;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSCreateTeamRequest::Activate()
{
	GameSparks::Api::Requests::CreateTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(teamId != ""){
		gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
	}
	if(teamName != ""){
		gsRequest.SetTeamName(TCHAR_TO_UTF8(*teamName));
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
    	gsRequest.Send(CreateTeamRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(CreateTeamRequestResponseCallback);
    }
	
	
	
}

UGSCreateTeamRequest::UGSCreateTeamRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

