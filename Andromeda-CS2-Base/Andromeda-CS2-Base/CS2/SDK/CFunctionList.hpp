#pragma once

#include <vector>
#include <Common/Common.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/CBasePattern.hpp>

#define DECLARATE_CS2_FUNCTION_SDK_FASTCALL(Ret,Function,Param,UsingParam,CallParam)\
inline Ret Function Param\
{\
	using Fn = Ret ( __fastcall* ) UsingParam;\
	Fn Original = static_cast<Fn>( GetFunctionList()->##Function##.GetFunction() );\
	return Original##CallParam##;\
}

class CFunctionList final
{
public:
	auto OnInit() -> bool;

public:
	CBasePattern CGameEntitySystem_GetBaseEntity = { VmpStr( "CGameEntitySystem::GetBaseEntity" ) , VmpStr( "4C 8D 49 10 81 FA ?? ?? 00 00 77 ?? 8B CA C1 F9 09" ) , CLIENT_DLL };
	CBasePattern CGameEntitySystem_GetLocalPlayerController = { VmpStr( "CGameEntitySystem::GetLocalPlayerController" ) , VmpStr( "E8 ? ? ? ? 48 8B E8 48 85 C0 74 ? 33 DB 39 1D" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern CCSInventoryManager_Get = { VmpStr( "CCSInventoryManager::Get" ) , VmpStr( "E8 ? ? ? ? 48 8B D8 E8 ? ? ? ? 8B 70" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };

	/* String -> "\nLOADOUT ACTION BATCH #%i\n" */
	CBasePattern CCSInventoryManager_EquipItemInLoadout = { VmpStr( "CCSInventoryManager::EquipItemInLoadout" ) , VmpStr( "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 89 54 24 ? 57 41 54 41 55 41 56 41 57 48 83 EC ? 0F B7 F2" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	
	/* String -> "item_sub_position2" */
	CBasePattern CCSPlayerInventory_GetItemInLoadout = { VmpStr( "CCSPlayerInventory::GetItemInLoadout" ) , VmpStr( "40 55 48 83 EC ? 49 63 E8" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };

	// 66 66 66 0F 1F 84 00 00 00 00 00 49 8B 42 28 0F B7 CF 48 8B 5C C8 08 49 8B CF 8B 53 30 E8
	/*E8 ? ? ? ? 33 ED C6 05 ? ? ? ? ?
	00007FF8EEEC826 | 666666:0F1F8400 00000000 | nop word ptr ds:[rax+rax],ax                                               |
	00007FF8EEEC827 | 49:8B42 28               | mov rax,qword ptr ds:[r10+0x28]                                            |
	00007FF8EEEC827 | 0FB7CF                   | movzx ecx,di                                                               |
	00007FF8EEEC827 | 48:8B5CC8 08             | mov rbx,qword ptr ds:[rax+rcx*8+0x8]                                       |
	00007FF8EEEC827 | 49:8BCF                  | mov rcx,r15                                                                |
	00007FF8EEEC827 | 8B53 30                  | mov edx,dword ptr ds:[rbx+0x30]                                            |
	00007FF8EEEC828 | E8 59FFFEFF              | call <client.sub_7FF8EEEB81E0>                                             | CreateBaseTypeCache
	*/
	CBasePattern CGCClientSharedObjectCache_CreateBaseTypeCache = { VmpStr( "CGCClientSharedObjectCache::CreateBaseTypeCache" ) , VmpStr( "E8 ? ? ? ? 41 8B D5 49 8B CD 44 89 68 30" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern CGCClientSharedObjectCache_FindTypeCache = { VmpStr( "CGCClientSharedObjectCache::FindTypeCache" ) , VmpStr( "4C 8B 49 18 44 8B D2 4C 63 41 10 4F 8D 1C C1 49 8B C3" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };

	/*
	00007FF866438B2 | 48:8D05 DD8D6D00         | lea rax,qword ptr ds:[0x7FF866B11908]                                      | 00007FF866B11908:"Update(CEconItem)"
	00007FF866438B2 | 45:33C0                  | xor r8d,r8d                                                                |
	00007FF866438B2 | 48:894424 30             | mov qword ptr ss:[rsp+0x30],rax                                            |
	00007FF866438B3 | 4C:8D0D 1E8E6D00         | lea r9,qword ptr ds:[0x7FF866B11958]                                       | 00007FF866B11958:"CEconItem"
	00007FF866438B3 | 48:8D05 DF8D6D00         | lea rax,qword ptr ds:[0x7FF866B11920]                                      | 00007FF866B11920:"Create(CEconItem)"
	00007FF866438B4 | 48:894424 28             | mov qword ptr ss:[rsp+0x28],rax                                            |
	00007FF866438B4 | 48:8D15 634AFBFF         | lea rdx,qword ptr ds:[0x7FF8663ED5B0]                                      | CreateSharedObjectSubclassEconItem
	*/
	CBasePattern CreateSharedObjectSubclassEconItem = { VmpStr( "CreateSharedObjectSubclassEconItem" ) , VmpStr( "48 83 EC 28 B9 48 00 00 00 E8 ? ? ? ? 48 85 C0 74 3A 48 8D ? ? ? ? ? C7 40 32 00 00 FF 00 48 89 08 48 8D ? ? ? ? ? 48 89 48 08" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };

	/*
	00007FF9D272C96 | 85D2                     | test edx,edx                                      | GetAttributeDefinitionInterface
	00007FF9D272C96 | 78 17                    | js client.7FF9D272C97B                            |
	00007FF9D272C96 | 3B91 58010000            | cmp edx,dword ptr ds:[rcx+0x158]                  |
	00007FF9D272C96 | 7D 0F                    | jge client.7FF9D272C97B                           |
	00007FF9D272C96 | 48:8B81 60010000         | mov rax,qword ptr ds:[rcx+0x160]                  |
	00007FF9D272C97 | 48:63D2                  | movsxd rdx,edx                                    |
	00007FF9D272C97 | 48:8B04D0                | mov rax,qword ptr ds:[rax+rdx*8]                  |
	00007FF9D272C97 | C3                       | ret                                               |
	00007FF9D272C97 | 33C0                     | xor eax,eax                                       |
	00007FF9D272C97 | C3                       | ret                                               |
	00007FF9D272C97 | CC                       | int3                                              |
	00007FF9D272C97 | CC                       | int3                                              |
	00007FF9D272C98 | 40:55                    | push rbp                                          |
	00007FF9D272C98 | 48:83EC 40               | sub rsp,0x40                                      |
	00007FF9D272C98 | 48:895C24 50             | mov qword ptr ss:[rsp+0x50],rbx                   |
	00007FF9D272C98 | 48:897424 58             | mov qword ptr ss:[rsp+0x58],rsi                   |
	00007FF9D272C99 | 48:8BF1                  | mov rsi,rcx                                       |
	00007FF9D272C99 | 48:8B0D 960D5900         | mov rcx,qword ptr ds:[<g_VProfCurrentProfile>]    |
	00007FF9D272C99 | 4C:897424 38             | mov qword ptr ss:[rsp+0x38],r14                   |
	00007FF9D272C99 | 4C:897C24 30             | mov qword ptr ss:[rsp+0x30],r15                   |
	00007FF9D272C9A | 4C:8BFA                  | mov r15,rdx                                       |
	00007FF9D272C9A | 44:8BB1 20100000         | mov r14d,dword ptr ds:[rcx+0x1020]                |
	00007FF9D272C9A | 45:85F6                  | test r14d,r14d                                    |
	00007FF9D272C9B | 74 24                    | je client.7FF9D272C9D7                            |
	00007FF9D272C9B | C74424 28 04000000       | mov dword ptr ss:[rsp+0x28],0x4                   |
	00007FF9D272C9B | 4C:8D0D 0A847B00         | lea r9,qword ptr ds:[0x7FF9D2EE4DCC]              | 00007FF9D2EE4DCC:"Steam"
	00007FF9D272C9C | 45:33C0                  | xor r8d,r8d                                       |
	00007FF9D272C9C | C64424 20 00             | mov byte ptr ss:[rsp+0x20],0x0                    |
	00007FF9D272C9C | 48:8D15 C70F7C00         | lea rdx,qword ptr ds:[0x7FF9D2EED998]             | 00007FF9D2EED998:"CEconItemSchema::GetAttributeDefinitionByName"
	*/
	CBasePattern CEconItemSchema_GetAttributeDefinitionInterface = { VmpStr( "CEconItemSchema::GetAttributeDefinitionInterface" ) , VmpStr( "E8 ? ? ? ? 48 85 C0 74 ? E8 ? ? ? ? 0F B7 14 3B 48 8B C8 E8 ? ? ? ? 0F B6 48" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern CEconItem_SetDynamicAttributeValueUint = { VmpStr( "CEconItem::SetDynamicAttributeValueUint" ) , VmpStr( "E9 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 49 8B C0 48 8B CA 48 8B D0" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	
	CBasePattern IGameEvent_GetName = { VmpStr( "IGameEvent::GetName" ) , VmpStr( "8B 41 14 0F BA E0 1E 73 05 48 8D 41 18 C3" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern IGameEvent_GetInt64 = { VmpStr( "IGameEvent::GetInt64" ) , VmpStr( "48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 41 56 48 83 EC 30 48 8B 01 41 8B F0 4C 8B F1 41 B0 01 48 8D 4C 24 20 48 8B DA 48 8B 78" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern IGameEvent_GetPlayerController = { VmpStr( "IGameEvent::GetPlayerController" ) , VmpStr( "48 83 EC 38 8B 02 4C 8D 44 24 20" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern IGameEvent_GetString = { VmpStr( "IGameEvent::GetString" ) , VmpStr( "48 83 EC 38 8B 02 48 83 C1 58 89 44 24 20 8B 42 04 89 44 24 24 48 8B 42 08 48 8D 54 24 20 48 89 44 24 28 E8 ? ? ? ? 48 83 C4 38 C3 CC CC CC 33 C9" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern IGameEvent_SetString = { VmpStr( "IGameEvent::SetString" ) , VmpStr( "48 83 EC 38 8B 02 48 83 C1 58 89 44 24 20 41 B1 1A" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	
	CBasePattern C_EconItemView_GetStaticData = { VmpStr( "C_EconItemView::GetStaticData" ) , VmpStr( "40 56 48 83 EC ? 48 89 5C 24 ? 48 8B F1 48 8B 1D ? ? ? ? 48 85 DB 75 ? B9 ? ? ? ? 48 89 7C 24 ? E8 ? ? ? ? 33 FF 48 8B D8 48 85 C0 74 ? 48 8D 05 ? ? ? ? 48 89 7B ? B9 ? ? ? ? 48 89 03 E8 ? ? ? ? 48 85 C0 74 ? 48 8B C8 E8 ? ? ? ? 48 8B F8 48 8D 05 ? ? ? ? 48 89 7B ? 48 89 03 EB ? 48 8B DF 48 8B 7C 24 ? 48 89 1D ? ? ? ? 48 8B 4B ? 48 8B 5C 24 ? 48 85 C9 75" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_EconItemView_GetBasePlayerWeaponVData = { VmpStr( "C_EconItemView::GetBasePlayerWeaponVData" ) , VmpStr( "48 81 EC ? ? ? ? 48 85 C9 75 ? 33 C0 48 81 C4 ? ? ? ? C3 48 89 9C 24" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_BaseModelEntity_SetModel = { VmpStr( "C_BaseModelEntity::SetModel" ) , VmpStr( "40 53 48 83 EC ? 48 8B D9 4C 8B C2 48 8B 0D ? ? ? ? 48 8D 54 24 40" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	
	CBasePattern CGameSceneNode_SetMeshGroupMask = { VmpStr( "CGameSceneNode::SetMeshGroupMask" ) , VmpStr( "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8D 99 ? ? ? ? 48 8B 71" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	
	CBasePattern C_CSWeaponBase_UpdateSubclass = { VmpStr( "C_CSWeaponBase::UpdateSubclass" ) , VmpStr( "40 53 48 83 EC 30 48 8B 41 10 48 8B D9 8B 50 30" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_CSWeaponBase_UpdateSkin = { VmpStr( "C_CSWeaponBase::UpdateSkin" ) , VmpStr( "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 8B DA 48 8B F9 E8" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_CSWeaponBase_UpdateCompositeMaterial = { VmpStr( "C_CSWeaponBase::UpdateCompositeMaterial" ) , VmpStr( "E8 ? ? ? ? 48 8D 8B ? ? ? ? 48 89 BC 24" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };

	CBasePattern CEconItem_SerializeToProtoBufItem = { VmpStr( "CEconItem::SerializeToProtoBufItem" ) , VmpStr( "40 55 56 48 83 EC ? 48 8B 41 ? 48 8B F2" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_BaseEntity_SetBodyGroup = { VmpStr( "C_BaseEntity::SetBodyGroup" ) , VmpStr( "85 D2 0F 88 5C" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern CCSGO_HudWeaponSelection_ClearHudWeaponIcon = { VmpStr( "CCSGO_HudWeaponSelection::ClearHudWeaponIcon" ) , VmpStr( "E8 ? ? ? ? 8B F8 C6 84 24" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern FindHudElement = { VmpStr( "FindHudElement" ) , VmpStr( "4C 8B DC 53 48 83 EC 50 48 8B 05" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdTick = { VmpStr( "GetCUserCmdTick" ) , VmpStr( "48 83 EC ? 4C 8B 0D ? ? ? ? 4C 8B DA" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdArray = { VmpStr( "GetCUserCmdArray" ) , VmpStr( "48 89 4C 24 ? 41 56 41 57" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdBySequenceNumber = { VmpStr( "GetCUserCmdBySequenceNumber" ) , VmpStr( "40 53 48 83 EC ? 8B DA E8 ? ? ? ? 4C 8B C0" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern CTraceFilter_Constructor = { VmpStr( "CTraceFilter::Constructor" ) , VmpStr( "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_BaseEntity_ComputeHitboxSurroundingBox = { VmpStr( "C_BaseEntity::ComputeHitboxSurroundingBox" ) , VmpStr( "48 89 5C 24 10 48 89 6C 24 18 56 57 41 56 B8 A0" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern CSkeletonInstance_CalcWorldSpaceBones = { VmpStr( "CSkeletonInstance::CalcWorldSpaceBones" ) , VmpStr( "48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 B8 ? ? ? ? E8 ? ? ? ? 48 2B E0 48 8D 6C 24 ? 48 8B 81" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_BaseEntity_GetBoneIdByName = { VmpStr( "C_BaseEntity::GetBoneIdByName" ) , VmpStr( "E8 ? ? ? ? 48 8B CF 85 C0 78 ? 44 8B C0" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern ScreenTransform = { VmpStr( "ScreenTransform" ) , VmpStr( "48 89 74 24 ? 57 48 83 EC ? 48 8B 05 ? ? ? ? 48 8B FA" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern CreateSubtickMoveStep = { VmpStr( "CreateSubtickMoveStep" ) , VmpStr( "E8 ? ? ? ? 48 8B D0 49 8D 4E 18 E8 ? ? ? ? 4C 8B C8 4C 8D 43 02 49 8B D1 48 8B CE E8 ? ? ? ? 48 8B D8 48 85 C0 0F 84 ? ? ? ? 48 3B 06 0F 83 ? ? ? ? 0F B7 00 66 C7 45 67 ? ? 66 3B 45 67 74 ? E9 ? ? ? ? 40 80 FF ? 0F 85 ? ? ? ? 41 83 4E 10 ?" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern ProtobufAddToRepeatedPtrElement = { VmpStr( "ProtobufAddToRepeatedPtrElement" ) , VmpStr( "48 89 5C 24 ? 57 48 83 EC ? 48 8B D9 48 8B FA 48 8B 49 ? 48 85 C9 74 ? 8B 01" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern IGamePhysicsQuery_TraceShape = { VmpStr( "IGamePhysicsQuery::TraceShape" ) , VmpStr( "48 89 5C 24 ? 48 89 4C 24 ? 55 57" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern CCSGOInput_GetViewAngles = { VmpStr( "CCSGOInput::GetViewAngles" ) , VmpStr( "E8 ? ? ? ? EB ? 48 8B 01 48 8D 54 24 ?" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern CCSGOInput_SetViewAngles = { VmpStr( "CCSGOInput::SetViewAngles" ) , VmpStr( "85 D2 75 ? 48 63 81" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
};

auto GetFunctionList() -> CFunctionList*;
