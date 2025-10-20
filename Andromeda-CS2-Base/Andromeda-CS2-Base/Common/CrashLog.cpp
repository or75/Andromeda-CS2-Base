#include "CrashLog.hpp"
#include "DllLauncher.hpp"

#include <Psapi.h>

static CCrashLog g_CCrashLog{};

auto IsBadPtr( PVOID Ptr ) -> bool
{
    MEMORY_BASIC_INFORMATION mbi = { 0 };

    if ( VirtualQuery( Ptr , &mbi , sizeof( mbi ) ) )
    {
        DWORD mask = ( PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY );

        bool b = !( mbi.Protect & mask );

        if ( mbi.Protect & ( PAGE_GUARD | PAGE_NOACCESS ) )
            b = true;

        return b;
    }

    return true;
}

auto CCrashLog::InitVectorExceptionHandler() -> void
{
	m_pVecExcHandler = AddVectoredExceptionHandler( 1 , VectoredExceptionHandler );

    if ( !m_pVecExcHandler )
        MessageBoxW( 0 , L"Error AddVectoredExceptionHandler" , L"Error" , MB_ICONERROR );
}

auto CCrashLog::DestroyVectorExceptionHandler() -> void
{
	RemoveVectoredExceptionHandler( m_pVecExcHandler );
}

auto WINAPI CCrashLog::VectoredExceptionHandler( PEXCEPTION_POINTERS pExceptionInfo )->LONG
{
    const auto ExceptionCode = pExceptionInfo->ExceptionRecord->ExceptionCode;
    auto ExceptionAddress = pExceptionInfo->ExceptionRecord->ExceptionAddress;
    const auto CheatHinstance = GetDllLauncher()->GetDllImage();

#if ENABLE_CPP_EH_EXCEPTION == 1
    bool CPP_EH_EXCEPTION = false;

    CPP_EH_EXCEPTION_INFO* pCppExceptionInfo = nullptr;

    if ( ExceptionCode == 0xE06D7363 && pExceptionInfo->ExceptionRecord->NumberParameters == 4 )
    {
        if ( pExceptionInfo->ExceptionRecord->ExceptionInformation[3] == (ULONG_PTR)CheatHinstance )
        {
            pCppExceptionInfo = (CPP_EH_EXCEPTION_INFO*)pExceptionInfo->ExceptionRecord->ExceptionInformation[1];
            ExceptionAddress = pCppExceptionInfo->pExceptionAddress[0];

            CPP_EH_EXCEPTION = true;
        }
    }
#endif

    if ( ExceptionCode == STATUS_ACCESS_VIOLATION )
    {
        auto hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ , false , GetCurrentProcessId() );

        if ( hProcess )
        {
            char RaxModuleName[MAX_PATH] = { 0 };
            
            if ( GetMappedFileNameA( hProcess , (PVOID)pExceptionInfo->ContextRecord->Rcx , RaxModuleName , MAX_PATH ) > 0 )
            {
                if ( strstr( RaxModuleName , XorStr( "DiscordHook64.dll" ) ) != nullptr )
                {
                    CloseHandle( hProcess );

                    return EXCEPTION_CONTINUE_SEARCH;
                }
            }

            CloseHandle( hProcess );
        }
    }

    std::string CrashModuleName;
    std::string ModuleName;

#if ENABLE_CPP_EH_EXCEPTION == 1
    if ( ExceptionCode == STATUS_ACCESS_VIOLATION ||
        ExceptionCode == STATUS_STACK_BUFFER_OVERRUN ||
        ExceptionCode == STATUS_STACK_OVERFLOW || 
         ExceptionCode == STATUS_BREAKPOINT || 
         CPP_EH_EXCEPTION )
#else
    if ( ExceptionCode == STATUS_ACCESS_VIOLATION ||
        ExceptionCode == STATUS_STACK_BUFFER_OVERRUN ||
        ExceptionCode == STATUS_STACK_OVERFLOW ||
         ExceptionCode == STATUS_BREAKPOINT )
