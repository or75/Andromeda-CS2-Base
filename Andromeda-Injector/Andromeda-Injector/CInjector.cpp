#include "CInjector.h"

#include <BlackBone/Process/Process.h>

auto CInjector::Init() -> bool
{
	GetModuleFileNameA( 0 , szDllFilePath , MAX_PATH );
	GetCurrentDirectoryA( MAX_PATH , szCurrentDir );

	int len = lstrlenA( szDllFilePath );

	szDllFilePath[len - 1] = 'l';
	szDllFilePath[len - 2] = 'l';
	szDllFilePath[len - 3] = 'd';

	if ( GetPrivileges() && FileExist( szDllFilePath ) )
		return true;

	return false;
}

auto CInjector::GetPrivileges() -> bool
{
	HANDLE hToken = NULL;
	LUID luid;
	TOKEN_PRIVILEGES tp;

	OpenProcessToken( GetCurrentProcess() , TOKEN_ALL_ACCESS , &hToken );

	LookupPrivilegeValue( NULL , SE_DEBUG_NAME , &luid );

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if ( AdjustTokenPrivileges( hToken , FALSE , &tp , sizeof( TOKEN_PRIVILEGES ) , NULL , NULL ) )
	{
		CloseHandle( hToken );
		return true;
	}

	return false;
}

auto CInjector::GetProcessIdByName( const char* szProcName )->DWORD
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS , 0 );
	DWORD dwGetProcessID = 0;

	if ( hSnapshot != INVALID_HANDLE_VALUE )
	{
		PROCESSENTRY32 ProcEntry32 = { 0 };
		ProcEntry32.dwSize = sizeof( MODULEENTRY32 );

		if ( Process32First( hSnapshot , &ProcEntry32 ) )
		{
			do
			{
				if ( _stricmp( ProcEntry32.szExeFile , szProcName ) == 0 )
				{
					dwGetProcessID = (DWORD)ProcEntry32.th32ProcessID;
					break;
				}
			} while ( Process32Next( hSnapshot , &ProcEntry32 ) );
		}

		CloseHandle( hSnapshot );
	}

	return dwGetProcessID;
}

auto CInjector::InjectManualMap( const char* szProcessName ) -> bool
{
	bool Result = false;
	DWORD PID = 0;

	DEV_LOG( "[info] Wait for start %s\n" , szProcessName );

	while ( !PID )
	{
		PID = GetProcessIdByName( szProcessName );
		Sleep( 100 );
	}

	m_hProcess = OpenProcess( PROCESS_ALL_ACCESS , FALSE , PID );

	if ( !m_hProcess )
	{
		DEV_LOG( "[-] inject code: #1\n" );
		return false;
	}

	// Read Dll File
	{
		auto hFile = CreateFileA( szDllFilePath , GENERIC_READ , 0 , NULL , OPEN_EXISTING , FILE_ATTRIBUTE_NORMAL , NULL );

		if ( !hFile )
		{
			DEV_LOG( "[-] inject code: #2\n" );
			CloseHandle( m_hProcess );
			return false;
		}

		auto dwLength = GetFileSize( hFile , NULL );

		if ( dwLength == INVALID_FILE_SIZE || dwLength == 0 )
		{
			DEV_LOG( "[-] inject code: #3\n" );

			CloseHandle( hFile );
			CloseHandle( m_hProcess );

			return false;
		}

		m_pDllFile = (PBYTE)HeapAlloc( GetProcessHeap() , 0 , dwLength );

		if ( !m_pDllFile )
		{
			DEV_LOG( "[-] inject code: #4\n" );

			CloseHandle( hFile );
			CloseHandle( m_hProcess );

			return false;
		}

		if ( ReadFile( hFile , m_pDllFile , dwLength , &m_DllFileSize , NULL ) == FALSE )
		{
			DEV_LOG( "[-] inject code: #5\n" );

			CloseHandle( hFile );
			CloseHandle( m_hProcess );

			return false;
		}

		if ( dwLength != m_DllFileSize )
		{
			DEV_LOG( "[-] inject code: #6\n" );

			CloseHandle( hFile );
			CloseHandle( m_hProcess );

			return false;
		}

		CloseHandle( hFile );
	}

	DllLoaderData_t LoaderData = { 0 };

	// Loader Data
	memcpy( LoaderData.DllPath , szCurrentDir , MAX_PATH );

	// Inject To Process
	{
		blackbone::Process CS2Process;
		CS2Process.Attach( m_hProcess );

		blackbone::CustomArgs_t Args;

		Args.push_back( &LoaderData , sizeof( DllLoaderData_t ) );

		Sleep( 3000 );

		auto pImage = CS2Process.mmap().MapImage( m_DllFileSize , m_pDllFile , false , blackbone::WipeHeader , nullptr , nullptr , &Args );

		if ( pImage )
			Result = true;
		else
			DEV_LOG( "[-] inject: %ws\n" , blackbone::Utils::GetErrorDescription( pImage.status ).c_str() );
	}

	// Free And Close
	{
		if ( m_pDllFile )
			HeapFree( GetProcessHeap() , 0 , m_pDllFile );

		CloseHandle( m_hProcess );
	}

	return Result;
}

auto GetInjector() -> CInjector*
{
	return CInjector::Instance();
}
