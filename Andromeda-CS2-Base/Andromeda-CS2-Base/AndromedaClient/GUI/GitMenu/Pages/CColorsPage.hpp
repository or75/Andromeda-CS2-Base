#pragma once

#include "PageWithSubPages.hpp"

namespace GitMenu
{
	class CColorsVisualSubPage final : public ISubPage
	{
	public:
		CColorsVisualSubPage();

		auto GetDisplayName() const -> const char* override { return "Visual"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf06e"; }
	};

	class CColorsPage final : public PageWithSubPages
	{
	public:
		CColorsPage()
		{
			AddSubPage( "visual" , std::make_unique<CColorsVisualSubPage>() );
		}

		auto GetName() const -> const char* override { return "Colors##Colors"; }
		auto GetDisplayName() const -> const char* override { return "Colors"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf53f"; }
	};
}
