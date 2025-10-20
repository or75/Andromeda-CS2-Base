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
		&C_EconItemView_GetStaticData,
		&C_EconItemView_GetBasePlayerWeaponVData,
		&C_BaseModelEntity_SetModel,
		&CGameSceneNode_SetMeshGroupMask,
		&C_CSWeaponBase_UpdateSubclass,
		&C_CSWeaponBase_UpdateSkin,
		&C_CSWeaponBase_UpdateCompositeMaterial,
		&CEconItem_SerializeToProtoBufItem,
		&C_BaseEntity_SetBodyGroup,
		&CCSGO_HudWeaponSelection_ClearHudWeaponIcon,
		&FindHudElement,
		&GetCUserCmdTick,
		&GetCUserCmdArray,
		&GetCUserCmdBySequenceNumber,
		&CTraceFilter_Constructor,
		&C_BaseEntity_ComputeHitboxSurroundingBox,
		&CSkeletonInstance_CalcWorldSpaceBones,
		&C_BaseEntity_GetBoneIdByName,
		&ScreenTransform,
		&CreateSubtickMoveStep,
		&ProtobufAddToRepeatedPtrElement,
		&IGamePhysicsQuery_TraceShape,
		&CCSGOInput_GetViewAngles,
		&CCSGOInput_SetViewAngles,
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
