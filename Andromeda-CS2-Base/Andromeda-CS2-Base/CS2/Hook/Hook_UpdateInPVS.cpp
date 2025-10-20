#include "Hook_UpdateInPVS.hpp"

#include <CS2/SDK/Types/CEntityData.hpp>

auto Hook_UpdateInPVS( CEntityInstance* pEntityInstance , int unk0 ) -> bool
{
	return true;

	//return UpdateInPVS_o( pEntityInstance , unk0 );
}
