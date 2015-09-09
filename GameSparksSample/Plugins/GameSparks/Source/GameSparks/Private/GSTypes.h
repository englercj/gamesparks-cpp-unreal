#pragma once
#include "GameSparksScriptData.h"
#include "GameSparks/GSData.h"
#include "GSTypes.generated.h"


USTRUCT(BlueprintType)
struct FGSUploadData
{
	GENERATED_USTRUCT_BODY()
	
	FGSUploadData(){}
	
	FGSUploadData(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("fileName")){
		HasFileName = true;
			FileName = wrappedData.GetString("fileName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("playerId")){
		HasPlayerId = true;
			PlayerId = wrappedData.GetString("playerId").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasFileName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString FileName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasPlayerId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString PlayerId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSSocialStatus
{
	GENERATED_USTRUCT_BODY()
	
	FGSSocialStatus(){}
	
	FGSSocialStatus(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("active")){
		HasActive = true;
			Active = wrappedData.GetBoolean("active").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("expires")){
		HasExpires = true;
			Expires = wrappedData.GetString("expires").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("systemId")){
		HasSystemId = true;
			SystemId = wrappedData.GetString("systemId").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasActive = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool Active;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasExpires = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Expires;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasSystemId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString SystemId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSInvitableFriend
{
	GENERATED_USTRUCT_BODY()
	
	FGSInvitableFriend(){}
	
	FGSInvitableFriend(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("displayName")){
		HasDisplayName = true;
			DisplayName = wrappedData.GetString("displayName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("id")){
		HasId = true;
			Id = wrappedData.GetString("id").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("profilePic")){
		HasProfilePic = true;
			ProfilePic = wrappedData.GetString("profilePic").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasDisplayName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString DisplayName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Id;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasProfilePic = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ProfilePic;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSPlayer
{
	GENERATED_USTRUCT_BODY()
	
	FGSPlayer(){}
	
	FGSPlayer(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("achievements")){
		HasAchievements = true;
			for(int i=0; i < wrappedData.GetStringList("achievements").size(); i++){
				FString Achievements_tmp = wrappedData.GetStringList("achievements")[i].c_str();
				Achievements.Add(Achievements_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("displayName")){
		HasDisplayName = true;
			DisplayName = wrappedData.GetString("displayName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("externalIds")){
		HasExternalIds = true;
			ExternalIds = NewObject<UGameSparksScriptData>();ExternalIds->SetGSData(wrappedData.GetGSDataObject("externalIds").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("id")){
		HasId = true;
			Id = wrappedData.GetString("id").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("online")){
		HasOnline = true;
			Online = wrappedData.GetBoolean("online").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("virtualGoods")){
		HasVirtualGoods = true;
			for(int i=0; i < wrappedData.GetStringList("virtualGoods").size(); i++){
				FString VirtualGoods_tmp = wrappedData.GetStringList("virtualGoods")[i].c_str();
				VirtualGoods.Add(VirtualGoods_tmp);
            }
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasAchievements = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	TArray<FString> Achievements;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasDisplayName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString DisplayName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasExternalIds = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	UGameSparksScriptData* ExternalIds = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Id;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasOnline = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool Online;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasVirtualGoods = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	TArray<FString> VirtualGoods;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		ExternalIds = nullptr;
		ScriptData = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSPlayerDetail
{
	GENERATED_USTRUCT_BODY()
	
	FGSPlayerDetail(){}
	
	FGSPlayerDetail(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("externalIds")){
		HasExternalIds = true;
			ExternalIds = NewObject<UGameSparksScriptData>();ExternalIds->SetGSData(wrappedData.GetGSDataObject("externalIds").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("id")){
		HasId = true;
			Id = wrappedData.GetString("id").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("name")){
		HasName = true;
			Name = wrappedData.GetString("name").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasExternalIds = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	UGameSparksScriptData* ExternalIds = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Id;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Name;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		ExternalIds = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSLocation
{
	GENERATED_USTRUCT_BODY()
	
	FGSLocation(){}
	
	FGSLocation(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("city")){
		HasCity = true;
			City = wrappedData.GetString("city").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("country")){
		HasCountry = true;
			Country = wrappedData.GetString("country").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("latitide")){
		HasLatitide = true;
			Latitide = wrappedData.GetFloat("latitide").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("longditute")){
		HasLongditute = true;
			Longditute = wrappedData.GetFloat("longditute").GetValue();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasCity = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	FString City;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasCountry = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	FString Country;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasLatitide = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	float Latitide;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasLongditute = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	float Longditute;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSTeam
{
	GENERATED_USTRUCT_BODY()
	
	FGSTeam(){}
	
	FGSTeam(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("members")){
		HasMembers = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("members").size(); i++){
				FGSPlayer Members_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("members")[i]);
				Members.Add(Members_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("owner")){
		HasOwner = true;
			Owner = FGSPlayer(wrappedData.GetGSDataObject("owner").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("teamId")){
		HasTeamId = true;
			TeamId = wrappedData.GetString("teamId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamType")){
		HasTeamType = true;
			TeamType = wrappedData.GetString("teamType").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasMembers = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	TArray<FGSPlayer> Members;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasOwner = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FGSPlayer Owner;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasTeamId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString TeamId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasTeamType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString TeamType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSPlayerTurnCount
{
	GENERATED_USTRUCT_BODY()
	
	FGSPlayerTurnCount(){}
	
	FGSPlayerTurnCount(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("count")){
		HasCount = true;
			Count = wrappedData.GetString("count").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("playerId")){
		HasPlayerId = true;
			PlayerId = wrappedData.GetString("playerId").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCount = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Count;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasPlayerId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString PlayerId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSLeaderboard
{
	GENERATED_USTRUCT_BODY()
	
	FGSLeaderboard(){}
	
	FGSLeaderboard(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("description")){
		HasDescription = true;
			Description = wrappedData.GetString("description").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("name")){
		HasName = true;
			Name = wrappedData.GetString("name").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("propertySet")){
		HasPropertySet = true;
			PropertySet = NewObject<UGameSparksScriptData>();PropertySet->SetGSData(wrappedData.GetGSDataObject("propertySet").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("shortCode")){
		HasShortCode = true;
			ShortCode = wrappedData.GetString("shortCode").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasDescription = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Description;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Name;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasPropertySet = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	UGameSparksScriptData* PropertySet = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		PropertySet = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSLeaderboardData
{
	GENERATED_USTRUCT_BODY()
	
	FGSLeaderboardData(){}
	
	FGSLeaderboardData(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("city")){
		HasCity = true;
			City = wrappedData.GetString("city").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("country")){
		HasCountry = true;
			Country = wrappedData.GetString("country").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("externalIds")){
		HasExternalIds = true;
			ExternalIds = NewObject<UGameSparksScriptData>();ExternalIds->SetGSData(wrappedData.GetGSDataObject("externalIds").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("id")){
		HasId = true;
			Id = wrappedData.GetString("id").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("rank")){
		HasRank = true;
			Rank = wrappedData.GetNumber("rank").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("userId")){
		HasUserId = true;
			UserId = wrappedData.GetString("userId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("userName")){
		HasUserName = true;
			UserName = wrappedData.GetString("userName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("when")){
		HasWhen = true;
			When = wrappedData.GetString("when").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCity = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString City;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCountry = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Country;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasExternalIds = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	UGameSparksScriptData* ExternalIds = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Id;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasRank = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Rank;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasUserId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString UserId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasUserName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString UserName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasWhen = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString When;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		ExternalIds = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSLeaderboardRankDetails
{
	GENERATED_USTRUCT_BODY()
	
	FGSLeaderboardRankDetails(){}
	
	FGSLeaderboardRankDetails(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("friendsPassed")){
		HasFriendsPassed = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("friendsPassed").size(); i++){
				FGSLeaderboardData FriendsPassed_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("friendsPassed")[i]);
				FriendsPassed.Add(FriendsPassed_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("globalCount")){
		HasGlobalCount = true;
			GlobalCount = wrappedData.GetNumber("globalCount").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("globalFrom")){
		HasGlobalFrom = true;
			GlobalFrom = wrappedData.GetNumber("globalFrom").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("globalFromPercent")){
		HasGlobalFromPercent = true;
			GlobalFromPercent = wrappedData.GetNumber("globalFromPercent").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("globalTo")){
		HasGlobalTo = true;
			GlobalTo = wrappedData.GetNumber("globalTo").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("globalToPercent")){
		HasGlobalToPercent = true;
			GlobalToPercent = wrappedData.GetNumber("globalToPercent").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("socialCount")){
		HasSocialCount = true;
			SocialCount = wrappedData.GetNumber("socialCount").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("socialFrom")){
		HasSocialFrom = true;
			SocialFrom = wrappedData.GetNumber("socialFrom").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("socialFromPercent")){
		HasSocialFromPercent = true;
			SocialFromPercent = wrappedData.GetNumber("socialFromPercent").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("socialTo")){
		HasSocialTo = true;
			SocialTo = wrappedData.GetNumber("socialTo").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("socialToPercent")){
		HasSocialToPercent = true;
			SocialToPercent = wrappedData.GetNumber("socialToPercent").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("topNPassed")){
		HasTopNPassed = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("topNPassed").size(); i++){
				FGSLeaderboardData TopNPassed_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("topNPassed")[i]);
				TopNPassed.Add(TopNPassed_tmp);
            }
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasFriendsPassed = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> FriendsPassed;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasGlobalCount = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 GlobalCount;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasGlobalFrom = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 GlobalFrom;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasGlobalFromPercent = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 GlobalFromPercent;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasGlobalTo = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 GlobalTo;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasGlobalToPercent = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 GlobalToPercent;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSocialCount = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 SocialCount;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSocialFrom = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 SocialFrom;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSocialFromPercent = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 SocialFromPercent;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSocialTo = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 SocialTo;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSocialToPercent = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 SocialToPercent;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasTopNPassed = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> TopNPassed;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSBoughtitem
{
	GENERATED_USTRUCT_BODY()
	
	FGSBoughtitem(){}
	
	FGSBoughtitem(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("quantity")){
		HasQuantity = true;
			Quantity = wrappedData.GetNumber("quantity").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("shortCode")){
		HasShortCode = true;
			ShortCode = wrappedData.GetString("shortCode").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasQuantity = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	int32 Quantity;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	FString ShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallenge
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallenge(){}
	
	FGSChallenge(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("accepted")){
		HasAccepted = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("accepted").size(); i++){
				FGSPlayerDetail Accepted_tmp = FGSPlayerDetail(wrappedData.GetGSDataObjectList("accepted")[i]);
				Accepted.Add(Accepted_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("challengeId")){
		HasChallengeId = true;
			ChallengeId = wrappedData.GetString("challengeId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("challengeMessage")){
		HasChallengeMessage = true;
			ChallengeMessage = wrappedData.GetString("challengeMessage").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("challengeName")){
		HasChallengeName = true;
			ChallengeName = wrappedData.GetString("challengeName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("challenged")){
		HasChallenged = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("challenged").size(); i++){
				FGSPlayerDetail Challenged_tmp = FGSPlayerDetail(wrappedData.GetGSDataObjectList("challenged")[i]);
				Challenged.Add(Challenged_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("challenger")){
		HasChallenger = true;
			Challenger = FGSPlayerDetail(wrappedData.GetGSDataObject("challenger").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("currency1Wager")){
		HasCurrency1Wager = true;
			Currency1Wager = wrappedData.GetNumber("currency1Wager").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency2Wager")){
		HasCurrency2Wager = true;
			Currency2Wager = wrappedData.GetNumber("currency2Wager").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency3Wager")){
		HasCurrency3Wager = true;
			Currency3Wager = wrappedData.GetNumber("currency3Wager").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency4Wager")){
		HasCurrency4Wager = true;
			Currency4Wager = wrappedData.GetNumber("currency4Wager").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency5Wager")){
		HasCurrency5Wager = true;
			Currency5Wager = wrappedData.GetNumber("currency5Wager").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency6Wager")){
		HasCurrency6Wager = true;
			Currency6Wager = wrappedData.GetNumber("currency6Wager").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("declined")){
		HasDeclined = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("declined").size(); i++){
				FGSPlayerDetail Declined_tmp = FGSPlayerDetail(wrappedData.GetGSDataObjectList("declined")[i]);
				Declined.Add(Declined_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("endDate")){
		HasEndDate = true;
			EndDate = wrappedData.GetString("endDate").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("expiryDate")){
		HasExpiryDate = true;
			ExpiryDate = wrappedData.GetString("expiryDate").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("maxTurns")){
		HasMaxTurns = true;
			MaxTurns = wrappedData.GetNumber("maxTurns").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("nextPlayer")){
		HasNextPlayer = true;
			NextPlayer = wrappedData.GetString("nextPlayer").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("shortCode")){
		HasShortCode = true;
			ShortCode = wrappedData.GetString("shortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("startDate")){
		HasStartDate = true;
			StartDate = wrappedData.GetString("startDate").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("state")){
		HasState = true;
			State = wrappedData.GetString("state").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("turnCount")){
		HasTurnCount = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("turnCount").size(); i++){
				FGSPlayerTurnCount TurnCount_tmp = FGSPlayerTurnCount(wrappedData.GetGSDataObjectList("turnCount")[i]);
				TurnCount.Add(TurnCount_tmp);
            }
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasAccepted = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	TArray<FGSPlayerDetail> Accepted;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasChallengeId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ChallengeId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasChallengeMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ChallengeMessage;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasChallengeName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ChallengeName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasChallenged = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	TArray<FGSPlayerDetail> Challenged;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasChallenger = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FGSPlayerDetail Challenger;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency1Wager = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency1Wager;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency2Wager = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency2Wager;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency3Wager = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency3Wager;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency4Wager = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency4Wager;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency5Wager = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency5Wager;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency6Wager = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency6Wager;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasDeclined = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	TArray<FGSPlayerDetail> Declined;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasEndDate = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString EndDate;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasExpiryDate = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ExpiryDate;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasMaxTurns = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 MaxTurns;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasNextPlayer = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString NextPlayer;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasStartDate = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString StartDate;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasState = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString State;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasTurnCount = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	TArray<FGSPlayerTurnCount> TurnCount;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSVirtualGood
{
	GENERATED_USTRUCT_BODY()
	
	FGSVirtualGood(){}
	
	FGSVirtualGood(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("WP8StoreProductId")){
		HasWP8StoreProductId = true;
			WP8StoreProductId = wrappedData.GetString("WP8StoreProductId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("amazonStoreProductId")){
		HasAmazonStoreProductId = true;
			AmazonStoreProductId = wrappedData.GetString("amazonStoreProductId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("currency1Cost")){
		HasCurrency1Cost = true;
			Currency1Cost = wrappedData.GetNumber("currency1Cost").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency2Cost")){
		HasCurrency2Cost = true;
			Currency2Cost = wrappedData.GetNumber("currency2Cost").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency3Cost")){
		HasCurrency3Cost = true;
			Currency3Cost = wrappedData.GetNumber("currency3Cost").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency4Cost")){
		HasCurrency4Cost = true;
			Currency4Cost = wrappedData.GetNumber("currency4Cost").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency5Cost")){
		HasCurrency5Cost = true;
			Currency5Cost = wrappedData.GetNumber("currency5Cost").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency6Cost")){
		HasCurrency6Cost = true;
			Currency6Cost = wrappedData.GetNumber("currency6Cost").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("description")){
		HasDescription = true;
			Description = wrappedData.GetString("description").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("googlePlayProductId")){
		HasGooglePlayProductId = true;
			GooglePlayProductId = wrappedData.GetString("googlePlayProductId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("iosAppStoreProductId")){
		HasIosAppStoreProductId = true;
			IosAppStoreProductId = wrappedData.GetString("iosAppStoreProductId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("maxQuantity")){
		HasMaxQuantity = true;
			MaxQuantity = wrappedData.GetNumber("maxQuantity").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("name")){
		HasName = true;
			Name = wrappedData.GetString("name").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("propertySet")){
		HasPropertySet = true;
			PropertySet = NewObject<UGameSparksScriptData>();PropertySet->SetGSData(wrappedData.GetGSDataObject("propertySet").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("shortCode")){
		HasShortCode = true;
			ShortCode = wrappedData.GetString("shortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("tags")){
		HasTags = true;
			Tags = wrappedData.GetString("tags").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("type")){
		HasType = true;
			Type = wrappedData.GetString("type").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("w8StoreProductId")){
		HasW8StoreProductId = true;
			W8StoreProductId = wrappedData.GetString("w8StoreProductId").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasWP8StoreProductId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString WP8StoreProductId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasAmazonStoreProductId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString AmazonStoreProductId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency1Cost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency1Cost;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency2Cost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency2Cost;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency3Cost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency3Cost;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency4Cost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency4Cost;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency5Cost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency5Cost;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasCurrency6Cost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 Currency6Cost;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasDescription = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Description;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasGooglePlayProductId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString GooglePlayProductId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasIosAppStoreProductId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString IosAppStoreProductId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasMaxQuantity = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	int32 MaxQuantity;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Name;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasPropertySet = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	UGameSparksScriptData* PropertySet = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasTags = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Tags;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Type;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasW8StoreProductId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString W8StoreProductId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		PropertySet = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSAchievement
{
	GENERATED_USTRUCT_BODY()
	
	FGSAchievement(){}
	
	FGSAchievement(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("description")){
		HasDescription = true;
			Description = wrappedData.GetString("description").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("earned")){
		HasEarned = true;
			Earned = wrappedData.GetBoolean("earned").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("name")){
		HasName = true;
			Name = wrappedData.GetString("name").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("propertySet")){
		HasPropertySet = true;
			PropertySet = NewObject<UGameSparksScriptData>();PropertySet->SetGSData(wrappedData.GetGSDataObject("propertySet").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("shortCode")){
		HasShortCode = true;
			ShortCode = wrappedData.GetString("shortCode").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasDescription = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	FString Description;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasEarned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool Earned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	FString Name;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasPropertySet = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	UGameSparksScriptData* PropertySet = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	bool HasShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|")
	FString ShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		PropertySet = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeType
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeType(){}
	
	FGSChallengeType(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeShortCode")){
		HasChallengeShortCode = true;
			ChallengeShortCode = wrappedData.GetString("challengeShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("description")){
		HasDescription = true;
			Description = wrappedData.GetString("description").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("getleaderboardName")){
		HasGetleaderboardName = true;
			GetleaderboardName = wrappedData.GetString("getleaderboardName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("name")){
		HasName = true;
			Name = wrappedData.GetString("name").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("tags")){
		HasTags = true;
			Tags = wrappedData.GetString("tags").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasChallengeShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString ChallengeShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasDescription = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Description;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasGetleaderboardName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString GetleaderboardName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Name;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	bool HasTags = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Helper")
	FString Tags;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};


USTRUCT(BlueprintType)
struct FGSAcceptChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSAcceptChallengeResponse(){}
	
	FGSAcceptChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstanceId")){
		HasChallengeInstanceId = true;
			ChallengeInstanceId = wrappedData.GetString("challengeInstanceId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallengeInstanceId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString ChallengeInstanceId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSAccountDetailsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSAccountDetailsResponse(){}
	
	FGSAccountDetailsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("achievements")){
		HasAchievements = true;
			for(int i=0; i < wrappedData.GetStringList("achievements").size(); i++){
				FString Achievements_tmp = wrappedData.GetStringList("achievements")[i].c_str();
				Achievements.Add(Achievements_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("currency1")){
		HasCurrency1 = true;
			Currency1 = wrappedData.GetNumber("currency1").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency2")){
		HasCurrency2 = true;
			Currency2 = wrappedData.GetNumber("currency2").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency3")){
		HasCurrency3 = true;
			Currency3 = wrappedData.GetNumber("currency3").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency4")){
		HasCurrency4 = true;
			Currency4 = wrappedData.GetNumber("currency4").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency5")){
		HasCurrency5 = true;
			Currency5 = wrappedData.GetNumber("currency5").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency6")){
		HasCurrency6 = true;
			Currency6 = wrappedData.GetNumber("currency6").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("displayName")){
		HasDisplayName = true;
			DisplayName = wrappedData.GetString("displayName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("externalIds")){
		HasExternalIds = true;
			ExternalIds = NewObject<UGameSparksScriptData>();ExternalIds->SetGSData(wrappedData.GetGSDataObject("externalIds").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("location")){
		HasLocation = true;
			Location = FGSLocation(wrappedData.GetGSDataObject("location").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("reservedCurrency1")){
		HasReservedCurrency1 = true;
			ReservedCurrency1 = NewObject<UGameSparksScriptData>();ReservedCurrency1->SetGSData(wrappedData.GetGSDataObject("reservedCurrency1").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("reservedCurrency2")){
		HasReservedCurrency2 = true;
			ReservedCurrency2 = NewObject<UGameSparksScriptData>();ReservedCurrency2->SetGSData(wrappedData.GetGSDataObject("reservedCurrency2").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("reservedCurrency3")){
		HasReservedCurrency3 = true;
			ReservedCurrency3 = NewObject<UGameSparksScriptData>();ReservedCurrency3->SetGSData(wrappedData.GetGSDataObject("reservedCurrency3").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("reservedCurrency4")){
		HasReservedCurrency4 = true;
			ReservedCurrency4 = NewObject<UGameSparksScriptData>();ReservedCurrency4->SetGSData(wrappedData.GetGSDataObject("reservedCurrency4").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("reservedCurrency5")){
		HasReservedCurrency5 = true;
			ReservedCurrency5 = NewObject<UGameSparksScriptData>();ReservedCurrency5->SetGSData(wrappedData.GetGSDataObject("reservedCurrency5").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("reservedCurrency6")){
		HasReservedCurrency6 = true;
			ReservedCurrency6 = NewObject<UGameSparksScriptData>();ReservedCurrency6->SetGSData(wrappedData.GetGSDataObject("reservedCurrency6").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("userId")){
		HasUserId = true;
			UserId = wrappedData.GetString("userId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("virtualGoods")){
		HasVirtualGoods = true;
			VirtualGoods = NewObject<UGameSparksScriptData>();VirtualGoods->SetGSData(wrappedData.GetGSDataObject("virtualGoods").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasAchievements = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	TArray<FString> Achievements;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency1 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	int32 Currency1;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency2 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	int32 Currency2;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency3 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	int32 Currency3;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency4 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	int32 Currency4;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency5 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	int32 Currency5;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency6 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	int32 Currency6;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasDisplayName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString DisplayName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasExternalIds = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ExternalIds = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasLocation = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FGSLocation Location;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasReservedCurrency1 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ReservedCurrency1 = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasReservedCurrency2 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ReservedCurrency2 = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasReservedCurrency3 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ReservedCurrency3 = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasReservedCurrency4 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ReservedCurrency4 = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasReservedCurrency5 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ReservedCurrency5 = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasReservedCurrency6 = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ReservedCurrency6 = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasUserId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString UserId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasVirtualGoods = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* VirtualGoods = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		ExternalIds = nullptr;
		ReservedCurrency1 = nullptr;
		ReservedCurrency2 = nullptr;
		ReservedCurrency3 = nullptr;
		ReservedCurrency4 = nullptr;
		ReservedCurrency5 = nullptr;
		ReservedCurrency6 = nullptr;
		VirtualGoods = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSAnalyticsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSAnalyticsResponse(){}
	
	FGSAnalyticsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Analytics")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Analytics")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Analytics")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Analytics")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Analytics")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSAroundMeLeaderboardResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSAroundMeLeaderboardResponse(){}
	
	FGSAroundMeLeaderboardResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstanceId")){
		HasChallengeInstanceId = true;
			ChallengeInstanceId = wrappedData.GetString("challengeInstanceId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("data")){
		HasData = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("data").size(); i++){
				FGSLeaderboardData Data_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("data")[i]);
				Data.Add(Data_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("first")){
		HasFirst = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("first").size(); i++){
				FGSLeaderboardData First_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("first")[i]);
				First.Add(First_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("last")){
		HasLast = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("last").size(); i++){
				FGSLeaderboardData Last_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("last")[i]);
				Last.Add(Last_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("leaderboardShortCode")){
		HasLeaderboardShortCode = true;
			LeaderboardShortCode = wrappedData.GetString("leaderboardShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("social")){
		HasSocial = true;
			Social = wrappedData.GetBoolean("social").GetValue();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasChallengeInstanceId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString ChallengeInstanceId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> Data;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasFirst = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> First;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLast = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> Last;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSocial = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool Social;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSAuthenticationResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSAuthenticationResponse(){}
	
	FGSAuthenticationResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("authToken")){
		HasAuthToken = true;
			AuthToken = wrappedData.GetString("authToken").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("displayName")){
		HasDisplayName = true;
			DisplayName = wrappedData.GetString("displayName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("newPlayer")){
		HasNewPlayer = true;
			NewPlayer = wrappedData.GetBoolean("newPlayer").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("switchSummary")){
		HasSwitchSummary = true;
			SwitchSummary = FGSPlayer(wrappedData.GetGSDataObject("switchSummary").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("userId")){
		HasUserId = true;
			UserId = wrappedData.GetString("userId").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasAuthToken = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString AuthToken;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasDisplayName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString DisplayName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasNewPlayer = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool NewPlayer;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasSwitchSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FGSPlayer SwitchSummary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasUserId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString UserId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSBuyVirtualGoodResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSBuyVirtualGoodResponse(){}
	
	FGSBuyVirtualGoodResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("boughtItems")){
		HasBoughtItems = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("boughtItems").size(); i++){
				FGSBoughtitem BoughtItems_tmp = FGSBoughtitem(wrappedData.GetGSDataObjectList("boughtItems")[i]);
				BoughtItems.Add(BoughtItems_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("currency1Added")){
		HasCurrency1Added = true;
			Currency1Added = wrappedData.GetNumber("currency1Added").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency2Added")){
		HasCurrency2Added = true;
			Currency2Added = wrappedData.GetNumber("currency2Added").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency3Added")){
		HasCurrency3Added = true;
			Currency3Added = wrappedData.GetNumber("currency3Added").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency4Added")){
		HasCurrency4Added = true;
			Currency4Added = wrappedData.GetNumber("currency4Added").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency5Added")){
		HasCurrency5Added = true;
			Currency5Added = wrappedData.GetNumber("currency5Added").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency6Added")){
		HasCurrency6Added = true;
			Currency6Added = wrappedData.GetNumber("currency6Added").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currencyConsumed")){
		HasCurrencyConsumed = true;
			CurrencyConsumed = wrappedData.GetNumber("currencyConsumed").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currencyType")){
		HasCurrencyType = true;
			CurrencyType = wrappedData.GetNumber("currencyType").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasBoughtItems = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	TArray<FGSBoughtitem> BoughtItems;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrency1Added = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 Currency1Added;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrency2Added = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 Currency2Added;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrency3Added = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 Currency3Added;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrency4Added = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 Currency4Added;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrency5Added = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 Currency5Added;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrency6Added = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 Currency6Added;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrencyConsumed = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 CurrencyConsumed;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasCurrencyType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	int32 CurrencyType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChangeUserDetailsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSChangeUserDetailsResponse(){}
	
	FGSChangeUserDetailsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChatOnChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSChatOnChallengeResponse(){}
	
	FGSChatOnChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstanceId")){
		HasChallengeInstanceId = true;
			ChallengeInstanceId = wrappedData.GetString("challengeInstanceId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallengeInstanceId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString ChallengeInstanceId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSConsumeVirtualGoodResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSConsumeVirtualGoodResponse(){}
	
	FGSConsumeVirtualGoodResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSCreateChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSCreateChallengeResponse(){}
	
	FGSCreateChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSCreateTeamResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSCreateTeamResponse(){}
	
	FGSCreateTeamResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("members")){
		HasMembers = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("members").size(); i++){
				FGSPlayer Members_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("members")[i]);
				Members.Add(Members_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("owner")){
		HasOwner = true;
			Owner = FGSPlayer(wrappedData.GetGSDataObject("owner").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("teamId")){
		HasTeamId = true;
			TeamId = wrappedData.GetString("teamId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamType")){
		HasTeamType = true;
			TeamType = wrappedData.GetString("teamType").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMembers = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	TArray<FGSPlayer> Members;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasOwner = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FGSPlayer Owner;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSDeclineChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSDeclineChallengeResponse(){}
	
	FGSDeclineChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstanceId")){
		HasChallengeInstanceId = true;
			ChallengeInstanceId = wrappedData.GetString("challengeInstanceId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallengeInstanceId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString ChallengeInstanceId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSDismissMessageResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSDismissMessageResponse(){}
	
	FGSDismissMessageResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSDropTeamResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSDropTeamResponse(){}
	
	FGSDropTeamResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("members")){
		HasMembers = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("members").size(); i++){
				FGSPlayer Members_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("members")[i]);
				Members.Add(Members_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("owner")){
		HasOwner = true;
			Owner = FGSPlayer(wrappedData.GetGSDataObject("owner").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("teamId")){
		HasTeamId = true;
			TeamId = wrappedData.GetString("teamId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamType")){
		HasTeamType = true;
			TeamType = wrappedData.GetString("teamType").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMembers = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	TArray<FGSPlayer> Members;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasOwner = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FGSPlayer Owner;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSEndSessionResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSEndSessionResponse(){}
	
	FGSEndSessionResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSFindChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSFindChallengeResponse(){}
	
	FGSFindChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstances")){
		HasChallengeInstances = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("challengeInstances").size(); i++){
				FGSChallenge ChallengeInstances_tmp = FGSChallenge(wrappedData.GetGSDataObjectList("challengeInstances")[i]);
				ChallengeInstances.Add(ChallengeInstances_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallengeInstances = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	TArray<FGSChallenge> ChallengeInstances;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSFindMatchResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSFindMatchResponse(){}
	
	FGSFindMatchResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("accessToken")){
		HasAccessToken = true;
			AccessToken = wrappedData.GetString("accessToken").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("host")){
		HasHost = true;
			Host = wrappedData.GetString("host").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("matchId")){
		HasMatchId = true;
			MatchId = wrappedData.GetString("matchId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("opponents")){
		HasOpponents = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("opponents").size(); i++){
				FGSPlayer Opponents_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("opponents")[i]);
				Opponents.Add(Opponents_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("peerId")){
		HasPeerId = true;
			PeerId = wrappedData.GetNumber("peerId").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("playerId")){
		HasPlayerId = true;
			PlayerId = wrappedData.GetString("playerId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("port")){
		HasPort = true;
			Port = wrappedData.GetNumber("port").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasAccessToken = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString AccessToken;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasHost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Host;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMatchId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MatchId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasOpponents = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	TArray<FGSPlayer> Opponents;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasPeerId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 PeerId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasPlayerId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString PlayerId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasPort = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Port;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGameSparksErrorResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGameSparksErrorResponse(){}
	
	FGSGameSparksErrorResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetChallengeResponse(){}
	
	FGSGetChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetDownloadableResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetDownloadableResponse(){}
	
	FGSGetDownloadableResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("lastModified")){
		HasLastModified = true;
			LastModified = wrappedData.GetString("lastModified").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("shortCode")){
		HasShortCode = true;
			ShortCode = wrappedData.GetString("shortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("size")){
		HasSize = true;
			Size = wrappedData.GetNumber("size").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("url")){
		HasUrl = true;
			Url = wrappedData.GetString("url").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasLastModified = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString LastModified;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString ShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasSize = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	int32 Size;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasUrl = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Url;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetLeaderboardEntriesResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetLeaderboardEntriesResponse(){}
	
	FGSGetLeaderboardEntriesResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("results")){
		HasResults = true;
			Results = NewObject<UGameSparksScriptData>();Results->SetGSData(wrappedData.GetGSDataObject("results").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasResults = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* Results = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		Results = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetMessageResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetMessageResponse(){}
	
	FGSGetMessageResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = NewObject<UGameSparksScriptData>();Message->SetGSData(wrappedData.GetGSDataObject("message").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Message = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		Message = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetMyTeamsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetMyTeamsResponse(){}
	
	FGSGetMyTeamsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("teams")){
		HasTeams = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("teams").size(); i++){
				FGSTeam Teams_tmp = FGSTeam(wrappedData.GetGSDataObjectList("teams")[i]);
				Teams.Add(Teams_tmp);
            }
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeams = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	TArray<FGSTeam> Teams;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetPropertyResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetPropertyResponse(){}
	
	FGSGetPropertyResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("property")){
		HasProperty = true;
			Property = NewObject<UGameSparksScriptData>();Property->SetGSData(wrappedData.GetGSDataObject("property").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasProperty = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Property = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		Property = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetPropertySetResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetPropertySetResponse(){}
	
	FGSGetPropertySetResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("propertySet")){
		HasPropertySet = true;
			PropertySet = NewObject<UGameSparksScriptData>();PropertySet->SetGSData(wrappedData.GetGSDataObject("propertySet").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasPropertySet = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* PropertySet = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		PropertySet = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetRunningTotalsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetRunningTotalsResponse(){}
	
	FGSGetRunningTotalsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("runningTotals")){
		HasRunningTotals = true;
			RunningTotals = NewObject<UGameSparksScriptData>();RunningTotals->SetGSData(wrappedData.GetGSDataObject("runningTotals").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRunningTotals = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* RunningTotals = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		RunningTotals = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetTeamResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetTeamResponse(){}
	
	FGSGetTeamResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("members")){
		HasMembers = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("members").size(); i++){
				FGSPlayer Members_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("members")[i]);
				Members.Add(Members_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("owner")){
		HasOwner = true;
			Owner = FGSPlayer(wrappedData.GetGSDataObject("owner").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("teamId")){
		HasTeamId = true;
			TeamId = wrappedData.GetString("teamId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamType")){
		HasTeamType = true;
			TeamType = wrappedData.GetString("teamType").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMembers = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	TArray<FGSPlayer> Members;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasOwner = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FGSPlayer Owner;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetUploadUrlResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetUploadUrlResponse(){}
	
	FGSGetUploadUrlResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("url")){
		HasUrl = true;
			Url = wrappedData.GetString("url").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasUrl = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Url;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGetUploadedResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSGetUploadedResponse(){}
	
	FGSGetUploadedResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("size")){
		HasSize = true;
			Size = wrappedData.GetNumber("size").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("url")){
		HasUrl = true;
			Url = wrappedData.GetString("url").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasSize = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	int32 Size;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasUrl = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Url;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSJoinChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSJoinChallengeResponse(){}
	
	FGSJoinChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSJoinTeamResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSJoinTeamResponse(){}
	
	FGSJoinTeamResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("members")){
		HasMembers = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("members").size(); i++){
				FGSPlayer Members_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("members")[i]);
				Members.Add(Members_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("owner")){
		HasOwner = true;
			Owner = FGSPlayer(wrappedData.GetGSDataObject("owner").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("teamId")){
		HasTeamId = true;
			TeamId = wrappedData.GetString("teamId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamType")){
		HasTeamType = true;
			TeamType = wrappedData.GetString("teamType").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMembers = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	TArray<FGSPlayer> Members;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasOwner = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FGSPlayer Owner;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSLeaderboardDataResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSLeaderboardDataResponse(){}
	
	FGSLeaderboardDataResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstanceId")){
		HasChallengeInstanceId = true;
			ChallengeInstanceId = wrappedData.GetString("challengeInstanceId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("data")){
		HasData = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("data").size(); i++){
				FGSLeaderboardData Data_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("data")[i]);
				Data.Add(Data_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("first")){
		HasFirst = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("first").size(); i++){
				FGSLeaderboardData First_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("first")[i]);
				First.Add(First_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("last")){
		HasLast = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("last").size(); i++){
				FGSLeaderboardData Last_tmp = FGSLeaderboardData(wrappedData.GetGSDataObjectList("last")[i]);
				Last.Add(Last_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("leaderboardShortCode")){
		HasLeaderboardShortCode = true;
			LeaderboardShortCode = wrappedData.GetString("leaderboardShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasChallengeInstanceId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString ChallengeInstanceId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> Data;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasFirst = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> First;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLast = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboardData> Last;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSLeaveTeamResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSLeaveTeamResponse(){}
	
	FGSLeaveTeamResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("members")){
		HasMembers = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("members").size(); i++){
				FGSPlayer Members_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("members")[i]);
				Members.Add(Members_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("owner")){
		HasOwner = true;
			Owner = FGSPlayer(wrappedData.GetGSDataObject("owner").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("teamId")){
		HasTeamId = true;
			TeamId = wrappedData.GetString("teamId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamType")){
		HasTeamType = true;
			TeamType = wrappedData.GetString("teamType").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMembers = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	TArray<FGSPlayer> Members;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasOwner = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FGSPlayer Owner;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListAchievementsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListAchievementsResponse(){}
	
	FGSListAchievementsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("achievements")){
		HasAchievements = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("achievements").size(); i++){
				FGSAchievement Achievements_tmp = FGSAchievement(wrappedData.GetGSDataObjectList("achievements")[i]);
				Achievements.Add(Achievements_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasAchievements = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	TArray<FGSAchievement> Achievements;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListChallengeResponse(){}
	
	FGSListChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstances")){
		HasChallengeInstances = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("challengeInstances").size(); i++){
				FGSChallenge ChallengeInstances_tmp = FGSChallenge(wrappedData.GetGSDataObjectList("challengeInstances")[i]);
				ChallengeInstances.Add(ChallengeInstances_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallengeInstances = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	TArray<FGSChallenge> ChallengeInstances;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListChallengeTypeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListChallengeTypeResponse(){}
	
	FGSListChallengeTypeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeTemplates")){
		HasChallengeTemplates = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("challengeTemplates").size(); i++){
				FGSChallengeType ChallengeTemplates_tmp = FGSChallengeType(wrappedData.GetGSDataObjectList("challengeTemplates")[i]);
				ChallengeTemplates.Add(ChallengeTemplates_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallengeTemplates = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	TArray<FGSChallengeType> ChallengeTemplates;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListGameFriendsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListGameFriendsResponse(){}
	
	FGSListGameFriendsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("friends")){
		HasFriends = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("friends").size(); i++){
				FGSPlayer Friends_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("friends")[i]);
				Friends.Add(Friends_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasFriends = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	TArray<FGSPlayer> Friends;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListInviteFriendsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListInviteFriendsResponse(){}
	
	FGSListInviteFriendsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("friends")){
		HasFriends = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("friends").size(); i++){
				FGSInvitableFriend Friends_tmp = FGSInvitableFriend(wrappedData.GetGSDataObjectList("friends")[i]);
				Friends.Add(Friends_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasFriends = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	TArray<FGSInvitableFriend> Friends;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListLeaderboardsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListLeaderboardsResponse(){}
	
	FGSListLeaderboardsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("leaderboards")){
		HasLeaderboards = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("leaderboards").size(); i++){
				FGSLeaderboard Leaderboards_tmp = FGSLeaderboard(wrappedData.GetGSDataObjectList("leaderboards")[i]);
				Leaderboards.Add(Leaderboards_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboards = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	TArray<FGSLeaderboard> Leaderboards;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListMessageResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListMessageResponse(){}
	
	FGSListMessageResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("messageList")){
		HasMessageList = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("messageList").size(); i++){
				UGameSparksScriptData* MessageList_tmp = NewObject<UGameSparksScriptData>();MessageList_tmp->SetGSData(wrappedData.GetGSDataObjectList("messageList")[i]);
				MessageList.Add(MessageList_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasMessageList = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	TArray<UGameSparksScriptData*> MessageList;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListMessageSummaryResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListMessageSummaryResponse(){}
	
	FGSListMessageSummaryResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("messageList")){
		HasMessageList = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("messageList").size(); i++){
				UGameSparksScriptData* MessageList_tmp = NewObject<UGameSparksScriptData>();MessageList_tmp->SetGSData(wrappedData.GetGSDataObjectList("messageList")[i]);
				MessageList.Add(MessageList_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasMessageList = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	TArray<UGameSparksScriptData*> MessageList;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListTeamChatResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListTeamChatResponse(){}
	
	FGSListTeamChatResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSListVirtualGoodsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSListVirtualGoodsResponse(){}
	
	FGSListVirtualGoodsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("virtualGoods")){
		HasVirtualGoods = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("virtualGoods").size(); i++){
				FGSVirtualGood VirtualGoods_tmp = FGSVirtualGood(wrappedData.GetGSDataObjectList("virtualGoods")[i]);
				VirtualGoods.Add(VirtualGoods_tmp);
            }
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	bool HasVirtualGoods = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Store")
	TArray<FGSVirtualGood> VirtualGoods;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSLogChallengeEventResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSLogChallengeEventResponse(){}
	
	FGSLogChallengeEventResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSLogEventResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSLogEventResponse(){}
	
	FGSLogEventResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSMatchDetailsResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSMatchDetailsResponse(){}
	
	FGSMatchDetailsResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("accessToken")){
		HasAccessToken = true;
			AccessToken = wrappedData.GetString("accessToken").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("host")){
		HasHost = true;
			Host = wrappedData.GetString("host").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("matchId")){
		HasMatchId = true;
			MatchId = wrappedData.GetString("matchId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("opponents")){
		HasOpponents = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("opponents").size(); i++){
				FGSPlayer Opponents_tmp = FGSPlayer(wrappedData.GetGSDataObjectList("opponents")[i]);
				Opponents.Add(Opponents_tmp);
            }
		}
		
		
	if(wrappedData.ContainsKey("peerId")){
		HasPeerId = true;
			PeerId = wrappedData.GetNumber("peerId").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("playerId")){
		HasPlayerId = true;
			PlayerId = wrappedData.GetString("playerId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("port")){
		HasPort = true;
			Port = wrappedData.GetNumber("port").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasAccessToken = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString AccessToken;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasHost = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Host;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMatchId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MatchId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasOpponents = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	TArray<FGSPlayer> Opponents;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasPeerId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 PeerId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasPlayerId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString PlayerId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasPort = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Port;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSPushRegistrationResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSPushRegistrationResponse(){}
	
	FGSPushRegistrationResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("registrationId")){
		HasRegistrationId = true;
			RegistrationId = wrappedData.GetString("registrationId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRegistrationId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RegistrationId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSRegistrationResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSRegistrationResponse(){}
	
	FGSRegistrationResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("authToken")){
		HasAuthToken = true;
			AuthToken = wrappedData.GetString("authToken").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("displayName")){
		HasDisplayName = true;
			DisplayName = wrappedData.GetString("displayName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("newPlayer")){
		HasNewPlayer = true;
			NewPlayer = wrappedData.GetBoolean("newPlayer").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("switchSummary")){
		HasSwitchSummary = true;
			SwitchSummary = FGSPlayer(wrappedData.GetGSDataObject("switchSummary").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("userId")){
		HasUserId = true;
			UserId = wrappedData.GetString("userId").GetValue().c_str();
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasAuthToken = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString AuthToken;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasDisplayName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString DisplayName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasNewPlayer = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool NewPlayer;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasSwitchSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FGSPlayer SwitchSummary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	bool HasUserId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
	FString UserId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSSendFriendMessageResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSSendFriendMessageResponse(){}
	
	FGSSendFriendMessageResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSSendTeamChatMessageResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSSendTeamChatMessageResponse(){}
	
	FGSSendTeamChatMessageResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSSocialDisconnectResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSSocialDisconnectResponse(){}
	
	FGSSocialDisconnectResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSSocialStatusResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSSocialStatusResponse(){}
	
	FGSSocialStatusResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("statuses")){
		HasStatuses = true;
			for(int i=0; i < wrappedData.GetGSDataObjectList("statuses").size(); i++){
				FGSSocialStatus Statuses_tmp = FGSSocialStatus(wrappedData.GetGSDataObjectList("statuses")[i]);
				Statuses.Add(Statuses_tmp);
            }
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasStatuses = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	TArray<FGSSocialStatus> Statuses;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSWithdrawChallengeResponse
{
	GENERATED_USTRUCT_BODY()
	
	FGSWithdrawChallengeResponse(){}
	
	FGSWithdrawChallengeResponse(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challengeInstanceId")){
		HasChallengeInstanceId = true;
			ChallengeInstanceId = wrappedData.GetString("challengeInstanceId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("requestId")){
		HasRequestId = true;
			RequestId = wrappedData.GetString("requestId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		if(wrappedData.ContainsKey("error")){
			Errors = NewObject<UGameSparksScriptData>();Errors->SetGSData(wrappedData.GetGSDataObject("error").GetValue());
    	}
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* Errors = nullptr;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallengeInstanceId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString ChallengeInstanceId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasRequestId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString RequestId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};


USTRUCT(BlueprintType)
struct FGSAchievementEarnedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSAchievementEarnedMessage(){}
	
	FGSAchievementEarnedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("achievementName")){
		HasAchievementName = true;
			AchievementName = wrappedData.GetString("achievementName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("achievementShortCode")){
		HasAchievementShortCode = true;
			AchievementShortCode = wrappedData.GetString("achievementShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("currency1Earned")){
		HasCurrency1Earned = true;
			Currency1Earned = wrappedData.GetString("currency1Earned").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("currency2Earned")){
		HasCurrency2Earned = true;
			Currency2Earned = wrappedData.GetString("currency2Earned").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("currency3Earned")){
		HasCurrency3Earned = true;
			Currency3Earned = wrappedData.GetString("currency3Earned").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("currency4Earned")){
		HasCurrency4Earned = true;
			Currency4Earned = wrappedData.GetString("currency4Earned").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("currency5Earned")){
		HasCurrency5Earned = true;
			Currency5Earned = wrappedData.GetString("currency5Earned").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("currency6Earned")){
		HasCurrency6Earned = true;
			Currency6Earned = wrappedData.GetString("currency6Earned").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("virtualGoodEarned")){
		HasVirtualGoodEarned = true;
			VirtualGoodEarned = wrappedData.GetString("virtualGoodEarned").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasAchievementName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString AchievementName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasAchievementShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString AchievementShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency1Earned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Currency1Earned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency2Earned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Currency2Earned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency3Earned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Currency3Earned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency4Earned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Currency4Earned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency5Earned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Currency5Earned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasCurrency6Earned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Currency6Earned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasVirtualGoodEarned = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString VirtualGoodEarned;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeAcceptedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeAcceptedMessage(){}
	
	FGSChallengeAcceptedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeChangedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeChangedMessage(){}
	
	FGSChallengeChangedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("leaderboardData")){
		HasLeaderboardData = true;
			LeaderboardData = FGSLeaderboardData(wrappedData.GetGSDataObject("leaderboardData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasLeaderboardData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSLeaderboardData LeaderboardData;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeChatMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeChatMessage(){}
	
	FGSChallengeChatMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeDeclinedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeDeclinedMessage(){}
	
	FGSChallengeDeclinedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeDrawnMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeDrawnMessage(){}
	
	FGSChallengeDrawnMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("leaderboardData")){
		HasLeaderboardData = true;
			LeaderboardData = FGSLeaderboardData(wrappedData.GetGSDataObject("leaderboardData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasLeaderboardData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSLeaderboardData LeaderboardData;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeExpiredMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeExpiredMessage(){}
	
	FGSChallengeExpiredMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeIssuedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeIssuedMessage(){}
	
	FGSChallengeIssuedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeJoinedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeJoinedMessage(){}
	
	FGSChallengeJoinedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeLapsedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeLapsedMessage(){}
	
	FGSChallengeLapsedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeLostMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeLostMessage(){}
	
	FGSChallengeLostMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("leaderboardData")){
		HasLeaderboardData = true;
			LeaderboardData = FGSLeaderboardData(wrappedData.GetGSDataObject("leaderboardData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("winnerName")){
		HasWinnerName = true;
			WinnerName = wrappedData.GetString("winnerName").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasLeaderboardData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSLeaderboardData LeaderboardData;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWinnerName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString WinnerName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeStartedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeStartedMessage(){}
	
	FGSChallengeStartedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeTurnTakenMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeTurnTakenMessage(){}
	
	FGSChallengeTurnTakenMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeWaitingMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeWaitingMessage(){}
	
	FGSChallengeWaitingMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeWithdrawnMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeWithdrawnMessage(){}
	
	FGSChallengeWithdrawnMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSChallengeWonMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSChallengeWonMessage(){}
	
	FGSChallengeWonMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("challenge")){
		HasChallenge = true;
			Challenge = FGSChallenge(wrappedData.GetGSDataObject("challenge").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("currency1Won")){
		HasCurrency1Won = true;
			Currency1Won = wrappedData.GetNumber("currency1Won").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency2Won")){
		HasCurrency2Won = true;
			Currency2Won = wrappedData.GetNumber("currency2Won").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency3Won")){
		HasCurrency3Won = true;
			Currency3Won = wrappedData.GetNumber("currency3Won").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency4Won")){
		HasCurrency4Won = true;
			Currency4Won = wrappedData.GetNumber("currency4Won").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency5Won")){
		HasCurrency5Won = true;
			Currency5Won = wrappedData.GetNumber("currency5Won").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("currency6Won")){
		HasCurrency6Won = true;
			Currency6Won = wrappedData.GetNumber("currency6Won").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardData")){
		HasLeaderboardData = true;
			LeaderboardData = FGSLeaderboardData(wrappedData.GetGSDataObject("leaderboardData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("winnerName")){
		HasWinnerName = true;
			WinnerName = wrappedData.GetString("winnerName").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasChallenge = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSChallenge Challenge;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasCurrency1Won = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Currency1Won;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasCurrency2Won = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Currency2Won;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasCurrency3Won = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Currency3Won;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasCurrency4Won = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Currency4Won;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasCurrency5Won = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Currency5Won;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasCurrency6Won = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	int32 Currency6Won;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasLeaderboardData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FGSLeaderboardData LeaderboardData;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	bool HasWinnerName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Challenges")
	FString WinnerName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSFriendMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSFriendMessage(){}
	
	FGSFriendMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("fromId")){
		HasFromId = true;
			FromId = wrappedData.GetString("fromId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasFromId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString FromId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Player")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSGlobalRankChangedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSGlobalRankChangedMessage(){}
	
	FGSGlobalRankChangedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("gameId")){
		HasGameId = true;
			GameId = wrappedData.GetNumber("gameId").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardName")){
		HasLeaderboardName = true;
			LeaderboardName = wrappedData.GetString("leaderboardName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardShortCode")){
		HasLeaderboardShortCode = true;
			LeaderboardShortCode = wrappedData.GetString("leaderboardShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("them")){
		HasThem = true;
			Them = FGSLeaderboardData(wrappedData.GetGSDataObject("them").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("you")){
		HasYou = true;
			You = FGSLeaderboardData(wrappedData.GetGSDataObject("you").GetValue());
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasGameId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 GameId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasThem = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardData Them;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasYou = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardData You;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSNewHighScoreMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSNewHighScoreMessage(){}
	
	FGSNewHighScoreMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("leaderboardData")){
		HasLeaderboardData = true;
			LeaderboardData = FGSLeaderboardData(wrappedData.GetGSDataObject("leaderboardData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("leaderboardName")){
		HasLeaderboardName = true;
			LeaderboardName = wrappedData.GetString("leaderboardName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardShortCode")){
		HasLeaderboardShortCode = true;
			LeaderboardShortCode = wrappedData.GetString("leaderboardShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("rankDetails")){
		HasRankDetails = true;
			RankDetails = FGSLeaderboardRankDetails(wrappedData.GetGSDataObject("rankDetails").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardData LeaderboardData;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasRankDetails = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardRankDetails RankDetails;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSNewTeamScoreMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSNewTeamScoreMessage(){}
	
	FGSNewTeamScoreMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("leaderboardData")){
		HasLeaderboardData = true;
			LeaderboardData = FGSLeaderboardData(wrappedData.GetGSDataObject("leaderboardData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("leaderboardName")){
		HasLeaderboardName = true;
			LeaderboardName = wrappedData.GetString("leaderboardName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardShortCode")){
		HasLeaderboardShortCode = true;
			LeaderboardShortCode = wrappedData.GetString("leaderboardShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("rankDetails")){
		HasRankDetails = true;
			RankDetails = FGSLeaderboardRankDetails(wrappedData.GetGSDataObject("rankDetails").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardData LeaderboardData;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasRankDetails = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardRankDetails RankDetails;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSScriptMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSScriptMessage(){}
	
	FGSScriptMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("data")){
		HasData = true;
			Data = NewObject<UGameSparksScriptData>();Data->SetGSData(wrappedData.GetGSDataObject("data").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("extCode")){
		HasExtCode = true;
			ExtCode = wrappedData.GetString("extCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* Data = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasExtCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString ExtCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		Data = nullptr;
	}
	
};

USTRUCT(BlueprintType)
struct FGSSessionTerminatedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSSessionTerminatedMessage(){}
	
	FGSSessionTerminatedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("authToken")){
		HasAuthToken = true;
			AuthToken = wrappedData.GetString("authToken").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasAuthToken = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString AuthToken;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSSocialRankChangedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSSocialRankChangedMessage(){}
	
	FGSSocialRankChangedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("gameId")){
		HasGameId = true;
			GameId = wrappedData.GetNumber("gameId").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardName")){
		HasLeaderboardName = true;
			LeaderboardName = wrappedData.GetString("leaderboardName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardShortCode")){
		HasLeaderboardShortCode = true;
			LeaderboardShortCode = wrappedData.GetString("leaderboardShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("them")){
		HasThem = true;
			Them = FGSLeaderboardData(wrappedData.GetGSDataObject("them").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("you")){
		HasYou = true;
			You = FGSLeaderboardData(wrappedData.GetGSDataObject("you").GetValue());
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasGameId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	int32 GameId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasLeaderboardShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString LeaderboardShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasThem = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardData Them;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	bool HasYou = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Leaderboards")
	FGSLeaderboardData You;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSTeamChatMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSTeamChatMessage(){}
	
	FGSTeamChatMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("chatMessageId")){
		HasChatMessageId = true;
			ChatMessageId = wrappedData.GetString("chatMessageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("fromId")){
		HasFromId = true;
			FromId = wrappedData.GetString("fromId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("message")){
		HasMessage = true;
			Message = wrappedData.GetString("message").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("ownerId")){
		HasOwnerId = true;
			OwnerId = wrappedData.GetString("ownerId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamId")){
		HasTeamId = true;
			TeamId = wrappedData.GetString("teamId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("teamType")){
		HasTeamType = true;
			TeamType = wrappedData.GetString("teamType").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("who")){
		HasWho = true;
			Who = wrappedData.GetString("who").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasChatMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString ChatMessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasFromId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString FromId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMessage = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString Message;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasOwnerId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString OwnerId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTeamType = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString TeamType;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasWho = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString Who;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSTeamRankChangedMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSTeamRankChangedMessage(){}
	
	FGSTeamRankChangedMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("gameId")){
		HasGameId = true;
			GameId = wrappedData.GetNumber("gameId").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardName")){
		HasLeaderboardName = true;
			LeaderboardName = wrappedData.GetString("leaderboardName").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("leaderboardShortCode")){
		HasLeaderboardShortCode = true;
			LeaderboardShortCode = wrappedData.GetString("leaderboardShortCode").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("them")){
		HasThem = true;
			Them = FGSLeaderboardData(wrappedData.GetGSDataObject("them").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("you")){
		HasYou = true;
			You = FGSLeaderboardData(wrappedData.GetGSDataObject("you").GetValue());
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasGameId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	int32 GameId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasLeaderboardName = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString LeaderboardName;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasLeaderboardShortCode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString LeaderboardShortCode;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasThem = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FGSLeaderboardData Them;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	bool HasYou = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Teams")
	FGSLeaderboardData You;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
	}
	
};

USTRUCT(BlueprintType)
struct FGSUploadCompleteMessage
{
	GENERATED_USTRUCT_BODY()
	
	FGSUploadCompleteMessage(){}
	
	FGSUploadCompleteMessage(const GameSparks::Core::GSData& wrappedData){
	
		
	if(wrappedData.ContainsKey("messageId")){
		HasMessageId = true;
			MessageId = wrappedData.GetString("messageId").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("notification")){
		HasNotification = true;
			Notification = wrappedData.GetBoolean("notification").GetValue();
		}
		
		
	if(wrappedData.ContainsKey("scriptData")){
		HasScriptData = true;
			ScriptData = NewObject<UGameSparksScriptData>();ScriptData->SetGSData(wrappedData.GetGSDataObject("scriptData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("subTitle")){
		HasSubTitle = true;
			SubTitle = wrappedData.GetString("subTitle").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("summary")){
		HasSummary = true;
			Summary = wrappedData.GetString("summary").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("title")){
		HasTitle = true;
			Title = wrappedData.GetString("title").GetValue().c_str();
		}
		
		
	if(wrappedData.ContainsKey("uploadData")){
		HasUploadData = true;
			UploadData = NewObject<UGameSparksScriptData>();UploadData->SetGSData(wrappedData.GetGSDataObject("uploadData").GetValue());
		}
		
		
	if(wrappedData.ContainsKey("uploadId")){
		HasUploadId = true;
			UploadId = wrappedData.GetString("uploadId").GetValue().c_str();
		}
		
	
	    JSONString = wrappedData.GetJSON().c_str();
	}

	
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasMessageId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString MessageId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasNotification = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool Notification;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasScriptData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* ScriptData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasSubTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString SubTitle;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasSummary = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Summary;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasTitle = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString Title;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasUploadData = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	UGameSparksScriptData* UploadData = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	bool HasUploadId = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Misc")
	FString UploadId;
	
	UPROPERTY(BlueprintReadOnly, Category = "GameSparks|Authentication")
    FString JSONString;
	
	
	void Destroy()
	{
		UploadData = nullptr;
	}
	
};



