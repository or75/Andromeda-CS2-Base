#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>
#include <initializer_list>
#include <span>

namespace GitMenu
{
	class CTollTip final
	{
	public:
		// Call immediately after the item that owns the tooltip.
		static auto Render( const char* szText , ImGuiHoveredFlags hoverFlags = ImGuiHoveredFlags_None ) -> void;

		// Each chord is a sequence step: { G, D } means G followed by D.
		static auto Render( const char* szText , std::span<const ImGuiKeyChord> shortcut ,
			ImGuiHoveredFlags hoverFlags = ImGuiHoveredFlags_None ) -> void;

		static auto Render( const char* szText , std::initializer_list<ImGuiKeyChord> shortcut ,
			ImGuiHoveredFlags hoverFlags = ImGuiHoveredFlags_None ) -> void
		{
			Render( szText , std::span<const ImGuiKeyChord>( shortcut.begin() , shortcut.size() ) , hoverFlags );
		}
	};
}
