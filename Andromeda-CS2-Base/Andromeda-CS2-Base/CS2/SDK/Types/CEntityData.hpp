#pragma once

#include <Common/Common.hpp>

#include "Color.hpp"

#include "CBaseTypes.hpp"
#include "CHandle.hpp"

#include "CUtlMemory.hpp"
#include "CUtlString.hpp"
#include "CUtlSymbol.hpp"
#include "CUtlSymbolLarge.hpp"
#include "CUtlVector.hpp"
#include "CStrongHandle.hpp"
#include "CUtlStringToken.hpp"

#include <CS2/SDK/Math/Rect_t.hpp>
#include <CS2/SDK/Update/Offsets.hpp>
#include <CS2/SDK/CSchemaOffset.hpp>
#include <CS2/SDK/Interface/CShemaSystemSDK.hpp>

namespace index
{
	namespace CEntityInstance
	{
		constexpr auto PostDataUpdate = 7;
	}
}

class C_BaseEntity;
class CEconItem;
class CEconItemDefinition;
class CSkeletonInstance;
class CCompositeMaterialOwner;

class IHandleEntity
{
public:
	virtual ~IHandleEntity() {}
};

class IEconItemInterface
{
public:
	virtual ~IEconItemInterface() {}
};

class CPlayerControllerComponent
{
public:
};

class CPlayerPawnComponent
{
public:
};

class CEntitySubclassVDataBase
{
public:
};

struct alignas( 16 ) CBoneData
{
	Vector3 position;
	float scale;
	Vector3 rotation;
};

class CModel
{
private:
	PAD( 0x130 + 0x38 );
public:
	const char** m_szBoneNames;
	uint32 m_nBoneCount;
};

class CModelState
{
private:
	PAD( 0x80 );

public:
	CBoneData* m_pBones;

public:
	SCHEMA_OFFSET( "CModelState" , "m_hModel" , m_hModel , CStrongHandle<CModel> );
	SCHEMA_OFFSET( "CModelState" , "m_ModelName" , m_ModelName , CUtlSymbolLarge );
};

class EntitySpottedState_t
{
public:
	SCHEMA_OFFSET( "EntitySpottedState_t" , "m_bSpotted" , m_bSpotted , bool );
};

class CEntityIdentity 
{
public:
	SCHEMA_OFFSET_CUSTOM( pBaseEntity , 0x0 , C_BaseEntity* );
	SCHEMA_OFFSET_CUSTOM( Handle , 0x10 , CHandle );

public:
	SCHEMA_OFFSET( "CEntityIdentity" , "m_name" , Name , CUtlSymbolLarge );
	SCHEMA_OFFSET( "CEntityIdentity" , "m_designerName" , DesingerName , CUtlSymbolLarge );
};

class CEntityInstance : public IHandleEntity
{
public:
	auto GetSchemaClassBinding() -> CSchemaClassBinding*
	{
		CSchemaClassBinding* pBinding = nullptr;

		VirtualFn( void )( CEntityInstance* , CSchemaClassBinding** );
		vget< Fn >( this , index::CSchemaSystem::SchemaClassInfo )( this , &pBinding );

		return pBinding;
	}

public:
	auto PostDataUpdate() -> void
	{
		VirtualFn( void )( CEntityInstance* , int UpdateType );
		return vget< Fn >( this , index::CEntityInstance::PostDataUpdate )( this , 1 );
	}

public:
	SCHEMA_OFFSET( "CEntityInstance" , "m_pEntity" , pEntityIdentity , CEntityIdentity* );
};

class CCollisionProperty
{
public:
	inline auto GetUnknownMask() -> uint16 { return CUSTOM_OFFSET( uint16 , g_CCollisionProperty_UnknownMask ); }

public:
	SCHEMA_OFFSET( "CCollisionProperty" , "m_vecMins" , m_vecMins , Vector3 );
	SCHEMA_OFFSET( "CCollisionProperty" , "m_vecMaxs" , m_vecMaxs , Vector3 );
	SCHEMA_OFFSET( "CCollisionProperty" , "m_usSolidFlags" , m_usSolidFlags , uint8 );
};

