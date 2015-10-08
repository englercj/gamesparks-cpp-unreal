#include "GameSparksPrivatePCH.h"
#include "GameSparksScriptData.h"
#include "GSViberConnectRequest.h"

void ViberConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
    	return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSViberConnectRequest* g_UGSViberConnectRequest = static_cast<UGSViberConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSViberConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSViberConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSViberConnectRequest* UGSViberConnectRequest::SendViberConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSViberConnectRequest* proxy = NewObject<UGSViberConnectRequest>();
	proxy->accessToken = AccessToken;
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
	
void UGSViberConnectRequest::Activate()
{
	GameSparks::Api::Requests::ViberConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(accessToken != ""){
		gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
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
    	gsRequest.Send(ViberConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ViberConnectRequestResponseCallback);
    }
	
	
	
}

UGSViberConnectRequest::UGSViberConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

UGSViberConnectRequest::~UGSViberConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
  	module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


