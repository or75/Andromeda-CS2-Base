#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

#include "CNavigationBar.hpp"
#include "CDashboard.hpp"

class CMenuController final
{
public:
	auto Init() -> void;
	auto OnRender( bool* bOpen = nullptr ) -> void;

	auto OpenDashboard() -> void { m_Dashboard.SetOpened(); }
	auto CloseDashboard() -> void { m_Dashboard.SetClosed(); }
	auto IsDashboardOpen() const -> bool { return m_Dashboard.IsOpen(); }

private:
	CNavigationBar m_NavigationBar;
	CDashboard     m_Dashboard;

private:
	static constexpr auto m_flSubDashboardDivValue = 4.f;
};

auto GetMenuController() -> CMenuController*;
