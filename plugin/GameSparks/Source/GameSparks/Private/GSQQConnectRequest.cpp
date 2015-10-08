#include "GameSparksPrivatePCH.h"
#include "GameSparksScriptData.h"
#include "GSQQConnectRequest.h"

void QQConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
    	return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSQQConnectRequest* g_UGSQQConnectRequest = static_cast<UGSQQConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSQQConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSQQConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSQQConnectRequest* UGSQQConnectRequest::SendQQConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString OpenId, FString RefreshToken, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSQQConnectRequest* proxy = NewObject<UGSQQConnectRequest>();
	proxy->accessToken = AccessToken;
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->openId = OpenId;
	proxy->refreshToken = RefreshToken;
	proxy->segments = Segments;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSQQConnectRequest::Activate()
{
	GameSparks::Api::Requests::QQConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(accessToken != ""){
		gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
	}
	if(doNotLinkToCurrentPlayer != false){
		gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
	}
	if(errorOnSwitch != false){
		gsRequest.SetErrorOnSwitch(errorOnSwitch);
	}
	if(openId != ""){
		gsRequest.SetOpenId(TCHAR_TO_UTF8(*openId));
	}
	if(refreshToken != ""){
		gsRequest.SetRefreshToken(TCHAR_TO_UTF8(*refreshToken));
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
    	gsRequest.Send(QQConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(QQConnectRequestResponseCallback);
    }
	
	
	
}

UGSQQConnectRequest::UGSQQConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

UGSQQConnectRequest::~UGSQQConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
  	module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


