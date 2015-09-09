#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSChatOnChallengeRequest.h"

void ChatOnChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ChatOnChallengeResponse& response){
    
    FGSChatOnChallengeResponse unreal_response = FGSChatOnChallengeResponse(response.GetBaseData());
    
    UGSChatOnChallengeRequest* g_UGSChatOnChallengeRequest = static_cast<UGSChatOnChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSChatOnChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSChatOnChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSChatOnChallengeRequest* UGSChatOnChallengeRequest::SendChatOnChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSChatOnChallengeRequest* proxy = NewObject<UGSChatOnChallengeRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->message = Message;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSChatOnChallengeRequest::Activate()
{
	GameSparks::Api::Requests::ChatOnChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(challengeInstanceId != ""){
		gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
	}
	if(message != ""){
		gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ChatOnChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ChatOnChallengeRequestResponseCallback);
    }
	
	
	
}

UGSChatOnChallengeRequest::UGSChatOnChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

