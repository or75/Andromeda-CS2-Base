#pragma once

#include <Common/Common.hpp>

auto Hook_MouseInputEnabled( void* RCX ) -> bool;

using MouseInputEnabled_t = decltype( &Hook_MouseInputEnabled );
inline MouseInputEnabled_t MouseInputEnabled_o = nullptr;
