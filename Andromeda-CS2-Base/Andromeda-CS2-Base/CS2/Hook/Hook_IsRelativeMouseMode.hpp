#pragma once

#include <Common/Common.hpp>

class CInputSystem;

auto Hook_IsRelativeMouseMode( CInputSystem* pInputSystem , bool Active ) -> void;

using IsRelativeMouseMode_t = decltype( &Hook_IsRelativeMouseMode );
inline IsRelativeMouseMode_t IsRelativeMouseMode_o = nullptr;
