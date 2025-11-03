#include "CVisual.hpp"

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/IEngineToClient.hpp>

#include <AndromedaClient/Render/CRender.hpp>
#include <AndromedaClient/Render/CRenderStackSystem.hpp>
#include <AndromedaClient/Settings/Settings.hpp>

#include <GameClient/CEntityCache/CEntityCache.hpp>
#include <GameClient/CL_Players.hpp>
#include <GameClient/CL_VisibleCheck.hpp>
#include <GameClient/CL_Bones.hpp>
#include <CS2/SDK/Math/Math.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>
#include <CS2/SDK/Types/Color.hpp>

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

		if ( Settings::Visual::BoneESP )
		{
			auto ShouldDrawBone = false;

			if ( Settings::Visual::BoneESPTeam && !IsEnemy )
				ShouldDrawBone = true;

			if ( Settings::Visual::BoneESPEnemy && IsEnemy )
				ShouldDrawBone = true;

			if ( Settings::Visual::OnlyVisible && !bVisible )
				ShouldDrawBone = false;

			if ( ShouldDrawBone )
			{
				DrawBoneESP( pC_CSPlayerPawn , bVisible , pCCSPlayerController->m_iTeamNum() );
			}
		}
	}
}

auto CVisual::ApplyGlow( C_CSPlayerPawn* pC_CSPlayerPawn , const bool bVisible , const int iTeamNum ) -> void
{
	if ( !pC_CSPlayerPawn || !pC_CSPlayerPawn->IsPlayerPawn() )
		return;

	auto IsEnemy = false;
	C_CSPlayerPawn* pLocalPawn = nullptr;

	if ( auto* pLocalPlayerController = GetCL_Players()->GetLocalPlayerController(); pLocalPlayerController )
	{
		pLocalPawn = pLocalPlayerController->m_hPawn().Get<C_CSPlayerPawn>();
		if ( pLocalPawn )
		{
			IsEnemy = iTeamNum != pLocalPawn->m_iTeamNum();

			// Local player'dan glow'u kaldır
			if ( pC_CSPlayerPawn == pLocalPawn )
			{
				auto& Glow = pC_CSPlayerPawn->m_Glow();
				Glow.m_bGlowing() = false;
				return;
			}
		}
	}

	auto DrawGlow = false;

	if ( Settings::Visual::GlowTeam && !IsEnemy )
		DrawGlow = true;

	if ( Settings::Visual::GlowEnemy && IsEnemy )
		DrawGlow = true;

	if ( Settings::Visual::OnlyVisible && !bVisible )
		DrawGlow = false;

	if ( !DrawGlow )
	{
		// Glow'u kapat
		auto& Glow = pC_CSPlayerPawn->m_Glow();
		Glow.m_bGlowing() = false;
		return;
	}

	auto GlowColor = Color( 255 , 255 , 255 , 255 );

	if ( iTeamNum == TEAM_TT )
	{
		const auto& ColorVec = Settings::Colors::Visual::GlowTT;
		if ( bVisible )
		{
			const auto& VisibleColorVec = Settings::Colors::Visual::GlowTT_Visible;
			GlowColor = Color( 
				static_cast<BYTE>( VisibleColorVec.x * 255.f ) , 
				static_cast<BYTE>( VisibleColorVec.y * 255.f ) , 
				static_cast<BYTE>( VisibleColorVec.z * 255.f ) , 
				static_cast<BYTE>( VisibleColorVec.w * 255.f ) 
			);
		}
		else
		{
			GlowColor = Color( 
				static_cast<BYTE>( ColorVec.x * 255.f ) , 
				static_cast<BYTE>( ColorVec.y * 255.f ) , 
				static_cast<BYTE>( ColorVec.z * 255.f ) , 
				static_cast<BYTE>( ColorVec.w * 255.f ) 
			);
		}
	}
	else if ( iTeamNum == TEAM_CT )
	{
		const auto& ColorVec = Settings::Colors::Visual::GlowCT;
		if ( bVisible )
		{
			const auto& VisibleColorVec = Settings::Colors::Visual::GlowCT_Visible;
			GlowColor = Color( 
				static_cast<BYTE>( VisibleColorVec.x * 255.f ) , 
				static_cast<BYTE>( VisibleColorVec.y * 255.f ) , 
				static_cast<BYTE>( VisibleColorVec.z * 255.f ) , 
				static_cast<BYTE>( VisibleColorVec.w * 255.f ) 
			);
		}
		else
		{
			GlowColor = Color( 
				static_cast<BYTE>( ColorVec.x * 255.f ) , 
				static_cast<BYTE>( ColorVec.y * 255.f ) , 
				static_cast<BYTE>( ColorVec.z * 255.f ) , 
				static_cast<BYTE>( ColorVec.w * 255.f ) 
			);
		}
	}

	// Glow'u uygula
	auto& Glow = pC_CSPlayerPawn->m_Glow();
	Glow.m_bGlowing() = true;
	Glow.m_glowColorOverride() = GlowColor;
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

				if ( Settings::Visual::Glow && pCCSPlayerController->m_bPawnIsAlive() )
				{
					auto* pC_CSPlayerPawn = pCCSPlayerController->m_hPawn().Get<C_CSPlayerPawn>();
					if ( pC_CSPlayerPawn && pC_CSPlayerPawn->IsPlayerPawn() )
					{
						ApplyGlow( pC_CSPlayerPawn , CachedEntity.m_bVisible , pCCSPlayerController->m_iTeamNum() );
					}
				}
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

auto CVisual::DrawBoneESP( C_CSPlayerPawn* pC_CSPlayerPawn , const bool bVisible , const int iTeamNum ) -> void
{
	if ( !pC_CSPlayerPawn || !pC_CSPlayerPawn->IsPlayerPawn() )
		return;

	auto BoneColor = ImColor( 255 , 255 , 255 );

	if ( iTeamNum == TEAM_TT )
	{
		BoneColor = Settings::Colors::Visual::BoneESPTT;

		if ( bVisible )
			BoneColor = Settings::Colors::Visual::BoneESPTT_Visible;
	}
	else if ( iTeamNum == TEAM_CT )
	{
		BoneColor = Settings::Colors::Visual::BoneESPCT;

		if ( bVisible )
			BoneColor = Settings::Colors::Visual::BoneESPCT_Visible;
	}

	// Bone connections structure for CS2 skeleton
	struct BoneConnection_t
	{
		const char* szFrom;
		const char* szTo;
	};

	static const BoneConnection_t BoneConnections[] =
	{
		// Head to spine chain
		{ "head_0" , "neck_0" },
		{ "neck_0" , "spine_1" },
		{ "spine_1" , "spine_2" },
		{ "spine_2" , "spine_3" },
		{ "spine_3" , "pelvis" },

		// Left arm
		{ "neck_0" , "clavicle_l" },
		{ "clavicle_l" , "arm_upper_l" },
		{ "arm_upper_l" , "arm_lower_l" },
		{ "arm_lower_l" , "hand_l" },

		// Right arm
		{ "neck_0" , "clavicle_r" },
		{ "clavicle_r" , "arm_upper_r" },
		{ "arm_upper_r" , "arm_lower_r" },
		{ "arm_lower_r" , "hand_r" },

		// Left leg
		{ "pelvis" , "leg_upper_l" },
		{ "leg_upper_l" , "leg_lower_l" },
		{ "leg_lower_l" , "ankle_l" },

		// Right leg
		{ "pelvis" , "leg_upper_r" },
		{ "leg_upper_r" , "leg_lower_r" },
		{ "leg_lower_r" , "ankle_r" },
	};

	for ( const auto& Connection : BoneConnections )
	{
		const Vector3 FromBone = GetCL_Bones()->GetBonePositionByName( pC_CSPlayerPawn , Connection.szFrom );
		const Vector3 ToBone = GetCL_Bones()->GetBonePositionByName( pC_CSPlayerPawn , Connection.szTo );

		if ( FromBone.IsZero() || ToBone.IsZero() )
			continue;

		ImVec2 FromScreen , ToScreen;

		if ( Math::WorldToScreen( FromBone , FromScreen ) && Math::WorldToScreen( ToBone , ToScreen ) )
		{
			GetRenderStackSystem()->DrawLine( FromScreen , ToScreen , BoneColor , 1.5f );
		}
	}
}

auto GetVisual() -> CVisual*
{
	return &g_CVisual;
}
