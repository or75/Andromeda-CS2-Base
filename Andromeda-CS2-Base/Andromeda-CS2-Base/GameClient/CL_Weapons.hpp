#pragma once

#include <Common/Common.hpp>

class C_CSWeaponBaseGun;
class CCSWeaponBaseVData;

enum class CSWeaponType_t;

class CL_Weapons final
{
public:
	auto GetLocalActiveWeapon() -> C_CSWeaponBaseGun*;
	auto GetLocalWeaponVData() -> CCSWeaponBaseVData*;
	auto GetLocalWeaponType() -> CSWeaponType_t;
	auto GetLocalWeaponDefinitionIndex() -> int;
};

auto GetCL_Weapons() -> CL_Weapons*;
