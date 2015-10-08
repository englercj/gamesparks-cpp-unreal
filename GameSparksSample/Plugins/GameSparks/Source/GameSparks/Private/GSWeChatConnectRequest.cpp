#include "GameSparksPrivatePCH.h"
#include "GameSparksScriptData.h"
#include "GSWeChatConnectRequest.h"

void WeChatConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
    	return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSWeChatConnectRequest* g_UGSWeChatConnectRequest = static_cast<UGSWeChatConnectRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSWeChatConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSWeChatConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSWeChatConnectRequest* UGSWeChatConnectRequest::SendWeChatConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString OpenId, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSWeChatConnectRequest* proxy = NewObject<UGSWeChatConnectRequest>();
	proxy->accessToken = AccessToken;
	proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
	proxy->errorOnSwitch = ErrorOnSwitch;
	proxy->openId = OpenId;
	proxy->segments = Segments;
	proxy->switchIfPossible = SwitchIfPossible;
	proxy->syncDisplayName = SyncDisplayName;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSWeChatConnectRequest::Activate()
{
	GameSparks::Api::Requests::WeChatConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
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
    	gsRequest.Send(WeChatConnectRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(WeChatConnectRequestResponseCallback);
    }
	
	
	
}

UGSWeChatConnectRequest::UGSWeChatConnectRequest(const class FObjectInitializer& PCIP) : Super(PCIP) {
}

UGSWeChatConnectRequest::~UGSWeChatConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
  	module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


