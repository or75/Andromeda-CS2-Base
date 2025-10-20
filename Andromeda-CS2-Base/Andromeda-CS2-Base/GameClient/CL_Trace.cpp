#include "CL_Trace.hpp"

#include <Fnv1a/Hash_Fnv1a_Constexpr.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/FunctionListSDK.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>

#include <CS2/SDK/Update/GameTrace.hpp>
#include <CS2/SDK/Update/CCSGOInput.hpp>

#include <CS2/SDK/Math/Math.hpp>

#include <GameClient/CL_Players.hpp>
#include <GameClient/CL_Weapons.hpp>
#include <GameClient/CL_Bones.hpp>

static CL_Trace g_CL_Trace{};

auto CL_Trace::TraceToBoneEntity( CCSGOInput* pInput , const QAngle* AngleCorrection , QAngle* ViewAngleCorrection ) -> std::pair<uint64_t , C_BaseEntity*>
{
	auto pLocalPlayerPawn = GetCL_Players()->GetLocalPlayerPawn();

	if ( !pLocalPlayerPawn )
		return { 0 , nullptr };

	Vector3 vForward;

	Ray_t Ray;
	CGameTrace GameTrace;
	CTraceFilter Filter( 0x1C1003 , pLocalPlayerPawn , 3 , 15 );

	const auto vStart = GetCL_Players()->GetLocalEyeOrigin();
	QAngle ViewAngles = *CCSGOInput_GetViewAngles( pInput , 0 );

	if ( AngleCorrection )
		ViewAngles += ( *AngleCorrection * 2.f );

	if ( ViewAngleCorrection )
		*ViewAngleCorrection = ViewAngles;

	Math::AngleVectors( ViewAngles , vForward );

	vForward *= 8192.f;

	const auto vEnd = vStart + vForward;

	if ( IGamePhysicsQuery_TraceShape( SDK::Pointers::CVPhys2World() , Ray , vStart , vEnd , &Filter , &GameTrace ) )
	{
		if ( GameTrace.pHitBox && GameTrace.pHitBox->szBoneName &&
				hash_64_fnv1a_const( GameTrace.pHitBox->szBoneName ) != hash_64_fnv1a_const( "invalid_bone" ) )
		{
			//DEV_LOG( "Trace: %s\n" , GameTrace.pHitBox->szBoneName );

			return { hash_64_fnv1a_const( GameTrace.pHitBox->szBoneName ) , GameTrace.pHitEntity };
		}
	}

	return { 0 , nullptr };
}

auto CL_Trace::TraceToEntityEndPos( const Vector3* vEnd ) -> C_BaseEntity*
{
	auto pLocalPlayerPawn = GetCL_Players()->GetLocalPlayerPawn();

	if ( !pLocalPlayerPawn )
		return nullptr;

	Ray_t Ray;
	CGameTrace GameTrace;
	CTraceFilter Filter( 0x1C1003 , pLocalPlayerPawn , 3 , 15 );

	const auto vStart = GetCL_Players()->GetLocalEyeOrigin();

	if ( IGamePhysicsQuery_TraceShape( SDK::Pointers::CVPhys2World() , Ray , vStart , *vEnd , &Filter , &GameTrace ) )
	{
		if ( GameTrace.pHitBox && GameTrace.pHitEntity && GameTrace.pHitBox->szBoneName &&
			 hash_64_fnv1a_const( GameTrace.pHitBox->szBoneName ) != hash_64_fnv1a_const( "invalid_bone" ) )
		{
			return GameTrace.pHitEntity;
		}
	}

	return nullptr;
}

auto GetCL_Trace() -> CL_Trace*
{
	return &g_CL_Trace;
}
