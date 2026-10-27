#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

#include "../Custom/IWidget.hpp"

#include <memory>
#include <utility>
#include <vector>

namespace GitMenu
{
	class ISubPage
	{
	public:
		virtual ~ISubPage() = default;

		virtual auto GetDisplayName() const -> const char* = 0;
		virtual auto GetIcon() const -> ImTextureRef { return m_Icon; }

		// UTF-8 glyph literal, e.g. u8"\uf015"; used when no texture is available.
		virtual auto GetFontAwesomeIcon() const -> const char8_t* { return nullptr; }

		auto SetIcon( ImTextureRef icon ) -> void { m_Icon = icon; }
		auto GetWidgets() const -> const std::vector<std::unique_ptr<IWidget>>& { return m_Widgets; }

		virtual auto OnRender() -> void
		{
			for ( const auto& pWidget : m_Widgets )
			{
				if ( pWidget )
					pWidget->OnRenderImGui();
			}
		}

		virtual auto OnEnter() -> void {}
		virtual auto OnLeave() -> void {}

	protected:
		auto AddWidget( std::unique_ptr<IWidget> pWidget ) -> IWidget*
		{
			m_Widgets.push_back( std::move( pWidget ) );
			return m_Widgets.back().get();
		}

	private:
		ImTextureRef m_Icon;
		std::vector<std::unique_ptr<IWidget>> m_Widgets;
	};
}
