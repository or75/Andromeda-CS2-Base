#include "CCSPlayerInventory.hpp"

#include <CS2/SDK/Cstrike15/CCSInventoryManager.hpp>
#include <CS2/SDK/FunctionListSDK.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>

#include <CS2/SDK/GCSDK/CGCClientSharedObjectTypeCache.hpp>
#include <CS2/SDK/GCSDK/CGCClientSharedObjectCache.hpp>

#include <CS2/SDK/GCSDK/GCSDKTypes/EconItemConstants.hpp>
#include <CS2/SDK/Econ/CEconItem.hpp>

#include <Common/MemoryEngine.hpp>

auto CCSPlayerInventory::Get() ->CCSPlayerInventory*
{
	auto* pCCSInventoryManager = CCSInventoryManager::Get();

	if ( !pCCSInventoryManager )
	{
		DEV_LOG( "[error] CCSInventoryManager::Get\n" );
		return nullptr;
	}

	auto* pCCSPlayerInventory = pCCSInventoryManager->GetLocalInventory();

	if ( !pCCSPlayerInventory )
	{
		DEV_LOG( "[error] CCSInventoryManager::GetLocalInventory\n" );
		return nullptr;
	}

	return pCCSPlayerInventory;
}

auto CCSPlayerInventory::AddEconItem( CEconItem* pItem ) -> bool
{
	if ( !pItem )
		return false;

	auto* pSOTypeCache = GetBaseTypeCache();

	if ( !pSOTypeCache || !pSOTypeCache->AddObject( (CSharedObject*)pItem ) )
		return false;

	SOCreated( GetOwner() , (CSharedObject*)pItem , GCSDK::eSOCacheEvent_Incremental );

	return true;
}

auto CCSPlayerInventory::RemoveEconItem( CEconItem* pItem ) -> void
{
	if ( !pItem )
		return;

	auto* pSOTypeCache = GetBaseTypeCache();

	if ( !pSOTypeCache )
		return;

	const CUtlVector<CEconItem*>& pSharedObjects = pSOTypeCache->GetVecObjects<CEconItem*>();

	if ( !pSharedObjects.Exists( pItem ) )
		return;

	SODestroyed( GetOwner() , (CSharedObject*)pItem , GCSDK::eSOCacheEvent_Incremental );

	pSOTypeCache->RemoveObject( (CSharedObject*)pItem );

	pItem->Destruct();
}

auto CCSPlayerInventory::GetItemInLoadout( int iClass , int iSlot ) -> C_EconItemView*
{
	return CCSPlayerInventory_GetItemInLoadout( this , iClass , iSlot );
}

auto CCSPlayerInventory::GetHighestIDs() -> std::pair<uint64_t , uint32_t>
{
	uint64_t maxItemID = 0;
	uint32_t maxInventoryID = 0;

	auto* pSOTypeCache = GetBaseTypeCache();

	if ( pSOTypeCache )
	{
		const CUtlVector<CEconItem*>& vecItems = pSOTypeCache->GetVecObjects<CEconItem*>();

		for ( CEconItem* it : vecItems )
		{
			if ( !it ) continue;

			// Checks if item is default.
			if ( ( it->m_ulID & 0xF000000000000000 ) != 0 )
				continue;

			maxItemID = max( maxItemID , it->m_ulID );
			maxInventoryID = max( maxInventoryID , it->m_unInventory );
		}
	}

	return std::make_pair( maxItemID , maxInventoryID );
}

auto CCSPlayerInventory::GetItemViewForItem( uint64_t itemID ) -> C_EconItemView*
{
	C_EconItemView* pEconItemView = nullptr;

	const CUtlVector<C_EconItemView*>& pItems = GetItemVector();

	for ( C_EconItemView* it : pItems )
	{
		if ( it && it->m_iItemID() == itemID )
		{
			pEconItemView = it;
			break;
		}
	}

	return pEconItemView;
}

auto CCSPlayerInventory::GetSOCDataForItem( uint64_t itemID ) -> CEconItem*
{
	CEconItem* pSOCData = nullptr;

	CGCClientSharedObjectTypeCache* pSOTypeCache = GetBaseTypeCache();

	if ( pSOTypeCache )
	{
		const CUtlVector<CEconItem*>& vecItems = pSOTypeCache->GetVecObjects<CEconItem*>();

		for ( CEconItem* it : vecItems )
		{
			if ( it && it->m_ulID == itemID )
			{
				pSOCData = it;
				break;
			}
		}
	}

	return pSOCData;
}

auto CCSPlayerInventory::GetOwner() -> GCSDK::SOID_t
{
	return CUSTOM_OFFSET( GCSDK::SOID_t , 0x10 );
}

auto CCSPlayerInventory::GetItemVector() -> CUtlVector<C_EconItemView*>
{
	return CUSTOM_OFFSET( CUtlVector<C_EconItemView*> , 0x20 );
}

auto CCSPlayerInventory::GetBaseTypeCache() -> CGCClientSharedObjectTypeCache*
{
	auto* pCGCClientSharedObjectCache = CUSTOM_OFFSET( CGCClientSharedObjectCache* , g_CCSPlayerInventory_CGCClientSharedObjectCache );

	if ( pCGCClientSharedObjectCache )
	{
		auto* pSOTypeCache = pCGCClientSharedObjectCache->FindTypeCache( k_EEconTypeItem );

		if ( !pSOTypeCache )
			return pCGCClientSharedObjectCache->CreateBaseTypeCache( k_EEconTypeItem );

		return pSOTypeCache;
	}

	return nullptr;
}
