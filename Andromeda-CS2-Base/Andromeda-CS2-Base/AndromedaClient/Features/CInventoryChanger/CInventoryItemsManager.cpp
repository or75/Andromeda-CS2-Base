#include "CInventoryItemsManager.hpp"

#include <Common/Helpers/StringHelper.hpp>

#include <algorithm>

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Econ/CEconItem.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>

#include <CS2/Protobuf/base_gcmessages.pb.h>

#include <CS2/SDK/Cstrike15/CCSPlayerInventory.hpp>
#include <CS2/SDK/Cstrike15/CCSInventoryManager.hpp>

#include <CS2/SDK/Econ/CEconItemSchema.hpp>
#include <CS2/SDK/Econ/CEconItemSystem.hpp>
#include <CS2/SDK/Econ/CEconItemDefinition.hpp>

#include <CS2/SDK/GCSDK/GCSDKTypes/EconItemConstants.hpp>

#include <CS2/SDK/Interface/CSource2Client.hpp>
#include <CS2/SDK/Interface/CLocalize.hpp>
#include <CS2/SDK/Interface/IBaseFileSystem.hpp>

#include <GameClient/CL_ItemDefinition.hpp>

#include <AndromedaClient/Features/CInventoryChanger/CInventoryChanger.hpp>
#include <AndromedaClient/Settings/CSettingsJson.hpp>

static CInventoryItemsManager g_CInventoryItemsManager{};

