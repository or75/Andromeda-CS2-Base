#pragma once

#include <Common/Common.hpp>
#include <d3d11.h>

auto WINAPI Hook_CreateSwapChain( IDXGIFactory* pFactory , IUnknown* pDevice , DXGI_SWAP_CHAIN_DESC* pDesc , IDXGISwapChain** ppSwapChain )->HRESULT;

using CreateSwapChain_t = decltype( &Hook_CreateSwapChain );
inline CreateSwapChain_t CreateSwapChain_o = nullptr;
