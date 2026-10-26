#include "GitMenu.hpp"
#include "CMenuController.hpp"

static auto g_GitMenu = CGitMenu{};

auto CGitMenu::Init() -> void
{
	if ( m_bInitialized )
		return;

	GetMenuController()->Init();
	m_bInitialized = true;
}

auto CGitMenu::Shutdown() -> void
{
	m_bInitialized = false;
}

auto CGitMenu::ShowGitMenu( bool* bOpen ) -> void
{
	if ( !m_bInitialized )
		Init();

	GetMenuController()->OnRender( bOpen );
}

auto GetGitMenu() -> CGitMenu*
{
	return &g_GitMenu;
}