// Scan all available items WITHOUT adding them to inventory
auto CInventoryItemsManager::ScanAllItems() -> void
{
	auto* pItemSchema = SDK::Interfaces::Source2Client()->GetEconItemSystem()->GetEconItemSchema();
	auto* pPlayerInventory = CCSPlayerInventory::Get();

	if ( !pItemSchema || !pPlayerInventory )
		return;

	static const std::string SkinIconPath = "panorama/images/econ/default_generated/";

	const CUtlMap<int , CEconItemDefinition*>& vecItems = pItemSchema->GetSortedItemDefinitionMap();
	const CUtlMap<int , CPaintKit*>& vecPaintKits = pItemSchema->GetPaintKits();
	const CUtlMap<int , CMusicKit*>& vecMusicKit = pItemSchema->GetMusicKitDefinitions();

	for ( const auto& it : vecItems )
	{
		auto* pItem = it.m_value;

		if ( !pItem )
			continue;

		const bool isWeapon = pItem->IsWeapon();
		const bool isKnife = pItem->IsKnife( true );
		const bool isGlove = pItem->IsGlove( true );
		const bool isAgent = pItem->IsAgent( true );

		if ( !isWeapon && !isKnife && !isGlove && !isAgent )
			continue;

		// Some items don't have names.
		const char* itemBaseName = pItem->m_pszItemBaseName();

		if ( !itemBaseName || itemBaseName[0] == '\0' )
			continue;

		const uint16_t defIdx = pItem->m_nDefIndex();

		DumpedItem_t dumpedItem;

		dumpedItem.m_DefIdx = defIdx;
		dumpedItem.m_Rarity = pItem->m_nItemRarity();

		// Get human-readable name for UI
		const char* localizedName = SDK::Interfaces::Localize()->FindSafe( itemBaseName );

		if ( localizedName && localizedName[0] != '\0' && localizedName[0] != '#' )
			dumpedItem.m_DisplayName = localizedName;
		else if ( itemBaseName && itemBaseName[0] != '\0' )
			dumpedItem.m_DisplayName = itemBaseName;
		else
			dumpedItem.m_DisplayName = "Unknown Item";

		if ( isWeapon )
			dumpedItem.m_ItemType = DUMPED_ITEM_TYPE_WEAPON;
		else if ( isKnife )
			dumpedItem.m_ItemType = DUMPED_ITEM_TYPE_KNIFE;
		else if ( isGlove )
			dumpedItem.m_ItemType = DUMPED_ITEM_TYPE_GLOVE;
		else if ( isAgent )
			dumpedItem.m_ItemType = DUMPED_ITEM_TYPE_AGENT;

		if ( strstr( SDK::Interfaces::Localize()->FindSafe( itemBaseName ) , XorStr( "#CSGO_CustomPlayer" ) ) )
			continue;

		if ( isKnife || isGlove || isAgent )
			dumpedItem.m_UnusualItem = true;

		if ( isAgent && strstr( itemBaseName , XorStr( "map_based" ) ) )
			continue;

		if ( isAgent )
		{
			std::string IconPath = "panorama/images/econ/characters/";
			std::string SkinName = itemBaseName + 19;

			IconPath += "customplayer_";
			IconPath += SkinName;
			IconPath += "_png.vtex_c";

			if ( SDK::Interfaces::BaseFileSystem()->FileExists( IconPath.c_str() ) )
			{
				dumpedItem.m_IconPath = IconPath;
				dumpedItem.m_PaintKitName = SkinName;
			}
		}

		for ( const auto& paintIt : vecPaintKits )
		{
			CPaintKit* pPaintKit = paintIt.m_value;

			if ( !pPaintKit || pPaintKit->nID == 0 || pPaintKit->nID == 9001 )
				continue;

			if ( strstr( pPaintKit->sName , XorStr( "doppler_phase2" ) ) ||
				 strstr( pPaintKit->sName , XorStr( "doppler_phase3" ) ) ||
				 strstr( pPaintKit->sName , XorStr( "doppler_phase4" ) ) )
				continue;

			bool hasValidIcon = false;
			std::string IconPath;

			// Weapons
			if ( !hasValidIcon )
			{
				if ( std::string WeaponName = GetWeaponDescFromDefinitionIndex( dumpedItem.m_DefIdx ); WeaponName.size() )
				{
					IconPath = SkinIconPath + WeaponName + "_" + std::string( pPaintKit->sName ) + "_light_png.vtex_c";

					if ( SDK::Interfaces::BaseFileSystem()->FileExists( IconPath.c_str() ) )
						hasValidIcon = true;
				}
			}

			// Gloves
			if ( !hasValidIcon )
			{
				if ( std::string GloveName = GetGloveDescFromDefinitionIndex( dumpedItem.m_DefIdx ); GloveName.size() )
				{
					IconPath = SkinIconPath + GloveName + "_" + std::string( pPaintKit->sName ) + "_light_png.vtex_c";

					if ( SDK::Interfaces::BaseFileSystem()->FileExists( IconPath.c_str() ) )
						hasValidIcon = true;
				}
			}

			// Knifes		
			if ( !hasValidIcon )
			{
				if ( std::string KnifeName = GetKnifeDescFromDefinitionIndex( dumpedItem.m_DefIdx ); KnifeName.size() )
				{
					IconPath = SkinIconPath + KnifeName + "_" + std::string( pPaintKit->sName ) + "_light_png.vtex_c";

					if ( SDK::Interfaces::BaseFileSystem()->FileExists( IconPath.c_str() ) )
						hasValidIcon = true;
				}
			}

			if ( hasValidIcon )
			{
				DumpedSkin_t dumpedSkin;

				dumpedSkin.m_ID = pPaintKit->nID;
				dumpedSkin.m_Rarity = pPaintKit->nRarity;
				dumpedSkin.m_bLegacyModel = pPaintKit->IsUseLegacyModel();
				dumpedSkin.m_PaintKitName = pPaintKit->sName;

				// Get skin name for UI
				if ( pPaintKit->sDescriptionTag && pPaintKit->sDescriptionTag[0] != '\0' )
				{
					const char* skinName = SDK::Interfaces::Localize()->FindSafe( pPaintKit->sDescriptionTag );

					if ( skinName && skinName[0] != '\0' && skinName[0] != '#' )
						dumpedSkin.m_DisplayName = skinName;
					else if ( pPaintKit->sName && pPaintKit->sName[0] != '\0' )
						dumpedSkin.m_DisplayName = pPaintKit->sName;
					else
						dumpedSkin.m_DisplayName = "Unknown Skin";
				}
				else if ( pPaintKit->sName && pPaintKit->sName[0] != '\0' )
				{
					dumpedSkin.m_DisplayName = pPaintKit->sName;
				}
				else
				{
					dumpedSkin.m_DisplayName = "Default";
				}

				dumpedSkin.m_IconPath = IconPath;
				dumpedItem.m_DumpedSkins.emplace_back( dumpedSkin );
			}
		}

		m_vecDumpedItems.emplace_back( dumpedItem );
	}

	// Music kits
	for ( const auto& it : vecMusicKit )
	{
		CMusicKit* pItem = it.m_value;

		if ( !pItem || pItem->nID == 1 || pItem->nID == 2 )
			continue;

		DumpedItem_t dumpedItem;
		DumpedSkin_t dumpedSkin;

		dumpedItem.m_DefIdx = EInventoryPrefab_t::INVENTORY_PREFAB_MUSIC_KIT;
		dumpedItem.m_ItemType = DUMPED_ITEM_TYPE_MUSIC;
		dumpedItem.m_Rarity = 1;
		dumpedItem.m_PaintKitName = pItem->sName;

		// Get music kit name
		if ( pItem->sNameLocToken && pItem->sNameLocToken[0] != '\0' )
		{
			const char* musicName = SDK::Interfaces::Localize()->FindSafe( pItem->sNameLocToken );

			if ( musicName && musicName[0] != '\0' && musicName[0] != '#' )
				dumpedItem.m_DisplayName = musicName;
			else if ( pItem->sName && pItem->sName[0] != '\0' )
				dumpedItem.m_DisplayName = pItem->sName;
			else
				dumpedItem.m_DisplayName = "Music Kit";
		}
		else if ( pItem->sName && pItem->sName[0] != '\0' )
		{
			dumpedItem.m_DisplayName = pItem->sName;
		}
		else
		{
			dumpedItem.m_DisplayName = "Music Kit";
		}

		std::string SkinPath = "panorama/images/";
		std::string IconPath = SkinPath + pItem->sInventoryImage;

		IconPath += "_png.vtex_c";

		if ( SDK::Interfaces::BaseFileSystem()->FileExists( IconPath.c_str() ) )
			dumpedSkin.m_IconPath = IconPath;

		dumpedSkin.m_ID = pItem->nID;
		dumpedSkin.m_Rarity = 1;
		dumpedSkin.m_DisplayName = dumpedItem.m_DisplayName;
		dumpedSkin.m_PaintKitName = dumpedItem.m_PaintKitName;
		dumpedItem.m_DumpedSkins.emplace_back( dumpedSkin );

		m_vecDumpedItems.emplace_back( dumpedItem );
	}
}

