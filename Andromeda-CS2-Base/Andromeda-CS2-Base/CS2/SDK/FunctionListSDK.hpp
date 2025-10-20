#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/CFunctionList.hpp>
#include <CS2/SDK/GCSDK/GCSDKTypes/SOID_t.hpp>
#include <CS2/SDK/Math/QAngle.hpp>
#include <CS2/SDK/Math/Vector3.hpp>
#include <CS2/SDK/Update/Offsets.hpp>

class CGameEntitySystem;
class CCSPlayerController;
class CCSInventoryManager;
class C_EconItemView;
class CCSPlayerInventory;
class CGCClientSharedObjectCache;
class CGCClient;
class CGCClientSharedObjectTypeCache;
class CGCClientSharedObjectCache;
class CEconItem;
class CEconItemSchema;
class IGameEvent;
class CEconItemDefinition;
class CCSWeaponBaseVData;
class C_BaseModelEntity;
class CGameSceneNode;
class C_CSWeaponBase;
class CCompositeMaterialOwner;
class C_BaseEntity;
class CSOEconItem;
class CCSGO_HudWeaponSelection;
class CUserCmdArray;
class CUserCmd;
class CTraceFilter;
class CGameTrace;
class CSkeletonInstance;
class CSubtickMoveStep;
class IVPhysics2World;
class CCSGOInput;
struct Ray_t;

// Declarations:

