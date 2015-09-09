#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetPropertyRequest.h"

void GetPropertyRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetPropertyResponse& response){
    
    FGSGetPropertyResponse unreal_response = FGSGetPropertyResponse(response.GetBaseData());
    
    UGSGetPropertyRequest* g_UGSGetPropertyRequest = static_cast<UGSGetPropertyRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetPropertyRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetPropertyRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetPropertyRequest* UGSGetPropertyRequest::SendGetPropertyRequest(FString PropertyShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetPropertyRequest* proxy = NewObject<UGSGetPropertyRequest>();
	proxy->propertyShortCode = PropertyShortCode;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetPropertyRequest::Activate()
{
	GameSparks::Api::Requests::GetPropertyRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(propertyShortCode != ""){
		gsRequest.SetPropertyShortCode(TCHAR_TO_UTF8(*propertyShortCode));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetPropertyRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetPropertyRequestResponseCallback);
    }
	
	
	
}

UGSGetPropertyRequest::UGSGetPropertyRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

