#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSJoinTeamRequest.h"

void JoinTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::JoinTeamResponse& response){
    
    FGSJoinTeamResponse unreal_response = FGSJoinTeamResponse(response.GetBaseData());
    
    UGSJoinTeamRequest* g_UGSJoinTeamRequest = static_cast<UGSJoinTeamRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSJoinTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSJoinTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSJoinTeamRequest* UGSJoinTeamRequest::SendJoinTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSJoinTeamRequest* proxy = NewObject<UGSJoinTeamRequest>();
	proxy->ownerId = OwnerId;
	proxy->teamId = TeamId;
	proxy->teamType = TeamType;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSJoinTeamRequest::Activate()
{
	GameSparks::Api::Requests::JoinTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(JoinTeamRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(JoinTeamRequestResponseCallback);
    }
	
	
	
}

UGSJoinTeamRequest::UGSJoinTeamRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

