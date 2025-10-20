#include "CL_Weapons.hpp"
#include "CL_Players.hpp"

#include <CS2/SDK/Types/CEntityData.hpp>

#include "CL_ItemDefinition.hpp"

static CL_Weapons g_CL_Weapons{};

auto CL_Weapons::GetLocalActiveWeapon() -> C_CSWeaponBaseGun*
{
	const auto pLocalPlayerPawn = GetCL_Players()->GetLocalPlayerPawn();

	if ( pLocalPlayerPawn )
	{
		const auto pWeaponService = pLocalPlayerPawn->m_pWeaponServices();

		if ( pWeaponService )
		{
			const auto pLocalWeapon = pWeaponService->m_hActiveWeapon().Get<C_CSWeaponBaseGun>();

			if ( pLocalWeapon )
				return pLocalWeapon;
		}
	}

	return nullptr;
}

auto CL_Weapons::GetLocalWeaponVData() -> CCSWeaponBaseVData*
{
	const auto pLocalWeapon = GetLocalActiveWeapon();

	if ( pLocalWeapon )
	{
		const auto pAttributeManager = pLocalWeapon->m_AttributeManager();

		if ( pAttributeManager )
		{
			const auto pEconItemView = pAttributeManager->m_Item();

			if ( pEconItemView )
			{
				const auto pWeaponVData = pEconItemView->GetBasePlayerWeaponVData();

				if ( pWeaponVData )
					return pWeaponVData;
			}
		}
	}

	return nullptr;
}

auto CL_Weapons::GetLocalWeaponType() -> CSWeaponType_t
{
	const auto pWeaponVData = GetLocalWeaponVData();

	if ( pWeaponVData )
		return pWeaponVData->m_WeaponType().m_Type;

	return CSWeaponType_t::WEAPONTYPE_UNKNOWN;
}

auto CL_Weapons::GetLocalWeaponDefinitionIndex() -> int
{
	const auto pLocalWeapon = GetLocalActiveWeapon();

	if ( pLocalWeapon )
	{
		const auto pAttributeManager = pLocalWeapon->m_AttributeManager();

		if ( pAttributeManager )
		{
			const auto pEconItemView = pAttributeManager->m_Item();

			if ( pEconItemView )
			{
				return pEconItemView->m_iItemDefinitionIndex();
			}
		}
	}

	return -1;
}

auto GetCL_Weapons() -> CL_Weapons*
{
	return &g_CL_Weapons;
}
