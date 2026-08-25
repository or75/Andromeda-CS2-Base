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
class CGameSceneNode;
class C_BaseEntity;
class CEconItemDefinition;
class CModel;
class CSkeletonInstance;
class C_CSPlayerPawn;
class C_BaseModelEntity;
class CCSWeaponBaseVData;
class KeyValues3;
class CUtlString;
struct KV3ID_t;
class CCSGOInput;
class C_CSWeaponBase;
class C_CSWeaponBaseGun;
class CSubtickMoveStep;
class KeyValues;
class IBaseFileSystem;
class CCompositeMaterialOwner;
class CUserCmdArray;
class CUserCmd;
class C_EnvSky;
class C_BaseCSGrenade;
class CGrenadeTrace;
class CSOEconItem;
struct TraceData_t;
struct HandleBulletPenetrationData_t;
class CTraceInfo;
class CGameTrace;
class CUIPanel;
struct Ray_t;
class CTraceFilter;
class IVPhysics2World;
class CCSGO_HudWeaponSelection;
class CHitBoxSet;

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
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , C_BaseEntity_ComputeHitboxSurroundingBox , ( C_BaseEntity* pBaseEntity , Vector3& mins , Vector3& maxs ) , ( C_BaseEntity* , Vector3& , Vector3& ) , ( pBaseEntity , mins , maxs ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CEconItemDefinition* , C_EconItemView_GetStaticData , ( C_EconItemView* pEconItemView ) , ( C_EconItemView* ) , ( pEconItemView ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CSkeletonInstance_CalcWorldSpaceBones , ( CSkeletonInstance* pCSkeletonInstance , unsigned int mask ) , ( CSkeletonInstance* , unsigned int ) , ( pCSkeletonInstance , mask ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( int , C_BaseEntity_GetBoneIdByName , ( C_BaseEntity* pC_BaseEntity , const char* szName ) , ( C_BaseEntity* , const char* ) , ( pC_BaseEntity , szName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CCSWeaponBaseVData* , C_EconItemView_GetBasePlayerWeaponVData , ( C_EconItemView* pC_EconItemView ) , ( C_EconItemView* ) , ( pC_EconItemView ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , KeyValues3_LoadKV3 , ( KeyValues3* pKV3 , const char* vmatBuffer , KV3ID_t* pID ) , ( KeyValues3* , CUtlString* , const char* , KV3ID_t* , const char* , unsigned int ) , ( pKV3 , nullptr , vmatBuffer , pID , "" , 0 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , IGamePhysicsQuery_TraceShape , ( IVPhysics2World** pIVPhysics2World , const Ray_t& ray , const Vector3& vecAbsStart , const Vector3& vecAbsEnd , const CTraceFilter* pFilter , CGameTrace* pTrace ) , ( IVPhysics2World** , const Ray_t& , const Vector3& , const Vector3& , const CTraceFilter* , CGameTrace* ) , ( pIVPhysics2World , ray , vecAbsStart , vecAbsEnd , pFilter , pTrace ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( QAngle* , CCSGOInput_GetViewAngles , ( CCSGOInput* pCCSGOInput , int32_t slot ) , ( CCSGOInput* , int32_t ) , ( pCCSGOInput , slot ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CCSGOInput_SetViewAngles , ( CCSGOInput* pCCSGOInput , int32_t slot , QAngle& Angles ) , ( CCSGOInput* , int32_t , QAngle& ) , ( pCCSGOInput , slot , Angles ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( float , LineGoesThroughSmoke , ( const Vector3& Start , const Vector3& End , int64 a3 ) , ( const Vector3& , const Vector3& , int64 ) , ( Start , End , a3 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void* , FindHudElement , ( const char* szHudName ) , ( const char* ) , ( szHudName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( float , C_CSWeaponBaseGun_GetInaccuracy , ( C_CSWeaponBaseGun* pC_CSWeaponBaseGun , float* unk1 = nullptr , float* unk2 = nullptr ) , ( C_CSWeaponBaseGun* , float* , float* ) , ( pC_CSWeaponBaseGun , unk1 , unk2 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( float , C_CSWeaponBaseGun_GetSpread , ( C_CSWeaponBaseGun* pC_CSWeaponBaseGun ) , ( C_CSWeaponBaseGun* ) , ( pC_CSWeaponBaseGun ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , SetLocalPlayerReady , ( const char* Reason ) , ( void* , const char* ) , ( nullptr , Reason ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , ScreenTransform , ( const Vector3& vOrigin , Vector3& vOut ) , ( const Vector3& , Vector3& ) , ( vOrigin , vOut ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CSubtickMoveStep* , CreateSubtickMoveStep , ( void* pArena ) , ( void* ) , ( pArena ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void* , ProtobufAddToRepeatedPtrElement , ( void* pRepeatedPtrField_t , void* pElement ) , ( void* , void* ) , ( pRepeatedPtrField_t , pElement ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( const char* , KeyValues_GetName , ( KeyValues* pThis ) , ( KeyValues* ) , ( pThis ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_GetFirstSubKey , ( KeyValues* pThis ) , ( KeyValues* ) , ( pThis ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_GetFirstTrueSubKey , ( KeyValues* pThis ) , ( KeyValues* ) , ( pThis ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_GetNextTrueSubKey , ( KeyValues* pThis ) , ( KeyValues* ) , ( pThis ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_GetNextKey , ( KeyValues* pThis ) , ( KeyValues* ) , ( pThis ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_FindKey , ( KeyValues* pThis , const char* szKeyName ) , ( KeyValues* , const char* ) , ( pThis , szKeyName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( int , KeyValues_GetInt , ( KeyValues* pThis , const char* szKeyName , int DefaultValue ) , ( KeyValues* , const char* , int ) , ( pThis , szKeyName , DefaultValue ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( float , KeyValues_GetFloat , ( KeyValues* pThis , const char* szKeyName , float DefaultValue ) , ( KeyValues* , const char* , float ) , ( pThis , szKeyName , DefaultValue ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( uint64_t , KeyValues_GetUint64 , ( KeyValues* pThis , const char* szKeyName , uint64_t DefaultValue ) , ( KeyValues* , const char* , uint64_t ) , ( pThis , szKeyName , DefaultValue ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_FindKeyAndParent , ( KeyValues* pThis , const char* szKeyName , KeyValues** Parent , bool Unk1 ) , ( KeyValues* , const char* , KeyValues** , bool ) , ( pThis , szKeyName , Parent , Unk1 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( const char* , CKeyValues_Internal_GetString , ( KeyValues* pData , const char* DefaultValue ) , ( KeyValues* , const char* ) , ( pData , DefaultValue ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_Constructor , ( KeyValues* pThis , const char* szName , void* IKeyValuesSystem , bool Unk1 ) , ( KeyValues* , const char* , void* , bool ) , ( pThis , szName , IKeyValuesSystem , Unk1 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , KeyValues_Destructor , ( KeyValues* pKeyValues ) , ( KeyValues* ) , ( pKeyValues ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , KeyValues_LoadFromFile , ( KeyValues* pKeyValues , IBaseFileSystem* pFileSystem , const char* szResourceName , const char* PathID , void* pFunc , void* Unk1 , const char* Unk2 ) , ( KeyValues* , IBaseFileSystem* , const char* , const char* , void* , void* , const char* ) , ( pKeyValues , pFileSystem , szResourceName , PathID , pFunc , Unk1 , Unk2 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( KeyValues* , KeyValues_Element , ( KeyValues* pKeyValues , int Index ) , ( KeyValues* , int ) , ( pKeyValues , Index ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( int , KeyValues_Count , ( KeyValues* pKeyValues ) , ( KeyValues* ) , ( pKeyValues ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( int , C_EconItemView_GetCustomPaintKitIndex , ( C_EconItemView* pEconItemView ) , ( C_EconItemView* ) , ( pEconItemView ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_BaseModelEntity_SetModel , ( C_BaseModelEntity* pBaseModelEntity , const char* szModelName ) , ( C_BaseModelEntity* , const char* ) , ( pBaseModelEntity , szModelName ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CGameSceneNode_SetMeshGroupMask , ( CGameSceneNode* pGameSceneNode , uint64_t MeshGroupMask ) , ( CGameSceneNode* , uint64_t ) , ( pGameSceneNode , MeshGroupMask ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSWeaponBase_UpdateSubclass , ( C_CSWeaponBase* pWeaponBase ) , ( C_CSWeaponBase* ) , ( pWeaponBase ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSWeaponBase_UpdateSkin , ( C_CSWeaponBase* pWeaponBase , bool Update ) , ( C_CSWeaponBase* , bool ) , ( pWeaponBase , Update ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSWeaponBase_UpdateCompositeMaterial , ( CCompositeMaterialOwner* pCompositeMaterialOwner , bool unk1 ) , ( CCompositeMaterialOwner* , bool ) , ( pCompositeMaterialOwner , unk1 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSPlayerPawn_SetBodyGroup , ( C_CSPlayerPawn* pC_CSPlayerPawn , const char* Group , int unk1 ) , ( C_CSPlayerPawn* , const char* , int ) , ( pC_CSPlayerPawn , Group , unk1 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , GetCUserCmdTick , ( CCSPlayerController* pPlayerController , int32_t* pOutputTick ) , ( CCSPlayerController* , int32_t* ) , ( pPlayerController , pOutputTick ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CUserCmdArray* , GetCUserCmdArray , ( CUserCmd** ppCUserCmd , int Tick ) , ( CUserCmd** , int ) , ( ppCUserCmd , Tick ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CUserCmd* , GetCUserCmdBySequenceNumber , ( CCSPlayerController* pPlayerController , uint32_t SequenceNumber ) , ( CCSPlayerController* , uint32_t ) , ( pPlayerController , SequenceNumber ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void* , CEconItem_SerializeToProtoBufItem , ( CEconItem* pCEconItem , CSOEconItem* pCSOEconItem ) , ( CEconItem* , CSOEconItem* ) , ( pCEconItem , pCSOEconItem ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CUIEngineSource2_RunScript , ( void* pThis , CUIPanel* pPanel , const char* pszScriptSrc , const char* szOriginFile , int Line ) , ( void* , CUIPanel* , const char* , const char* , int ) , ( pThis , pPanel , pszScriptSrc , szOriginFile , Line ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CTraceFilter_Constructor , ( CTraceFilter* pThis , uint64_t uMask , void* pSkip1 , int nLayer , uint16_t unkNum ) , ( CTraceFilter* , void* , uint64_t , int , uint16_t ) , ( pThis , pSkip1 , uMask , nLayer , unkNum ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , CCSGO_HudWeaponSelection_ClearHudWeaponIcon , ( CCSGO_HudWeaponSelection* pCCSGO_HudWeaponSelection , int unk1 , int64_t unk2 ) , ( CCSGO_HudWeaponSelection* , int , int64_t ) , ( pCCSGO_HudWeaponSelection , unk1 , unk2 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( CHitBoxSet* , C_BaseEntity_GetHitBoxSet , ( C_BaseEntity* pC_BaseEntity , uint32_t Index = 0 ) , ( C_BaseEntity* , uint32_t ) , ( pC_BaseEntity , Index ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_BaseEntity_UpdateBodyGroupChoice , ( C_BaseEntity* pC_BaseEntity ) , ( C_BaseEntity* ) , ( pC_BaseEntity ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_EconItemView_SetAttributeValueByName , ( C_EconItemView* pC_EconItemView , const char* szAttributeName , float flValue ) , ( C_EconItemView* , const char* , float ) , ( pC_EconItemView , szAttributeName , flValue ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( void , C_CSWeaponBase_UpdateCompositeMaterialSet , ( C_CSWeaponBase* pC_CSWeaponBase , bool unk1 ) , ( C_CSWeaponBase* , bool ) , ( pC_CSWeaponBase , unk1 ) );
DECLARATE_CS2_FUNCTION_SDK_FASTCALL( bool , AnalizePeModule , ( HANDLE ModuleHandle , void* pModuleInfo_t , bool CalculateHash ) , ( HANDLE , void* , bool ) , ( ModuleHandle , pModuleInfo_t , CalculateHash ) );

// Helpers:

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
