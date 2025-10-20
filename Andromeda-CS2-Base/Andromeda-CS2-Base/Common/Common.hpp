#pragma once

#include <Windows.h>
#include <cstdint>

#include "Include/Config.hpp"
#include "Include/XorStr/XorStr.hpp"
#include "Include/VMProtect/VMProtectSDK.h"

#include "DevLog.hpp"

#if ENABLE_XOR_STR == 1

#define XorStr(str) xorstr_(str)

#else

#define XorStr(str) str

#endif

#if ENABLE_XOR_VMP_STR == 1

#define VmpStr(str) VMProtectDecryptStringA(str)

#else

#define VmpStr(str) str

#endif

#define CS_CLASS_NO_ASSIGNMENT(CLASS)	\
	CLASS& operator=(CLASS&&) = delete;		\
	CLASS& operator=(const CLASS&) = delete;

#define IS_KEY_DOWN( KeyNum ) ( GetKeyState(KeyNum) & 0x100 )
