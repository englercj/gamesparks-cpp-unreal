#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSLeaderboardDataRequest.h"

void LeaderboardDataRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LeaderboardDataResponse& response){
    
    FGSLeaderboardDataResponse unreal_response = FGSLeaderboardDataResponse(response.GetBaseData());
    
    UGSLeaderboardDataRequest* g_UGSLeaderboardDataRequest = static_cast<UGSLeaderboardDataRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSLeaderboardDataRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLeaderboardDataRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLeaderboardDataRequest* UGSLeaderboardDataRequest::SendLeaderboardDataRequest(FString ChallengeInstanceId, bool DontErrorOnNotSocial, int32 EntryCount, UGameSparksRequestArray* FriendIds, int32 IncludeFirst, int32 IncludeLast, bool InverseSocial, FString LeaderboardShortCode, int32 Offset, bool Social, UGameSparksRequestArray* TeamIds, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSLeaderboardDataRequest* proxy = NewObject<UGSLeaderboardDataRequest>();
	proxy->challengeInstanceId = ChallengeInstanceId;
	proxy->dontErrorOnNotSocial = DontErrorOnNotSocial;
	proxy->entryCount = EntryCount;
	proxy->friendIds = FriendIds;
	proxy->includeFirst = IncludeFirst;
	proxy->includeLast = IncludeLast;
	proxy->inverseSocial = InverseSocial;
	proxy->leaderboardShortCode = LeaderboardShortCode;
	proxy->offset = Offset;
	proxy->social = Social;
	proxy->teamIds = TeamIds;
	proxy->teamTypes = TeamTypes;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSLeaderboardDataRequest::Activate()
{
	GameSparks::Api::Requests::LeaderboardDataRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(challengeInstanceId != ""){
		gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
	}
	if(dontErrorOnNotSocial != false){
		gsRequest.SetDontErrorOnNotSocial(dontErrorOnNotSocial);
	}
	if(entryCount != 0){
		gsRequest.SetEntryCount(entryCount);
	}
	if(friendIds != nullptr){
		gsstl::vector<gsstl::string> arrFriendIds;
	
	    for(int32 b_arrFriendIds = 0; b_arrFriendIds < friendIds->StringArray.Num(); b_arrFriendIds++)
	    {
	        arrFriendIds.push_back(TCHAR_TO_UTF8(*friendIds->StringArray[b_arrFriendIds]));
	    }
	    
		gsRequest.SetFriendIds(arrFriendIds);
	}
	if(includeFirst != 0){
		gsRequest.SetIncludeFirst(includeFirst);
	}
	if(includeLast != 0){
		gsRequest.SetIncludeLast(includeLast);
	}
	if(inverseSocial != false){
		gsRequest.SetInverseSocial(inverseSocial);
	}
	if(leaderboardShortCode != ""){
		gsRequest.SetLeaderboardShortCode(TCHAR_TO_UTF8(*leaderboardShortCode));
	}
	if(offset != 0){
		gsRequest.SetOffset(offset);
	}
	if(social != false){
		gsRequest.SetSocial(social);
	}
	if(teamIds != nullptr){
		gsstl::vector<gsstl::string> arrTeamIds;
	
	    for(int32 b_arrTeamIds = 0; b_arrTeamIds < teamIds->StringArray.Num(); b_arrTeamIds++)
	    {
	        arrTeamIds.push_back(TCHAR_TO_UTF8(*teamIds->StringArray[b_arrTeamIds]));
	    }
	    
		gsRequest.SetTeamIds(arrTeamIds);
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
    	gsRequest.Send(LeaderboardDataRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(LeaderboardDataRequestResponseCallback);
    }
	
	
	
}

UGSLeaderboardDataRequest::UGSLeaderboardDataRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

