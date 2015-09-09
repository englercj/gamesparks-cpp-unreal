#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSListChallengeRequest.h"

void ListChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListChallengeResponse& response){
    
    FGSListChallengeResponse unreal_response = FGSListChallengeResponse(response.GetBaseData());
    
    UGSListChallengeRequest* g_UGSListChallengeRequest = static_cast<UGSListChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListChallengeRequest* UGSListChallengeRequest::SendListChallengeRequest(int32 EntryCount, int32 Offset, FString ShortCode, FString State, UGameSparksRequestArray* States,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListChallengeRequest* proxy = NewObject<UGSListChallengeRequest>();
	proxy->entryCount = EntryCount;
	proxy->offset = Offset;
	proxy->shortCode = ShortCode;
	proxy->state = State;
	proxy->states = States;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListChallengeRequest::Activate()
{
	GameSparks::Api::Requests::ListChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(entryCount != 0){
		gsRequest.SetEntryCount(entryCount);
	}
	if(offset != 0){
		gsRequest.SetOffset(offset);
	}
	if(shortCode != ""){
		gsRequest.SetShortCode(TCHAR_TO_UTF8(*shortCode));
	}
	if(state != ""){
		gsRequest.SetState(TCHAR_TO_UTF8(*state));
	}
	if(states != nullptr){
		gsstl::vector<gsstl::string> arrStates;
	
	    for(int32 b_arrStates = 0; b_arrStates < states->StringArray.Num(); b_arrStates++)
	    {
	        arrStates.push_back(TCHAR_TO_UTF8(*states->StringArray[b_arrStates]));
	    }
	    
		gsRequest.SetStates(arrStates);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListChallengeRequestResponseCallback);
    }
	
	
	
}

UGSListChallengeRequest::UGSListChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

