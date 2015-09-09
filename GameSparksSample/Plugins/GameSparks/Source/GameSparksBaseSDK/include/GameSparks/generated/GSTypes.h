#pragma once

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include "../GSTypedResponse.h"

namespace GameSparks
{
	namespace Api
	{
		namespace Types
		{

			/*!
			\ingroup Types
			This object represents the result of uploading a file to the GameSparks platform.
			*/
			class UploadData : public  GameSparks::Core::GSTypedResponse
			{
			public:
				UploadData(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				UploadData(const UploadData& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The filename of the file that was uploaded.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetFileName () const
					{
						return m_Response.GetString("fileName");
					}
			/// <summary>
			/// The unique player id of the player that uploaded the file.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
			};

			/*!
			\ingroup Types
			A the details of a social connection
			*/
			class SocialStatus : public  GameSparks::Core::GSTypedResponse
			{
			public:
				SocialStatus(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				SocialStatus(const SocialStatus& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// When the token is still active.
			/// </summary>
					// method type 4
					Optional::t_BoolOptional GetActive () const
					{
						return m_Response.GetBoolean("active");
					}
			/// <summary>
			/// When the token expires (if available).
			/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpires () const
					{
						return m_Response.GetDate("expires");
					}
			/// <summary>
			/// The identifier of the external platform.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetSystemId () const
					{
						return m_Response.GetString("systemId");
					}
			};

			/*!
			\ingroup Types
			A nested object that represents the invitable friend.
			*/
			class InvitableFriend : public  GameSparks::Core::GSTypedResponse
			{
			public:
				InvitableFriend(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				InvitableFriend(const InvitableFriend& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The display name of the External Friend
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The ID of the External Friend
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The profile picture URL of the External Friend
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetProfilePic () const
					{
						return m_Response.GetString("profilePic");
					}
			};

			/*!
			\ingroup Types
			A nested object that represents a player.
			*/
			class Player : public  GameSparks::Core::GSTypedResponse
			{
			public:
				Player(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				Player(const Player& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("getAchievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("getVirtualGoods");
						}
			};

			/*!
			\ingroup Types
			An object representing a player's id and name
			*/
			class PlayerDetail : public  GameSparks::Core::GSTypedResponse
			{
			public:
				PlayerDetail(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				PlayerDetail(const PlayerDetail& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// A player's external identifiers
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// A player's id
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// A player's name
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			};

			/*!
			\ingroup Types
			Location details.
			*/
			class Location : public  GameSparks::Core::GSTypedResponse
			{
			public:
				Location(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				Location(const Location& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The city
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
			/// <summary>
			/// The country
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
			/// <summary>
			/// The latitude
			/// </summary>
					// method type 4
					Optional::t_FloatOptional GetLatitide () const
					{
						return m_Response.GetFloat("latitide");
					}
			/// <summary>
			/// The longditute
			/// </summary>
					// method type 4
					Optional::t_FloatOptional GetLongditute () const
					{
						return m_Response.GetFloat("longditute");
					}
			};

			/*!
			\ingroup Types
			A nested object that represents the team.
			*/
			class Team : public  GameSparks::Core::GSTypedResponse
			{
			public:
				Team(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				Team(const Team& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The team members
			/// </summary>
					// method type 1
					gsstl::vector<Player> GetMembers() const
					{
						gsstl::vector<Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getMembers");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(Player(*it));
						}
						return result; 
					}
			/// <summary>
			/// A summary of the owner
			/// </summary>
					// method type 2
					Player GetOwner() const
					{
						return Player(m_Response.GetGSDataObject("owner").GetValue());
					}
			/// <summary>
			/// The Id of the team
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetTeamId () const
					{
						return m_Response.GetString("teamId");
					}
			/// <summary>
			/// The team type
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetTeamType () const
					{
						return m_Response.GetString("teamType");
					}
			};

			/*!
			\ingroup Types
			Represents the number of turns a player has taken in a turn based challenge.
			*/
			class PlayerTurnCount : public  GameSparks::Core::GSTypedResponse
			{
			public:
				PlayerTurnCount(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				PlayerTurnCount(const PlayerTurnCount& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The number of turns that the player has taken so far during this challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
			/// <summary>
			/// The unique player id.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
			};

			/*!
			\ingroup Types
			A nested object that represents the leaderboard configuration data.
			*/
			class Leaderboard : public  GameSparks::Core::GSTypedResponse
			{
			public:
				Leaderboard(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				Leaderboard(const Leaderboard& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The leaderboard's description.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// The leaderboard's name.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The custom property set configured on this Leaderboard
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetPropertySet () const
					{
						return m_Response.GetGSDataObject("propertySet");
					}
			/// <summary>
			/// The leaderboard's short code.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			};

			/*!
			\ingroup Types
			Leaderboard entry data
			As well as the parameters below there may be others depending on your game's configuration.
			*/
			class LeaderboardData : public  GameSparks::Core::GSTypedResponse
			{
			public:
				LeaderboardData(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				LeaderboardData(const LeaderboardData& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The city where the player was located when they logged this leaderboard entry.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
			/// <summary>
			/// The country code where the player was located when they logged this leaderboard entry.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
			/// <summary>
			/// The players rank.
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The unique leaderboard id.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The players rank.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
			/// <summary>
			/// The unique player id for this leaderboard entry.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
			/// <summary>
			/// The players display name.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
			/// <summary>
			/// The date when this leaderboard entry was created.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
			};

			/*!
			\ingroup Types
			Ranking information.
			*/
			class LeaderboardRankDetails : public  GameSparks::Core::GSTypedResponse
			{
			public:
				LeaderboardRankDetails(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				LeaderboardRankDetails(const LeaderboardRankDetails& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The leaderboard entries of the players friends that were beaten as part of this score submission.
			/// </summary>
					// method type 1
					gsstl::vector<LeaderboardData> GetFriendsPassed() const
					{
						gsstl::vector<LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getFriendsPassed");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(LeaderboardData(*it));
						}
						return result; 
					}
			/// <summary>
			/// The number of entries in this leaderboard.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetGlobalCount () const
					{
						return m_Response.GetLong("globalCount");
					}
			/// <summary>
			/// The Global Rank of the player in this leaderboard before the score was submitted.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetGlobalFrom () const
					{
						return m_Response.GetLong("globalFrom");
					}
			/// <summary>
			/// The old global rank of the player as a percentage of the total number of scores in this leaderboard .
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetGlobalFromPercent () const
					{
						return m_Response.GetLong("globalFromPercent");
					}
			/// <summary>
			/// The Global Rank of the player in this leaderboard after the score was submitted.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetGlobalTo () const
					{
						return m_Response.GetLong("globalTo");
					}
			/// <summary>
			/// The new global rank of the player as a percentage of the total number of scores in this leaderboard .
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetGlobalToPercent () const
					{
						return m_Response.GetLong("globalToPercent");
					}
			/// <summary>
			/// The number of friend entries the player has in this leaderboard.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetSocialCount () const
					{
						return m_Response.GetLong("socialCount");
					}
			/// <summary>
			/// The Social Rank of the player in this leaderboard before the score was submitted.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetSocialFrom () const
					{
						return m_Response.GetLong("socialFrom");
					}
			/// <summary>
			/// The old social rank of the player as a percentage of the total number of friend scores in this leaderboard.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetSocialFromPercent () const
					{
						return m_Response.GetLong("socialFromPercent");
					}
			/// <summary>
			/// The Social Rank of the player in this leaderboard after the score was submitted.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetSocialTo () const
					{
						return m_Response.GetLong("socialTo");
					}
			/// <summary>
			/// The old global rank of the player as a percentage of the total number of friend scores in this leaderboard.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetSocialToPercent () const
					{
						return m_Response.GetLong("socialToPercent");
					}
			/// <summary>
			/// The leaderboard entries of the global players that were beaten as part of this score submission. Requires Top N to be configured on the leaderboard
			/// </summary>
					// method type 1
					gsstl::vector<LeaderboardData> GetTopNPassed() const
					{
						gsstl::vector<LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTopNPassed");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(LeaderboardData(*it));
						}
						return result; 
					}
			};

			/*!
			\ingroup Types
			A nested object that represents a bought item.
			*/
			class Boughtitem : public  GameSparks::Core::GSTypedResponse
			{
			public:
				Boughtitem(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				Boughtitem(const Boughtitem& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The quantity of the bought item
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetQuantity () const
					{
						return m_Response.GetLong("quantity");
					}
			/// <summary>
			/// The short code of the bought item
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			};

			/*!
			\ingroup Types
			A nested object that represents the challenge data.
			*/
			class Challenge : public  GameSparks::Core::GSTypedResponse
			{
			public:
				Challenge(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				Challenge(const Challenge& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
			/// </summary>
					// method type 1
					gsstl::vector<PlayerDetail> GetAccepted() const
					{
						gsstl::vector<PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(PlayerDetail(*it));
						}
						return result; 
					}
			/// <summary>
			/// A unique identifier for this challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
			/// <summary>
			/// The message included in the challenge by the challenging player who created the challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
			/// <summary>
			/// The name of the challenge that this message relates to.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
			/// <summary>
			/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
			/// </summary>
					// method type 1
					gsstl::vector<PlayerDetail> GetChallenged() const
					{
						gsstl::vector<PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(PlayerDetail(*it));
						}
						return result; 
					}
			/// <summary>
			/// Details of the player who issued this challenge.
			/// </summary>
					// method type 2
					PlayerDetail GetChallenger() const
					{
						return PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
			/// <summary>
			/// The amount of type 1 currency that has been wagered on this challenge.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
			/// <summary>
			/// The amount of type 2 currency that has been wagered on this challenge.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
			/// <summary>
			/// The amount of type 3 currency that has been wagered on this challenge.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
			/// <summary>
			/// The amount of type 4 currency that has been wagered on this challenge.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
			/// <summary>
			/// The amount of type 5 currency that has been wagered on this challenge.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
			/// <summary>
			/// The amount of type 6 currency that has been wagered on this challenge.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
			/// <summary>
			/// A list of PlayerDetail objects that represents the players that have declined this challenge.
			/// </summary>
					// method type 1
					gsstl::vector<PlayerDetail> GetDeclined() const
					{
						gsstl::vector<PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(PlayerDetail(*it));
						}
						return result; 
					}
			/// <summary>
			/// The date when the challenge ends.
			/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
			/// <summary>
			/// The latest date that a player can accept the challenge.
			/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
			/// <summary>
			/// The maximum number of turns that this challenge is configured for.
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
			/// <summary>
			/// In a turn based challenge this fields contains the player's id whose turn it is next.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
			/// <summary>
			/// The challenge's short code.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			/// <summary>
			/// The date when the challenge starts.
			/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
			/// <summary>
			/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
			/// <summary>
			/// A collection containing the number of turns taken by each player that has accepted the challenge.
			/// Each turn count is a Long keyed on a String that represents the player's id
			/// </summary>
					// method type 1
					gsstl::vector<PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(PlayerTurnCount(*it));
						}
						return result; 
					}
			};

			/*!
			\ingroup Types
			A nested object that represents the virtual good.
			*/
			class VirtualGood : public  GameSparks::Core::GSTypedResponse
			{
			public:
				VirtualGood(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				VirtualGood(const VirtualGood& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The Windows Phone 8 productId of the item.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetWP8StoreProductId () const
					{
						return m_Response.GetString("WP8StoreProductId");
					}
			/// <summary>
			/// The Amazon Store productId of the item.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetAmazonStoreProductId () const
					{
						return m_Response.GetString("amazonStoreProductId");
					}
			/// <summary>
			/// The Currency1 cost of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency1Cost () const
					{
						return m_Response.GetLong("currency1Cost");
					}
			/// <summary>
			/// The Currency2 cost of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency2Cost () const
					{
						return m_Response.GetLong("currency2Cost");
					}
			/// <summary>
			/// The Currency3 cost of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency3Cost () const
					{
						return m_Response.GetLong("currency3Cost");
					}
			/// <summary>
			/// The Currency4 cost of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency4Cost () const
					{
						return m_Response.GetLong("currency4Cost");
					}
			/// <summary>
			/// The Currency5 cost of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency5Cost () const
					{
						return m_Response.GetLong("currency5Cost");
					}
			/// <summary>
			/// The Currency6 cost of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetCurrency6Cost () const
					{
						return m_Response.GetLong("currency6Cost");
					}
			/// <summary>
			/// The description of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// The google play productId of the item.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetGooglePlayProductId () const
					{
						return m_Response.GetString("googlePlayProductId");
					}
			/// <summary>
			/// The iOS AppStore productId of the item.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetIosAppStoreProductId () const
					{
						return m_Response.GetString("iosAppStoreProductId");
					}
			/// <summary>
			/// The maximum number of the Virtual Good that can be owned at one time
			/// </summary>
					// method type 4
					Optional::t_LongOptional GetMaxQuantity () const
					{
						return m_Response.GetLong("maxQuantity");
					}
			/// <summary>
			/// The name of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The custom property set configured on the item.
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetPropertySet () const
					{
						return m_Response.GetGSDataObject("propertySet");
					}
			/// <summary>
			/// The short code of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			/// <summary>
			/// The tags of the Virtual Good
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetTags () const
					{
						return m_Response.GetString("tags");
					}
			/// <summary>
			/// The type of the virtual good, "VGOOD" or "CURRENCY"
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetType () const
					{
						return m_Response.GetString("type");
					}
			/// <summary>
			/// The Windows 8 productId of the item.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetW8StoreProductId () const
					{
						return m_Response.GetString("w8StoreProductId");
					}
			};

			/*!
			\ingroup Types
			A nested object that represents the achievement data.
			*/
			class Achievement : public  GameSparks::Core::GSTypedResponse
			{
			public:
				Achievement(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				Achievement(const Achievement& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The desciption of the Achievement
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// Whether to current player has earned the achievement
			/// </summary>
					// method type 4
					Optional::t_BoolOptional GetEarned () const
					{
						return m_Response.GetBoolean("earned");
					}
			/// <summary>
			/// The name of the Achievement
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The custom property set configured on this Achievement
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetPropertySet () const
					{
						return m_Response.GetGSDataObject("propertySet");
					}
			/// <summary>
			/// The shortCode of the Achievement
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			};

			/*!
			\ingroup Types
			
			*/
			class ChallengeType : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ChallengeType(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ChallengeType(const ChallengeType& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The shortCode for this challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetChallengeShortCode () const
					{
						return m_Response.GetString("challengeShortCode");
					}
			/// <summary>
			/// The description of this challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// The name of the leaderboard for this challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetGetleaderboardName () const
					{
						return m_Response.GetString("getleaderboardName");
					}
			/// <summary>
			/// The name of this challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The tags for this challenge.
			/// </summary>
					// method type 4
					Optional::t_StringOptional GetTags () const
					{
						return m_Response.GetString("tags");
					}
			};
		}
	}
}


/*!
\addtogroup Types
*/