class CGameSceneNode
{
public:
	SCHEMA_OFFSET( "CGameSceneNode" , "m_pOwner" , m_pOwner , CEntityInstance* );
	SCHEMA_OFFSET( "CGameSceneNode" , "m_pChild" , m_pChild , CGameSceneNode* );
	SCHEMA_OFFSET( "CGameSceneNode" , "m_pNextSibling" , m_pNextSibling , CGameSceneNode* );
	SCHEMA_OFFSET( "CGameSceneNode" , "m_vecAbsOrigin" , m_vecAbsOrigin , Vector3 );
	SCHEMA_OFFSET( "CGameSceneNode" , "m_bDormant" , m_bDormant , bool );

public:
	auto SetMeshGroupMask( uint64_t meshGroupMask ) -> void;
	auto GetBonePosition( int32 BoneIndex , Vector3& BonePos ) -> bool;

public:
	auto GetSkeletonInstance() -> CSkeletonInstance*
	{
		return reinterpret_cast<CSkeletonInstance*>( this );
	}
};

class CSkeletonInstance : public CGameSceneNode
{
public:
	SCHEMA_OFFSET( "CSkeletonInstance" , "m_modelState" , m_modelState , CModelState );
	SCHEMA_OFFSET( "CSkeletonInstance" , "m_nHitboxSet" , m_nHitboxSet , uint8 );

public:
	auto CalcWorldSpaceBones( unsigned int Mask ) -> void;
};

class CBasePlayerWeaponVData : public CEntitySubclassVDataBase
{
public:
	SCHEMA_OFFSET( "CBasePlayerWeaponVData" , "m_iMaxClip1" , m_iMaxClip1 , int32 );
};

class CCSWeaponBaseVData : public CBasePlayerWeaponVData
{
public:
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_WeaponType" , m_WeaponType , CSWeaponType );
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_szName" , m_szName , CGlobalSymbol );
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_nDamage" , m_nDamage , int32 );
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_flHeadshotMultiplier" , m_flHeadshotMultiplier , float32 );
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_flArmorRatio" , m_flArmorRatio , float32 );
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_flPenetration" , m_flPenetration , float32 );
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_flRange" , m_flRange , float32 );
	SCHEMA_OFFSET( "CCSWeaponBaseVData" , "m_flRangeModifier" , m_flRangeModifier , float32 );
};

class C_EconItemView : public IEconItemInterface
{
public:
	auto GetSOCData() -> CEconItem*;
	auto GetStaticData() -> CEconItemDefinition*;
	auto GetBasePlayerWeaponVData() -> CCSWeaponBaseVData*;

public:
	SCHEMA_OFFSET( "C_EconItemView" , "m_bRestoreCustomMaterialAfterPrecache" , m_bRestoreCustomMaterialAfterPrecache , bool );
	SCHEMA_OFFSET( "C_EconItemView" , "m_iItemDefinitionIndex" , m_iItemDefinitionIndex , uint16 );
	SCHEMA_OFFSET( "C_EconItemView" , "m_iItemID" , m_iItemID , uint64 );
	SCHEMA_OFFSET( "C_EconItemView" , "m_iItemIDLow" , m_iItemIDLow , uint32 );
	SCHEMA_OFFSET( "C_EconItemView" , "m_iItemIDHigh" , m_iItemIDHigh , uint32 );
	SCHEMA_OFFSET( "C_EconItemView" , "m_iAccountID" , m_iAccountID , uint32 );
	SCHEMA_OFFSET( "C_EconItemView" , "m_bInitialized" , m_bInitialized , bool );
	SCHEMA_OFFSET( "C_EconItemView" , "m_bDisallowSOC" , m_bDisallowSOC , bool );

public:
	CUSTOM_OFFSET_FIELD( uintptr_t , pCEconItemDescription , 0x200 );
};

class C_AttributeContainer
{
public:
	PSCHEMA_OFFSET( "C_AttributeContainer" , "m_Item" , m_Item , C_EconItemView );
};

