#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/Types/CHandle.hpp>

class CGameEntitySystem;
class CEntityInstance;

auto Hook_OnRemoveEntity( CGameEntitySystem* pCGameEntitySystem , CEntityInstance* pInst , CHandle handle ) -> void;

using OnRemoveEntity_t = decltype( &Hook_OnRemoveEntity );
inline OnRemoveEntity_t OnRemoveEntity_o = nullptr;
