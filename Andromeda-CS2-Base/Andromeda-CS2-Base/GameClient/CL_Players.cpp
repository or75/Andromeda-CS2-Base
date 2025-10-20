#include "CL_Players.hpp"

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/CGameEntitySystem.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>

static CL_Players g_CL_Players{};

auto CL_Players::GetLocalPlayerController() -> CCSPlayerController*
{
	return SDK::Interfaces::GameEntitySystem()->GetLocalPlayerController();
}

auto CL_Players::GetLocalPlayerPawn() -> C_CSPlayerPawn*
{
	auto pLocalPlayerController = GetLocalPlayerController();

	if ( pLocalPlayerController )
	{
		auto pLocalPawn = pLocalPlayerController->m_hPawn().Get<C_CSPlayerPawn>();

		if ( pLocalPawn && pLocalPawn->IsPlayerPawn() )
			return pLocalPawn;
	}

	return nullptr;
}

auto CL_Players::IsLocalPlayerAlive() -> bool
{
	auto pLocalPlayerController = GetLocalPlayerController();

	if ( pLocalPlayerController && pLocalPlayerController->m_bPawnIsAlive() )
		return true;

	return false;
}

auto GetCL_Players() -> CL_Players*
{
	return &g_CL_Players;
}