class C_BaseEntity : public CEntityInstance
{
public:
	auto IsBasePlayerController() -> bool;
	auto IsBasePlayerWeapon() -> bool;
	auto IsObserverPawn() -> bool;
	auto IsPlayerPawn() -> bool;
	auto IsPlantedC4() -> bool;
	auto IsC4() -> bool;
	auto IsSmokeGrenadeProjectile() -> bool;
	auto IsGrenadeProjectile() -> bool;
	auto IsCS2HudModelWeapon() -> bool;

public:
	auto GetOrigin() -> const Vector3&;

public:
	auto GetBoundingBox( Rect_t& out , bool computeSurroundingBox = false ) -> bool;
	auto ComputeHitboxSurroundingBox( Vector3& mins , Vector3& maxs ) -> bool;
	auto SetBodyGroup() -> void;
	auto GetBoneIdByName( const char* szName ) -> int;

public:
	SCHEMA_OFFSET( "C_BaseEntity" , "m_pGameSceneNode" , m_pGameSceneNode , CGameSceneNode* );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_pCollision" , m_pCollision , CCollisionProperty* );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_iMaxHealth" , m_iMaxHealth , int32 );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_iHealth" , m_iHealth , int32 );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_iTeamNum" , m_iTeamNum , uint8 );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_fFlags" , m_fFlags , uint32 );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_MoveType" , m_MoveType , MoveType_t );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_hOwnerEntity" , m_hOwnerEntity , CHandle );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_nSubclassID" , m_nSubclassID , CUtlStringToken );
};

class CGlowProperty
{
public:
	CUSTOM_OFFSET_FIELD( CEntityInstance* , m_pOwner , 0x18 );

public:
	SCHEMA_OFFSET( "CGlowProperty" , "m_glowColorOverride" , m_glowColorOverride , Color );
	SCHEMA_OFFSET( "CGlowProperty" , "m_bGlowing" , m_bGlowing , bool );
};

class C_BaseModelEntity : public C_BaseEntity
{
public:
	SCHEMA_OFFSET( "C_BaseModelEntity" , "m_vecViewOffset" , m_vecViewOffset , CNetworkViewOffsetVector );
	SCHEMA_OFFSET( "C_BaseModelEntity" , "m_Collision" , m_Collision , CCollisionProperty );
	SCHEMA_OFFSET( "C_BaseModelEntity" , "m_Glow" , m_Glow , CGlowProperty );

public:
	auto SetModel( const char* szModel ) -> void;
};

class CBaseAnimGraph : public C_BaseModelEntity
{
public:
};

class C_BaseViewModel : public CBaseAnimGraph
{
public:
	SCHEMA_OFFSET( "C_BaseViewModel" , "m_hWeapon" , m_hWeapon , CHandle ); // C_BasePlayerWeapon
};

class C_PredictedViewModel : public C_BaseViewModel
{
public:
};

class C_CSGOViewModel : public C_PredictedViewModel
{
public:
};

class CBasePlayerController : public C_BaseEntity
{
public:
	SCHEMA_OFFSET( "CBasePlayerController" , "m_nTickBase" , m_nTickBase , uint32 );
	SCHEMA_OFFSET( "CBasePlayerController" , "m_hPawn" , m_hPawn , CHandle ); // C_CSPlayerPawn,C_CSObserverPawn
	SCHEMA_OFFSET( "CBasePlayerController" , "m_steamID" , m_steamID , uint64 );
	SCHEMA_OFFSET( "CBasePlayerController" , "m_bIsLocalPlayerController" , m_bIsLocalPlayerController , bool );
};

class CCSPlayerController_InGameMoneyServices : public CPlayerControllerComponent
{
public:
	SCHEMA_OFFSET( "CCSPlayerController_InGameMoneyServices" , "m_iAccount" , m_iAccount , int32 );
};

class CCSPlayerController_InventoryServices : public CPlayerControllerComponent
{
public:
	SCHEMA_OFFSET( "CCSPlayerController_InventoryServices" , "m_unMusicID" , m_unMusicID , uint16 );
};

class CCSPlayerController : public CBasePlayerController
{
public:
	SCHEMA_OFFSET( "CCSPlayerController" , "m_pInGameMoneyServices" , m_pInGameMoneyServices , CCSPlayerController_InGameMoneyServices* );
	SCHEMA_OFFSET( "CCSPlayerController" , "m_pInventoryServices" , m_pInventoryServices , CCSPlayerController_InventoryServices* );
	SCHEMA_OFFSET( "CCSPlayerController" , "m_sSanitizedPlayerName" , m_sSanitizedPlayerName , const char* );
	SCHEMA_OFFSET( "CCSPlayerController" , "m_bPawnIsAlive" , m_bPawnIsAlive , bool );
};

