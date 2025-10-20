#include "DllLauncher.hpp"

#include <string>
#include <winternl.h>

#include <Common/CrashLog.hpp>
#include <Common/Helpers/StringHelper.hpp>

#include <CS2/CSDK_Loader.hpp>
#include <CS2/CHook_Loader.hpp>
#include <CS2/SDK/CFunctionList.hpp>

#include <AndromedaClient/CAndromedaClient.hpp>

static CDllLauncher g_CDllLauncher{};

auto CDllLauncher::OnDllMain( LPVOID lpReserved , HINSTANCE hInstace ) -> void
{
#if ENABLE_MANUAL_MAP == 0
	char szDllDir[MAX_PATH];

	GetModuleFileNameA( hInstace , szDllDir , MAX_PATH );
	
	m_DllDir = szDllDir;
	m_DllDir = m_DllDir.substr( 0 , m_DllDir.find_last_of( '\\' ) );
	m_DllDir += '\\';
#else
	m_DllDir = "C:\\";
#endif

#if ENABLE_MANUAL_MAP == 1
	if ( lpReserved )
	{
		ManualMapParam_t* pParam = reinterpret_cast<ManualMapParam_t*>( lpReserved );

		if ( pParam )
		{
			m_DllDir = pParam->DllPath;
			m_DllDir += "\\";
			m_DllDir = m_DllDir.substr( 0 , m_DllDir.find_last_of( '\\' ) + 1 );
		}
		else
			return;
	}
#endif

	m_hDllImage = hInstace;

	m_SizeofImage = GetSizeOfImageInternal();
	m_BaseOfCode = GetBaseOfCodeInternal();

	char szGameFile[MAX_PATH] = { 0 };
	GetModuleFileNameA( 0 , szGameFile , MAX_PATH );

	m_CS2Dir = szGameFile;
	m_CS2Dir = m_CS2Dir.substr( 0 , m_CS2Dir.find_last_of( "\\/" ) );
	m_CS2Dir += '\\';

	memset( szGameFile , 0 , MAX_PATH );

	CreateThread( 0 , 0 , StartCheatTheard , lpReserved , 0 , 0 );
}

auto CDllLauncher::OnDestroy() -> void
{
	if ( !m_bDestroyed )
	{
		GetDevLog()->Destroy();
		GetHook_Loader()->DestroyHooks();
		GetCrashLog()->DestroyVectorExceptionHandler();
		
		m_bDestroyed = true;
	}
}

auto WINAPI CDllLauncher::StartCheatTheard( LPVOID lpThreadParameter ) -> DWORD
{
	GetDevLog()->Init();
	GetCrashLog()->InitVectorExceptionHandler();

#if ENABLE_CONSOLE_DEBUG == 1
	DEV_LOG( "[+] StartCheatThread: %s\n" , ansi_to_utf8( GetDllDir() ).c_str() );
#endif

	if ( !GetHook_Loader()->InitalizeMH() )
	{
		DEV_LOG( "[error] Hook_Loader::InitalizeMH\n" );
		return 0;
	}

	if ( !GetHook_Loader()->InstallFirstHook() )
	{
		DEV_LOG( "[error] Hook_Loader::InstallFirstHook\n" );
		return 0;
	}

	if ( !GetFunctionList()->OnInit() )
	{
		DEV_LOG( "[error] FunctionList::OnInit\n" );
		return 0;
	}

	if ( !GetSDK_Loader()->LoadSDK() )
	{
		DEV_LOG( "[error] CSDK_Loader::LoadSDK\n" );
		return 0;
	}

	if ( !GetHook_Loader()->InstallSecondHook() )
	{
		DEV_LOG( "[error] Hook_Loader::InstallSecondHook\n" );
		return 0;
	}

	GetAndromedaClient()->OnInit();

	return 0;
}

auto GetDllDir()->std::string&
{
	return GetDllLauncher()->m_DllDir;
}

auto GetCS2Dir() -> std::string
{
	return GetDllLauncher()->m_CS2Dir;
}

auto GetDllLauncher() -> CDllLauncher*
{
	return &g_CDllLauncher;
}
