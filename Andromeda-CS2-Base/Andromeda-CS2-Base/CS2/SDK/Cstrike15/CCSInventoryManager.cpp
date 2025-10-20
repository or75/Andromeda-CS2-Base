#include "CCSInventoryManager.hpp"

#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/FunctionListSDK.hpp>
#include <CS2/SDK/Update/Offsets.hpp>

auto CCSInventoryManager::Get() ->CCSInventoryManager*
{
	return CCSInventoryManager_Get();
}

auto CCSInventoryManager::EquipItemInLoadout( int iTeam , int iSlot , uint64_t iItemID ) -> bool
{
	return CCSInventoryManager_EquipItemInLoadout( this , iTeam , iSlot , iItemID );
}

auto CCSInventoryManager::GetLocalInventory() -> CCSPlayerInventory*
{
	return CUSTOM_OFFSET( CCSPlayerInventory* , g_CCSInventoryManager_GetLocalInventory );
}
