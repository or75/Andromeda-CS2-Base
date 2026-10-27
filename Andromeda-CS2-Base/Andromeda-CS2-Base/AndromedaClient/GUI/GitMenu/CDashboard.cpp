#include "CDashboard.hpp"
#include "CPageManager.hpp"

#include <ImGui/im_anim.h>

#include "Custom/CSidebarItem.hpp"
#include "Custom/CTollTip.hpp"

#include "Core/CResourceManager.hpp"
#include "Core/CStyleManager.hpp"

#include "CMenuController.hpp"

CDashboard::CDashboard( const char8_t* closeButtonIcon )
	: m_CloseButtonIcon( closeButtonIcon ? closeButtonIcon : u8"" )
{
}

auto CDashboard::RenderHeader( float scale ) -> void
{
	if ( ImGui::BeginChild( "##DashboardHeader" , ImVec2( 0.f , 64.f * scale ) , ImGuiChildFlags_None , ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse ) )
	{
		const auto start = ImGui::GetCursorScreenPos();
		const auto width = ImGui::GetContentRegionAvail().x;

		if ( width >= 80.f * scale )
		{
			ImGui::SetCursorScreenPos( ImVec2( start.x + 8.f * scale , start.y ) );
			ImGui::Image( GetResourceManager()->GetTexture( EResource::DashBoardIcon ) , ImVec2( 32.f * scale , 32.f * scale ) );
		}

		const auto closeX = start.x + ImMax( 0.f , width - 40.f * scale );

		ImGui::SetCursorScreenPos( ImVec2( closeX , start.y ) );

		ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding , 6.f * scale );
		ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , 0.f );

		ImGui::PushStyleColor( ImGuiCol_Button , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
		ImGui::PushStyleColor( ImGuiCol_ButtonHovered , GetStyleManager()->GetNavigationColors().Hovered );
		ImGui::PushStyleColor( ImGuiCol_ButtonActive , GetStyleManager()->GetNavigationColors().Active );

		if ( ImGui::Button( "##CloseMenu" , ImVec2( 32.f * scale , 32.f * scale ) ) )
			SetClosed();

		auto* pDrawList = ImGui::GetWindowDrawList();

		// Close Button Icon
		if ( auto* font = GetAndromedaGUI()->GetFontAwesome7ProIcons(); font && !m_CloseButtonIcon.empty() && scale > 0.f )
		{
			const auto center = ImVec2( closeX + 16.f * scale , start.y + 16.f * scale );
			const auto iconColor = ImGui::GetColorU32( GetStyleManager()->GetNavigationColors().Muted );
			const auto* text = reinterpret_cast<const char*>( m_CloseButtonIcon.c_str() );
			
			auto fontSize = CAndromedaGUI::m_IconsFontSize * scale;
			auto textSize = font->CalcTextSizeA( fontSize , FLT_MAX , 0.f , text );

			if ( textSize.x > 0.f && textSize.y > 0.f )
			{
				fontSize *= ImMin( 1.f , ImMin( 16.f * scale / textSize.x , 16.f * scale / textSize.y ) );
				textSize = font->CalcTextSizeA( fontSize , FLT_MAX , 0.f , text );
				
				pDrawList->AddText( font , fontSize , ImVec2( center.x - textSize.x * 0.5f , center.y - textSize.y * 0.5f ) , iconColor , text );
			}
		}

		GitMenu::CTollTip::Render( "Close Menu" );

		ImGui::PopStyleColor( 3 );
		ImGui::PopStyleVar( 2 );
	}

	ImGui::EndChild();
}

auto CDashboard::RenderSeparator( float scale ) -> void
{
	ImGui::Dummy( ImVec2( 0.f , 8.f * scale ) );
	ImGui::PushStyleColor( ImGuiCol_Separator , ImGui::GetStyleColorVec4( ImGuiCol_Border ) );
	ImGui::Separator();
	ImGui::PopStyleColor();
	ImGui::Dummy( ImVec2( 0.f , 8.f * scale ) );
}

auto CDashboard::RenderPages( float scale ) -> void
{
	auto* pPageMgr = GetPageManager();
	auto bHasVisiblePages = false;

	ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing , ImVec2( 8.f * scale , 0.f ) );

	for ( auto i = 0; i < pPageMgr->GetPageCount(); ++i )
	{
		if ( !pPageMgr->IsPageVisible( i ) )
			continue;

		if ( bHasVisiblePages && pPageMgr->HasPageSeparator( i ) )
			RenderSeparator( scale );

		bHasVisiblePages = true;

		const auto pageId = pPageMgr->GetPageId( i );
		const auto* displayName = pPageMgr->GetPageDisplayName( i );
		const auto icon = pPageMgr->GetPageIcon( i );
		const auto bIsActive = ( pageId == pPageMgr->GetActivePageId() );

		if ( GitMenu::CSidebarItem::Render( pageId.c_str() , displayName , icon , bIsActive , scale , pPageMgr->GetPageFontAwesomeIcon( i ) ) )
		{
			pPageMgr->SetActivePage( pageId );
			SetClosed();
		}
	}

	if ( bHasVisiblePages )
		RenderSeparator( scale );
	else
		ImGui::TextDisabled( "No matches" );

	ImGui::PopStyleVar();
}

