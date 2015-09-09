#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetPropertySetRequest.h"

void GetPropertySetRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetPropertySetResponse& response){
    
    FGSGetPropertySetResponse unreal_response = FGSGetPropertySetResponse(response.GetBaseData());
    
    UGSGetPropertySetRequest* g_UGSGetPropertySetRequest = static_cast<UGSGetPropertySetRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetPropertySetRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetPropertySetRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetPropertySetRequest* UGSGetPropertySetRequest::SendGetPropertySetRequest(FString PropertySetShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetPropertySetRequest* proxy = NewObject<UGSGetPropertySetRequest>();
	proxy->propertySetShortCode = PropertySetShortCode;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetPropertySetRequest::Activate()
{
	GameSparks::Api::Requests::GetPropertySetRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(propertySetShortCode != ""){
		gsRequest.SetPropertySetShortCode(TCHAR_TO_UTF8(*propertySetShortCode));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetPropertySetRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetPropertySetRequestResponseCallback);
    }
	
	
	
}

UGSGetPropertySetRequest::UGSGetPropertySetRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

