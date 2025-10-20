#include "SDL3_Functions.hpp"

static CSDL3Functions g_CSDL3Functions{};

auto CSDL3Functions::OnInit() -> bool
{
	auto hSDL3Module = GetModuleHandleA( XorStr( "SDL3.dll" ) );

	if ( !hSDL3Module )
	{
		DEV_LOG( "[error] SDL3.dll Module\n" );
		return false;
	}

	SDL_WarpMouseInWindow_o = (SDL_WarpMouseInWindow_t)GetProcAddress( hSDL3Module , XorStr( "SDL_WarpMouseInWindow" ) );

	if ( !SDL_WarpMouseInWindow_o )
	{
		DEV_LOG( "[error] SDL3 SDL_WarpMouseInWindow\n" );
		return false;
	}

	return true;
}

auto GetSDL3Functions() -> CSDL3Functions*
{
	return &g_CSDL3Functions;
}
