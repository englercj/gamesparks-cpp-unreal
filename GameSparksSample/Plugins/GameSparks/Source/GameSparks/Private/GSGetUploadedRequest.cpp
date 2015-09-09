#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetUploadedRequest.h"

void GetUploadedRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetUploadedResponse& response){
    
    FGSGetUploadedResponse unreal_response = FGSGetUploadedResponse(response.GetBaseData());
    
    UGSGetUploadedRequest* g_UGSGetUploadedRequest = static_cast<UGSGetUploadedRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetUploadedRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetUploadedRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetUploadedRequest* UGSGetUploadedRequest::SendGetUploadedRequest(FString UploadId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetUploadedRequest* proxy = NewObject<UGSGetUploadedRequest>();
	proxy->uploadId = UploadId;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetUploadedRequest::Activate()
{
	GameSparks::Api::Requests::GetUploadedRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(uploadId != ""){
		gsRequest.SetUploadId(TCHAR_TO_UTF8(*uploadId));
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetUploadedRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetUploadedRequestResponseCallback);
    }
	
	
	
}

UGSGetUploadedRequest::UGSGetUploadedRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