// Legacy function - now scans items and loads selected skins from config
auto CInventoryItemsManager::OnAddAllItems() -> void
{
	ScanAllItems();

	for ( auto& Item : m_vecDumpedItems )
	{
		if ( Item.m_ItemType == EDumpedItemType_t::DUMPED_ITEM_TYPE_WEAPON ||
			Item.m_ItemType == EDumpedItemType_t::DUMPED_ITEM_TYPE_KNIFE ||
			Item.m_ItemType == EDumpedItemType_t::DUMPED_ITEM_TYPE_GLOVE )
		{
			if ( Item.m_DumpedSkins.size() )
			{
				for ( auto& Skin : Item.m_DumpedSkins )
				{
					AddSelectedSkinToInventory( Item.m_DefIdx , Skin.m_ID , 0.0f , false , 0 , -1 );
				}
			}
		}
		else if ( Item.m_ItemType == EDumpedItemType_t::DUMPED_ITEM_TYPE_AGENT )
		{
			AddSelectedSkinToInventory( Item.m_DefIdx , 0 , 0.0f , false , 0 , -1 );
		}
		else if ( Item.m_ItemType == EDumpedItemType_t::DUMPED_ITEM_TYPE_MUSIC )
		{
			if ( Item.m_DumpedSkins.size() )
			{
				for ( auto& Skin : Item.m_DumpedSkins )
				{
					AddMusicToInventory( Item.m_DefIdx , Skin.m_ID );
				}
			}
		}
	}
}

