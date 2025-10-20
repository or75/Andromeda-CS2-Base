#include "CRenderStackSystem.hpp"
#include "CRender.hpp"

static CRenderStackSystem g_CRenderStackSystem{};

auto CRenderObjectDrawLine::OnRender() -> void
{
	GetRender()->DrawLine( m_Start , m_End , m_Color , m_Thickness );
}

auto CRenderObjectDrawBox::OnRender() -> void
{
	GetRender()->DrawBox( m_Min , m_Max , m_Color );
}

auto CRenderObjectDrawOutlineBox::OnRender() -> void
{
	GetRender()->DrawOutlineBox( m_Min , m_Max , m_Color );
}

auto CRenderObjectDrawCoalBox::OnRender() -> void
{
	GetRender()->DrawCoalBox( m_Min , m_Max , m_Color );
}

auto CRenderObjectDrawOutlineCoalBox::OnRender() -> void
{
	GetRender()->DrawOutlineCoalBox( m_Min , m_Max , m_Color );
}

auto CRenderObjectDrawFillBox::OnRender() -> void
{
	GetRender()->DrawFillBox( m_Min , m_Max , m_Color );
}

auto CRenderObjectDrawRectFilledMultiColor::OnRender() -> void
{
	GetRender()->DrawRectFilledMultiColor( m_Min , m_Max , m_Col_upr_left , m_Col_upr_right , m_Col_bot_right , m_Col_bot_left );
}

auto CRenderObjectDrawCircle::OnRender() -> void
{
	GetRender()->DrawCircle( m_Center , m_flRadius , m_Color );
}

auto CRenderObjectDrawCircleFilled::OnRender() -> void
{
	GetRender()->DrawCircleFilled( m_Center , m_flRadius , m_Color );
}

auto CRenderObjectDrawCircle3D::OnRender() -> void
{
	GetRender()->DrawCircle3D( m_Center , m_flRadius , m_Color );
}

auto CRenderObjectDrawTriangleFilled::OnRender() -> void
{
	GetRender()->DrawTriangleFilled( m_Center , m_pos1 , m_pos2 , m_Color );
}

auto CRenderObjectDrawString::OnRender() -> void
{
	m_pFont->DrawString( m_x , m_y , m_Color , m_Flags , "%s" , m_Text.c_str() );
}

auto CRenderStackSystem::DrawLine( const ImVec2& Start , const ImVec2& End , const ImColor& Color , const float thickness ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawLine>( Start , End , Color , thickness ) );
}

auto CRenderStackSystem::DrawBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawBox>( Min , Max , Color ) );
}

auto CRenderStackSystem::DrawOutlineBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawOutlineBox>( Min , Max , Color ) );
}

auto CRenderStackSystem::DrawCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.push_back( std::make_shared<CRenderObjectDrawCoalBox>( Min , Max , Color ) );
}

auto CRenderStackSystem::DrawOutlineCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawOutlineCoalBox>( Min , Max , Color ) );
}

auto CRenderStackSystem::DrawFillBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawFillBox>( Min , Max , Color ) );
}

auto CRenderStackSystem::DrawRectFilledMultiColor( const ImVec2& Min , const ImVec2& Max , const ImU32 col_upr_left , const ImU32 col_upr_right , const ImU32 col_bot_right , const ImU32 col_bot_left ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawRectFilledMultiColor>( Min , Max , col_upr_left , col_upr_right , col_bot_right , col_bot_left ) );
}

auto CRenderStackSystem::DrawCircle( const ImVec2& Center , float radius , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawCircle>( Center , radius , Color ) );
}

auto CRenderStackSystem::DrawCircleFilled( const ImVec2& Center , const float radius , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawCircleFilled>( Center , radius , Color ) );
}

auto CRenderStackSystem::DrawCircle3D( const Vector3& Center , float radius , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawCircle3D>( Center , radius , Color ) );
}

auto CRenderStackSystem::DrawTriangleFilled( const ImVec2& Center , const ImVec2& pos1 , const ImVec2& pos2 , const ImColor& Color ) -> void
{
	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawTriangleFilled>( Center , pos1 , pos2 , Color ) );
}

// TODO: SURIK std::format - kruto, ETO HUETA EBANAYA
auto CRenderStackSystem::DrawString( CFont* pFont , const int X , const int Y , const int Flags , const ImColor& Color , const char* fmt , ... ) -> void
{
	char Buffer[g_BufferSize] = { 0 };

	va_list va_alist;
	va_start( va_alist , fmt );
	vsnprintf( Buffer , sizeof( Buffer ) , fmt , va_alist );
	va_end( va_alist );

	std::scoped_lock lock( m_Lock );
	m_vecUpdateBuffer.emplace_back( std::make_shared<CRenderObjectDrawString>( pFont , X , Y , Flags , Color , Buffer ) );
}

auto CRenderStackSystem::DrawString( CFont* pFont , const ImVec2& Pos , const int Flags , const ImColor& Color , const char* fmt , ... ) -> void
{
	char Buffer[g_BufferSize] = { 0 };

	va_list va_alist;
	va_start( va_alist , fmt );
	vsnprintf( Buffer , sizeof( Buffer ) , fmt , va_alist );
	va_end( va_alist );

	DrawString( pFont , static_cast<int>( Pos.x ) , static_cast<int>( Pos.y ) , Flags , Color , Buffer );
}

auto CRenderStackSystem::OnClientOutput() -> void
{
	std::scoped_lock lock( m_Lock );

	if ( m_vecUpdateBuffer.empty() )
	{
		// Nothing has been drawn on this frame
		m_pSharedBuffer = std::make_shared<RenderObjectsVec_t>();
		m_bSharedBufferReady = true;
		return;
	}

	m_pSharedBuffer = std::make_shared<RenderObjectsVec_t>( std::move( m_vecUpdateBuffer ) );
	m_bSharedBufferReady = true;
}

auto CRenderStackSystem::OnRenderStack() -> void
{
	if ( m_bSharedBufferReady.exchange( false ) )
	{
		m_pRenderBuffer = std::move( m_pSharedBuffer.load() );
	}

	if ( m_pRenderBuffer )
	{
		auto& bufferCopy = *m_pRenderBuffer;

		for ( auto& order : bufferCopy )
		{
			order->OnRender();
		}
	}
}

auto GetRenderStackSystem() -> CRenderStackSystem*
{
	return &g_CRenderStackSystem;
}
