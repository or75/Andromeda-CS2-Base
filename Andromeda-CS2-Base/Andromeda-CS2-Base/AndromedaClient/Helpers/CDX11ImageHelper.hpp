#pragma once

#include <Common/Common.hpp>

struct ID3D11ShaderResourceView;

class CDX11ImageHelper final
{
public:
	auto LoadPNGTextureFromMemory( const byte* pBuffer , size_t BufferSize , int* w , int* h , bool whiteSilhouette = false ) -> ID3D11ShaderResourceView*;
};

auto GetDX11ImageHelper() -> CDX11ImageHelper*;
