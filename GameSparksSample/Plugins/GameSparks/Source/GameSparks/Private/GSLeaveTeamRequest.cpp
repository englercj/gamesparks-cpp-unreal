#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSLeaveTeamRequest.h"

void LeaveTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LeaveTeamResponse& response){
    
    FGSLeaveTeamResponse unreal_response = FGSLeaveTeamResponse(response.GetBaseData());
    
    UGSLeaveTeamRequest* g_UGSLeaveTeamRequest = static_cast<UGSLeaveTeamRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSLeaveTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLeaveTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLeaveTeamRequest* UGSLeaveTeamRequest::SendLeaveTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSLeaveTeamRequest* proxy = NewObject<UGSLeaveTeamRequest>();
	proxy->ownerId = OwnerId;
	proxy->teamId = TeamId;
	proxy->teamType = TeamType;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSLeaveTeamRequest::Activate()
{
	GameSparks::Api::Requests::LeaveTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(LeaveTeamRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(LeaveTeamRequestResponseCallback);
    }
	
	
	
}

UGSLeaveTeamRequest::UGSLeaveTeamRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

