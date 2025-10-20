#pragma once

#include "Common.hpp"

struct CPP_EH_EXCEPTION_INFO
{
	PVOID* pExceptionAddress = nullptr;
	const char* ExceptionInfo = nullptr;
	int AddressCount = 0;
};

class CCrashLog final
{
public:
	auto InitVectorExceptionHandler() -> void;
	auto DestroyVectorExceptionHandler() -> void;

private:
	static auto WINAPI VectoredExceptionHandler( PEXCEPTION_POINTERS pExceptionInfo ) -> LONG;

private:
	auto WriteCrashLogFile( const char* fmt , ... ) -> void;

private:
	auto IsCrashCheat( PVOID Address ) -> bool;

private:
	auto GetCurrentDateTime() -> std::wstring;

private:
	PVOID m_pVecExcHandler = nullptr;

public:
	std::recursive_mutex m_Lock;

	static constexpr auto MAX_CALLSTACK_AND_STACK_LOG_COUNT = 256;
};

auto GetCrashLog() -> CCrashLog*;
