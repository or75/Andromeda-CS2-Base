#pragma once

#include <common/Common.hpp>

class IGameEventManager2;
class IGameEvent;

auto Hook_FireEventClientSide( IGameEventManager2* pGameEventManager2 , IGameEvent* pGameEvent ) -> bool;

using FireEventClientSide_t = decltype( &Hook_FireEventClientSide );
inline FireEventClientSide_t FireEventClientSide_o = nullptr;
