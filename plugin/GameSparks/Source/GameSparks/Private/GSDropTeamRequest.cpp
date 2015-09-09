#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSDropTeamRequest.h"

void DropTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::DropTeamResponse& response){
    
    FGSDropTeamResponse unreal_response = FGSDropTeamResponse(response.GetBaseData());
    
    UGSDropTeamRequest* g_UGSDropTeamRequest = static_cast<UGSDropTeamRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSDropTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDropTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDropTeamRequest* UGSDropTeamRequest::SendDropTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSDropTeamRequest* proxy = NewObject<UGSDropTeamRequest>();
	proxy->ownerId = OwnerId;
	proxy->teamId = TeamId;
	proxy->teamType = TeamType;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSDropTeamRequest::Activate()
{
	GameSparks::Api::Requests::DropTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(DropTeamRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(DropTeamRequestResponseCallback);
    }
	
	
	
}

UGSDropTeamRequest::UGSDropTeamRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

