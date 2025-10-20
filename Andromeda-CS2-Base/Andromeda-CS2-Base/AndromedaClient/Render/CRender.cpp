#include "CRender.hpp"

static CRender g_CRender{};

auto CRender::DrawLine( const ImVec2& Start , const ImVec2& End , const ImColor& Color , float thickness ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	pBackgroundDrawList->AddLine( Start , End , Color , thickness );
}

auto CRender::DrawBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	pBackgroundDrawList->AddRect( Min , Max , Color );
}

auto CRender::DrawOutlineBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	const ImVec2 MinBlack1 = Min - ImVec2{ 1.f, 1.f };
	const ImVec2 MaxBlack1 = Max + ImVec2{ 1.f, 1.f };

	const ImVec2 MinBlack2 = Min + ImVec2{ 1.f, 1.f };
	const ImVec2 MaxBlack2 = Max - ImVec2{ 1.f, 1.f };

	const ImColor BlackColor = IM_COL32( 0 , 0 , 0 , 255 );

	DrawBox( MinBlack1 , MaxBlack1 , BlackColor );
	DrawBox( MinBlack2 , MaxBlack2 , BlackColor );

	DrawBox( Min , Max , Color );
}

auto CRender::DrawCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	const auto w = Max.x - Min.x;
	const auto h = Max.y - Min.y;

	const auto iw = roundf( w / 4.f );
	const auto ih = roundf( h / 4.f );

	// top
	DrawLine( ImVec2( Min.x , Min.y ) , ImVec2( Min.x + iw , Min.y ) , Color );					// left			_
	DrawLine( ImVec2( Min.x + w - iw , Min.y ) , ImVec2( Min.x + w , Min.y ) , Color );			// right			_
	DrawLine( ImVec2( Min.x , Min.y ) , ImVec2( Min.x , Min.y + ih ) , Color );					// top left		|
	DrawLine( ImVec2( Min.x + w , Min.y ) , ImVec2( Min.x + w , Min.y + ih ) , Color );			// top right		|

	// bottom
	DrawLine( ImVec2( Min.x , Min.y + h ) , ImVec2( Min.x + iw , Min.y + h ) , Color );					// left			_
	DrawLine( ImVec2( Min.x + w - iw , Min.y + h ) , ImVec2( Min.x + w , Min.y + h ) , Color );			// right			_
	DrawLine( ImVec2( Min.x , Min.y + h - ih ) , ImVec2( Min.x , Min.y + h ) , Color );					// bottom left	|
	DrawLine( ImVec2( Min.x + w , Min.y + h - ih ) , ImVec2( Min.x + w , Min.y + h + 1.f ) , Color );	// bottom right		|
}

auto CRender::DrawOutlineCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	const auto BlackColor = ImColor( 0 , 0 , 0 );

	const auto w = Max.x - Min.x;
	const auto h = Max.y - Min.y;

	const auto iw = roundf( w / 4.f );
	const auto ih = roundf( h / 4.f );

	DrawCoalBox( Min , Max , BlackColor );
	DrawCoalBox( Min + ImVec2( 1.f , 1.f ) , Max - ImVec2( 1.f , 1.f ) , Color );
	DrawCoalBox( Min + ImVec2( 2.f , 2.f ) , Max - ImVec2( 2.f , 2.f ) , BlackColor );

	// top left left
	DrawLine( ImVec2( Min.x , Min.y + ih ) , ImVec2( Min.x + 3.f , Min.y + ih ) , BlackColor );
	// top right right
	DrawLine( ImVec2( Min.x + w - 2.f , Min.y + ih ) , ImVec2( Min.x + w + 1.f , Min.y + ih ) , BlackColor );
	// top left top
	DrawLine( ImVec2( Min.x + iw , Min.y ) , ImVec2( Min.x + iw , Min.y + 3.f ) , BlackColor );
	// top right top
	DrawLine( ImVec2( Min.x + w - iw - 1.f , Min.y ) , ImVec2( Min.x + w - iw - 1.f , Min.y + 3.f ) , BlackColor );

	// bottom left left
	DrawLine( ImVec2( Min.x , Min.y + h - ih - 1.f ) , ImVec2( Min.x + 3.f , Min.y + h - ih - 1.f ) , BlackColor );
	// bottom right right
	DrawLine( ImVec2( Min.x + w - 2.f , Min.y + h - ih - 1.f ) , ImVec2( Min.x + w + 1.f , Min.y + h - ih - 1.f ) , BlackColor );
	// bottom left bottom
	DrawLine( ImVec2( Min.x + iw , Min.y + h - 2.f ) , ImVec2( Min.x + iw , Min.y + h + 1.f ) , BlackColor );
	// bottom right bottom
	DrawLine( ImVec2( Min.x + w - iw - 1.f , Min.y + h - 2.f ) , ImVec2( Min.x + w - iw - 1.f , Min.y + h + 1.f ) , BlackColor );
}

auto CRender::DrawFillBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	pBackgroundDrawList->AddRectFilled( Min , Max , Color );
}

auto CRender::DrawRectFilledMultiColor( const ImVec2& Min , const ImVec2& Max , const ImU32 col_upr_left , const ImU32 col_upr_right , const ImU32 col_bot_right , const ImU32 col_bot_left ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	pBackgroundDrawList->AddRectFilledMultiColor( Min , Max , col_upr_left , col_upr_right , col_bot_right , col_bot_left );
}

auto CRender::DrawCircle( const ImVec2& Center , float radius , const ImColor& Color ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	pBackgroundDrawList->AddCircle( Center , radius , Color );
}

auto CRender::DrawCircleFilled( const ImVec2& Center , float radius , const ImColor& Color ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	pBackgroundDrawList->AddCircleFilled( Center , radius , Color );
}

auto CRender::DrawCircle3D( const Vector3& Center , float radius , const ImColor& Color ) -> void
{
	static float Step = M_PI_F * 2.0f / 40.f;

	ImVec2 prev;

	static constexpr auto LineSize = 1.f;

	for ( float lat = 0.f; lat <= M_PI * 2.0f + 0.1f; lat += Step )
	{
		float sin1 = sinf( lat );
		float cos1 = cosf( lat );
		float sin3 = sinf( 0.0f );
		float cos3 = cosf( 0.0f );

		ImVec2 Out;

		Vector3 point1 = Vector3( sin1 * cos3 , cos1 , sin1 * sin3 ) * radius;
		Vector3 point2 = Center + point1;

		if ( Math::WorldToScreen( point2 , Out ) )
		{
			if ( lat > 0.01f )
			{
				if ( prev.x > 0.f && prev.y > 0.f && Out.x > 0.f && Out.y > 0.f )
				{
					DrawLine( prev , Out , Color , LineSize );
				}
			}
		}

		prev = Out;
	}
}

auto CRender::DrawTriangleFilled( const ImVec2& Center , const ImVec2& Pos1 , const ImVec2& Pos2 , const ImColor& Color ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	ImGui::GetBackgroundDrawList()->AddTriangleFilled( Center , Pos1 , Pos2 , Color );
}

auto CRender::DrawImage( ID3D11ShaderResourceView* pD3D11ShaderResourceView , const float x , const float y , const float w , const float h ) -> void
{
	auto pBackgroundDrawList = ImGui::GetBackgroundDrawList();

	if ( !pBackgroundDrawList )
		return;

	ImGui::GetBackgroundDrawList()->AddImage( reinterpret_cast<ImTextureID>( pD3D11ShaderResourceView ) , ImVec2( x , y ) , ImVec2( x + w , y + h ) );
}

auto GetRender() -> CRender*
{
	return &g_CRender;
}
