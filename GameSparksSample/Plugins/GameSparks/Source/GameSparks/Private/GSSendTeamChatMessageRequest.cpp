#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSSendTeamChatMessageRequest.h"

void SendTeamChatMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SendTeamChatMessageResponse& response){
    
    FGSSendTeamChatMessageResponse unreal_response = FGSSendTeamChatMessageResponse(response.GetBaseData());
    
    UGSSendTeamChatMessageRequest* g_UGSSendTeamChatMessageRequest = static_cast<UGSSendTeamChatMessageRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSSendTeamChatMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSendTeamChatMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSendTeamChatMessageRequest* UGSSendTeamChatMessageRequest::SendSendTeamChatMessageRequest(FString Message, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSSendTeamChatMessageRequest* proxy = NewObject<UGSSendTeamChatMessageRequest>();
	proxy->message = Message;
	proxy->ownerId = OwnerId;
	proxy->teamId = TeamId;
	proxy->teamType = TeamType;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSSendTeamChatMessageRequest::Activate()
{
	GameSparks::Api::Requests::SendTeamChatMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(message != ""){
		gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
	}
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
    	gsRequest.Send(SendTeamChatMessageRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(SendTeamChatMessageRequestResponseCallback);
    }
	
	
	
}

UGSSendTeamChatMessageRequest::UGSSendTeamChatMessageRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

