#include "DllMain.hpp"
#include "DllLauncher.hpp"

BOOL WINAPI DllMain( HINSTANCE hInstace , DWORD dwReason , LPVOID lpReserved )
{
	switch ( dwReason )
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls( hInstace );
			GetDllLauncher()->OnDllMain( lpReserved , hInstace );

			return TRUE;
			break;
		case DLL_PROCESS_DETACH:
			GetDllLauncher()->OnDestroy();

			return TRUE;
			break;
	}

	return TRUE;
}
