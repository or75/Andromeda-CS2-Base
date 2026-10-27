#include "CHomePage.hpp"

namespace GitMenu
{
	auto CHomeSubPage::OnRender() -> void
	{
		ImGui::TextUnformatted( "Home" );
		ImGui::Separator();
		ImGui::TextWrapped( "Welcome to Git Menu. Select a page from the menu to get started." );
	}
}
