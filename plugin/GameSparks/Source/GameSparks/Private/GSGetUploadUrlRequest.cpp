#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetUploadUrlRequest.h"

void GetUploadUrlRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetUploadUrlResponse& response){
    
    FGSGetUploadUrlResponse unreal_response = FGSGetUploadUrlResponse(response.GetBaseData());
    
    UGSGetUploadUrlRequest* g_UGSGetUploadUrlRequest = static_cast<UGSGetUploadUrlRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetUploadUrlRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetUploadUrlRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetUploadUrlRequest* UGSGetUploadUrlRequest::SendGetUploadUrlRequest(UGameSparksScriptData* UploadData,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetUploadUrlRequest* proxy = NewObject<UGSGetUploadUrlRequest>();
	proxy->uploadData = UploadData;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetUploadUrlRequest::Activate()
{
	GameSparks::Api::Requests::GetUploadUrlRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(uploadData != nullptr){
		gsRequest.SetUploadData(uploadData->ToRequestData());
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetUploadUrlRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetUploadUrlRequestResponseCallback);
    }
	
	
	
}

UGSGetUploadUrlRequest::UGSGetUploadUrlRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

