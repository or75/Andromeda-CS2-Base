#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

class CDashboard final
{
public:
	auto OnRender( const ImVec2& windowPos , const ImVec2& windowSize ) -> void;

public:
	auto SetOpened() -> void
	{
		if ( m_bIsOpen )
			return;

		m_bIsOpen = true;
		m_bWasOpen = false;
		m_flOpenProgress = 0.f;
	}

	auto SetClosed() -> void { m_bIsOpen = false; m_bWasOpen = false; m_flOpenProgress = 0.f; }
	auto IsOpen() const -> bool { return m_bIsOpen; }

private:
	auto RenderHeader( float scale ) -> void;
	auto RenderPages( float scale ) -> void;
	auto RenderSeparator( float scale ) -> void;
	auto ResetAnimation( ImGuiID animationId ) -> void;
	auto RenderBackground( const ImVec2& panelPos , const ImVec2& panelSize , const ImVec2& clipMin , const ImVec2& clipMax , float scale ) -> void;

	float m_flOpenProgress = 0.f;
	bool m_bIsOpen = false;
	bool m_bWasOpen = false;

	static constexpr auto m_flDashboardSize = 270.f;
	static constexpr auto m_flOpenDuration = 0.17f;
	static constexpr auto m_flCornerRounding = 10.f;
	static constexpr auto m_flShadowSize = 10.f;
};
