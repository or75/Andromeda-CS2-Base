#pragma once

#include "IWidget.hpp"

namespace GitMenu
{
	class CSliderFloatWidget final : public IWidget
	{
	public:
		// value must remain valid for the lifetime of the widget.
		CSliderFloatWidget( const char* name , const char* description , float* value , float minValue , float maxValue , const char* format = "%.2f" , bool separatorAfter = false );

		auto OnRenderImGui() -> void override;
		auto SetSeparatorAfter( bool enabled ) -> void { m_SeparatorAfter = enabled; }

	private:
		float* m_Value;
		float m_MinValue;
		float m_MaxValue;
		std::string m_Format;
		bool m_SeparatorAfter;
	};
}
