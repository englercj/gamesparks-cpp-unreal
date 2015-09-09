#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSSendFriendMessageRequest.h"

void SendFriendMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SendFriendMessageResponse& response){
    
    FGSSendFriendMessageResponse unreal_response = FGSSendFriendMessageResponse(response.GetBaseData());
    
    UGSSendFriendMessageRequest* g_UGSSendFriendMessageRequest = static_cast<UGSSendFriendMessageRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSSendFriendMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSendFriendMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSendFriendMessageRequest* UGSSendFriendMessageRequest::SendSendFriendMessageRequest(UGameSparksRequestArray* FriendIds, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSSendFriendMessageRequest* proxy = NewObject<UGSSendFriendMessageRequest>();
	proxy->friendIds = FriendIds;
	proxy->message = Message;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSSendFriendMessageRequest::Activate()
{
	GameSparks::Api::Requests::SendFriendMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(friendIds != nullptr){
		gsstl::vector<gsstl::string> arrFriendIds;
	
	    for(int32 b_arrFriendIds = 0; b_arrFriendIds < friendIds->StringArray.Num(); b_arrFriendIds++)
	    {
	        arrFriendIds.push_back(TCHAR_TO_UTF8(*friendIds->StringArray[b_arrFriendIds]));
	    }
	    
		gsRequest.SetFriendIds(arrFriendIds);
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
    	gsRequest.Send(SendFriendMessageRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(SendFriendMessageRequestResponseCallback);
    }
	
	
	
}

UGSSendFriendMessageRequest::UGSSendFriendMessageRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

