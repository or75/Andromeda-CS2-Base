#pragma once

#include "IWidget.hpp"

#include <string>

namespace GitMenu
{
	class CCheckBoxWidget final : public IWidget
	{
	public:
		// value must remain valid for the lifetime of the widget.
		CCheckBoxWidget( const char* name , const char* description , bool* value , bool separatorAfter = false );

		auto OnRenderImGui() -> void override;
		auto SetSeparatorAfter( bool enabled ) -> void { m_SeparatorAfter = enabled; }

	private:
		bool* m_Value;
		bool m_SeparatorAfter;
		bool m_AnimationInitialized = false;

		static constexpr float m_ToggleDuration = 0.16f;
	};
}
