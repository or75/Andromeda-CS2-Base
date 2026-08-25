#include "CFunctionList.hpp"

static CFunctionList g_CFunctionList{};

auto CFunctionList::OnInit() -> bool
{
	std::vector<CBasePattern*> vPatterns =
	{
		&CGameEntitySystem_GetBaseEntity,
		&CGameEntitySystem_GetLocalPlayerController,
		&CCSInventoryManager_Get,
		&CCSInventoryManager_EquipItemInLoadout,
		&CCSPlayerInventory_GetItemInLoadout,
		&CGCClientSharedObjectCache_CreateBaseTypeCache,
		&CGCClientSharedObjectCache_FindTypeCache,
		&CreateSharedObjectSubclassEconItem,
		&CEconItemSchema_GetAttributeDefinitionInterface,
		&CEconItem_SetDynamicAttributeValueUint,
		&IGameEvent_GetName,
		&IGameEvent_GetInt64,
		&IGameEvent_GetPlayerController,
		&IGameEvent_GetString,
		&IGameEvent_SetString,
		&C_BaseEntity_ComputeHitboxSurroundingBox,
		&C_EconItemView_GetStaticData,
		&CSkeletonInstance_CalcWorldSpaceBones,
		&C_BaseEntity_GetBoneIdByName,
		&C_EconItemView_GetBasePlayerWeaponVData,
		&KeyValues3_LoadKV3,
		&IGamePhysicsQuery_TraceShape,
		&CCSGOInput_GetViewAngles,
		&CCSGOInput_SetViewAngles,
		&LineGoesThroughSmoke,
		&FindHudElement,
		&C_CSWeaponBaseGun_GetInaccuracy,
		&C_CSWeaponBaseGun_GetSpread,
		&SetLocalPlayerReady,
		&ScreenTransform,
		&CreateSubtickMoveStep,
		&ProtobufAddToRepeatedPtrElement,
		&KeyValues_GetName,
		&KeyValues_GetFirstSubKey,
		&KeyValues_GetFirstTrueSubKey,
		&KeyValues_GetNextTrueSubKey,
		&KeyValues_GetNextKey,
		&KeyValues_FindKey,
		&KeyValues_GetInt,
		&KeyValues_GetFloat,
		&KeyValues_GetUint64,
		&KeyValues_FindKeyAndParent,
		&CKeyValues_Internal_GetString,
		&KeyValues_Constructor,
		&KeyValues_Destructor,
		&KeyValues_LoadFromFile,
		&KeyValues_Element,
		&KeyValues_Count,
		&C_EconItemView_GetCustomPaintKitIndex,
		&C_BaseModelEntity_SetModel,
		&CGameSceneNode_SetMeshGroupMask,
		&C_CSWeaponBase_UpdateSubclass,
		&C_CSWeaponBase_UpdateSkin,
		&C_CSWeaponBase_UpdateCompositeMaterial,
		&C_CSPlayerPawn_SetBodyGroup,
		&GetCUserCmdTick,
		&GetCUserCmdArray,
		&GetCUserCmdBySequenceNumber,
		&CEconItem_SerializeToProtoBufItem,
		&CUIEngineSource2_RunScript,
		&CTraceFilter_Constructor,
		&CCSGO_HudWeaponSelection_ClearHudWeaponIcon,
		&C_BaseEntity_GetHitBoxSet,
		&C_BaseEntity_UpdateBodyGroupChoice,
		&C_EconItemView_SetAttributeValueByName,
		&C_CSWeaponBase_UpdateCompositeMaterialSet,
		&AnalizePeModule,
	};

	auto Searched = true;

	for ( auto& Pattern : vPatterns )
	{
		if ( !Pattern->Search() )
			Searched = false;
	}

	return Searched;
}

auto GetFunctionList() -> CFunctionList*
{
	return &g_CFunctionList;
}
