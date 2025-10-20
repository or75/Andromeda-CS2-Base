#pragma once

#include <Common/Common.hpp>
#include <vector>

#include <CS2/SDK/Math/Vector3.hpp>

class C_CSPlayerPawn;

extern std::vector<std::string> g_AllTraceVisibleCheckBones;

class CL_Bones final
{
public:
	auto GetBonePositionByName( C_CSPlayerPawn* pC_CSPlayerPawn , const char* szBoneName ) -> Vector3;
};

auto GetCL_Bones() -> CL_Bones*;
