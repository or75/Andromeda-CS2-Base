#include "CInventoryChanger.hpp"

#include <algorithm>
#include <Fnv1a/Hash_Fnv1a_Constexpr.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>

#include <CS2/SDK/Interface/IGameEvent.hpp>
#include <CS2/SDK/Interface/CSource2Client.hpp>
#include <CS2/SDK/Interface/IEngineToClient.hpp>
#include <CS2/SDK/Interface/CGameEntitySystem.hpp>
#include <CS2/SDK/Interface/CLocalize.hpp>

#include <CS2/SDK/Econ/CEconItem.hpp>
#include <CS2/SDK/Econ/CEconItemSchema.hpp>
#include <CS2/SDK/Econ/CEconItemSystem.hpp>
#include <CS2/SDK/Econ/CEconItemDefinition.hpp>

#include <CS2/Protobuf/base_gcmessages.pb.h>

#include <CS2/Hook/Hook_EquipItemInLoadout.hpp>

#include <CS2/SDK/Cstrike15/CCSPlayerInventory.hpp>
#include <CS2/SDK/Cstrike15/CCSInventoryManager.hpp>

#include <CS2/SDK/GCSDK/GCSDKTypes/EconItemConstants.hpp>
#include <CS2/SDK/GCSDK/GCSDKTypes/ESOCacheEvent.hpp>

#include <GameClient/CL_Players.hpp>
#include <GameClient/CL_Weapons.hpp>
#include <GameClient/CL_ItemDefinition.hpp>

#include <AndromedaClient/Settings/CSettingsJson.hpp>
#include <AndromedaClient/Features/CInventoryChanger/CInventoryItemsManager.hpp>

static CInventoryChanger g_CInventoryChanger{};

