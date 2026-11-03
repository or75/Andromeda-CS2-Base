#pragma once

#include "IWidget.hpp"

#include <memory>
#include <utility>
#include <vector>

#include <AndromedaClient/CAndromedaGUI.hpp>

namespace GitMenu
{
	class CSectionBar : public IWidget
	{
	public:
		// Height: 0 fills the available space, negative fits content, positive is fixed.
		CSectionBar( const char* szSectionName , ImVec2 SectionSize = ImVec2( 0.f , -1.f ) );

		auto OnRenderImGui() -> void override;

		// Adds a child widget rendered inside the section's body.
		auto AddWidget( std::unique_ptr<IWidget> pWidget ) -> IWidget*;
		auto GetChildren() const -> const std::vector<std::unique_ptr<IWidget>>& override { return m_Widgets; }

	private:
		const char* m_szSectionName;
		ImVec2      m_SectionSize;

		// Natural size of the inner widgets, measured last frame. Used to
		// auto-fit the section when its height is negative.
		ImVec2      m_AutoContentSize = ImVec2( 0.f , 0.f );
		bool        m_HasMeasured     = false;
		float       m_MeasuredWidth   = 0.f;
		float       m_MeasuredScale   = 0.f;

		std::vector<std::unique_ptr<IWidget>> m_Widgets;

		static constexpr auto m_SectionTextPadding = ImVec2( 16.f , 32.f );
		static constexpr auto m_SectionItemsPadding = ImVec2( 16.f , 16.f );
	};
}
