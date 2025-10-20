#include "CHandle.hpp"

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/CGameEntitySystem.hpp>

auto CHandle::GetBaseEntity() const -> C_BaseEntity*
{
	if ( auto pEntity = (C_BaseEntity*)SDK::Interfaces::GameEntitySystem()->GetBaseEntity( GetEntryIndex() ); pEntity )
		return pEntity;

	return nullptr;
}
