#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/Math/Vector3.hpp>

class CCSPlayerController;
class C_CSPlayerPawn;

class CL_Players final
{
public:
	auto GetLocalPlayerController() -> CCSPlayerController*;
	auto GetLocalPlayerPawn() -> C_CSPlayerPawn*;

public:
	auto IsLocalPlayerAlive() -> bool;
};

auto GetCL_Players() -> CL_Players*;
