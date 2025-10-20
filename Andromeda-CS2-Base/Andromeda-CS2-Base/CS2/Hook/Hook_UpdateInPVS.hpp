#pragma once

#include <Common/Common.hpp>

class CEntityInstance;

auto Hook_UpdateInPVS( CEntityInstance* pEntityInstance , int unk0 ) -> bool;

using UpdateInPVS_t = decltype( &Hook_UpdateInPVS );
inline UpdateInPVS_t UpdateInPVS_o = nullptr;
