// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSTypedResponse_h__
#define GSTypedResponse_h__

#pragma once

#include "GSData.h"
#include <GameSparks/GSLeakDetector.h>

namespace GameSparks
{
	namespace Core
	{
		/// base class for all responses
		class GSTypedResponse
		{
			protected:
				 const static gsstl::string SCRIPT_DATA_KEY; ///< the key name of the users script data inside the response object
				 const static gsstl::string ERROR_KEY;       ///< the key name of the server-side errors embedded in this response
				 const static gsstl::string REQUEST_ID_KEY;  ///< the key name of the request id
			public:

				/// construct from GSData
				GSTypedResponse(const GSData& response)
					: m_Response(response)
                    , m_userData()
				{
				}

				/// construct from GSTypedResponse
				GSTypedResponse(const GSTypedResponse& other)
					: m_Response(other.m_Response)
                    , m_userData()
				{

				}

				/// get the response-data as a JSON formated string
				gsstl::string GetJSONString() const
				{
					return m_Response.GetJSON();
				}

				/// accessor for the internal cJSON object associated with this response.
				const cJSON* GetJSONData() const
				{
					return m_Response.GetBaseData();
				}

				/// get the ScriptData associated with this response
				GSData::t_Optional GetScriptData() const
				{
					return m_Response.GetGSDataObject(SCRIPT_DATA_KEY);
				}

				/// returns true, if a server-side error occured, false otherwise.
				bool GetHasErrors() const
				{
					return m_Response.ContainsKey(ERROR_KEY);
				}

				/// return an Optional GSData object containing the errors associated with this response
				GSData::t_Optional GetErrors() const
				{
					return m_Response.GetGSDataObject(ERROR_KEY);
				}

				/// the id of the request that caused this response
				Optional::t_StringOptional GetRequestId() const
				{
					return m_Response.GetString(REQUEST_ID_KEY);
				}

				/// the internal GSData object
				const GSData& GetBaseData() const
				{
					return m_Response;
				}
            
                bool HasUserData() const
                {
                    return m_userData != 0;
                }
            
                void* GetUserData() const
                {
                    return m_userData;
                }
            
				protected:
					GSData m_Response; ///< the wrapped response data
				private:
                    template<typename RequestType, typename ResponseType>
                    friend class GSTypedRequest;
            
                    void* m_userData;
					GS_LEAK_DETECTOR(GSTypedResponse)
		};
	}
}
#endif // GSTypedResponse_h__
