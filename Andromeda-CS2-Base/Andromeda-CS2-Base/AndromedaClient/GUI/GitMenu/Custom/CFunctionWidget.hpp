#pragma once

#include "IWidget.hpp"

#include <functional>
#include <utility>

namespace GitMenu
{
	// Wraps arbitrary ImGui code as an IWidget so raw controls
	// (checkboxes, sliders, etc.) can live inside a widget list.
	class CFunctionWidget : public IWidget
	{
	public:
		explicit CFunctionWidget( std::function<void()> fnRender )
			: m_fnRender( std::move( fnRender ) )
		{
		}

		auto OnRenderImGui() -> void override
		{
			if ( m_fnRender )
				m_fnRender();
		}

	private:
		std::function<void()> m_fnRender;
	};
}