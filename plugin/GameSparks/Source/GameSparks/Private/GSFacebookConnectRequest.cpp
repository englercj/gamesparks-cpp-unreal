#include "GameSparksPrivatePCH.h"
#include "GameSparksScriptData.h"
#include "GSFacebookConnectRequest.h"

void FacebookConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
    	return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSFacebookConnectRequest* g_UGSFacebookConnectRequest = static_cast<UGSFacebookConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSFacebookConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSFacebookConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSFacebookConnectRequest* UGSFacebookConnectRequest::SendFacebookConnectRequest(FString AccessToken, FString Code, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSFacebookConnectRequest* proxy = NewObject<UGSFacebookConnectRequest>();
	proxy->accessToken = AccessToken;
	proxy->code = Code;
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->segments = Segments;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSFacebookConnectRequest::Activate()
{
	GameSparks::Api::Requests::FacebookConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(accessToken != ""){
		gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
	}
	if(code != ""){
		gsRequest.SetCode(TCHAR_TO_UTF8(*code));
	}
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
	}
	if(segments != nullptr){
		gsRequest.SetSegments(segments->ToRequestData());
	}
	if(switchIfPossible != false){
		gsRequest.SetSwitchIfPossible(switchIfPossible);
	}
	if(syncDisplayName != false){
		gsRequest.SetSyncDisplayName(syncDisplayName);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(FacebookConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(FacebookConnectRequestResponseCallback);
    }
	
	
	
}

UGSFacebookConnectRequest::UGSFacebookConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

UGSFacebookConnectRequest::~UGSFacebookConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
  	module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


