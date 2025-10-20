#include "Hook_FrameStageNotify.hpp"

#include <AndromedaClient/CAndromedaClient.hpp>

auto Hook_FrameStageNotify( CSource2Client* pCSource2Client , int FrameStage ) -> void
{
	GetAndromedaClient()->OnFrameStageNotify( FrameStage );

	return FrameStageNotify_o( pCSource2Client , FrameStage );
}
