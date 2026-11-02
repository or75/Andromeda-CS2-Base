#pragma once

#include "IWidget.hpp"

#include <ImGui/imgui.h>

namespace GitMenu
{
	class CColorWidget final : public IWidget
	{
	public:
		// RGBA components are in [0, 1]; value must outlive the widget.
		CColorWidget( const char* name , const char* description , ImVec4* value , bool separatorAfter = false );

		auto OnRenderImGui() -> void override;
		auto SetSeparatorAfter( bool enabled ) -> void { m_SeparatorAfter = enabled; }

	private:
		ImVec4* m_Value;
		bool m_SeparatorAfter;
	};
}
