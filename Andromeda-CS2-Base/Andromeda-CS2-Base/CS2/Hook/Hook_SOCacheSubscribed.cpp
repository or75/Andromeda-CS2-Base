#include "Hook_SOCacheSubscribed.hpp"

#include <Common/Include/Config.hpp>

#include <CS2/SDK/Cstrike15/CCSPlayerInventory.hpp>
#include <AndromedaClient/Features/CInventoryChanger/CInventoryItemsManager.hpp>

auto Hook_SOCacheSubscribed( CCSPlayerInventory* pCSPlayerInventory , GCSDK::SOID_t owner , int64_t unk ) -> void*
{
	auto pResult = SOCacheSubscribed_o( pCSPlayerInventory , owner , unk );

	if ( pCSPlayerInventory->GetOwner().m_type == owner.m_type && pCSPlayerInventory->GetOwner().m_id == owner.m_id )
	{
#if DISABLE_INVENTORY == 0
		GetInventoryItemsManager()->OnAddAllItems();
#endif
	}

	return pResult;
}
