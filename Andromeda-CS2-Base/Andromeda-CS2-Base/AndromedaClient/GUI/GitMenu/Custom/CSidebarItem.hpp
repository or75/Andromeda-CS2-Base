#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

namespace GitMenu
{
	class CSidebarItem final
	{
	public:
		static auto Render( const char* id , const char* displayName , ImTextureRef icon , bool bIsActive , float scale , const char8_t* fontAwesomeIcon = nullptr ) -> bool;
	};
}