class CPlayer_WeaponServices : public CPlayerPawnComponent
{
public:
	SCHEMA_OFFSET( "CPlayer_WeaponServices" , "m_hActiveWeapon" , m_hActiveWeapon , CHandle ); // C_CSWeaponBaseGun
	SCHEMA_OFFSET( "CPlayer_WeaponServices" , "m_hMyWeapons" , m_hMyWeapons , C_NetworkUtlVectorBase< CHandle > ); // C_BasePlayerWeapon
};

class CCSPlayer_WeaponServices : public CPlayer_WeaponServices
{
public:
};

class CPlayer_ItemServices : public CPlayerPawnComponent
{
public:
};

class CCSPlayer_ItemServices : public CPlayer_ItemServices
{
public:
	SCHEMA_OFFSET( "CCSPlayer_ItemServices" , "m_bHasDefuser" , m_bHasDefuser , bool );
	SCHEMA_OFFSET( "CCSPlayer_ItemServices" , "m_bHasHelmet" , m_bHasHelmet , bool );
	SCHEMA_OFFSET( "CCSPlayer_ItemServices" , "m_bHasHeavyArmor" , m_bHasHeavyArmor , bool );
};

class CPlayer_ObserverServices : public CPlayerPawnComponent
{
public:
	SCHEMA_OFFSET( "CPlayer_ObserverServices" , "m_iObserverMode" , m_iObserverMode , uint8 );
	SCHEMA_OFFSET( "CPlayer_ObserverServices" , "m_hObserverTarget" , m_hObserverTarget , CHandle ); // C_CSPlayerPawn,C_PlantedC4
};

class C_BaseToggle : public C_BaseModelEntity
{
public:
};

class C_BaseTrigger : public C_BaseToggle
{
public:
};

class C_BaseFlex : public CBaseAnimGraph
{
public:
};

class C_LateUpdatedAnimating : public CBaseAnimGraph
{
public:
};

class C_CS2HudModelBase : public C_LateUpdatedAnimating
{
public:
};

class C_CS2HudModelWeapon : public C_CS2HudModelBase
{
public:
};

class C_CS2HudModelArms : public C_CS2HudModelBase
{
public:
};

class C_PostProcessingVolume : public C_BaseTrigger
{
public:
	SCHEMA_OFFSET( "C_PostProcessingVolume" , "m_flMinExposure" , m_flMinExposure , float32 );
	SCHEMA_OFFSET( "C_PostProcessingVolume" , "m_flMaxExposure" , m_flMaxExposure , float32 );
	SCHEMA_OFFSET( "C_PostProcessingVolume" , "m_bExposureControl" , m_bExposureControl , bool );
};

class CPlayer_ViewModelServices : public CPlayerPawnComponent
{
public:
};

class CCSPlayer_ViewModelServices : public CPlayer_ViewModelServices
{
public:
	PSCHEMA_OFFSET( "CCSPlayer_ViewModelServices" , "m_hViewModel" , m_hViewModel , CHandle ); // C_CSGOViewModel
};

class CPlayer_CameraServices : public CPlayerPawnComponent
{
public:
	SCHEMA_OFFSET( "CPlayer_CameraServices" , "m_vecCsViewPunchAngle" , m_vecCsViewPunchAngle , QAngle );
	SCHEMA_OFFSET( "CPlayer_CameraServices" , "m_hActivePostProcessingVolume" , m_hActivePostProcessingVolume , CHandle ); // C_PostProcessingVolume
};

class CCSPlayerBase_CameraServices : public CPlayer_CameraServices
{
public:
	SCHEMA_OFFSET( "CCSPlayerBase_CameraServices" , "m_iFOV" , m_iFOV , uint32 );
};

