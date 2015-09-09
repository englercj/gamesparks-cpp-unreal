#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListTeamChatRequest.h"

void ListTeamChatRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListTeamChatResponse& response){
    
    FGSListTeamChatResponse unreal_response = FGSListTeamChatResponse(response.GetBaseData());
    
    UGSListTeamChatRequest* g_UGSListTeamChatRequest = static_cast<UGSListTeamChatRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListTeamChatRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListTeamChatRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListTeamChatRequest* UGSListTeamChatRequest::SendListTeamChatRequest(int32 EntryCount, int32 Offset, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListTeamChatRequest* proxy = NewObject<UGSListTeamChatRequest>();
	proxy->entryCount = EntryCount;
	proxy->offset = Offset;
	proxy->ownerId = OwnerId;
	proxy->teamId = TeamId;
	proxy->teamType = TeamType;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListTeamChatRequest::Activate()
{
	GameSparks::Api::Requests::ListTeamChatRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(entryCount != 0){
		gsRequest.SetEntryCount(entryCount);
	}
	if(offset != 0){
		gsRequest.SetOffset(offset);
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
    	gsRequest.Send(ListTeamChatRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListTeamChatRequestResponseCallback);
    }
	
	
	
}

UGSListTeamChatRequest::UGSListTeamChatRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

