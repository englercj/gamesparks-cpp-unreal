#include "GameSparksPrivatePCH.h"

#define UI GET_OF_MY_LAWN

// silence warnings on windows

#if defined(_MSC_VER)
#	if !defined(_CRT_SECURE_NO_WARNINGS)
#		define _CRT_SECURE_NO_WARNINGS
#	endif
#	if !defined(_CRT_SECURE_NO_DEPRECATE)
#		define _CRT_SECURE_NO_DEPRECATE
#	endif
#endif

//dependencies
#if defined(WIN32)
#define _CRTIMP __declspec(dllimport)
_CRTIMP bool __cdecl __uncaught_exception();
#endif

#include <easywsclient.cpp>
#include <timesupport.cpp>
#include <strptime.cpp>

#include <cJSON.cpp>
#include <hmac_sha2.cpp>
#include <sha2.cpp>

#include <GS.cpp>
#include <GSConnection.cpp>
#include <GSData.cpp>
#include <GSDateTime.cpp>
#include <GSIosHelper.mm>
#include <GSMessage.cpp>
#include <GSRequest.cpp>
#include <GSTypedResponse.cpp>
#include <GSUtil.cpp>
#include <IGSPlatform.cpp>

#undef PF_MAX

// so that unreal still includes MinWindows.h
#ifdef _WINDOWS_
#	undef _WINDOWS_
// Undo any Windows defines.
#	undef uint8
#	undef uint16
#	undef uint32
#	undef int32
#	undef float
#	undef MAX_uint8
#	undef MAX_uint16
#	undef MAX_uint32
#	undef MAX_int32
#	undef CDECL
#	undef PF_MAX
#	undef PlaySound
#	undef DrawText
#	undef CaptureStackBackTrace
#	undef MemoryBarrier
#	undef DeleteFile
#	undef MoveFile
#	undef CopyFile
#	undef CreateDirectory
#endif

#undef UI