auto CInventoryChanger::OnFrameStageNotify( int FrameStage ) -> void
{
	if ( FrameStage != 6 || !SDK::Interfaces::EngineToClient()->IsInGame() )
		return;

	auto pLocalInventory = CCSPlayerInventory::Get();

	if ( !pLocalInventory )
		return;

	const auto steamID = pLocalInventory->GetOwner().ID();
	const auto pLocalPlayerController = GetCL_Players()->GetLocalPlayerController();

	if ( !pLocalPlayerController )
		return;

	auto* pLocalPawn = GetCL_Players()->GetLocalPlayerPawn();

	if ( !pLocalPawn )
		return;

	auto* pWeaponServices = pLocalPawn->m_pWeaponServices();

	if ( !pWeaponServices )
		return;

	auto* pC_CS2HudModelWeapon = pLocalPawn->GetViewModel();

	if ( !pC_CS2HudModelWeapon )
		return;

	for ( auto WeaponIndex = 0; WeaponIndex < pWeaponServices->m_hMyWeapons().Count(); ++WeaponIndex )
	{
		const auto& Weapon = pWeaponServices->m_hMyWeapons()[WeaponIndex];

		if ( !Weapon.IsValid() )
			continue;

		auto* pEntity = Weapon.Get();

		if ( !pEntity || !pEntity->IsBasePlayerWeapon() )
			continue;

		auto pWeapon = reinterpret_cast<C_CSWeaponBase*>( pEntity );

		if ( pWeapon->GetOriginalOwnerXuid() != steamID )
			continue;

		auto pAttributeContainer = pWeapon->m_AttributeManager();

		if ( !pAttributeContainer )
			continue;

		auto pWeaponItemView = pAttributeContainer->m_Item();

		if ( !pWeaponItemView )
			continue;

		auto pWeaponDefinition = pWeaponItemView->GetStaticData();

		if ( !pWeaponDefinition )
			continue;

		auto pWeaponSceneNode = pWeapon->m_pGameSceneNode();

		if ( !pWeaponSceneNode )
			continue;

		int id = pAttributeContainer->m_Item()->m_iItemDefinitionIndex();

		if ( id == 43 || id == 44 || id == 45 || id == 46 || id == 47 || id == 48 || id == 49 )
			continue;

		C_EconItemView* pWeaponInLoadoutItemView = nullptr;

		if ( pWeaponDefinition->IsWeapon() )
		{
			for ( int i = 0; i < LOADOUT_SLOT_COUNT; ++i )
			{
				auto pItemView = pLocalInventory->GetItemInLoadout( pWeapon->m_iOriginalTeamNumber() , i );

				if ( !pItemView )
					continue;

				if ( pItemView->m_iItemDefinitionIndex() == pWeaponDefinition->m_nDefIndex() )
				{
					pWeaponInLoadoutItemView = pItemView;
					break;
				}
			}
		}
		else
		{
			pWeaponInLoadoutItemView = pLocalInventory->GetItemInLoadout( pWeapon->m_iOriginalTeamNumber() , pWeaponDefinition->LoadoutSlot() );
		}

		if ( !pWeaponInLoadoutItemView )
			continue;

		auto pWeaponInLoadoutDefinition = pWeaponInLoadoutItemView->GetStaticData();

		if ( !pWeaponInLoadoutDefinition )
			continue;

		const auto isKnife = pWeaponInLoadoutDefinition->IsKnife( false );

		if ( !isKnife && pWeaponInLoadoutDefinition->m_nDefIndex() != pWeaponDefinition->m_nDefIndex() )
			continue;

		pWeaponItemView->m_bDisallowSOC() = false;
		pWeaponItemView->m_bRestoreCustomMaterialAfterPrecache() = true;
		pWeaponItemView->m_iItemID() = pWeaponInLoadoutItemView->m_iItemID();
		pWeaponItemView->m_iItemIDHigh() = pWeaponInLoadoutItemView->m_iItemIDHigh();
		pWeaponItemView->m_iItemIDLow() = pWeaponInLoadoutItemView->m_iItemIDLow();
		pWeaponItemView->m_iItemDefinitionIndex() = pWeaponInLoadoutItemView->m_iItemDefinitionIndex();
		pWeaponItemView->m_iAccountID() = uint32_t( steamID );

		pWeapon->m_nFallbackPaintKit() = pWeaponInLoadoutItemView->GetCustomPaintKitIndex();

		C_EconItemView_SetAttributeValueByName( pWeaponItemView , "set item texture prefab" , pWeaponInLoadoutItemView->GetCustomPaintKitIndex() );

		const auto& AddedItems = GetInventoryItemsManager()->GetAddedItems();
		const auto& Skin = AddedItems.find( pWeaponInLoadoutItemView->m_iItemID() );

		if ( Skin != AddedItems.end() ) 
		{
			pWeapon->m_nFallbackSeed() = Skin->second.m_Seed;
			pWeapon->m_flFallbackWear() = Skin->second.m_Wear;

			C_EconItemView_SetAttributeValueByName( pWeaponItemView , "set item texture wear" , Skin->second.m_Wear );
			C_EconItemView_SetAttributeValueByName( pWeaponItemView , "set item texture seed" , static_cast<float>( Skin->second.m_Seed ) );
		}

		auto* pKnifeModel = pLocalPawn->GetKnifeModel();
		auto* pCompositeMaterial = reinterpret_cast<CCompositeMaterialOwner*>( (PBYTE)pWeapon + g_CompositeMaterialOffset );

		if ( pCompositeMaterial && m_ApplySkin.find( pCompositeMaterial ) == m_ApplySkin.end() )
		{
			uint64_t meshGroupMask = 1;

			if ( Skin != AddedItems.end() )
				meshGroupMask = 1 + static_cast<uint64_t>( Skin->second.m_bLegacyModel );

			DEV_LOG( "meshGroupMask: %i\n" , meshGroupMask );

			if ( isKnife )
			{
				pWeapon->SetModel( pWeaponInLoadoutDefinition->m_pszModelName() );

				if ( pKnifeModel )
				{
					pKnifeModel->SetModel( pWeaponInLoadoutDefinition->m_pszModelName() );
					pKnifeModel->m_pGameSceneNode()->SetMeshGroupMask( meshGroupMask );
					pKnifeModel->m_pGameSceneNode()->PostDataUpdate();
				}
			}

			pWeapon->m_pGameSceneNode()->SetMeshGroupMask( meshGroupMask );
			pC_CS2HudModelWeapon->m_pGameSceneNode()->SetMeshGroupMask( meshGroupMask );

			std::uint32_t Hash = CUtlStringToken( std::to_string( pWeaponInLoadoutDefinition->m_nDefIndex() ).c_str() ).GetHashCode();

			pWeapon->m_nSubclassID().SetHashCode( Hash );
			pWeapon->UpdateSubclass();

			pWeapon->UpdateCompositeMaterial( pCompositeMaterial );
			pWeapon->UpdateCompositeMaterialSet();
			pWeapon->UpdateSkin();
			pWeapon->m_pGameSceneNode()->PostDataUpdate();

			auto* pCCSGO_HudWeaponSelection = CCSGOHudElement::Find<CCSGO_HudWeaponSelection>( "HudWeaponSelection" );

			if ( pCCSGO_HudWeaponSelection )
			{
				pWeaponItemView->pCEconItemDescription() = 0;

				CCSGO_HudWeaponSelection_ClearHudWeaponIcon(
					reinterpret_cast<CCSGO_HudWeaponSelection*>(
						(uintptr_t)pCCSGO_HudWeaponSelection - 0x98 ) , 0 , 0 );
			}

			m_ApplySkin[pCompositeMaterial] = true;
		}
	}

	SetGlove( pLocalInventory , pLocalPawn , pC_CS2HudModelWeapon );
	SetAgent( pLocalInventory , pLocalPawn );
	SetMusic( pLocalInventory );
}

