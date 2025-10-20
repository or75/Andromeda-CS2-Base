#include "Hook_IsRelativeMouseMode.hpp"

#include <AndromedaClient/CAndromedaGUI.hpp>

auto Hook_IsRelativeMouseMode( CInputSystem* pInputSystem , bool Active ) -> void
{
	GetAndromedaGUI()->m_bMainActive = Active;

	if ( GetAndromedaGUI()->IsVisible() )
		return IsRelativeMouseMode_o( pInputSystem , false );

	return IsRelativeMouseMode_o( pInputSystem , Active );
}
