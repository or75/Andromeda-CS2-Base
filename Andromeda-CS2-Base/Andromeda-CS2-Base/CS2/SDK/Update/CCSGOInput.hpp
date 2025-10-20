#pragma once

#include "CUserCmd.hpp"

#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Math/Vector3.hpp>
#include <CS2/SDK/Update/Offsets.hpp>
#include <CS2/SDK/FunctionListSDK.hpp>

#include <GameClient/CL_Players.hpp>

class CCSInputMoves
{
public:
	CUSTOM_OFFSET_FIELD( Vector3 , m_vecViewAngles , g_CCSInputMoves_m_vecViewAngles );
};

class CCSGOInput
{
public:
	CUSTOM_OFFSET_FIELD( bool , m_bInThirdPerson , g_CCSGOInput_m_bInThirdPerson );
	CUSTOM_OFFSET_FIELD( CCSInputMoves* , m_pInputMoves , g_CCSGOInput_m_pInputMoves );

public:
	auto GetSequenceNumber( CCSPlayerController* pLocalPlayerController ) -> uint32_t
	{
		int32_t OutputTick = 0;
		GetCUserCmdTick( pLocalPlayerController , &OutputTick );

		int32_t Tick = OutputTick - 1;

		if ( OutputTick == -1 )
			Tick = -1;

		auto* pCUserCmdArray = GetCUserCmdArray( SDK::Pointers::GetFirstCUserCmdArray() , Tick );

		if ( pCUserCmdArray )
			return pCUserCmdArray->m_nSequenceNumber();

		return 0;
	}

	auto GetUserCmd( CCSPlayerController* pLocalPlayerController ) -> CUserCmd*
	{
		const auto SequenceNumber = GetSequenceNumber( pLocalPlayerController );

		if ( SequenceNumber )
			return GetCUserCmdBySequenceNumber( pLocalPlayerController , SequenceNumber );

		return nullptr;
	}
};
