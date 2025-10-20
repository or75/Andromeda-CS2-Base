#include "CEntityData.hpp"

#include <CS2/SDK/Cstrike15/CCSPlayerInventory.hpp>
#include <CS2/SDK/FunctionListSDK.hpp>
#include <CS2/SDK/Math/Math.hpp>

#include <GameClient/CL_Weapons.hpp>

auto C_BaseEntity::IsBasePlayerController() -> bool
{
	auto DesingerName = this->pEntityIdentity()->DesingerName().String();

	if ( DesingerName && strcmp( DesingerName , XorStr( "cs_player_controller" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsBasePlayerWeapon() -> bool
{
	auto DesingerName = this->pEntityIdentity()->DesingerName().String();

	if ( DesingerName && strstr( DesingerName , XorStr( "weapon_" ) ) )
		return true;

	return false;
}

auto C_BaseEntity::IsObserverPawn() -> bool
{
	auto m_bindingName = this->GetSchemaClassBinding()->m_bindingName();

	if ( m_bindingName && strcmp( m_bindingName , XorStr( "C_CSObserverPawn" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsPlayerPawn() -> bool
{
	auto m_bindingName = this->GetSchemaClassBinding()->m_bindingName();

	if ( m_bindingName && strcmp( m_bindingName , XorStr( "C_CSPlayerPawn" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsPlantedC4() -> bool
{
	auto m_bindingName = this->GetSchemaClassBinding()->m_bindingName();

	if ( m_bindingName && strcmp( m_bindingName , XorStr( "C_PlantedC4" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsC4() -> bool
{
	auto m_bindingName = this->GetSchemaClassBinding()->m_bindingName();

	if ( m_bindingName && strcmp( m_bindingName , XorStr( "C_C4" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsSmokeGrenadeProjectile() -> bool
{
	auto m_bindingName = this->GetSchemaClassBinding()->m_bindingName();

	if ( m_bindingName && strcmp( m_bindingName , XorStr( "C_SmokeGrenadeProjectile" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsGrenadeProjectile() -> bool
{
	auto m_bindingName = this->GetSchemaClassBinding()->m_bindingName();

	if ( m_bindingName )
	{
		if ( strcmp( m_bindingName , XorStr( "C_HEGrenadeProjectile" ) ) == 0 )
			return true;

		if ( strcmp( m_bindingName , XorStr( "C_FlashbangProjectile" ) ) == 0 )
			return true;

		if ( strcmp( m_bindingName , XorStr( "C_SmokeGrenadeProjectile" ) ) == 0 )
			return true;

		if ( strcmp( m_bindingName , XorStr( "C_DecoyProjectile" ) ) == 0 )
			return true;

		if ( strcmp( m_bindingName , XorStr( "C_MolotovProjectile" ) ) == 0 )
			return true;
	}

	return false;
}

auto C_BaseEntity::IsCS2HudModelWeapon() -> bool
{
	auto m_bindingName = this->GetSchemaClassBinding()->m_bindingName();

	if ( m_bindingName && strcmp( m_bindingName , XorStr( "C_CS2HudModelWeapon" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::GetOrigin() -> const Vector3&
{
	auto pGameSceneNode = m_pGameSceneNode();

	if ( !pGameSceneNode )
		return Vector3::Zero;

	return pGameSceneNode->m_vecAbsOrigin();
}

auto C_BaseEntity::GetBoundingBox( Rect_t& out , bool computeSurroundingBox ) -> bool
{
	auto pCollision = m_pCollision();

	if ( !pCollision )
		return false;

	Vector3 mins;
	Vector3 maxs;

	if ( computeSurroundingBox )
	{
		if ( !ComputeHitboxSurroundingBox( mins , maxs ) )
			return false;
	}
	else
	{
		const auto absOrigin = GetOrigin();

		mins = pCollision->m_vecMins() + absOrigin;
		maxs = pCollision->m_vecMaxs() + absOrigin;
	}

#undef max
#undef min

	out.x = out.y = std::numeric_limits<float>::max();
	out.w = out.h = -std::numeric_limits<float>::max();

	for ( int i = 0; i < 8; ++i )
	{
		const Vector3 point_list[8] =
		{
		  Vector3( mins.m_x, mins.m_y, mins.m_z ), Vector3( mins.m_x, maxs.m_y, mins.m_z ),
		  Vector3( maxs.m_x, maxs.m_y, mins.m_z ), Vector3( maxs.m_x, mins.m_y, mins.m_z ),
		  Vector3( maxs.m_x, maxs.m_y, maxs.m_z ), Vector3( mins.m_x, maxs.m_y, maxs.m_z ),
		  Vector3( mins.m_x, mins.m_y, maxs.m_z ), Vector3( maxs.m_x, mins.m_y, maxs.m_z )
		};

		const Vector3 Point = point_list[i];

		ImVec2 Screen;
		
		if ( !Math::WorldToScreen( Point , Screen ) )
			return false;

		out.x = std::min( out.x , Screen.x );
		out.y = std::min( out.y , Screen.y );
		out.w = std::max( out.w , Screen.x );
		out.h = std::max( out.h , Screen.y );
	}

	return true;
}

auto C_BaseEntity::ComputeHitboxSurroundingBox( Vector3& mins , Vector3& maxs ) -> bool
{
	return C_BaseEntity_ComputeHitboxSurroundingBox( this , mins , maxs );
}

auto C_BaseEntity::SetBodyGroup() -> void
{
	return C_BaseEntity_SetBodyGroup( this , 0 , 1 );
}

auto C_BaseEntity::GetBoneIdByName( const char* szName ) -> int
{
	return C_BaseEntity_GetBoneIdByName( this , szName );
}

auto C_CSPlayerPawn::GetViewModels() -> std::vector<C_CS2HudModelWeapon*>
{
	auto* pC_CS2HudModelArms = m_hHudModelArms().Get<C_CS2HudModelArms>();

	std::vector<C_CS2HudModelWeapon*> vecViewModels;

	if ( pC_CS2HudModelArms )
	{
		auto* pCGameSceneNode = pC_CS2HudModelArms->m_pGameSceneNode();

		if ( pCGameSceneNode )
		{
			for ( auto* pChild = pCGameSceneNode->m_pChild(); pChild; pChild = pChild->m_pNextSibling() )
			{
				auto* pOwner = reinterpret_cast<C_BaseEntity*>( pChild->m_pOwner() );

				if ( pOwner && pOwner->IsCS2HudModelWeapon() )
				{
					vecViewModels.push_back( reinterpret_cast<C_CS2HudModelWeapon*>( pOwner ) );
				}
			}
		}
	}

	return vecViewModels;
}

auto C_CSPlayerPawn::GetViewModel() -> C_CS2HudModelWeapon*
{
	auto* pC_CSWeaponBaseGun = GetCL_Weapons()->GetLocalActiveWeapon();

	if ( pC_CSWeaponBaseGun )
	{
		const auto& ViewModels = GetViewModels();

		if ( !ViewModels.empty() )
		{
			for ( auto pViewModel : ViewModels )
			{
				auto* pOwnerEntity = pViewModel->m_hOwnerEntity().Get();

				if ( pOwnerEntity == pC_CSWeaponBaseGun )
					return pViewModel;
			}
		}
	}

	return nullptr;
}

auto C_CSPlayerPawn::GetKnifeModel() -> C_CS2HudModelWeapon*
{
	auto vecViewModels = GetViewModels();

	if ( vecViewModels.empty() )
		return nullptr;

	for ( auto model : vecViewModels )
	{
		CGameSceneNode* pGameSceneNode = model->m_pGameSceneNode();

		if ( pGameSceneNode && pGameSceneNode->GetSkeletonInstance() )
		{
			auto& pModelState = pGameSceneNode->GetSkeletonInstance()->m_modelState();

			std::string modelName = pModelState.m_ModelName().String();

			if ( modelName.find( "knife" ) != std::string::npos )
				return model;
		}
	}

	return nullptr;
}

auto C_EconItemView::GetSOCData() -> CEconItem*
{
	auto pInventory = CCSPlayerInventory::Get();

	if ( !pInventory )
		return nullptr;

	return pInventory->GetSOCDataForItem( m_iItemID() );
}

auto C_EconItemView::GetStaticData() -> CEconItemDefinition*
{
	return C_EconItemView_GetStaticData( this );
}

auto C_EconItemView::GetBasePlayerWeaponVData() -> CCSWeaponBaseVData*
{
	return C_EconItemView_GetBasePlayerWeaponVData( this );
}

auto C_BaseModelEntity::SetModel( const char* szModel ) -> void
{
	return C_BaseModelEntity_SetModel( this , szModel );
}

auto CGameSceneNode::SetMeshGroupMask( uint64_t meshGroupMask ) -> void
{
	return CGameSceneNode_SetMeshGroupMask( this , meshGroupMask );
}

auto C_CSWeaponBase::UpdateCompositeMaterial( CCompositeMaterialOwner* pCCompositeMaterialOwner ) -> void
{
	C_CSWeaponBase_UpdateCompositeMaterial( pCCompositeMaterialOwner , true );
}

auto C_CSWeaponBase::UpdateSubclass() -> void
{
	return C_CSWeaponBase_UpdateSubclass( this );
}

auto C_CSWeaponBase::UpdateSkin() -> void
{
	C_CSWeaponBase_UpdateSkin( this , true );
}

auto CGameSceneNode::GetBonePosition( int32 BoneIndex , Vector3& BonePos ) -> bool
{
	if ( auto* pSkeletonInstance = GetSkeletonInstance(); pSkeletonInstance && BoneIndex != -1 )
	{
		CModelState ModelState = pSkeletonInstance->m_modelState();

		if ( const CBoneData* pBones = ModelState.m_pBones; pBones )
		{
			const CBoneData& Data = pBones[BoneIndex];

			BonePos = Data.position;

			return true;
		}
	}

	return false;
}

auto CSkeletonInstance::CalcWorldSpaceBones( unsigned int Mask ) -> void
{
	return CSkeletonInstance_CalcWorldSpaceBones( this , Mask );
}
