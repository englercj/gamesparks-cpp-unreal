#include "GameSparksPrivatePCH.h"
#if defined(GS_USE_EASTL)
#include "EASTL/string.h"


// EASTL expects us to define these, see allocator.h line 194
void* operator new[](size_t size, const char* pName, int flags,
	unsigned debugFlags, const char* file, int line)
{
	return new char[size];
}

void* operator new[](size_t size, size_t alignment, size_t alignmentOffset,
const char* pName, int flags, unsigned debugFlags, const char* file, int line)
{
	return new char[size];
}
// EASTL also wants us to define this (see string.h line 197)
int Vsnprintf8(char* pDestination, size_t n, const char* pFormat, va_list arguments)
{
	#if defined(WINDOWS_32) || defined(WINDOWS_PHONE8)
		return _vsnprintf(pDestination, n, pFormat, arguments);
	#else
		return vsnprintf(pDestination, n, pFormat, arguments);
	#endif
}
#endif // #if defined(GS_USE_EASTL)