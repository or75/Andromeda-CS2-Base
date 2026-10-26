#pragma once

#include "XorStr/XorStr.hpp"
#include "VMProtect/VMProtectSDK.h"

#if defined RELEASE_BUILD
#define XorStr(str) xorstr_(str)
#define VmpStr(str) VMProtectDecryptStringA(str)
#else
#define XorStr(str) str
#define VmpStr(str) str
#endif