auto CInventoryChanger::OnEquipItemInLoadout( int iTeam , int iSlot , uint64_t iItemID ) -> void
{
	auto* pInventoryManager = CCSInventoryManager::Get();

	if ( !pInventoryManager )
		return;

	auto* pPlayerInventory = CCSPlayerInventory::Get();

	if ( !pPlayerInventory )
		return;

	const auto& AddedItems = GetInventoryItemsManager()->GetAddedItems();

	if ( AddedItems.find( iItemID ) == AddedItems.end() )
		return;

	DEV_LOG( "OnEquipItemInLoadout: %i , %i , %lld\n" , iTeam , iSlot , iItemID );

	EquipConfigItem( iTeam , iSlot , iItemID , true );

	auto* pEconItemView = pPlayerInventory->GetItemViewForItem( iItemID );

	if ( !pEconItemView )
		return;

	auto* pItemInLoadOut = pPlayerInventory->GetItemInLoadout( iTeam , iSlot );

	if ( !pItemInLoadOut )
		return;

	auto* pItemInLoadoutStaticData = pItemInLoadOut->GetStaticData();

	if ( !pItemInLoadoutStaticData )
		return;

	if ( pItemInLoadoutStaticData->IsGlove( false ) ||
		 pItemInLoadoutStaticData->IsKnife( false ) ||
		 pItemInLoadoutStaticData->IsAgent( false ) ||
		 pItemInLoadoutStaticData->m_nDefIndex() == pEconItemView->m_iItemDefinitionIndex() )
	{
		DEV_LOG( "Skin Cleared #1\n" );

		// force glove
		if ( pItemInLoadoutStaticData->IsGlove( false ) )
			m_bApplyGloves = true;

		// force skins and knife reaplly
		if ( pItemInLoadoutStaticData->m_nDefIndex() == pEconItemView->m_iItemDefinitionIndex() ||
			 pItemInLoadoutStaticData->IsKnife( false ) )
		{
			m_ApplySkin.clear();

			DEV_LOG( "Skin Cleared #2\n" );
		}

		return;
	}

	const uint64_t defaultItemID = ( std::uint64_t( 0xF ) << 60 ) | pEconItemView->m_iItemDefinitionIndex();

	pInventoryManager->EquipItemInLoadout( iTeam , iSlot , defaultItemID );

	auto* pItemInLoadoutSOCData = pItemInLoadOut->GetSOCData();
	
	if ( !pItemInLoadoutSOCData )
		return;

	pPlayerInventory->SOUpdated( pPlayerInventory->GetOwner() , (CSharedObject*)pItemInLoadoutSOCData , GCSDK::eSOCacheEvent_Incremental );
}