class C_BasePlayerPawn : public C_BaseModelEntity
{
public:
	SCHEMA_OFFSET( "C_BasePlayerPawn" , "m_pWeaponServices" , m_pWeaponServices , CCSPlayer_WeaponServices* );
	SCHEMA_OFFSET( "C_BasePlayerPawn" , "m_pItemServices" , m_pItemServices , CCSPlayer_ItemServices* );
	SCHEMA_OFFSET( "C_BasePlayerPawn" , "m_pObserverServices" , m_pObserverServices , CPlayer_ObserverServices* );
	SCHEMA_OFFSET( "C_BasePlayerPawn" , "m_pCameraServices" , m_pCameraServices , CCSPlayerBase_CameraServices* );
	SCHEMA_OFFSET( "C_BasePlayerPawn" , "m_vOldOrigin" , m_vOldOrigin , Vector3 );
	SCHEMA_OFFSET( "C_BasePlayerPawn" , "m_hController" , m_hController , CHandle ); // CCSPlayerController
};

class C_CSPlayerPawnBase : public C_BasePlayerPawn
{
public:
	SCHEMA_OFFSET( "C_CSPlayerPawnBase" , "m_pViewModelServices" , m_pViewModelServices , CCSPlayer_ViewModelServices* );
	SCHEMA_OFFSET( "C_CSPlayerPawnBase" , "m_flFlashBangTime" , m_flFlashBangTime , float32 );
	SCHEMA_OFFSET( "C_CSPlayerPawnBase" , "m_flFlashMaxAlpha" , m_flFlashMaxAlpha , float32 );
	SCHEMA_OFFSET( "C_CSPlayerPawnBase" , "m_flFlashDuration" , m_flFlashDuration , float32 );
	SCHEMA_OFFSET( "C_CSPlayerPawnBase" , "m_flLastSpawnTimeIndex" , m_flLastSpawnTimeIndex , GameTime_t );
	SCHEMA_OFFSET( "C_CSPlayerPawnBase" , "m_bGunGameImmunity" , m_bGunGameImmunity , bool );
	SCHEMA_OFFSET( "C_CSPlayerPawnBase" , "m_angEyeAngles" , m_angEyeAngles , QAngle );
};

class C_CSObserverPawn : public C_CSPlayerPawnBase
{
public:
};

class C_CSPlayerPawn : public C_CSPlayerPawnBase
{
public:
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_aimPunchCache" , m_aimPunchCache , CUtlVector< QAngle > );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_ArmorValue" , m_ArmorValue , int32 );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_iShotsFired" , m_iShotsFired , int32 );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_bIsDefusing" , m_bIsDefusing , bool );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_bIsScoped" , m_bIsScoped , bool );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_bWaitForNoAttack" , m_bWaitForNoAttack , bool );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_bNeedToReApplyGloves" , m_bNeedToReApplyGloves , bool );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_entitySpottedState" , m_entitySpottedState , EntitySpottedState_t );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_EconGloves" , m_EconGloves , C_EconItemView );
	SCHEMA_OFFSET( "C_CSPlayerPawn" , "m_hHudModelArms" , m_hHudModelArms , CHandle ); // C_CS2HudModelArms

public:
	auto GetViewModels() -> std::vector<C_CS2HudModelWeapon*>;
	auto GetViewModel() -> C_CS2HudModelWeapon*;
	auto GetKnifeModel() -> C_CS2HudModelWeapon*;

public:
	inline auto IsAlive() -> bool
	{
		return m_iHealth() > 0;
	}

	inline auto HasArmor( int HitGroup ) -> bool
	{
		if ( HitGroup == 1 )
			return m_pItemServices()->m_bHasHelmet();

		return m_ArmorValue();
	}

public:
	inline auto GetCollisionMask() -> uint16
	{
		return m_Collision().GetUnknownMask();
	}

public:
	inline auto GetOwnerHandle() -> uint32
	{
		uint32 Result = INVALID_EHANDLE_INDEX;

		if ( !( m_Collision().m_usSolidFlags() & 4 ) )
		{
			auto pC_BaseEntity = m_hOwnerEntity().Get();

			if ( pC_BaseEntity )
				Result = pC_BaseEntity->pEntityIdentity()->Handle().GetEntryIndex();
		}

		return Result;
	}
};

