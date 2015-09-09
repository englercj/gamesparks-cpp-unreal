#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSFindChallengeRequest.h"

void FindChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::FindChallengeResponse& response){
    
    FGSFindChallengeResponse unreal_response = FGSFindChallengeResponse(response.GetBaseData());
    
    UGSFindChallengeRequest* g_UGSFindChallengeRequest = static_cast<UGSFindChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSFindChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSFindChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSFindChallengeRequest* UGSFindChallengeRequest::SendFindChallengeRequest(FString AccessType, int32 Count, UGameSparksScriptData* Eligibility, int32 Offset, UGameSparksRequestArray* ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSFindChallengeRequest* proxy = NewObject<UGSFindChallengeRequest>();
	proxy->accessType = AccessType;
	proxy->count = Count;
	proxy->eligibility = Eligibility;
	proxy->offset = Offset;
	proxy->shortCode = ShortCode;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSFindChallengeRequest::Activate()
{
	GameSparks::Api::Requests::FindChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(accessType != ""){
		gsRequest.SetAccessType(TCHAR_TO_UTF8(*accessType));
	}
	if(count != 0){
		gsRequest.SetCount(count);
	}
	if(eligibility != nullptr){
		gsRequest.SetEligibility(eligibility->ToRequestData());
	}
	if(offset != 0){
		gsRequest.SetOffset(offset);
	}
	if(shortCode != nullptr){
		gsstl::vector<gsstl::string> arrShortCode;
	
	    for(int32 b_arrShortCode = 0; b_arrShortCode < shortCode->StringArray.Num(); b_arrShortCode++)
	    {
	        arrShortCode.push_back(TCHAR_TO_UTF8(*shortCode->StringArray[b_arrShortCode]));
	    }
	    
		gsRequest.SetShortCode(arrShortCode);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(FindChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(FindChallengeRequestResponseCallback);
    }
	
	
	
}

UGSFindChallengeRequest::UGSFindChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

