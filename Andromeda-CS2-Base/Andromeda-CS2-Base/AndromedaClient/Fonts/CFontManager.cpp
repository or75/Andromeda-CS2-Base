#include "CFontManager.hpp"

static CFontManager g_CFontManager{};

auto CFontManager::FirstInitFonts() -> void
{
	if ( !m_bInit )
	{
		if ( FAILED( FW1CreateFactory( FW1_VERSION , &m_pFW1Factory ) ) )
		{
			DEV_LOG( "[error] FW1CreateFactory\n" );
			m_bInit = true;
			return;
		}

		m_VerdanaFont.InitFont( m_pFW1Factory , L"Verdana" , 11.f );

		m_pFW1Factory->Release();

		m_bInit = true;
	}
}

auto GetFontManager() -> CFontManager*
{
	return &g_CFontManager;
}