DECLARATE_CS2_FUNCTION_SDK_FASTCALL( PVOID , CGameEntitySystem_GetBaseEntity , ( CGameEntitySystem* pGameEntitySystem , int iIndex ) , ( CGameEntitySystem* , int ) , ( pGameEntitySystem , iIndex ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CCSPlayerController* , CGameEntitySystem_GetLocalPlayerController , ( int Unk ) , ( int ) , ( Unk ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CCSInventoryManager* , CCSInventoryManager_Get , ( ) , ( ) , ( ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , CCSInventoryManager_EquipItemInLoadout , ( CCSInventoryManager* pCCSInventoryManager , int iTeam , int iSlot , uint64_t iItemID ) , ( CCSInventoryManager* , int , int , uint64_t ) , ( pCCSInventoryManager , iTeam , iSlot , iItemID ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( C_EconItemView* , CCSPlayerInventory_GetItemInLoadout , ( CCSPlayerInventory* pCCSPlayerInventory , int iClass , int iSlot ) , ( CCSPlayerInventory* , int , int ) , ( pCCSPlayerInventory , iClass , iSlot ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CGCClientSharedObjectTypeCache* , CGCClientSharedObjectCache_CreateBaseTypeCache , ( CGCClientSharedObjectCache* pCGCClientSharedObjectCache , int nClassID ) , ( CGCClientSharedObjectCache* , int ) , ( pCGCClientSharedObjectCache , nClassID ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CGCClientSharedObjectTypeCache* , CGCClientSharedObjectCache_FindTypeCache , ( CGCClientSharedObjectCache* pCGCClientSharedObjectCache , int nClassID ) , ( CGCClientSharedObjectCache* , int ) , ( pCGCClientSharedObjectCache , nClassID ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CEconItem* , CreateSharedObjectSubclassEconItem , ( ) , ( ) , ( ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void* , CEconItemSchema_GetAttributeDefinitionInterface , ( CEconItemSchema* pEconItemSchema , int iAttribIndex ) , ( CEconItemSchema* , int ) , ( pEconItemSchema , iAttribIndex ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CEconItem_SetDynamicAttributeValueUint , ( CEconItem* pEconItem , void* pAttributeDefinitionInterface , void* pValue ) , ( CEconItem* , void* , void* ) , ( pEconItem , pAttributeDefinitionInterface , pValue ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( const char* , IGameEvent_GetName , ( IGameEvent* pIGameEvent ) , ( IGameEvent* ) , ( pIGameEvent ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( int64_t , IGameEvent_GetInt64 , ( IGameEvent* pIGameEvent , const char* szEventName ) , ( IGameEvent* , const char* ) , ( pIGameEvent , szEventName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CCSPlayerController* , IGameEvent_GetPlayerController , ( IGameEvent* pIGameEvent , void* pEventNameHash ) , ( IGameEvent* , void* ) , ( pIGameEvent , pEventNameHash ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( const char* , IGameEvent_GetString , ( IGameEvent* pIGameEvent , void* pEventNameHash ) , ( IGameEvent* , void* , void* ) , ( pIGameEvent , pEventNameHash , nullptr ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( const char* , IGameEvent_SetString , ( IGameEvent* pIGameEvent , void* pEventNameHash , const char* pEventValue ) , ( IGameEvent* , void* , const char* , int ) , ( pIGameEvent , pEventNameHash , pEventValue , 0 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CEconItemDefinition* , C_EconItemView_GetStaticData , ( C_EconItemView* pEconItemView ) , ( C_EconItemView* ) , ( pEconItemView ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CCSWeaponBaseVData* , C_EconItemView_GetBasePlayerWeaponVData , ( C_EconItemView* pC_EconItemView ) , ( C_EconItemView* ) , ( pC_EconItemView ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_BaseModelEntity_SetModel , ( C_BaseModelEntity* pBaseModelEntity , const char* szModelName ) , ( C_BaseModelEntity* , const char* ) , ( pBaseModelEntity , szModelName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CGameSceneNode_SetMeshGroupMask , ( CGameSceneNode* pGameSceneNode , uint64_t MeshGroupMask ) , ( CGameSceneNode* , uint64_t ) , ( pGameSceneNode , MeshGroupMask ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSWeaponBase_UpdateSubclass , ( C_CSWeaponBase* pWeaponBase ) , ( C_CSWeaponBase* ) , ( pWeaponBase ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSWeaponBase_UpdateSkin , ( C_CSWeaponBase* pWeaponBase , uint32_t Update ) , ( C_CSWeaponBase* , uint32_t ) , ( pWeaponBase , Update ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSWeaponBase_UpdateCompositeMaterial , ( CCompositeMaterialOwner* pCompositeMaterialOwner , bool unk1 ) , ( CCompositeMaterialOwner* , bool ) , ( pCompositeMaterialOwner , unk1 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void* , CEconItem_SerializeToProtoBufItem , ( CEconItem* pCEconItem , CSOEconItem* pCSOEconItem ) , ( CEconItem* , CSOEconItem* ) , ( pCEconItem , pCSOEconItem ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_BaseEntity_SetBodyGroup , ( C_BaseEntity* pC_BaseEntity , int unk1 , unsigned int unk2 ) , ( C_BaseEntity* , int , unsigned int ) , ( pC_BaseEntity , unk1 , unk2 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CCSGO_HudWeaponSelection_ClearHudWeaponIcon , ( CCSGO_HudWeaponSelection* pCCSGO_HudWeaponSelection , int unk1 , int64_t unk2 ) , ( CCSGO_HudWeaponSelection* , int , int64_t ) , ( pCCSGO_HudWeaponSelection , unk1 , unk2 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void* , FindHudElement , ( const char* szHudName ) , ( const char* ) , ( szHudName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , GetCUserCmdTick , ( CCSPlayerController* pPlayerController , int32_t* pOutputTick ) , ( CCSPlayerController* , int32_t* ) , ( pPlayerController , pOutputTick ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CUserCmdArray* , GetCUserCmdArray , ( CUserCmd** ppCUserCmd , int Tick ) , ( CUserCmd** , int ) , ( ppCUserCmd , Tick ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CUserCmd* , GetCUserCmdBySequenceNumber , ( CCSPlayerController* pPlayerController , uint32_t SequenceNumber ) , ( CCSPlayerController* , uint32_t ) , ( pPlayerController , SequenceNumber ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CTraceFilter_Constructor , ( CTraceFilter* pThis , uint64_t uMask , void* pSkip1 , int nLayer , uint16_t unkNum ) , ( CTraceFilter* , void* , uint64_t , int , uint16_t ) , ( pThis , pSkip1 , uMask , nLayer , unkNum ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , C_BaseEntity_ComputeHitboxSurroundingBox , ( C_BaseEntity* pBaseEntity , Vector3& mins , Vector3& maxs ) , ( C_BaseEntity* , Vector3& , Vector3& ) , ( pBaseEntity , mins , maxs ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CSkeletonInstance_CalcWorldSpaceBones , ( CSkeletonInstance* pCSkeletonInstance , unsigned int mask ) , ( CSkeletonInstance* , unsigned int ) , ( pCSkeletonInstance , mask ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( int , C_BaseEntity_GetBoneIdByName , ( C_BaseEntity* pC_BaseEntity , const char* szName ) , ( C_BaseEntity* , const char* ) , ( pC_BaseEntity , szName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , ScreenTransform , ( const Vector3& vOrigin , Vector3& vOut ) , ( const Vector3& , Vector3& ) , ( vOrigin , vOut ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CSubtickMoveStep* , CreateSubtickMoveStep , ( void* pArena ) , ( void* ) , ( pArena ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void* , ProtobufAddToRepeatedPtrElement , ( void* pRepeatedPtrField_t , void* pElement ) , ( void* , void* ) , ( pRepeatedPtrField_t , pElement ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , IGamePhysicsQuery_TraceShape , ( IVPhysics2World** pIVPhysics2World , const Ray_t& ray , const Vector3& vecAbsStart , const Vector3& vecAbsEnd , const CTraceFilter* pFilter , CGameTrace* pTrace ) , ( IVPhysics2World** , const Ray_t& , const Vector3& , const Vector3& , const CTraceFilter* , CGameTrace* ) , ( pIVPhysics2World , ray , vecAbsStart , vecAbsEnd , pFilter , pTrace ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( QAngle* , CCSGOInput_GetViewAngles , ( CCSGOInput* pCCSGOInput , int32_t slot ) , ( CCSGOInput* , int32_t ) , ( pCCSGOInput , slot ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CCSGOInput_SetViewAngles , ( CCSGOInput* pCCSGOInput , int32_t slot , QAngle& Angles ) , ( CCSGOInput* , int32_t , QAngle& ) , ( pCCSGOInput , slot , Angles ) );

namespace CCSGOHudElement
{
	template<typename T>
	inline auto Find( const char* szHudName ) -> T*
	{
		return reinterpret_cast<T*>( FindHudElement( szHudName ) );
	}
}

inline auto CGameEntitySystem_GetHighestEntityIndex( CGameEntitySystem* pGameEntitySystem , int& HighestIdx ) -> void
{
	// FF 81 ? ? ? ? 48 85 D2
	HighestIdx = *(int32_t*)( (uintptr_t)pGameEntitySystem + g_OFFSET_CGameEntitySystem_GetHighestEntityIndex );
}
