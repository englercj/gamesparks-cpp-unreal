#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetRunningTotalsRequest.h"

void GetRunningTotalsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetRunningTotalsResponse& response){
    
    FGSGetRunningTotalsResponse unreal_response = FGSGetRunningTotalsResponse(response.GetBaseData());
    
    UGSGetRunningTotalsRequest* g_UGSGetRunningTotalsRequest = static_cast<UGSGetRunningTotalsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetRunningTotalsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetRunningTotalsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetRunningTotalsRequest* UGSGetRunningTotalsRequest::SendGetRunningTotalsRequest(UGameSparksRequestArray* FriendIds, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetRunningTotalsRequest* proxy = NewObject<UGSGetRunningTotalsRequest>();
	proxy->friendIds = FriendIds;
	proxy->shortCode = ShortCode;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetRunningTotalsRequest::Activate()
{
	GameSparks::Api::Requests::GetRunningTotalsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(friendIds != nullptr){
		gsstl::vector<gsstl::string> arrFriendIds;
	
	    for(int32 b_arrFriendIds = 0; b_arrFriendIds < friendIds->StringArray.Num(); b_arrFriendIds++)
	    {
	        arrFriendIds.push_back(TCHAR_TO_UTF8(*friendIds->StringArray[b_arrFriendIds]));
	    }
	    
		gsRequest.SetFriendIds(arrFriendIds);
	}
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
    	gsRequest.Send(GetRunningTotalsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetRunningTotalsRequestResponseCallback);
    }
	
	
	
}

UGSGetRunningTotalsRequest::UGSGetRunningTotalsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