// Add a specific skin to inventory
auto CInventoryItemsManager::AddSelectedSkinToInventory( uint16_t defIdx , int paintKit , float wear , bool equip , int seed , int statTrak ) -> bool
{
	auto* pCCSPlayerInventory = CCSPlayerInventory::Get();

	if ( !pCCSPlayerInventory )
		return false;

	// Find the item in our scanned list
	DumpedItem_t* pFoundItem = nullptr;
	DumpedSkin_t* pFoundSkin = nullptr;

	for ( auto& item : m_vecDumpedItems )
	{
		if ( item.m_DefIdx == defIdx )
		{
			pFoundItem = &item;

			for ( auto& skin : item.m_DumpedSkins )
			{
				if ( skin.m_ID == paintKit )
				{
					pFoundSkin = &skin;
					break;
				}
			}

			break;
		}
	}

	if ( !pFoundItem )
		return false;

	CEconItem* pItem = CEconItem::Create();

	if ( !pItem )
		return false;

	auto highestIDs = pCCSPlayerInventory->GetHighestIDs();

	pItem->m_ulID = highestIDs.first + 1;
	pItem->m_unInventory = highestIDs.second + 1;
	pItem->m_unAccountID = uint32_t( pCCSPlayerInventory->GetOwner().m_id );
	pItem->m_unDefIndex = defIdx;

	if ( pFoundItem->m_UnusualItem )
		pItem->m_nQuality = IQ_UNUSUAL;

	int skinRarity = pFoundSkin ? pFoundSkin->m_Rarity : 0;
	pItem->m_nRarity = std::clamp( pFoundItem->m_Rarity + skinRarity - 1 , 0 , ( skinRarity == 7 ) ? 7 : 6 );

	if ( paintKit )
	{
		pItem->SetPaintKit( static_cast<float>( paintKit ) );
	}

	// Set wear if specified
	if ( wear > 0.0f )
	{
		pItem->SetPaintWear( wear );
	}

	// Set seed if specified
	if ( seed > 0 )
	{
		pItem->SetPaintSeed( static_cast<float>( seed ) );
	}

	// Set StatTrak if specified
	if ( statTrak >= 0 )
	{
		pItem->SetStatTrak( statTrak );
	}

	if ( pCCSPlayerInventory->AddEconItem( pItem ) )
	{
		AddedItem_t Item;

		if( pFoundItem )
		{
			Item.m_DefIdx = defIdx;
			Item.m_PaintKit = paintKit;
			Item.m_Rarity = pItem->m_nRarity;
			Item.m_Wear = wear;
			Item.m_Seed = seed;
			Item.m_UnusualItem = pFoundItem->m_UnusualItem;
			Item.m_ItemType = pFoundItem->m_ItemType;

			if ( pFoundItem->m_ItemType == EDumpedItemType_t::DUMPED_ITEM_TYPE_AGENT )
			{
				Item.m_bLegacyModel = false;
				Item.m_PaintKitName = pFoundItem->m_PaintKitName;
				Item.m_DisplayName = pFoundItem->m_DisplayName;
			}
			else
			{
				if ( pFoundSkin )
				{
					Item.m_bLegacyModel = pFoundSkin->m_bLegacyModel;
					Item.m_PaintKitName = pFoundSkin->m_PaintKitName;
					Item.m_DisplayName = pFoundSkin->m_DisplayName;
				}
			}

			Item.m_pEconItem = pItem;

			m_AddedItems[pItem->m_ulID] = Item;
		}

		// Auto-equip to loadout for both teams
		auto* pInventoryManager = CCSInventoryManager::Get();
		
		if ( pInventoryManager && pFoundItem )
		{
			// Get item definition to find loadout slot
			auto* pItemSchema = SDK::Interfaces::Source2Client()->GetEconItemSystem()->GetEconItemSchema();
			
			if ( pItemSchema )
			{
				// Find item definition from map
				CEconItemDefinition* pItemDef = nullptr;
				const auto& itemMap = pItemSchema->GetSortedItemDefinitionMap();

				for ( const auto& it : itemMap )
				{
					if ( it.m_value && it.m_value->m_nDefIndex() == defIdx )
					{
						pItemDef = it.m_value;
						break;
					}
				}

				if ( pItemDef )
				{
					int loadoutSlot = pItemDef->LoadoutSlot();

					if ( loadoutSlot >= 0 && equip )
					{
						// Equip to T side (team 2) and CT side (team 3)
						GetInventoryChanger()->OnEquipItemInLoadout( TEAM_TT , loadoutSlot , pItem->m_ulID );
						GetInventoryChanger()->OnEquipItemInLoadout( TEAM_CT , loadoutSlot , pItem->m_ulID );
					}
				}
			}
		}

		DEV_LOG( "[Inventory] Added skin: DefIdx=%d, PaintKit=%d\n" , defIdx , paintKit );

		return true;
	}

	return false;
}

