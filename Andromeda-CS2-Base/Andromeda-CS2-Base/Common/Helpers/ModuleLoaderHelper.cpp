#include "ModuleLoaderHelper.hpp"

auto IsModuleLoad( const char* szModule , DWORD dwMsec ) -> bool
{
	HMODULE hModule = GetModuleHandleA( szModule );

	if ( !hModule )
	{
		DWORD dwMsecFind = 0;

		while ( !hModule )
		{
			if ( dwMsecFind == dwMsec )
				return false;

			hModule = GetModuleHandleA( szModule );

			Sleep( 1000 );
			dwMsecFind++;
		}
	}

	return true;
}
