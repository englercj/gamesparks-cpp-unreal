#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksScriptData.h"
#include "GSCreateChallengeRequest.h"

void CreateChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::CreateChallengeResponse& response){
    
    FGSCreateChallengeResponse unreal_response = FGSCreateChallengeResponse(response.GetBaseData());
    
    UGSCreateChallengeRequest* g_UGSCreateChallengeRequest = static_cast<UGSCreateChallengeRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSCreateChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSCreateChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSCreateChallengeRequest* UGSCreateChallengeRequest::SendCreateChallengeRequest(FString AccessType, bool AutoStartJoinedChallengeOnMaxPlayers, FString ChallengeMessage, FString ChallengeShortCode, int32 Currency1Wager, int32 Currency2Wager, int32 Currency3Wager, int32 Currency4Wager, int32 Currency5Wager, int32 Currency6Wager, UGameSparksScriptData* EligibilityCriteria, FString EndTime, FString ExpiryTime, int32 MaxAttempts, int32 MaxPlayers, int32 MinPlayers, bool Silent, FString StartTime, UGameSparksRequestArray* UsersToChallenge,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSCreateChallengeRequest* proxy = NewObject<UGSCreateChallengeRequest>();
	proxy->accessType = AccessType;
	proxy->autoStartJoinedChallengeOnMaxPlayers = AutoStartJoinedChallengeOnMaxPlayers;
	proxy->challengeMessage = ChallengeMessage;
	proxy->challengeShortCode = ChallengeShortCode;
	proxy->currency1Wager = Currency1Wager;
	proxy->currency2Wager = Currency2Wager;
	proxy->currency3Wager = Currency3Wager;
	proxy->currency4Wager = Currency4Wager;
	proxy->currency5Wager = Currency5Wager;
	proxy->currency6Wager = Currency6Wager;
	proxy->eligibilityCriteria = EligibilityCriteria;
	proxy->endTime = EndTime;
	proxy->expiryTime = ExpiryTime;
	proxy->maxAttempts = MaxAttempts;
	proxy->maxPlayers = MaxPlayers;
	proxy->minPlayers = MinPlayers;
	proxy->silent = Silent;
	proxy->startTime = StartTime;
	proxy->usersToChallenge = UsersToChallenge;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSCreateChallengeRequest::Activate()
{
	GameSparks::Api::Requests::CreateChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(accessType != ""){
		gsRequest.SetAccessType(TCHAR_TO_UTF8(*accessType));
	}
	if(autoStartJoinedChallengeOnMaxPlayers != false){
		gsRequest.SetAutoStartJoinedChallengeOnMaxPlayers(autoStartJoinedChallengeOnMaxPlayers);
	}
	if(challengeMessage != ""){
		gsRequest.SetChallengeMessage(TCHAR_TO_UTF8(*challengeMessage));
	}
	if(challengeShortCode != ""){
		gsRequest.SetChallengeShortCode(TCHAR_TO_UTF8(*challengeShortCode));
	}
	if(currency1Wager != 0){
		gsRequest.SetCurrency1Wager(currency1Wager);
	}
	if(currency2Wager != 0){
		gsRequest.SetCurrency2Wager(currency2Wager);
	}
	if(currency3Wager != 0){
		gsRequest.SetCurrency3Wager(currency3Wager);
	}
	if(currency4Wager != 0){
		gsRequest.SetCurrency4Wager(currency4Wager);
	}
	if(currency5Wager != 0){
		gsRequest.SetCurrency5Wager(currency5Wager);
	}
	if(currency6Wager != 0){
		gsRequest.SetCurrency6Wager(currency6Wager);
	}
	if(eligibilityCriteria != nullptr){
		gsRequest.SetEligibilityCriteria(eligibilityCriteria->ToRequestData());
	}
	if(endTime != ""){
		gsRequest.SetEndTime(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*endTime)));
	}
	if(expiryTime != ""){
		gsRequest.SetExpiryTime(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*expiryTime)));
	}
	if(maxAttempts != 0){
		gsRequest.SetMaxAttempts(maxAttempts);
	}
	if(maxPlayers != 0){
		gsRequest.SetMaxPlayers(maxPlayers);
	}
	if(minPlayers != 0){
		gsRequest.SetMinPlayers(minPlayers);
	}
	if(silent != false){
		gsRequest.SetSilent(silent);
	}
	if(startTime != ""){
		gsRequest.SetStartTime(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*startTime)));
	}
	if(usersToChallenge != nullptr){
		gsstl::vector<gsstl::string> arrUsersToChallenge;
	
	    for(int32 b_arrUsersToChallenge = 0; b_arrUsersToChallenge < usersToChallenge->StringArray.Num(); b_arrUsersToChallenge++)
	    {
	        arrUsersToChallenge.push_back(TCHAR_TO_UTF8(*usersToChallenge->StringArray[b_arrUsersToChallenge]));
	    }
	    
		gsRequest.SetUsersToChallenge(arrUsersToChallenge);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(CreateChallengeRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(CreateChallengeRequestResponseCallback);
    }
	
	
	
}

UGSCreateChallengeRequest::UGSCreateChallengeRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

