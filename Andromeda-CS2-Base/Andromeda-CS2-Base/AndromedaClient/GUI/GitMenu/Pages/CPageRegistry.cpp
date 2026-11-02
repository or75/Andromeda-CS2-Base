#include "CPageRegistry.hpp"

#include "../CPageManager.hpp"

#include "CHomePage.hpp"
#include "CVIsualPage.hpp"
#include "CMenuPage.hpp"
#include "CColorsPage.hpp"

auto CPageRegistry::RegisterAll( CPageManager* pPageManager ) -> void
{
	if ( !pPageManager )
		return;

	pPageManager->RegisterPage( "home" , std::make_unique<GitMenu::CHomePage>() );
	pPageManager->RegisterPage( "visual" , std::make_unique<GitMenu::CVIsualPage>() );
	pPageManager->RegisterPage( "colors" , std::make_unique<GitMenu::CColorsPage>() );
	pPageManager->RegisterPage( "menu" , std::make_unique<GitMenu::CMenuPage>() );
}
