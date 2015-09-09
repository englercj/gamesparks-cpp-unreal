#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSAuthenticationRequest.h"

void AuthenticationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSAuthenticationRequest* g_UGSAuthenticationRequest = static_cast<UGSAuthenticationRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSAuthenticationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAuthenticationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAuthenticationRequest* UGSAuthenticationRequest::SendAuthenticationRequest(FString Password, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSAuthenticationRequest* proxy = NewObject<UGSAuthenticationRequest>();
	proxy->password = Password;
	proxy->userName = UserName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSAuthenticationRequest::Activate()
{
	GameSparks::Api::Requests::AuthenticationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(password != ""){
		gsRequest.SetPassword(TCHAR_TO_UTF8(*password));
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
    	gsRequest.Send(AuthenticationRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(AuthenticationRequestResponseCallback);
    }
	
	
	
}

UGSAuthenticationRequest::UGSAuthenticationRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

