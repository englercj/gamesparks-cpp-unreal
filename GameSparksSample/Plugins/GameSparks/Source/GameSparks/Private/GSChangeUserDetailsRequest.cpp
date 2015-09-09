#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSChangeUserDetailsRequest.h"

void ChangeUserDetailsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ChangeUserDetailsResponse& response){
    
    FGSChangeUserDetailsResponse unreal_response = FGSChangeUserDetailsResponse(response.GetBaseData());
    
    UGSChangeUserDetailsRequest* g_UGSChangeUserDetailsRequest = static_cast<UGSChangeUserDetailsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSChangeUserDetailsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSChangeUserDetailsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSChangeUserDetailsRequest* UGSChangeUserDetailsRequest::SendChangeUserDetailsRequest(FString DisplayName, FString Language, FString NewPassword, FString OldPassword, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSChangeUserDetailsRequest* proxy = NewObject<UGSChangeUserDetailsRequest>();
	proxy->displayName = DisplayName;
	proxy->language = Language;
	proxy->newPassword = NewPassword;
	proxy->oldPassword = OldPassword;
	proxy->userName = UserName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSChangeUserDetailsRequest::Activate()
{
	GameSparks::Api::Requests::ChangeUserDetailsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(displayName != ""){
		gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
	}
	if(language != ""){
		gsRequest.SetLanguage(TCHAR_TO_UTF8(*language));
	}
	if(newPassword != ""){
		gsRequest.SetNewPassword(TCHAR_TO_UTF8(*newPassword));
	}
	if(oldPassword != ""){
		gsRequest.SetOldPassword(TCHAR_TO_UTF8(*oldPassword));
	}
	if(userName != ""){
		gsRequest.SetUserName(TCHAR_TO_UTF8(*userName));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ChangeUserDetailsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ChangeUserDetailsRequestResponseCallback);
    }
	
	
	
}

UGSChangeUserDetailsRequest::UGSChangeUserDetailsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

