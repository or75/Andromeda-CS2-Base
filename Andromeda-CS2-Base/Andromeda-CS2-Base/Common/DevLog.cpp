#include "DevLog.hpp"

#include "Include/Config.hpp"
#include "DllLauncher.hpp"

#if ENABLE_CONSOLE_DEBUG == 1

#include <iostream>
#include <fstream>
#include <io.h>
#include <fcntl.h>

#endif

static CDevLog g_DevLog{};

auto CDevLog::Init() -> void
{
#if ENABLE_CONSOLE_DEBUG == 1
	AllocConsole();

	SetConsoleCP( CP_UTF8 );
	SetConsoleOutputCP( CP_UTF8 );

	// Get STDOUT handle
	HANDLE ConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	int SystemOutput = _open_osfhandle( intptr_t( ConsoleOutput ) , _O_TEXT );
	COutputHandle = _fdopen( SystemOutput , XorStr( "w" ) );

	// Get STDERR handle
	HANDLE ConsoleError = GetStdHandle( STD_ERROR_HANDLE );
	int SystemError = _open_osfhandle( intptr_t( ConsoleError ) , _O_TEXT );
	CErrorHandle = _fdopen( SystemError , XorStr( "w" ) );

	// Redirect the CRT standard input, output, and error handles to the console
	freopen_s( &COutputHandle , XorStr( "CONOUT$" ) , XorStr( "w" ) , stdout );
	freopen_s( &CErrorHandle , XorStr( "CONOUT$" ) , XorStr( "w" ) , stderr );

	std::wcout.clear();
	std::cout.clear();
	std::wcerr.clear();
	std::cerr.clear();
#endif

	const auto LogFile = GetDllDir() + LOG_FILE;

	hLogFile = CreateFileA( LogFile.c_str() , GENERIC_WRITE , FILE_SHARE_READ , 0 , CREATE_ALWAYS , FILE_ATTRIBUTE_NORMAL , 0 );
}

auto CDevLog::Destroy() -> void
{
#if ENABLE_CONSOLE_DEBUG == 1
	if ( CErrorHandle && COutputHandle )
	{
		fflush( CErrorHandle );
		fflush( COutputHandle );

		FreeConsole();

		fclose( CErrorHandle );
		fclose( COutputHandle );
	}
#endif

	CloseHandle( hLogFile );
}

auto CDevLog::AddLog( const char* fmt , ... ) -> void
{
	std::lock_guard lk( m_Lock );

	char buff[4096] = { 0 };

	va_list args;
	va_start( args , fmt );
	vsnprintf( buff , sizeof( buff ) - 1 , fmt , args );
	va_end( args );

#if ENABLE_CONSOLE_DEBUG == 1
	printf( XorStr( "%s" ) , buff );
#endif

	WriteFile( hLogFile , (PVOID)buff , lstrlenA( buff ) , 0 , 0 );
}

auto GetDevLog() -> CDevLog*
{
	return &g_DevLog;
}