auto CInventoryItemsManager::AddMusicToInventory( uint16_t defIdx , int MusicId , bool equip ) -> bool
{
	if ( auto* pCCSPlayerInventory = CCSPlayerInventory::Get(); pCCSPlayerInventory )
	{
		// Find the item in our scanned list
		DumpedItem_t* pFoundItem = nullptr;
		DumpedSkin_t* pFoundSkin = nullptr;

		for ( auto& item : m_vecDumpedItems )
		{
			if ( item.m_DefIdx == defIdx )
			{
				pFoundItem = &item;

				for ( auto& skin : item.m_DumpedSkins )
				{
					if ( skin.m_ID == MusicId )
					{
						pFoundSkin = &skin;
						break;
					}
				}
			}
		}

		if ( !pFoundItem || !pFoundSkin )
			return false;

		CEconItem* pItem = CEconItem::Create();

		if ( pItem )
		{
			auto highestIDs = pCCSPlayerInventory->GetHighestIDs();

			pItem->m_ulID = highestIDs.first + 1;
			pItem->m_unInventory = highestIDs.second + 1;
			pItem->m_unAccountID = uint32_t( pCCSPlayerInventory->GetOwner().m_id );
			pItem->m_unDefIndex = EInventoryPrefab_t::INVENTORY_PREFAB_MUSIC_KIT;

			pItem->SetMusicId( MusicId );

			if ( pCCSPlayerInventory->AddEconItem( pItem ) )
			{
				AddedItem_t Item;
				{
					Item.m_DefIdx = EInventoryPrefab_t::INVENTORY_PREFAB_MUSIC_KIT;
					Item.m_PaintKit = MusicId;
					Item.m_Rarity = 1;
					Item.m_UnusualItem = false;
					Item.m_PaintKitName = pFoundSkin->m_PaintKitName;
					Item.m_DisplayName = pFoundSkin->m_DisplayName;
					Item.m_ItemType = DUMPED_ITEM_TYPE_MUSIC;
					Item.m_pEconItem = pItem;
				}
				
				m_AddedItems[pItem->m_ulID] = Item;

				if ( equip )
				{
					// Equip to T side (team 2) and CT side (team 3)
					GetInventoryChanger()->OnEquipItemInLoadout( 0 , LOADOUT_SLOT_MUSICKIT , pItem->m_ulID );
				}

				return true;
			}
		}
	}

	return false;
}

auto CInventoryItemsManager::RemoveItemFromInventoryByID( uint64_t ID ) -> bool
{
	if ( IsItemIDAdded( ID ) )
	{
		if ( auto* pInventory = CCSPlayerInventory::Get(); pInventory )
		{
			auto Item = m_AddedItems.find( ID );
			{
				pInventory->RemoveEconItem( Item->second.m_pEconItem );
			}

			m_AddedItems.erase( ID );

			return true;
		}
	}

	return false;
}

auto CInventoryItemsManager::GetSkinName( int paintKitId ) -> std::string
{
	for ( const auto& item : m_vecDumpedItems )
	{
		for ( const auto& skin : item.m_DumpedSkins )
		{
			if ( skin.m_ID == paintKitId )
				return skin.m_DisplayName;
		}
	}

	return "Unknown";
}

auto CInventoryItemsManager::GetWeaponName( uint16_t defIdx ) -> std::string
{
	for ( const auto& item : m_vecDumpedItems )
	{
		if ( item.m_DefIdx == defIdx )
			return item.m_DisplayName;
	}

	return "Unknown";
}

auto CInventoryItemsManager::GetRarityName( int rarity ) -> std::string
{
	switch ( rarity )
	{
		case 0: return "Common";
		case 1: return "Consumer Grade";
		case 2: return "Industrial Grade";
		case 3: return "Mil-Spec";
		case 4: return "Restricted";
		case 5: return "Classified";
		case 6: return "Covert";
		case 7: return "Contraband";
		case 99: return "Unsual";
		default: return "Common";
	}
}

auto CInventoryItemsManager::GetRarityColor( int rarity ) -> ImU32
{
	switch ( rarity )
	{
		case 0: return ImColor( 77 , 116 , 85 );
		case 1: return ImColor( 176 , 195 , 217 );
		case 2: return ImColor( 94 , 152 , 217 );
		case 3: return ImColor( 75 , 105 , 255 );
		case 4: return ImColor( 136 , 71 , 255 );
		case 5: return ImColor( 211 , 44 , 230 );
		case 6: return ImColor( 235 , 75 , 75 );
		case 7: return ImColor( 207 , 106 , 50 );
		case 99: return ImColor( 255 , 215 , 0 );
		default: return ImColor( 222 , 214 , 204 );
	}
}

auto GetInventoryItemsManager() -> CInventoryItemsManager*
{
	return &g_CInventoryItemsManager;
}
