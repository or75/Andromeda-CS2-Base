#pragma once

#include <Common/Common.hpp>

class CCSPlayerInventory;

class CCSInventoryManager
{
public:
	static auto Get() -> CCSInventoryManager*;

public:
	// Function String -> "\nLOADOUT ACTION BATCH #%i\n"
	auto EquipItemInLoadout( int iTeam , int iSlot , uint64_t iItemID ) -> bool;

public:
	// Vmt Index -> "59" -> "mov rax,qword ptr ds:[rcx+0x3D1A0]"
	auto GetLocalInventory() -> CCSPlayerInventory*;
};
