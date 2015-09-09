#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSPushRegistrationRequest.h"

void PushRegistrationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::PushRegistrationResponse& response){
    
    FGSPushRegistrationResponse unreal_response = FGSPushRegistrationResponse(response.GetBaseData());
    
    UGSPushRegistrationRequest* g_UGSPushRegistrationRequest = static_cast<UGSPushRegistrationRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSPushRegistrationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSPushRegistrationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSPushRegistrationRequest* UGSPushRegistrationRequest::SendPushRegistrationRequest(FString DeviceOS, FString PushId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSPushRegistrationRequest* proxy = NewObject<UGSPushRegistrationRequest>();
	proxy->deviceOS = DeviceOS;
	proxy->pushId = PushId;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSPushRegistrationRequest::Activate()
{
	GameSparks::Api::Requests::PushRegistrationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(deviceOS != ""){
		gsRequest.SetDeviceOS(TCHAR_TO_UTF8(*deviceOS));
	}
	if(pushId != ""){
		gsRequest.SetPushId(TCHAR_TO_UTF8(*pushId));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(PushRegistrationRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(PushRegistrationRequestResponseCallback);
    }
	
	
	
}

UGSPushRegistrationRequest::UGSPushRegistrationRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

