#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetMyTeamsRequest.h"

void GetMyTeamsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetMyTeamsResponse& response){
    
    FGSGetMyTeamsResponse unreal_response = FGSGetMyTeamsResponse(response.GetBaseData());
    
    UGSGetMyTeamsRequest* g_UGSGetMyTeamsRequest = static_cast<UGSGetMyTeamsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetMyTeamsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetMyTeamsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetMyTeamsRequest* UGSGetMyTeamsRequest::SendGetMyTeamsRequest(bool OwnedOnly, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetMyTeamsRequest* proxy = NewObject<UGSGetMyTeamsRequest>();
	proxy->ownedOnly = OwnedOnly;
	proxy->teamTypes = TeamTypes;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetMyTeamsRequest::Activate()
{
	GameSparks::Api::Requests::GetMyTeamsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(ownedOnly != false){
		gsRequest.SetOwnedOnly(ownedOnly);
	}
	if(teamTypes != nullptr){
		gsstl::vector<gsstl::string> arrTeamTypes;
	
	    for(int32 b_arrTeamTypes = 0; b_arrTeamTypes < teamTypes->StringArray.Num(); b_arrTeamTypes++)
	    {
	        arrTeamTypes.push_back(TCHAR_TO_UTF8(*teamTypes->StringArray[b_arrTeamTypes]));
	    }
	    
		gsRequest.SetTeamTypes(arrTeamTypes);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(GetMyTeamsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetMyTeamsRequestResponseCallback);
    }
	
	
	
}

UGSGetMyTeamsRequest::UGSGetMyTeamsRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

