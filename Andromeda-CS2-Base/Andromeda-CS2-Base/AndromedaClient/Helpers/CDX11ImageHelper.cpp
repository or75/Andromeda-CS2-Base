#include "CDX11ImageHelper.hpp"

#include <AndromedaClient/CAndromedaGUI.hpp>

#include <stb/stb_image.h>

static auto g_CDX11ImageHelper = CDX11ImageHelper{};

auto CDX11ImageHelper::LoadPNGTextureFromMemory( const byte* pBuffer , size_t BufferSize , int* w , int* h , bool whiteSilhouette ) -> ID3D11ShaderResourceView*
{
	ID3D11ShaderResourceView* pD3D11ShaderResourceView = nullptr;

	auto pstbImage = stbi_load_from_memory( pBuffer , static_cast<int>( BufferSize ) , w , h , nullptr , 4 );

	if ( !pstbImage )
	{
		DEV_LOG( "[error] stbi_load_from_memory: %p\n" , pBuffer );
		return nullptr;
	}

	// Reuse the monochrome logo's alpha mask on dark backgrounds.
	if ( whiteSilhouette )
	{
		for ( auto i = size_t{ 0 }; i < static_cast<size_t>( *w ) * *h * 4; i += 4 )
			pstbImage[i] = pstbImage[i + 1] = pstbImage[i + 2] = 255;
	}

	auto desc = D3D11_TEXTURE2D_DESC{};

	desc.Width = *w;
	desc.Height = *h;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = 0;

	ID3D11Texture2D* pTexture = NULL;
	auto subResource = D3D11_SUBRESOURCE_DATA{};

	subResource.pSysMem = pstbImage;
	subResource.SysMemPitch = desc.Width * 4;
	subResource.SysMemSlicePitch = 0;

	GetAndromedaGUI()->GetDevice()->CreateTexture2D( &desc , &subResource , &pTexture );

	// Create texture view
	auto srvDesc = D3D11_SHADER_RESOURCE_VIEW_DESC{};

	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = desc.MipLevels;
	srvDesc.Texture2D.MostDetailedMip = 0;

	if ( pTexture )
	{
		GetAndromedaGUI()->GetDevice()->CreateShaderResourceView( pTexture , &srvDesc , &pD3D11ShaderResourceView );
		pTexture->Release();
	}

	stbi_image_free( pstbImage );

	return pD3D11ShaderResourceView;
}

auto GetDX11ImageHelper() -> CDX11ImageHelper*
{
	return &g_CDX11ImageHelper;
}