auto CDashboard::RenderBackground( const ImVec2& panelPos , const ImVec2& panelSize , const ImVec2& clipMin , const ImVec2& clipMax , float scale ) -> void
{
	auto* pDrawList = ImGui::GetWindowDrawList();

	const auto panelMax = ImVec2( panelPos.x + panelSize.x , panelPos.y + panelSize.y );
	const auto visibleMin = ImVec2( ImMax( panelPos.x , clipMin.x ) , ImMax( panelPos.y , clipMin.y ) );
	const auto visibleMax = ImVec2( ImMin( panelMax.x , clipMax.x ) , ImMin( panelMax.y , clipMax.y ) );

	if ( visibleMax.x <= visibleMin.x || visibleMax.y <= visibleMin.y )
		return;

	const auto rounding = ImMin( m_flCornerRounding * scale , ImMin( visibleMax.x - visibleMin.x , visibleMax.y - visibleMin.y ) * 0.5f );
	const auto shadowSize = static_cast<int>( m_flShadowSize * scale );
	const auto cornerFlags = ImDrawFlags_RoundCornersTopRight | ImDrawFlags_RoundCornersBottomRight;

	// Draw outside this window for the shadow, while staying inside the main menu.
	pDrawList->PushClipRect( clipMin , clipMax , false );
	pDrawList->PushClipRect( ImVec2( ImMax( panelMax.x - rounding , ( visibleMin.x + visibleMax.x ) * 0.5f ) , panelPos.y ) , ImVec2( panelMax.x + shadowSize , panelMax.y ) , true );

	for ( auto i = shadowSize; i > 0; --i )
	{
		const auto distance = static_cast<float>( i );
		const auto weight = 1.f - distance / ( shadowSize + 1.f );
		const auto alpha = 0.025f * weight * m_flOpenProgress / scale;

		pDrawList->AddRectFilled( panelPos , ImVec2( panelMax.x + distance , panelMax.y ) , ImGui::GetColorU32( ImVec4( 0.f , 0.f , 0.f , alpha ) ) , rounding + distance , cornerFlags );
	}

	pDrawList->PopClipRect();

	// Keep the left corners rounded at the clipping edge throughout the slide.
	pDrawList->AddRectFilled( visibleMin , visibleMax , ImGui::GetColorU32( ImGuiCol_PopupBg ) , rounding , ImDrawFlags_RoundCornersAll );
	pDrawList->PopClipRect();
}

auto CDashboard::ResetAnimation( ImGuiID animationId ) -> void
{
	iam_tween_float( animationId , 0 , 0.f , 0.f , iam_ease_preset( iam_ease_out_cubic ) ,
	iam_policy_cut , ImGui::GetIO().DeltaTime );

	m_flOpenProgress = 0.f;
	m_bWasOpen = false;
}

auto CDashboard::OnRender( const ImVec2& windowPos , const ImVec2& windowSize ) -> void
{
	const auto pInstance = this;
	const auto animationId = ImHashData( &pInstance , sizeof( pInstance ) , ImHashStr( "##DashboardAnimation" ) );

	if ( !m_bIsOpen )
	{
		ResetAnimation( animationId );
		return;
	}

	const auto bOpening = !m_bWasOpen;

	if ( bOpening )
		ResetAnimation( animationId );

	m_bWasOpen = true;
	m_flOpenProgress = ImClamp( iam_tween_float( animationId , 0 , 1.f , m_flOpenDuration , iam_ease_preset( iam_ease_out_cubic ) , iam_policy_crossfade , ImGui::GetIO().DeltaTime ) , 0.f , 1.f );

	if ( windowSize.x <= 0.f || windowSize.y <= 0.f )
		return;

	const auto scale = ImGui::GetFontSize() / 16.f;
	const auto dashboardSize = ImVec2( ImMax( 1.f , ImMin( m_flDashboardSize * scale , windowSize.x ) ) , ImMax( 1.f , windowSize.y ) );
	const auto panelPos = ImVec2( windowPos.x - dashboardSize.x * ( 1.f - m_flOpenProgress ) , windowPos.y );
	const auto clipMax = ImVec2( windowPos.x + windowSize.x , windowPos.y + windowSize.y );

	if ( bOpening )
		ImGui::SetNextWindowFocus();

	ImGui::SetNextWindowSize( dashboardSize , ImGuiCond_Always );
	ImGui::SetNextWindowPos( panelPos , ImGuiCond_Always );

	ImGui::PushFont( nullptr , 14.f );
	ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding , ImVec2( 8.f * scale , 16.f * scale ) );
	ImGui::PushStyleVar( ImGuiStyleVar_WindowRounding , 0.f );
	ImGui::PushStyleVar( ImGuiStyleVar_WindowBorderSize , 0.f );
	ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing , ImVec2( 8.f * scale , 8.f * scale ) );
	ImGui::PushStyleColor( ImGuiCol_WindowBg , ImGui::GetStyleColorVec4( ImGuiCol_PopupBg ) );
	ImGui::PushStyleColor( ImGuiCol_ChildBg , ImVec4( 0.f , 0.f , 0.f , 0.f ) );

	if ( ImGui::Begin( "DashBoard##DashBoardMenu" , nullptr ,
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar |
		ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground ) )
	{
		// Match hit testing to the visible part of the sliding panel.
		ImGui::GetCurrentWindow()->OuterRectClipped.ClipWith( ImRect( windowPos , clipMax ) );
		
		RenderBackground( panelPos , dashboardSize , windowPos , clipMax , scale );
		
		ImGui::PushClipRect( windowPos , clipMax , true );

		RenderHeader( scale );

		if ( m_bIsOpen )
		{
			if ( ImGui::BeginChild( "##DashboardPages" , ImVec2( 0.f , 0.f ) ) )
				RenderPages( scale );

			ImGui::EndChild();
		}

		ImGui::PopClipRect();
	}

	ImGui::End();
	ImGui::PopStyleColor( 2 );
	ImGui::PopStyleVar( 4 );
	ImGui::PopFont();

	if ( !m_bIsOpen )
		ResetAnimation( animationId );
}
