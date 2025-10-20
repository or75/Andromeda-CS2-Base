#include "Hook_MouseInputEnabled.hpp"

#include <AndromedaClient/CAndromedaGUI.hpp>

auto Hook_MouseInputEnabled( void* RCX ) -> bool
{
	if ( GetAndromedaGUI()->IsVisible() )
		return false;

	return MouseInputEnabled_o( RCX );
}
