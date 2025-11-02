#include "CVisual.hpp"

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/IEngineToClient.hpp>

#include <AndromedaClient/Render/CRender.hpp>
#include <AndromedaClient/Render/CRenderStackSystem.hpp>
#include <AndromedaClient/Settings/Settings.hpp>

#include <GameClient/CEntityCache/CEntityCache.hpp>
#include <GameClient/CL_Players.hpp>
#include <GameClient/CL_VisibleCheck.hpp>

static CVisual g_CVisual{};

auto CVisual::OnRender() -> void
{
	if ( !Settings::Visual::Active )
		return;

	const auto& CachedVec = GetEntityCache()->GetCachedEntity();

	std::scoped_lock Lock( GetEntityCache()->GetLock() );

	for ( const auto& CachedEntity : *CachedVec )
	{
		auto pEntity = CachedEntity.m_Handle.Get();

		if ( !pEntity )
			continue;

		auto hEntity = pEntity->pEntityIdentity()->Handle();

		if ( hEntity != CachedEntity.m_Handle )
			continue;

		switch ( CachedEntity.m_Type )
		{
			case CachedEntity_t::PLAYER_CONTROLLER:
			{
				auto* pCCSPlayerController = reinterpret_cast<CCSPlayerController*>( pEntity );

				if ( CachedEntity.m_bDraw )
					OnRenderPlayerEsp( pCCSPlayerController , CachedEntity.m_Bbox , CachedEntity.m_bVisible );
			}
			break;
		}
	}
}

auto CVisual::OnRenderPlayerEsp( CCSPlayerController* pCCSPlayerController , const Rect_t& bBox , const bool bVisible ) -> void
{
	if ( !pCCSPlayerController->m_bPawnIsAlive() )
		return;

	auto* pC_CSPlayerPawn = pCCSPlayerController->m_hPawn().Get<C_CSPlayerPawn>();

	if ( !pC_CSPlayerPawn || !pC_CSPlayerPawn->IsPlayerPawn() )
		return;

	auto IsEnemy = false;

	if ( auto* pLocalPlayerController = GetCL_Players()->GetLocalPlayerController(); pLocalPlayerController )
		IsEnemy = pCCSPlayerController->m_iTeamNum() != pLocalPlayerController->m_iTeamNum();

	const ImVec2 min = { bBox.x, bBox.y };
	const ImVec2 max = { bBox.w, bBox.h };

	std::vector<std::string> PlayerItemIconList;

	auto Draw = false;

	if ( Settings::Visual::Team && !IsEnemy )
		Draw = true;

	if ( Settings::Visual::Enemy && IsEnemy )
		Draw = true;

	if ( Settings::Visual::OnlyVisible )
	{
		if ( bVisible )
			Draw = true;
		else
			Draw = false;
	}

	if ( Draw )
	{
		if ( Settings::Visual::PlayerBox )
		{
			auto PlayerColor = ImColor( 255 , 255 , 255 );

			if ( pCCSPlayerController->m_iTeamNum() == TEAM_TT )
			{
				PlayerColor = Settings::Colors::Visual::PlayerBoxTT;

				if ( bVisible )
					PlayerColor = Settings::Colors::Visual::PlayerBoxTT_Visible;
			}
			else if ( pCCSPlayerController->m_iTeamNum() == TEAM_CT )
			{
				PlayerColor = Settings::Colors::Visual::PlayerBoxCT;

				if ( bVisible )
					PlayerColor = Settings::Colors::Visual::PlayerBoxCT_Visible;
			}

			if ( Settings::Visual::PlayerBoxType == EVisualBoxType_t::BOX )
				GetRenderStackSystem()->DrawBox( min , max , PlayerColor );
			else if ( Settings::Visual::PlayerBoxType == EVisualBoxType_t::OUTLINE_BOX )
				GetRenderStackSystem()->DrawOutlineBox( min , max , PlayerColor );
			else if ( Settings::Visual::PlayerBoxType == EVisualBoxType_t::COAL_BOX )
				GetRenderStackSystem()->DrawCoalBox( min , max , PlayerColor );
			else if ( Settings::Visual::PlayerBoxType == EVisualBoxType_t::OUTLINE_COAL_BOX )
				GetRenderStackSystem()->DrawOutlineCoalBox( min , max , PlayerColor );
		}
	}
}

auto CVisual::OnClientOutput() -> void
{
	OnRender();
}

auto CVisual::OnCreateMove() -> void
{
	if ( !Settings::Visual::Active )
		return;

	const auto CachedVec = GetEntityCache()->GetCachedEntity();

	for ( auto& CachedEntity : *CachedVec )
	{
		auto pEntity = CachedEntity.m_Handle.Get();

		if ( !pEntity )
			continue;

		auto hEntity = pEntity->pEntityIdentity()->Handle();

		if ( hEntity != CachedEntity.m_Handle )
			continue;

		switch ( CachedEntity.m_Type )
		{
			case CachedEntity_t::PLAYER_CONTROLLER:
			{
				auto* pCCSPlayerController = reinterpret_cast<CCSPlayerController*>( pEntity );

				CachedEntity.m_bVisible = GetCL_VisibleCheck()->IsPlayerControllerVisible( pCCSPlayerController );
			}
			break;
			default:
				break;
		}
	}
}

auto CVisual::CalculateBoundingBoxes() -> void
{
	if ( !SDK::Interfaces::EngineToClient()->IsInGame() )
		return;

	const auto& CachedVec = GetEntityCache()->GetCachedEntity();

	std::scoped_lock Lock( GetEntityCache()->GetLock() );

	for ( auto& it : *CachedVec )
	{
		auto pEntity = it.m_Handle.Get();

		if ( !pEntity )
			continue;

		auto hEntity = pEntity->pEntityIdentity()->Handle();

		if ( hEntity != it.m_Handle )
			continue;

		switch ( it.m_Type )
		{
			case CachedEntity_t::PLAYER_CONTROLLER:
			{
				auto pPlayerController = reinterpret_cast<CCSPlayerController*>( pEntity );
				auto pPlayerPawn = pPlayerController->m_hPawn().Get<C_CSPlayerPawn>();

				if ( pPlayerPawn && pPlayerPawn->IsPlayerPawn() && pPlayerController->m_bPawnIsAlive() )
					it.m_bDraw = pPlayerPawn->GetBoundingBox( it.m_Bbox );
			}
			break;
		}
	}
}

auto GetVisual() -> CVisual*
{
	return &g_CVisual;
}
