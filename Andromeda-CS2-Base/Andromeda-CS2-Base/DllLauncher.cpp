#include "DllLauncher.hpp"

#include <string>
#include <winternl.h>

#include <Common/CrashLog.hpp>
#include <Common/Helpers/StringHelper.hpp>

#include <CS2/CSDK_Loader.hpp>
#include <CS2/CHook_Loader.hpp>
#include <CS2/SDK/CFunctionList.hpp>
#include <CS2/SDK/FunctionListSDK.hpp>

#include <AndromedaClient/CAndromedaClient.hpp>

static CDllLauncher g_CDllLauncher{};

auto Hook_AnalizePeModule( HANDLE ModuleHandle , ModuleInfo_t* pModuleInfo_t , bool CalculateHash ) -> bool
{
	auto Ret = AnalizePeModule_o( ModuleHandle , pModuleInfo_t , CalculateHash );

	if ( !Ret || !CalculateHash )
		return Ret;

	for ( const auto& Module : GetDllLauncher()->GetCachedModules() )
	{
		if ( Module.m_ModuleHandle == ModuleHandle )
		{
			DEV_LOG( "[Spoof CRC32]: [%u] -> [%u] [%s]\n" , pModuleInfo_t->CRC32 , Module.m_nCRC32 , pModuleInfo_t->filename );

			pModuleInfo_t->CRC32 = Module.m_nCRC32;

			return Ret;
		}
	}

	return Ret;
}

auto CDllLauncher::OnDllMain( LPVOID lpReserved , HINSTANCE hInstace ) -> void
{
	if ( lpReserved )
	{
		ManualMapParam_t* pParam = reinterpret_cast<ManualMapParam_t*>( lpReserved );

		if ( pParam )
		{
			m_DllDir = pParam->DllPath;
			m_DllDir += "\\";
			m_DllDir = m_DllDir.substr( 0 , m_DllDir.find_last_of( '\\' ) + 1 );
		}
	}
	else
	{
		char szDllDir[MAX_PATH];

		GetModuleFileNameA( hInstace , szDllDir , MAX_PATH );

		m_DllDir = szDllDir;
		m_DllDir = m_DllDir.substr( 0 , m_DllDir.find_last_of( '\\' ) );
		m_DllDir += '\\';
	}

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

	// Cached Modules CRC32
	{
		std::vector<HANDLE> Modules = {};

		const auto peb = reinterpret_cast<PEB*>( __readgsqword( 0x60 ) );
		const auto ldr = peb->Ldr;
		const auto list = &ldr->InMemoryOrderModuleList;

		for ( auto entry = list->Flink; entry != list; entry = entry->Flink )
		{
			const auto ldr_entry = CONTAINING_RECORD( entry , LDR_DATA_TABLE_ENTRY , InMemoryOrderLinks );
			const auto base = reinterpret_cast<std::uintptr_t>( ldr_entry->DllBase );

			if ( base && ldr_entry->FullDllName.Buffer )
				Modules.push_back( (HANDLE)base );
		}

		if ( !Modules.empty() )
		{
			for ( const auto& ModuleHandle : Modules )
			{
				ModuleInfo_t ModuleInfo = {};

				if ( AnalizePeModule( ModuleHandle , &ModuleInfo , true ) )
				{
					CachedModule ModuleData = { ModuleHandle , ModuleInfo.CRC32 };

					GetDllLauncher()->GetCachedModules().push_back( ModuleData );
				}
				else
				{
					DEV_LOG( "[error] Get CRC32 Modules: #2\n" );
				}
			}
		}
		else
		{
			DEV_LOG( "[error] Get CRC32 Modules: #1\n" );
		}
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
