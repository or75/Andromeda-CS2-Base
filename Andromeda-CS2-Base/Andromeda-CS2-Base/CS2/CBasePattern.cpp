#include "CBasePattern.hpp"

#include <Common/MemoryEngine.hpp>

CBasePattern::CBasePattern( const char* szPatternName , const char* szPattern , const char* szDll , uint32_t Offset , eBasePatternSearchType Type )
{
	PatternName = szPatternName;
	Pattern = szPattern;
	Dll = szDll;
	dwOffset = Offset;
	m_Type = Type;
}

auto CBasePattern::Search( bool SkipError ) -> bool
{
	if ( m_Type != eBasePatternSearchType::SEARCH_TYPE_PROC )
	{
		pFunction = FindPattern( Dll , Pattern , dwOffset );

		if ( !pFunction )
		{
			if ( !SkipError )
				DEV_LOG( "[error] CBasePattern: %s\n" , PatternName );

			return false;
		}
	}

	if ( m_Type == eBasePatternSearchType::SEARCH_TYPE_PTR )
		pFunction = reinterpret_cast<PVOID>( *reinterpret_cast<intptr_t*>( pFunction ) );
	else if ( m_Type == eBasePatternSearchType::SEARCH_TYPE_CALL )
		pFunction = GetCallAddress( reinterpret_cast<intptr_t>( pFunction ) );
	else if ( m_Type == eBasePatternSearchType::SEARCH_TYPE_PTR2 )
		pFunction = GetPtrAddress<PVOID>( (intptr_t)pFunction );
	else if ( m_Type == eBasePatternSearchType::SEARCH_TYPE_PROC )
		pFunction = GetProcAddress( GetModuleHandleA( Dll ) , Pattern );

#if LOG_SDK_PATTERN == 1
	DEV_LOG( "[+] CBasePattern: %s -> %p\n" , PatternName , pFunction );
#endif

	return true;
}

auto CBasePattern::GetPatternName() -> const char*
{
	return PatternName;
}

auto CBasePattern::GetDllName() -> const char*
{
	return Dll;
}

auto CBasePattern::GetFunction() -> PVOID
{
	return pFunction;
}
