#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/Types/CHandle.hpp>

class CGameEntitySystem;
class CEntityInstance;

auto Hook_OnAddEntity( CGameEntitySystem* pCGameEntitySystem , CEntityInstance* pInst , CHandle handle ) -> void;

using OnAddEntity_t = decltype( &Hook_OnAddEntity );
inline OnAddEntity_t OnAddEntity_o = nullptr;
