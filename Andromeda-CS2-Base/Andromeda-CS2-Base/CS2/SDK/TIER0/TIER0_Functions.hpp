#pragma once

#include <Common/Common.hpp>

class CTIER0Functions final
{
public:
	auto OnInit() -> bool;

public:
	using RandomFloat_t = float( __fastcall* )( float , float );

public:
	RandomFloat_t RandomFloat_o = nullptr;
};

auto GetTIER0Functions() -> CTIER0Functions*;