#endif
    {
        auto hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ , false , GetCurrentProcessId() );

        if ( hProcess )
        {
            GetCrashLog()->WriteCrashLogFile( XorStr( "Cheat Name: %s\n" ) , CHEAT_NAME );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Cheat Version: %s\n" ) , CHEAT_VERSION );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Cheat Hinstance: %p\n\n" ) , CheatHinstance );

            char CrashModuleNameTmp[MAX_PATH] = { 0 };

            if ( GetMappedFileNameA( hProcess , (PVOID)ExceptionAddress , CrashModuleNameTmp , MAX_PATH ) > 0 )
            {
                CrashModuleName = CrashModuleNameTmp;
                CrashModuleName = CrashModuleName.substr( CrashModuleName.find_last_of( '\\' ) + 1 );

                const auto ModuleHinstance = GetModuleHandleA( CrashModuleName.c_str() );
                const auto ModuleCrashOffset = (uintptr_t)ExceptionAddress - (uintptr_t)ModuleHinstance;

                GetCrashLog()->WriteCrashLogFile( XorStr( "Exception Handle: %p\n" ) , ModuleHinstance );
                GetCrashLog()->WriteCrashLogFile( XorStr( "Exception Module: %s\n" ) , CrashModuleName.c_str() );
                GetCrashLog()->WriteCrashLogFile( XorStr( "Exception Offset: %X\n" ) , ModuleCrashOffset );
            }

            GetCrashLog()->WriteCrashLogFile( XorStr( "Exception Code: %X\n" ) , ExceptionCode );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Exception Thread: %X\n" ) , GetCurrentThreadId() );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Exception Address: %p\n\n" ) , ExceptionAddress );

#if ENABLE_CPP_EH_EXCEPTION == 1
            if ( CPP_EH_EXCEPTION && pCppExceptionInfo )
                GetCrashLog()->WriteCrashLogFile( XorStr( "\nCPP_EH_EXCEPTION: %s\n\n" ) , pCppExceptionInfo->ExceptionInfo );
