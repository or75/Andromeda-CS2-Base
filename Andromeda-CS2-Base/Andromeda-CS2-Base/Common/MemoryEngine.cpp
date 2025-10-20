#include "MemoryEngine.hpp"

#define INRANGE(x,a,b) (x >= a && x <= b) 
#define getBits( x ) (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x ) (getBits(x[0]) << 4 | getBits(x[1]))

auto GetIDAPatternSize( const char* pattern ) -> size_t
{
	auto pattern_size = 0;
	auto pattern_scan = pattern;
	auto pattern_scan_end = pattern + strlen( pattern ) + 1;

	while ( pattern_scan[0] && pattern_scan[1] && pattern_scan < pattern_scan_end )
	{
		char symbol = pattern_scan[0];
		char next_symbol = pattern_scan[1];

		auto IsByte = []( char sym )
		{
			return ( sym >= '0' && sym <= '9' || sym >= 'A' && sym <= 'F' );
		};

		if ( IsByte( symbol ) && IsByte( next_symbol ) )
		{
			pattern_size++;
			pattern_scan += 3;
			continue;
		}
		else if ( symbol == '?' )
		{
			pattern_scan += 2;
			pattern_size++;
		}
		else
			break;
	}

	return pattern_size;
}

auto FindPattern( const char* szPattern , uintptr_t StartAddr , uintptr_t EndAddr , uint32_t offset )->PVOID
{
	auto Pattern = szPattern;
	auto PatternSize = GetIDAPatternSize( szPattern );

	auto FindIDA = [&]( DWORD_PTR Address )
	{
		auto IDASign = Pattern;

		for ( auto CurrentAddr = Address; CurrentAddr < ( Address + PatternSize ); CurrentAddr++ )
		{
			if ( !IDASign[0] || !IDASign[1] )
				break;

			bool IsUnk = *(PBYTE)IDASign == '\?';
			bool IsGetByte = *(PBYTE)CurrentAddr == getByte( IDASign );

			if ( IsUnk || IsGetByte )
			{
				if ( IsUnk )
					IDASign += 2;
				else
					IDASign += 3;

				continue;
			}
			else
				return (DWORD_PTR)0;
		}

		return Address + offset;
	};

	for ( auto CurrentAddr = StartAddr; CurrentAddr < EndAddr; CurrentAddr++ )
	{
		auto FoundAddress = FindIDA( CurrentAddr );

		if ( FoundAddress )
			return (PVOID)FoundAddress;
	}

	return nullptr;
}

auto FindPattern( const char* szModuleName , const char* szPattern , uint32_t offset )->PVOID
{
	PVOID pFoundAddress = nullptr;

GetModuleStart:;

	auto hModule = GetModuleHandleA( szModuleName );

	if ( hModule == nullptr )
	{
		Sleep( 100 );
		goto GetModuleStart;
	}

	auto pDosHeader = (PIMAGE_DOS_HEADER)hModule;

	if ( pDosHeader->e_magic == (WORD)'ZM' )
	{
		auto pNtHeader = (PIMAGE_NT_HEADERS64)( (uintptr_t)pDosHeader + pDosHeader->e_lfanew );

		if ( pNtHeader->Signature == (WORD)'EP' )
		{
			auto Start = (DWORD_PTR)hModule + pNtHeader->OptionalHeader.BaseOfCode;
			auto End = (DWORD_PTR)hModule + pNtHeader->OptionalHeader.SizeOfCode;

			pFoundAddress = FindPattern( szPattern , Start , End , offset );
		}
	}

	return pFoundAddress;
}
