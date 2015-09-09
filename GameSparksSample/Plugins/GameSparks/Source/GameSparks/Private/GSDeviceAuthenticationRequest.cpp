#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSDeviceAuthenticationRequest.h"

void DeviceAuthenticationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSDeviceAuthenticationRequest* g_UGSDeviceAuthenticationRequest = static_cast<UGSDeviceAuthenticationRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSDeviceAuthenticationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDeviceAuthenticationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDeviceAuthenticationRequest* UGSDeviceAuthenticationRequest::SendDeviceAuthenticationRequest(FString DeviceId, FString DeviceModel, FString DeviceName, FString DeviceOS, FString DeviceType, FString DisplayName, FString OperatingSystem, UGameSparksScriptData* Segments,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSDeviceAuthenticationRequest* proxy = NewObject<UGSDeviceAuthenticationRequest>();
	proxy->deviceId = DeviceId;
	proxy->deviceModel = DeviceModel;
	proxy->deviceName = DeviceName;
	proxy->deviceOS = DeviceOS;
	proxy->deviceType = DeviceType;
	proxy->displayName = DisplayName;
	proxy->operatingSystem = OperatingSystem;
	proxy->segments = Segments;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSDeviceAuthenticationRequest::Activate()
{
	GameSparks::Api::Requests::DeviceAuthenticationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(deviceId != ""){
		gsRequest.SetDeviceId(TCHAR_TO_UTF8(*deviceId));
	}
	if(deviceModel != ""){
		gsRequest.SetDeviceModel(TCHAR_TO_UTF8(*deviceModel));
	}
	if(deviceName != ""){
		gsRequest.SetDeviceName(TCHAR_TO_UTF8(*deviceName));
	}
	if(deviceOS != ""){
		gsRequest.SetDeviceOS(TCHAR_TO_UTF8(*deviceOS));
	}
	if(deviceType != ""){
		gsRequest.SetDeviceType(TCHAR_TO_UTF8(*deviceType));
	}
	if(displayName != ""){
		gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
	}
	if(operatingSystem != ""){
		gsRequest.SetOperatingSystem(TCHAR_TO_UTF8(*operatingSystem));
	}
	if(segments != nullptr){
		gsRequest.SetSegments(segments->ToRequestData());
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(DeviceAuthenticationRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(DeviceAuthenticationRequestResponseCallback);
    }
	
	
	
}

UGSDeviceAuthenticationRequest::UGSDeviceAuthenticationRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

