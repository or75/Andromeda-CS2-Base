#include "CFont.hpp"

#include <AndromedaClient/CAndromedaGUI.hpp>
#include <Common/Helpers/StringHelper.hpp>

#ifndef D3DCOLOR_ABGR
#define D3DCOLOR_ABGR(a,b,g,r) \
	((DWORD)((((a)&0xff)<<24)|(((b)&0xff)<<16)|(((g)&0xff)<<8)|((r)&0xff)))
#endif

auto CFont::InitFont( IFW1Factory* pFW1Factory , std::wstring Name , float FontSize ) -> void
{
	m_FontSize = FontSize;
	m_FontName = Name;

	FW1_FONTWRAPPERCREATEPARAMS createParams;
	ZeroMemory( &createParams , sizeof( createParams ) );

	createParams.GlyphSheetWidth = 512;
	createParams.GlyphSheetHeight = 512;
	createParams.MaxGlyphCountPerSheet = 2048;
	createParams.SheetMipLevels = 1;
	createParams.AnisotropicFiltering = TRUE;
	createParams.MaxGlyphWidth = 384;
	createParams.MaxGlyphHeight = 384;
	createParams.DisableGeometryShader = TRUE;
	createParams.VertexBufferSize = 0;

	createParams.DefaultFontParams.pszFontFamily = Name.c_str();
	createParams.DefaultFontParams.FontWeight = static_cast<DWRITE_FONT_WEIGHT>( FW_MEDIUM );
	createParams.DefaultFontParams.FontStyle = DWRITE_FONT_STYLE_NORMAL;
	createParams.DefaultFontParams.FontStretch = DWRITE_FONT_STRETCH_NORMAL;
	createParams.DefaultFontParams.pszLocale = L"";

	if ( FAILED( pFW1Factory->CreateFontWrapper( GetAndromedaGUI()->GetDevice() , NULL , &createParams , &m_pFontWrapper ) ) )
	{
		DEV_LOG( "[error] CreateFontWrapper::%s\n" , Name.c_str() );
	}
}

auto CFont::DrawString( int x , int y , ImColor Color , int Flags , const char* fmt , ... ) -> void
{
	char Buffer[g_BufferSize] = { 0 };

	va_list va_alist;
	va_start( va_alist , fmt );
	vsnprintf( Buffer , sizeof( Buffer ) , fmt , va_alist );
	va_end( va_alist );

	auto RenderText = ansi_to_unicode( Buffer );

	DWORD dwColor = D3DCOLOR_ABGR(
		static_cast<DWORD>( Color.Value.w * 255.f ) ,
		static_cast<DWORD>( Color.Value.z * 255.f ) ,
		static_cast<DWORD>( Color.Value.y * 255.f ) ,
		static_cast<DWORD>( Color.Value.x * 255.f ) );

	if ( m_pFontWrapper )
	{
		const auto fw1Flags = Flags | FW1_ALIASED | FW1_RESTORESTATE;

		auto RenderFontWrapperText = [&]( const float x_pos , const float y_pos , DWORD color )
		{
			m_pFontWrapper->DrawString( GetAndromedaGUI()->GetDeviceContext() ,
									RenderText.c_str() , m_FontSize ,
									static_cast<FLOAT>( x_pos ) , static_cast<FLOAT>( y_pos ) , color , fw1Flags );
		};

		RenderFontWrapperText( static_cast<FLOAT>( x ) + 1.f , static_cast<FLOAT>( y ) + 1.f , D3DCOLOR_ABGR( static_cast<DWORD>( Color.Value.w * 255.f ) , 0 , 0 , 0 ) );
		RenderFontWrapperText( static_cast<FLOAT>( x ) - 1.f , static_cast<FLOAT>( y ) + 1.f , D3DCOLOR_ABGR( static_cast<DWORD>( Color.Value.w * 255.f ) , 0 , 0 , 0 ) );
		RenderFontWrapperText( static_cast<FLOAT>( x ) - 1.f , static_cast<FLOAT>( y ) - 1.f , D3DCOLOR_ABGR( static_cast<DWORD>( Color.Value.w * 255.f ) , 0 , 0 , 0 ) );
		RenderFontWrapperText( static_cast<FLOAT>( x ) + 1.f , static_cast<FLOAT>( y ) - 1.f , D3DCOLOR_ABGR( static_cast<DWORD>( Color.Value.w * 255.f ) , 0 , 0 , 0 ) );

		RenderFontWrapperText( static_cast<FLOAT>( x ) , static_cast<FLOAT>( y ) , dwColor );
	}
}

auto CFont::DrawString( ImVec2 Pos , ImColor Color , int Flags , const char* fmt , ... ) -> void
{
	char Buffer[g_BufferSize] = { 0 };

	va_list va_alist;
	va_start( va_alist , fmt );
	vsnprintf( Buffer , sizeof( Buffer ) , fmt , va_alist );
	va_end( va_alist );

	DrawString( static_cast<int>( Pos.x ) , static_cast<int>( Pos.y ) , Color , Flags , Buffer );
}

auto CFont::GetStringLayoutRect( int Flags , FW1_RECTF* pRECTF , const char* fmt , ... ) -> FW1_RECTF
{
	char Buffer[g_BufferSize] = { 0 };

	va_list va_alist;
	va_start( va_alist , fmt );
	vsnprintf( Buffer , sizeof( Buffer ) , fmt , va_alist );
	va_end( va_alist );

	auto TextToLayoutRect = ansi_to_unicode( Buffer );

	return m_pFontWrapper->MeasureString( TextToLayoutRect.c_str() , m_FontName.c_str() , m_FontSize , pRECTF , Flags );
}
