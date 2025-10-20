#pragma once

#include "Common.hpp"

#include <stdio.h>
#include <mutex>

class CDevLog final
{
public:
	auto Init() -> void;
	auto Destroy() -> void;

public:
	auto AddLog( const char* fmt , ... ) -> void;

private:

#if ENABLE_CONSOLE_DEBUG == 1
	FILE* COutputHandle = nullptr;
	FILE* CErrorHandle = nullptr;
#endif

public:
	HANDLE hLogFile = INVALID_HANDLE_VALUE;

private:
	std::recursive_mutex m_Lock;
};

auto GetDevLog() -> CDevLog*;

#define DEV_LOG( fmt , ... ) \
	GetDevLog()->AddLog( XorStr( fmt ) , __VA_ARGS__ )
