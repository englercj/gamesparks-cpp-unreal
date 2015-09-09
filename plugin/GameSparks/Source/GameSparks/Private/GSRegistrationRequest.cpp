#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSRegistrationRequest.h"

void RegistrationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::RegistrationResponse& response){
    
    FGSRegistrationResponse unreal_response = FGSRegistrationResponse(response.GetBaseData());
    
    UGSRegistrationRequest* g_UGSRegistrationRequest = static_cast<UGSRegistrationRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSRegistrationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSRegistrationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSRegistrationRequest* UGSRegistrationRequest::SendRegistrationRequest(FString DisplayName, FString Password, UGameSparksScriptData* Segments, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSRegistrationRequest* proxy = NewObject<UGSRegistrationRequest>();
	proxy->displayName = DisplayName;
	proxy->password = Password;
	proxy->segments = Segments;
	proxy->userName = UserName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSRegistrationRequest::Activate()
{
	GameSparks::Api::Requests::RegistrationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(displayName != ""){
		gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
	}
	if(password != ""){
		gsRequest.SetPassword(TCHAR_TO_UTF8(*password));
	}
	if(segments != nullptr){
		gsRequest.SetSegments(segments->ToRequestData());
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
    	gsRequest.Send(RegistrationRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(RegistrationRequestResponseCallback);
    }
	
	
	
}

UGSRegistrationRequest::UGSRegistrationRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

