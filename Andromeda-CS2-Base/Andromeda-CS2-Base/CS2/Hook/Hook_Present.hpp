#pragma once

#include <Common/Common.hpp>
#include <d3d11.h>

auto Hook_Present( IDXGISwapChain* pSwapChain , UINT SyncInterval , UINT Flags ) -> HRESULT;

using Present_t = decltype( &Hook_Present );
inline Present_t Present_o = nullptr;
