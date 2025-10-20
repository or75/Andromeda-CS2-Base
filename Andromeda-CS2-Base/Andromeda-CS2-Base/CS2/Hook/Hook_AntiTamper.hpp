#pragma once

#include <Common/Common.hpp>

auto Hook_AntiTamper( void* Src , int a2 , __int64 a3 , int a4 ) -> bool;

using AntiTamper_t = decltype( &Hook_AntiTamper );
inline AntiTamper_t AntiTamper_o = nullptr;
