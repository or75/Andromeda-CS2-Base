#include "CResourceManager.hpp"
#include "CStyleManager.hpp"

#include <AndromedaClient/Helpers/CDX11ImageHelper.hpp>

#include "../Resources/DashBoardIcon.hpp"
#include "../Resources/DashBoardOpenButtonIcon.hpp"
#include "../Resources/DashBoardCloseButtonIcon.hpp"
#include "../Resources/AndromedaIcon.hpp"

static auto g_ResourceManager = CResourceManager{};

auto CResourceManager::LoadAll() -> void
{
	auto w = 0;
	auto h = 0;

	m_Textures[static_cast<int>( EResource::DashBoardIcon )] =
		GetDX11ImageHelper()->LoadPNGTextureFromMemory( (const byte*)DashBoardIcon_data , DashBoardIcon_size , &w , &h );

	m_Textures[static_cast<int>( EResource::DashBoardIconDark )] =
		GetDX11ImageHelper()->LoadPNGTextureFromMemory( (const byte*)DashBoardIcon_data , DashBoardIcon_size , &w , &h , true );

	m_Textures[static_cast<int>( EResource::DashBoardOpenButtonIcon )] =
		GetDX11ImageHelper()->LoadPNGTextureFromMemory( (const byte*)m_pDashBoardOpenButtonIcon_data , m_pDashBoardOpenButtonIcon_size , &w , &h );

	m_Textures[static_cast<int>( EResource::DashBoardCloseButtonIcon )] =
		GetDX11ImageHelper()->LoadPNGTextureFromMemory( (const byte*)DashBoardCloseButtonIcon_data , DashBoardCloseButtonIcon_size , &w , &h );

	m_Textures[static_cast<int>( EResource::AndromedaIcon )] =
		GetDX11ImageHelper()->LoadPNGTextureFromMemory( (const byte*)AndromedaIcon_data , AndromedaIcon_size , &w , &h );
}

auto CResourceManager::Shutdown() -> void
{
	for ( auto& texture : m_Textures )
	{
		// These textures are backend SRVs we created directly (not owned by the
		// font atlas), so _TexData is null and _TexID holds the ID3D11ShaderResourceView*.
		if ( auto* pSRV = reinterpret_cast<ID3D11ShaderResourceView*>( texture.GetTexID() ) )
			pSRV->Release();

		texture = ImTextureRef();
	}
}

auto CResourceManager::GetTexture( EResource id ) const -> ImTextureRef
{
	if ( id == EResource::DashBoardIcon && GetStyleManager()->GetTheme() == CStyleManager::ETheme::Dark )
		id = EResource::DashBoardIconDark;

	return m_Textures[static_cast<int>( id )];
}

auto GetResourceManager() -> CResourceManager*
{
	return &g_ResourceManager;
}
