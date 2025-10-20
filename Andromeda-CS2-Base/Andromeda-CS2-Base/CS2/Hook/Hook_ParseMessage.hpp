#pragma once

#include <Common/Common.hpp>

class CDemoRecorder;
class CNetworkSerializerPB;
class CNetMessagePB;

auto Hook_CDemoRecorder( CDemoRecorder* pDemoRecorder , CNetworkSerializerPB* pSerializer , CNetMessagePB* pNetMessage ) -> bool;

using CDemoRecorder_t = decltype( &Hook_CDemoRecorder );
inline CDemoRecorder_t CDemoRecorder_o = nullptr;
