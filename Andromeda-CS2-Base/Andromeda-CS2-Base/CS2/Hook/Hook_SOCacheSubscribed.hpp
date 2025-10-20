#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/GCSDK/GCSDKTypes/SOID_t.hpp>

class CCSPlayerInventory;

auto Hook_SOCacheSubscribed( CCSPlayerInventory* pCSPlayerInventory , GCSDK::SOID_t owner , int64_t unk ) -> void*;

using SOCacheSubscribed_t = decltype( &Hook_SOCacheSubscribed );
inline SOCacheSubscribed_t SOCacheSubscribed_o = nullptr;
