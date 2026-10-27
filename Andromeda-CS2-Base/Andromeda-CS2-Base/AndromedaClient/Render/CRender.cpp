#include "CRender.hpp"

#include <cmath>

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
	auto* drawList = ImGui::GetBackgroundDrawList();

	if ( !drawList || Color.Value.w <= 0.f )
		return;

	// Snap once and share the same segments between the color and its outline.
	const auto left = roundf( Min.x ) + 1.f;
	const auto top = roundf( Min.y ) + 1.f;
	const auto right = roundf( Max.x ) - 1.f;
	const auto bottom = roundf( Max.y ) - 1.f;

	if ( right <= left || bottom <= top )
		return;

	const auto iw = std::fmax( 1.f , roundf( ( right - left ) / 4.f ) );
	const auto ih = std::fmax( 1.f , roundf( ( bottom - top ) / 4.f ) );

	struct SSegment { ImVec2 Min; ImVec2 Max; };

	const SSegment segments[] =
	{
		{ { left , top } , { left + iw + 1.f , top + 1.f } },
		{ { right - iw , top } , { right + 1.f , top + 1.f } },
		{ { left , top } , { left + 1.f , top + ih + 1.f } },
		{ { right , top } , { right + 1.f , top + ih + 1.f } },
		{ { left , bottom } , { left + iw + 1.f , bottom + 1.f } },
		{ { right - iw , bottom } , { right + 1.f , bottom + 1.f } },
		{ { left , bottom - ih } , { left + 1.f , bottom + 1.f } },
		{ { right , bottom - ih } , { right + 1.f , bottom + 1.f } },
	};

	const auto outlineColor = ImGui::ColorConvertFloat4ToU32( ImVec4( 0.f , 0.f , 0.f , Color.Value.w ) );
	
	for ( const auto& segment : segments )
		drawList->AddRectFilled( segment.Min - ImVec2( 1.f , 1.f ) , segment.Max + ImVec2( 1.f , 1.f ) , outlineColor );

	// Draw every outline first so adjoining segments cannot cover the color.
	for ( const auto& segment : segments )
		drawList->AddRectFilled( segment.Min , segment.Max , Color );
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