#endif

            GetCrashLog()->WriteCrashLogFile( XorStr( "Rax: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rax );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Rcx: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rcx );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Rdx: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rdx );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Rbx: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rbx );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Rsp: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rsp );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Rbp: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rbp );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Rsi: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rsi );
            GetCrashLog()->WriteCrashLogFile( XorStr( "Rdi: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->Rdi );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R8: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->R8 );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R9: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->R9 );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R10: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->R10 );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R11: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->R11 );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R12: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->R12 );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R13: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->R13 );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R14: %p\n" ) , (PVOID)pExceptionInfo->ContextRecord->R14 );
            GetCrashLog()->WriteCrashLogFile( XorStr( "R15: %p\n\n" ) , (PVOID)pExceptionInfo->ContextRecord->R15 );

            if ( GetCrashLog()->IsCrashCheat( ExceptionAddress ) )
            {
                auto CheatOffset = (uintptr_t)ExceptionAddress - (uintptr_t)CheatHinstance;

                GetCrashLog()->WriteCrashLogFile( XorStr( "%s Offset: %X\n" ) , CHEAT_NAME , (uint32_t)CheatOffset );
            }

            PVOID pCallStackList[MAX_CALLSTACK_AND_STACK_LOG_COUNT] = { 0 };
            const auto NumFrameCaptured = RtlCaptureStackBackTrace( 4 , MAX_CALLSTACK_AND_STACK_LOG_COUNT , pCallStackList , nullptr );

            if ( NumFrameCaptured )
            {
                GetCrashLog()->WriteCrashLogFile( XorStr( "\nCALLSTACK:\n" ) );

                for ( uint32_t i = 0; i < NumFrameCaptured; i++ )
                {
                    auto pStack = pCallStackList[i];

                    if ( GetCrashLog()->IsCrashCheat( pStack ) )
                    {
                        const auto CheatOffset = (uintptr_t)pStack - (uintptr_t)CheatHinstance;

                        GetCrashLog()->WriteCrashLogFile( XorStr( "CallStack (%i): %p (%s) -> %X\n" ) , i , pStack , CHEAT_NAME , (uint32_t)CheatOffset );
                    }
                    else
                    {
                        char ModuleNameTmp[MAX_PATH] = { 0 };

                        if ( pStack && GetMappedFileNameA( hProcess , (PVOID)pStack , ModuleNameTmp , MAX_PATH ) > 0 )
                        {
                            ModuleName = ModuleNameTmp;
                            ModuleName = ModuleName.substr( ModuleName.find_last_of( '\\' ) + 1 );

                            const auto ModuleHinstance = GetModuleHandleA( ModuleName.c_str() );
                            const auto ModuleCrashOffset = (uintptr_t)pStack - (uintptr_t)ModuleHinstance;

                            GetCrashLog()->WriteCrashLogFile( XorStr( "CallStack (%i): %p (%s) -> %X\n" ) , i , pStack , ModuleName.c_str() , (uint32_t)ModuleCrashOffset );
                        }
                    }
                }
            }

            GetCrashLog()->WriteCrashLogFile( XorStr( "\n\nFULLSTACK:\n" ) );

            for ( uint32_t i = 0; i < MAX_CALLSTACK_AND_STACK_LOG_COUNT; i++ )
            {
                const auto RSP = pExceptionInfo->ContextRecord->Rsp;
                const auto RSP_Ptr = (uintptr_t)RSP + ( i * sizeof( PVOID ) );

                if ( IsBadPtr( (PVOID)RSP_Ptr ) == false )
                {
                    const auto RSP_Data = *(uintptr_t*)RSP_Ptr;

                    if ( GetCrashLog()->IsCrashCheat( (PVOID)RSP_Data ) )
                    {
                        const auto CheatOffset = (uintptr_t)RSP_Data - (uintptr_t)CheatHinstance;

                        GetCrashLog()->WriteCrashLogFile( XorStr( "Stack (%i): %p (%s) -> %X\n" ) , i , (PVOID)RSP_Data , CHEAT_NAME , (uint32_t)CheatOffset );
                    }
                    else
                    {
                        char ModuleNameTmp[MAX_PATH] = { 0 };

                        if ( GetMappedFileNameA( hProcess , (PVOID)RSP_Data , ModuleNameTmp , MAX_PATH ) > 0 )
                        {
                            ModuleName = ModuleNameTmp;
                            ModuleName = ModuleName.substr( ModuleName.find_last_of( '\\' ) + 1 );

                            const auto ModuleHinstance = GetModuleHandleA( ModuleName.c_str() );
                            const auto ModuleCrashOffset = (uintptr_t)RSP_Data - (uintptr_t)ModuleHinstance;

                            GetCrashLog()->WriteCrashLogFile( XorStr( "Stack (%i): %p (%s) -> %X\n" ) , i , (PVOID)RSP_Data , ModuleName.c_str() , (uint32_t)ModuleCrashOffset );
                        }
                        else
                        {
                            GetCrashLog()->WriteCrashLogFile( XorStr( "Stack (%i): %p\n" ) , i , (PVOID)RSP_Data );
                        }
                    }
                }
                else
                {
                    break;
                }
            }

            CloseHandle( hProcess );
        }
    }

	return EXCEPTION_CONTINUE_SEARCH;
}

auto CCrashLog::WriteCrashLogFile( const char* fmt , ... ) -> void
{
    std::lock_guard lk( m_Lock );

    char buff[4096] = { 0 };

    va_list args;
    va_start( args , fmt );
    vsnprintf( buff , sizeof( buff ) - 1 , fmt , args );
    va_end( args );

    DEV_LOG( "%s" , buff );
}

auto CCrashLog::IsCrashCheat( PVOID Address ) -> bool
{
    const auto CheatStart = GetDllLauncher()->GetDllImage();
    const auto CheatEnd = CheatStart + GetDllLauncher()->GetSizeOfImage();

    if ( (uintptr_t)Address > (uintptr_t)CheatStart && (uintptr_t)Address < (uintptr_t)CheatEnd )
        return true;

    return false;
}

auto CCrashLog::GetCurrentDateTime() -> std::wstring
{
    time_t now = time( 0 );
    tm tstruct = { 0 };
    char buf[80] = { 0 };

    localtime_s( &tstruct , &now );
    strftime( buf , sizeof( buf ) , XorStr( "%d.%m.%Y.%H.%M.%S" ) , &tstruct );

    std::string StrBuf( buf );

    return std::wstring( StrBuf.begin() , StrBuf.end() );
}

auto GetCrashLog() -> CCrashLog*
{
	return &g_CCrashLog;
}
