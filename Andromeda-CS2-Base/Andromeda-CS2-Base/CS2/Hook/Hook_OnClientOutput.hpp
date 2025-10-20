#pragma once

#include <Common/Common.hpp>

auto Hook_OnClientOutput( void* a1 , void* a2 , void* a3 , void* a4 ) -> void;

using OnClientOutput_t = decltype( &Hook_OnClientOutput );
inline OnClientOutput_t OnClientOutput_o = nullptr;
