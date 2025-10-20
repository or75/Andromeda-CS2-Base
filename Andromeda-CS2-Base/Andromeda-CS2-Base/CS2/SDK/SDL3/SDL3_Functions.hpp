#pragma once

#include <Common/Common.hpp>

class CSDL3Functions final
{
public:
	auto OnInit() -> bool;

public:
	using SDL_WarpMouseInWindow_t = int( __stdcall* )( void* , float , float );

public:
	SDL_WarpMouseInWindow_t SDL_WarpMouseInWindow_o = nullptr;
};

auto GetSDL3Functions() -> CSDL3Functions*;
