#pragma once

#include "PageWithSubPages.hpp"

namespace GitMenu
{
	class CMenuGeneralSubPage final : public ISubPage
	{
	public:
		CMenuGeneralSubPage();

		auto GetDisplayName() const -> const char* override { return "General"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf1de"; }
	};

	class CMenuPage final : public PageWithSubPages
	{
	public:
		CMenuPage()
		{
			AddSubPage( "general" , std::make_unique<CMenuGeneralSubPage>() );
		}

		auto GetName() const -> const char* override { return "Menu##Menu"; }
		auto GetDisplayName() const -> const char* override { return "Menu"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf013"; }
	};
}
