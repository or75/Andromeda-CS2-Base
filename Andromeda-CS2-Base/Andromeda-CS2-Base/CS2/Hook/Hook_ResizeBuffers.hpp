#pragma once

#include <Common/Common.hpp>
#include <d3d11.h>

auto Hook_ResizeBuffers( IDXGISwapChain* pSwapChain , UINT BufferCount , UINT Width , UINT Height , DXGI_FORMAT NewFormat , UINT SwapChainFlags ) -> HRESULT;

using ResizeBuffers_t = decltype( &Hook_ResizeBuffers );
inline ResizeBuffers_t ResizeBuffers_o = nullptr;
