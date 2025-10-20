#include "CL_VisibleCheck.hpp"

#include <CS2/SDK/Types/CEntityData.hpp>

#include <GameClient/CL_Bones.hpp>
#include <GameClient/CL_Trace.hpp>

static CL_VisibleCheck g_CL_VisibleCheck{};

auto CL_VisibleCheck::IsPlayerControllerVisible( CCSPlayerController* pCCSPlayerController ) -> bool
{
	auto Visible = false;

	if ( pCCSPlayerController )
		Visible = IsPlayerPawnVisible( pCCSPlayerController->m_hPawn().Get<C_CSPlayerPawn>() );

	return Visible;
}

auto CL_VisibleCheck::IsPlayerPawnVisible( C_CSPlayerPawn* pC_CSPlayerPawn ) -> bool
{
	auto Visible = false;

	if ( pC_CSPlayerPawn && pC_CSPlayerPawn->IsPlayerPawn() )
	{
		bool IsBoneVisible = false;

		for ( const auto& BoneName : g_AllTraceVisibleCheckBones )
		{
			const Vector3 BonePos = GetCL_Bones()->GetBonePositionByName( pC_CSPlayerPawn , BoneName.c_str() );

			if ( !BonePos.IsZero() )
			{
				const auto* pTracedEntity = GetCL_Trace()->TraceToEntityEndPos( &BonePos );

				if ( pTracedEntity == pC_CSPlayerPawn )
					IsBoneVisible = true;
				else
					continue;
			}
			else
			{
				IsBoneVisible = false;
			}
		}

		Visible = IsBoneVisible;
	}

	return Visible;
}

auto CL_VisibleCheck::IsBoneVisible( C_CSPlayerPawn* pC_CSPlayerPawn , const Vector3& BonePos ) -> bool
{
	auto Visible = false;

	if ( pC_CSPlayerPawn && pC_CSPlayerPawn->IsPlayerPawn() )
	{
		if ( !BonePos.IsZero() )
		{
			const auto* pTracedEntity = GetCL_Trace()->TraceToEntityEndPos( &BonePos );

			if ( pTracedEntity == pC_CSPlayerPawn )
				Visible = true;
		}
	}

	return Visible;
}

auto GetCL_VisibleCheck() -> CL_VisibleCheck*
{
	return &g_CL_VisibleCheck;
}
