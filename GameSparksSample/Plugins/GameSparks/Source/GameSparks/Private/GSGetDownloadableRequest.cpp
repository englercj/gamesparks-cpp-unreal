#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetDownloadableRequest.h"

void GetDownloadableRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetDownloadableResponse& response){
    
    FGSGetDownloadableResponse unreal_response = FGSGetDownloadableResponse(response.GetBaseData());
    
    UGSGetDownloadableRequest* g_UGSGetDownloadableRequest = static_cast<UGSGetDownloadableRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetDownloadableRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetDownloadableRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetDownloadableRequest* UGSGetDownloadableRequest::SendGetDownloadableRequest(FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetDownloadableRequest* proxy = NewObject<UGSGetDownloadableRequest>();
	proxy->shortCode = ShortCode;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetDownloadableRequest::Activate()
{
	GameSparks::Api::Requests::GetDownloadableRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(shortCode != ""){
		gsRequest.SetShortCode(TCHAR_TO_UTF8(*shortCode));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetDownloadableRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetDownloadableRequestResponseCallback);
    }
	
	
	
}

UGSGetDownloadableRequest::UGSGetDownloadableRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

