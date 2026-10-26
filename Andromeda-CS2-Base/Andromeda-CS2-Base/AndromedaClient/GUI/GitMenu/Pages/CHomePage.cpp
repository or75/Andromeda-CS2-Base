#include "CHomePage.hpp"
#include "SubPages/CHomeSubPage.hpp"

#include "../Core/CResourceManager.hpp"
#include "../Resources/ResourceCatalog.hpp"

namespace GitMenu
{
	CHomePage::CHomePage()
	{
		AddSubPage( "home" , std::make_unique<CHomeSubPage>() );
	}

	auto CHomePage::GetIcon() const -> ImTextureRef
	{
		return GetResourceManager()->GetTexture( EResource::DashBoardIcon );
	}
}
