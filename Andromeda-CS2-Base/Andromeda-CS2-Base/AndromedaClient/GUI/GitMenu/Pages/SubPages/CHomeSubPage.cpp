#include "CHomeSubPage.hpp"

#include "../../Core/CResourceManager.hpp"
#include "../../Resources/ResourceCatalog.hpp"

namespace GitMenu
{
	auto CHomeSubPage::GetIcon() const -> ImTextureRef
	{
		return GetResourceManager()->GetTexture( EResource::DashBoardIcon );
	}

	auto CHomeSubPage::OnRender() -> void
	{
		ImGui::TextUnformatted( "Home" );
		ImGui::Separator();
		ImGui::TextWrapped( "Welcome to Git Menu. Select a page from the menu to get started." );
	}
}
