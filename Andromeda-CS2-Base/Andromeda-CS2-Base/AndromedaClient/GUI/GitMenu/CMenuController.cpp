#include "CMenuController.hpp"
#include "CPageManager.hpp"

#include <Common/Include/Config.hpp>

#include "Pages/CPageRegistry.hpp"
#include "Custom/ImGuiCustom.hpp"

#include <ImGui/imgui_internal.h>

static auto g_MenuController = CMenuController{};

auto CMenuController::Init() -> void
{
	CPageRegistry::RegisterAll( GetPageManager() );
}

auto CMenuController::SyncSearchReset() -> void
{
	if ( GetPageManager()->ConsumeSearchReset() )
		m_NavigationBar.ClearSearch();
}

auto CMenuController::OnRender( bool* bOpen ) -> void
{
	ImGui::SetNextWindowSize( ImVec2( 1000.f , 600.f ) , ImGuiCond_Once );

	if ( !ImGui::Begin( CHEAT_NAME , bOpen ) )
	{
		ImGui::End();
		return;
	}

	const auto bCloseDashboard = m_Dashboard.IsOpen() && ImGui::IsWindowHovered( ImGuiHoveredFlags_RootAndChildWindows ) && ImGui::IsMouseClicked( ImGuiMouseButton_Left );

	const auto windowPos = ImGui::GetWindowPos();
	const auto windowSize = ImGui::GetWindowSize();

	// ImGui draws the active resize border at least two pixels thick.
	const auto borderInset = ImMax( 2.f , ImGui::GetStyle().WindowBorderSize );

	ImGui::PushClipRect( windowPos + ImVec2( borderInset , borderInset ) , windowPos + windowSize - ImVec2( borderInset , borderInset ) , true );

	SyncSearchReset();
	m_NavigationBar.OnRender( m_Dashboard.IsFocused() );

	GetPageManager()->SetSearchQuery( m_NavigationBar.GetSearchQuery() );

	if ( m_NavigationBar.ConsumeAction() == CNavigationBar::EAction::Home )
	{
		GetPageManager()->SetActivePage( "home" );
		GetPageManager()->SetActiveSubPage( "home" );

		CloseDashboard();
	}

	if ( m_NavigationBar.IsMenuToggled() )
	{
		if ( m_Dashboard.IsOpen() )
		{
			CloseDashboard();
			ImGui::SetWindowFocus();
		}
		else
			OpenDashboard();

		m_NavigationBar.ResetMenuToggle();
	}
	else if ( bCloseDashboard )
	{
		CloseDashboard();
	}

	ImGui::BeginChild( "##SubDashBoard" , ImVec2( ImGui::GetContentRegionAvail().x / m_flSubDashboardDivValue , ImGui::GetContentRegionAvail().y ) );

	const auto childSubDashBoardWidth = ImGui::GetContentRegionAvail().x;

	auto* pPageMgr = GetPageManager();

	pPageMgr->RenderSubPages();
	SyncSearchReset();

	ImGui::EndChild();

	ImGui::SameLine();

	const auto p_min = ImGui::GetCursorScreenPos();
	const auto p_max = ImVec2( p_min.x + 1.0f , p_min.y + ImGui::GetContentRegionMax().y );

	ImGui::GetWindowDrawList()->AddLine(
		p_min ,
		p_max ,
		ImGui::GetColorU32( ImGuiCol_Border ) ,
		1.0f
	);

	ImGui::SameLine( childSubDashBoardWidth + ( ImGui::GetStyle().ItemSpacing.x * 3.f ) );

	ImGui::BeginChild( "##SubDashBoardContent" , ImGui::GetContentRegionAvail() , ImGuiChildFlags_AlwaysUseWindowPadding );

	pPageMgr->RenderActivePage();

	ImGui::EndChild();

	ImGui::PopClipRect();
	ImGui::End();

	m_Dashboard.OnRender( windowPos , windowSize );
	SyncSearchReset();
}

auto GetMenuController() -> CMenuController*
{
	return &g_MenuController;
}