class C_EconEntity : public C_BaseFlex
{
public:
	PSCHEMA_OFFSET( "C_EconEntity" , "m_AttributeManager" , m_AttributeManager , C_AttributeContainer );
	SCHEMA_OFFSET( "C_EconEntity" , "m_OriginalOwnerXuidLow" , m_OriginalOwnerXuidLow , uint32 );
	SCHEMA_OFFSET( "C_EconEntity" , "m_OriginalOwnerXuidHigh" , m_OriginalOwnerXuidHigh , uint32 );

	inline auto GetOriginalOwnerXuid() -> uint64_t
	{
		return ( (uint64_t)( m_OriginalOwnerXuidHigh() ) << 32 ) | m_OriginalOwnerXuidLow();
	}
};

class C_BasePlayerWeapon : public C_EconEntity
{
public:
	SCHEMA_OFFSET( "C_BasePlayerWeapon" , "m_nNextPrimaryAttackTick" , m_nNextPrimaryAttackTick , GameTick_t );
	SCHEMA_OFFSET( "C_BasePlayerWeapon" , "m_nNextSecondaryAttackTick" , m_nNextSecondaryAttackTick , GameTick_t );
	SCHEMA_OFFSET( "C_BasePlayerWeapon" , "m_iClip1" , m_iClip1 , int32 );
};

class C_CSWeaponBase : public C_BasePlayerWeapon
{
public:
	SCHEMA_OFFSET( "C_CSWeaponBase" , "m_bInReload" , m_bInReload , bool );
	SCHEMA_OFFSET( "C_CSWeaponBase" , "m_bBurstMode" , m_bBurstMode , bool );
	SCHEMA_OFFSET( "C_CSWeaponBase" , "m_iOriginalTeamNumber" , m_iOriginalTeamNumber , int32 );

public:
	auto UpdateCompositeMaterial( CCompositeMaterialOwner* pCCompositeMaterialOwner ) -> void;
	auto UpdateSubclass() -> void;
	auto UpdateSkin() -> void;
};

class C_CSWeaponBaseGun : public C_CSWeaponBase
{
public:
	SCHEMA_OFFSET( "C_CSWeaponBaseGun" , "m_iBurstShotsRemaining" , m_iBurstShotsRemaining , int32 );
};

class C_BaseGrenade : public C_BaseFlex
{
public:
};

class C_BaseCSGrenade : public C_CSWeaponBase
{
public:
};

class C_BaseCSGrenadeProjectile : public C_BaseGrenade
{
public:

};

class C_SmokeGrenadeProjectile : public C_BaseCSGrenadeProjectile
{
public:
	SCHEMA_OFFSET( "C_SmokeGrenadeProjectile" , "m_bDidSmokeEffect" , m_bDidSmokeEffect , bool );
	SCHEMA_OFFSET( "C_SmokeGrenadeProjectile" , "m_vSmokeColor" , m_vSmokeColor , Vector3 );
};

class C_PlantedC4 : public CBaseAnimGraph
{
public:
	SCHEMA_OFFSET( "C_PlantedC4" , "m_nBombSite" , m_nBombSite , int32 );
	SCHEMA_OFFSET( "C_PlantedC4" , "m_flC4Blow" , m_flC4Blow , GameTime_t );
	SCHEMA_OFFSET( "C_PlantedC4" , "m_bHasExploded" , m_bHasExploded , bool );
	SCHEMA_OFFSET( "C_PlantedC4" , "m_bBeingDefused" , m_bBeingDefused , bool );
	SCHEMA_OFFSET( "C_PlantedC4" , "m_bBombDefused" , m_bBombDefused , bool );
};

class C_C4 : public C_CSWeaponBase
{
public:
	SCHEMA_OFFSET( "C_C4" , "m_bStartedArming" , m_bStartedArming , bool );
	SCHEMA_OFFSET( "C_C4" , "m_bBombPlacedAnimation" , m_bBombPlacedAnimation , bool );
	SCHEMA_OFFSET( "C_C4" , "m_bBombPlanted" , m_bBombPlanted , bool );
};

class C_EnvSky : public C_BaseModelEntity
{
public:
	SCHEMA_OFFSET( "C_EnvSky" , "m_vTintColor" , m_vTintColor , Color );
	SCHEMA_OFFSET( "C_EnvSky" , "m_vTintColorLightingOnly" , m_vTintColorLightingOnly , Color );
};
