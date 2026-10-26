#include "CPageRegistry.hpp"

#include "../CPageManager.hpp"

#include "CHomePage.hpp"

auto CPageRegistry::RegisterAll( CPageManager* pPageManager ) -> void
{
	if ( !pPageManager )
		return;

	pPageManager->RegisterPage( "home" , std::make_unique<GitMenu::CHomePage>() );
}
