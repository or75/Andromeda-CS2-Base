#include "DevLog.hpp"
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
	COutputHandle = _fdopen( SystemOutput , "w" );

	// Get STDERR handle
	HANDLE ConsoleError = GetStdHandle( STD_ERROR_HANDLE );
	int SystemError = _open_osfhandle( intptr_t( ConsoleError ) , _O_TEXT );
	CErrorHandle = _fdopen( SystemError , "w" );

	// Redirect the CRT standard input, output, and error handles to the console
	freopen_s( &COutputHandle , "CONOUT$" , "w" , stdout );
	freopen_s( &CErrorHandle , "CONOUT$" , "w" , stderr );

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
	std::scoped_lock lock( m_Lock );

	char buff[4096] = { 0 };

	va_list args;
	va_start( args , fmt );
	vsnprintf( buff , sizeof( buff ) - 1 , fmt , args );
	va_end( args );

	m_Buffer.append( buff );

#if ENABLE_CONSOLE_DEBUG == 1
	printf( "%s" , buff );
#endif

	WriteFile( hLogFile , (PVOID)buff , lstrlenA( buff ) , 0 , 0 );
}

auto CDevLog::GetBuffer() -> std::string
{
	std::scoped_lock lock( m_Lock );
	return m_Buffer;
}

auto GetDevLog() -> CDevLog*
{
	return &g_DevLog;
}
