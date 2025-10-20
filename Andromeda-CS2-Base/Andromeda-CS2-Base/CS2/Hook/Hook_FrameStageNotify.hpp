#pragma once

#include <Common/Common.hpp>

class CSource2Client;

auto Hook_FrameStageNotify( CSource2Client* pCSource2Client , int FrameStage ) -> void;

using FrameStageNotify_t = decltype( &Hook_FrameStageNotify );
inline FrameStageNotify_t FrameStageNotify_o = nullptr;
