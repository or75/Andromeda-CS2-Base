#include "CL_Bypass.hpp"

#include <Common/Base64.h>

#include <CS2/SDK/Math/Math.hpp>

#include <CS2/SDK/Update/CUserCmd.hpp>
#include <CS2/SDK/Update/CCSGOInput.hpp>
#include <CS2/SDK/Update/CGlobalVarsBase.hpp>

#include <CS2/SDK/Interface/CInputSystem.hpp>
#include <CS2/SDK/FunctionListSDK.hpp>

static CL_Bypass g_CL_Bypass{};

auto CL_Bypass::PreClientCreateMove( CUserCmd* pUserCmd ) -> void
{
	m_InternalSubTickList.clear();
}

auto CL_Bypass::PostClientCreateMove( CCSGOInput* pCCSGOInput , CUserCmd* pUserCmd ) -> void
{
	for ( auto& SubTick : m_InternalSubTickList )
		AddSubtickMoveStep( pUserCmd , SubTick.m_Button , SubTick.m_Pressed , SubTick.m_flWhen );

	int EncodeLen = 0;

	const auto OriginalCrc = pUserCmd->cmd.base().move_crc();
	const auto OriginalCrcBase64 = base64( (unsigned char*)OriginalCrc.c_str() , OriginalCrc.size() , &EncodeLen );

	const auto SpoofedOriginalCrc = SpoofCrc();
	const auto SpoofedOriginalCrcBase64 = base64( (unsigned char*)SpoofedOriginalCrc.c_str() , SpoofedOriginalCrc.size() , &EncodeLen );

	if ( std::string( OriginalCrcBase64 ) != std::string( SpoofedOriginalCrcBase64 ) )
	{
		DEV_LOG( "[error] spoof move_crc\n" );
		ExitProcess( 0 );
	}

	free( OriginalCrcBase64 );
	free( SpoofedOriginalCrcBase64 );

	m_Backup.mutable_buttons_pb()->set_buttonstate1( pUserCmd->button_states.buttonstate1 );
	m_Backup.mutable_buttons_pb()->set_buttonstate2( pUserCmd->button_states.buttonstate2 );
	m_Backup.mutable_buttons_pb()->set_buttonstate3( pUserCmd->button_states.buttonstate3 );

	m_Backup.mutable_viewangles()->set_x( pUserCmd->cmd.base().viewangles().x() );
	m_Backup.mutable_viewangles()->set_y( pUserCmd->cmd.base().viewangles().y() );

	const auto SpoofedCrc = SpoofCrc();

	pUserCmd->cmd.mutable_base()->set_move_crc( SpoofedCrc );
}

auto CL_Bypass::SetViewAngles( QAngle* ViewAngles , CCSGOInput* pInput , CUserCmd* pUserCmd , bool AddSetViewAngles , bool OnlyInputHistory ) -> void
{
	Math::NormalizeAngles( *ViewAngles );
	Math::ClampAngles( *ViewAngles );

	const auto ViewAngleX = ( *ViewAngles ).m_x;
	const auto ViewAngleY = ( *ViewAngles ).m_y;

	if ( AddSetViewAngles && !OnlyInputHistory )
		CCSGOInput_SetViewAngles( pInput , 0 , *ViewAngles );

#if DISABLE_PROTOBUF == 0

	if ( !OnlyInputHistory )
	{
		pUserCmd->cmd.mutable_base()->mutable_viewangles()->set_x( ViewAngleX );
		pUserCmd->cmd.mutable_base()->mutable_viewangles()->set_y( ViewAngleY );
	}
	else
	{
		for ( auto i = 0; i < pUserCmd->cmd.input_history_size(); i++ )
		{
			auto pInputHistory = pUserCmd->cmd.mutable_input_history( i );

			if ( pInputHistory )
			{
				pInputHistory->mutable_view_angles()->set_x( ViewAngleX );
				pInputHistory->mutable_view_angles()->set_y( ViewAngleY );
			}
		}
	}

#endif
}

auto CL_Bypass::SetAttack( CUserCmd* pUserCmd , bool AddSubTIck ) -> void
{
	pUserCmd->button_states.buttonstate1 |= IN_ATTACK;

	pUserCmd->cmd.mutable_base()->mutable_buttons_pb()->set_buttonstate1( pUserCmd->button_states.buttonstate1 );

#if DISABLE_PROTOBUF == 0

	pUserCmd->cmd.set_attack1_start_history_index( 0 );

	if ( AddSubTIck )
		AddProcessSubTick( IN_ATTACK , true );

#endif
}

auto CL_Bypass::SetDontAttack( CUserCmd* pUserCmd , bool AddSubTIck ) -> void
{
	pUserCmd->button_states.buttonstate1 &= ~IN_ATTACK;

	pUserCmd->cmd.mutable_base()->mutable_buttons_pb()->set_buttonstate1( pUserCmd->button_states.buttonstate1 );

#if DISABLE_PROTOBUF == 0

	if( AddSubTIck )
		AddProcessSubTick( IN_ATTACK , false );

#endif
}

auto CL_Bypass::AddProcessSubTick( const uint64_t Button , const bool Pressed ) -> void
{
	m_InternalSubTickList.emplace_back( Button , Pressed , CalculateWhenValue() );
}

auto CL_Bypass::OnCBaseUserCmdPB( CBaseUserCmdPB* pBaseUserCmdPB ) -> void
{
	m_Backup = *pBaseUserCmdPB;
}

auto CL_Bypass::CalculateWhenValue() -> float
{
	return 0.99f;
}

auto CL_Bypass::AddSubtickMoveStep( CUserCmd* pUserCmd , const uint64_t button , const bool pressed , const float when ) -> void
{
	auto pRepeatedMoveSteps = reinterpret_cast<google::protobuf::RepeatedPtrField_t<CSubtickMoveStep>*>( (PBYTE)pUserCmd->cmd.mutable_base() + 0x18 );

	CSubtickMoveStep* pSubtickMoveStep = nullptr;

	if ( pRepeatedMoveSteps->m_pRep && pRepeatedMoveSteps->m_nCurrentSize < pRepeatedMoveSteps->m_pRep->m_nAllocatedSize )
	{
		pSubtickMoveStep = pRepeatedMoveSteps->m_pRep->m_tElements[pRepeatedMoveSteps->m_nCurrentSize++];

		if ( pSubtickMoveStep )
		{
			pSubtickMoveStep->set_button( button );
			pSubtickMoveStep->set_pressed( pressed );
			pSubtickMoveStep->set_when( when );
		}
	}
	else
	{
		pSubtickMoveStep = CreateSubtickMoveStep( pRepeatedMoveSteps->m_pArena );

		pSubtickMoveStep->set_button( button );
		pSubtickMoveStep->set_pressed( pressed );
		pSubtickMoveStep->set_when( when );

		ProtobufAddToRepeatedPtrElement( pRepeatedMoveSteps , pSubtickMoveStep );
	}
}

auto CL_Bypass::SpoofCrc() -> std::string
{
	const auto size = static_cast<int>( m_Backup.ByteSizeLong() );

	std::vector<uint8_t> bytes;
	bytes.resize( size );

	if ( !m_Backup.SerializePartialToArray( bytes.data() , size ) )
		DEV_LOG( "SpoofCrc: #1\n" );

	return std::string( bytes.begin() , bytes.end() );
}

auto GetCL_Bypass() -> CL_Bypass*
{
	return &g_CL_Bypass;
}
