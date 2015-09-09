#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSGetLeaderboardEntriesRequest.h"

void GetLeaderboardEntriesRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetLeaderboardEntriesResponse& response){
    
    FGSGetLeaderboardEntriesResponse unreal_response = FGSGetLeaderboardEntriesResponse(response.GetBaseData());
    
    UGSGetLeaderboardEntriesRequest* g_UGSGetLeaderboardEntriesRequest = static_cast<UGSGetLeaderboardEntriesRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSGetLeaderboardEntriesRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetLeaderboardEntriesRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetLeaderboardEntriesRequest* UGSGetLeaderboardEntriesRequest::SendGetLeaderboardEntriesRequest(UGameSparksRequestArray* Challenges, bool InverseSocial, UGameSparksRequestArray* Leaderboards, FString Player, bool Social, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSGetLeaderboardEntriesRequest* proxy = NewObject<UGSGetLeaderboardEntriesRequest>();
	proxy->challenges = Challenges;
	proxy->inverseSocial = InverseSocial;
	proxy->leaderboards = Leaderboards;
	proxy->player = Player;
	proxy->social = Social;
	proxy->teamTypes = TeamTypes;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSGetLeaderboardEntriesRequest::Activate()
{
	GameSparks::Api::Requests::GetLeaderboardEntriesRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(challenges != nullptr){
		gsstl::vector<gsstl::string> arrChallenges;
	
	    for(int32 b_arrChallenges = 0; b_arrChallenges < challenges->StringArray.Num(); b_arrChallenges++)
	    {
	        arrChallenges.push_back(TCHAR_TO_UTF8(*challenges->StringArray[b_arrChallenges]));
	    }
	    
		gsRequest.SetChallenges(arrChallenges);
	}
	if(inverseSocial != false){
		gsRequest.SetInverseSocial(inverseSocial);
	}
	if(leaderboards != nullptr){
		gsstl::vector<gsstl::string> arrLeaderboards;
	
	    for(int32 b_arrLeaderboards = 0; b_arrLeaderboards < leaderboards->StringArray.Num(); b_arrLeaderboards++)
	    {
	        arrLeaderboards.push_back(TCHAR_TO_UTF8(*leaderboards->StringArray[b_arrLeaderboards]));
	    }
	    
		gsRequest.SetLeaderboards(arrLeaderboards);
	}
	if(player != ""){
		gsRequest.SetPlayer(TCHAR_TO_UTF8(*player));
	}
	if(social != false){
		gsRequest.SetSocial(social);
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
    	gsRequest.Send(GetLeaderboardEntriesRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(GetLeaderboardEntriesRequestResponseCallback);
    }
	
	
	
}

UGSGetLeaderboardEntriesRequest::UGSGetLeaderboardEntriesRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

