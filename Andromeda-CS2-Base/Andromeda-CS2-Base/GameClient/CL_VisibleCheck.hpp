#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/Math/Vector3.hpp>

class CCSPlayerController;
class C_CSPlayerPawn;

class CL_VisibleCheck final
{
public:
	auto IsPlayerControllerVisible( CCSPlayerController* pCCSPlayerController ) -> bool;
	auto IsPlayerPawnVisible( C_CSPlayerPawn* pC_CSPlayerPawn ) -> bool;
	auto IsBoneVisible( C_CSPlayerPawn* pC_CSPlayerPawn , const Vector3& BonePos ) -> bool;
};

auto GetCL_VisibleCheck() -> CL_VisibleCheck*;