auto CInventoryChanger::OnFireEventClientSide( IGameEvent* pGameEvent ) -> void
{
	if ( _strcmpi( pGameEvent->GetName() , XorStr( "player_death" ) ) == 0 )
	{
		if ( auto* pPlayerInventory = CCSPlayerInventory::Get(); pPlayerInventory )
		{
			if ( auto* pLocalPlayerPawn = GetCL_Players()->GetLocalPlayerPawn(); pLocalPlayerPawn )
			{
				if ( auto* pItemInLoadOut = pPlayerInventory->GetItemInLoadout( pLocalPlayerPawn->m_iTeamNum() , LOADOUT_SLOT_MELEE ); pItemInLoadOut )
				{
					if ( auto* pItemInLoadoutStaticData = pItemInLoadOut->GetStaticData(); pItemInLoadoutStaticData )
					{
						if ( const auto* pAttackerController = pGameEvent->GetPlayerController( XorStr( "attacker" ) ); pAttackerController )
						{
							if ( GetCL_Weapons()->GetLocalWeaponType() == CSWeaponType_t::WEAPONTYPE_KNIFE )
							{
								if ( auto* pLocalPlayerController = GetCL_Players()->GetLocalPlayerController(); pLocalPlayerController )
								{
									if ( pAttackerController == pLocalPlayerController )
									{
										const auto WeaponKillName = pGameEvent->GetString( "weapon" );

										if ( !strcmp( WeaponKillName , "knife" ) )
										{
											const auto szKnifeName = GetKnifeIconNameFromDefinitionIndex( pItemInLoadoutStaticData->m_nDefIndex() );

											pGameEvent->SetString( "weapon" , szKnifeName );
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

auto CInventoryChanger::SetGlove( CCSPlayerInventory* pInventory , C_CSPlayerPawn* pLocalPawn , C_CS2HudModelWeapon* pViewModel ) -> void
{
	auto& pGloveItemView = pLocalPawn->m_EconGloves();
	auto* pItemViewLoadout = pInventory->GetItemInLoadout( pLocalPawn->m_iTeamNum() , LOADOUT_SLOT_CLOTHING_HANDS );
	
	if ( !pItemViewLoadout )
		return;

	static std::uint8_t uUpdateFrames = 0U;

	if ( pLocalPawn->m_flLastSpawnTimeIndex().m_Value != m_flLastSpawnTime || m_bApplyGloves )
	{
		uUpdateFrames = 3;

		{
			pGloveItemView.m_bDisallowSOC() = false;
			pGloveItemView.m_bRestoreCustomMaterialAfterPrecache() = true;
			pGloveItemView.m_iItemDefinitionIndex() = pItemViewLoadout->m_iItemDefinitionIndex();
			pGloveItemView.m_iItemID() = pItemViewLoadout->m_iItemID();
			pGloveItemView.m_iItemIDHigh() = pItemViewLoadout->m_iItemIDHigh();
			pGloveItemView.m_iItemIDLow() = pItemViewLoadout->m_iItemIDLow();
			pGloveItemView.m_iAccountID() = pItemViewLoadout->m_iAccountID();
		}

		m_flLastSpawnTime = pLocalPawn->m_flLastSpawnTimeIndex().m_Value;
		m_bApplyGloves = false;
	}

	if ( uUpdateFrames > 0 )
	{
		pGloveItemView.m_bInitialized() = true;

		pLocalPawn->SetBodyGroup();
		C_BaseEntity_UpdateBodyGroupChoice( pLocalPawn );
		pLocalPawn->m_bNeedToReApplyGloves() = true;

		uUpdateFrames--;
	}
}

auto CInventoryChanger::SetAgent( CCSPlayerInventory* pInventory , C_CSPlayerPawn* pLocalPawn ) -> void
{
	auto* pItemViewLoadout = pInventory->GetItemInLoadout( pLocalPawn->m_iTeamNum() , LOADOUT_SLOT_CLOTHING_CUSTOMPLAYER );

	if ( !pItemViewLoadout )
		return;

	auto* pEconDefinition = pItemViewLoadout->GetStaticData();

	if ( !pEconDefinition )
		return;

	if ( !pLocalPawn->m_pGameSceneNode() || !pLocalPawn->m_pGameSceneNode()->GetSkeletonInstance() )
		return;

	static uint64_t HashAgent = 0;

	const auto pModelName = pEconDefinition->m_pszModelName();

	if ( pModelName )
	{
		if ( hash_64_fnv1a_const( pModelName ) == HashAgent )
			return;

		HashAgent = hash_64_fnv1a_const( pModelName );

		if ( strlen( pModelName ) > 0 )
			pLocalPawn->SetModel( pModelName );
	}
}

auto CInventoryChanger::SetMusic( CCSPlayerInventory* pInventory ) -> void
{
	if ( auto* pLocalPlayerController = GetCL_Players()->GetLocalPlayerController(); pLocalPlayerController )
	{
		if ( auto* pInventoryServices = pLocalPlayerController->m_pInventoryServices(); pInventoryServices )
		{
			auto* pItemViewLoadout = pInventory->GetItemInLoadout( 0 , LOADOUT_SLOT_MUSICKIT );

			if ( !pItemViewLoadout )
				return;

			auto* pEconDefinition = pItemViewLoadout->GetStaticData();

			if ( !pEconDefinition )
				return;

			auto* pSOCData = pItemViewLoadout->GetSOCData();

			if ( !pSOCData )
				return;

			static CSOEconItem g_CSOEconItem;

			pSOCData->SerializeToProtoBufItem( &g_CSOEconItem );

			for ( auto AttributeIndex = 0; AttributeIndex < g_CSOEconItem.attribute_size(); AttributeIndex++ )
			{
				const auto& Attribute = g_CSOEconItem.attribute( AttributeIndex );

				if ( Attribute.has_def_index() && Attribute.has_value_bytes() && Attribute.def_index() == ATTRIBUTE_MUSIC_ID )
				{
					pInventoryServices->m_unMusicID() = *(uint32_t*)( Attribute.value_bytes().data() );
				}
			}
		}
	}
}

auto CInventoryChanger::EquipConfigItem( int iTeam , int iSlot , uint64_t iItemID , bool Equipped ) -> void
{
	DEV_LOG( "EquipConfigItem: %i , %i , %lld , %i\n" , iTeam , iSlot , iItemID , Equipped );

	for ( auto& EquipItem : m_vecEquipItems )
	{
		if ( EquipItem.m_iTeam == iTeam && EquipItem.m_iSlot == iSlot )
		{
			EquipItem.m_bEquipped = false;
		}
	}

	auto ItemHasAdded = false;

	for ( auto& EquipItem : m_vecEquipItems )
	{
		if ( EquipItem.m_iItemID == iItemID )
		{
			EquipItem.m_bEquipped = Equipped;
			ItemHasAdded = true;

			break;
		}
	}

	if ( !ItemHasAdded )
		m_vecEquipItems.emplace_back( iTeam , iSlot , iItemID , Equipped );

	if ( Equipped )
		EquipItemInLoadout_o( CCSInventoryManager::Get() , iTeam , iSlot , iItemID );
}

auto GetInventoryChanger() -> CInventoryChanger*
{
	return &g_CInventoryChanger;
}
