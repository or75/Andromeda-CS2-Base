#pragma once

#include "PageWithSubPages.hpp"

namespace GitMenu
{
	class CHomeSubPage final : public ISubPage
	{
	public:
		auto GetDisplayName() const -> const char* override { return "Home"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf015"; }

	public:
		auto OnRender() -> void override;
	};

	class CHomePage final : public PageWithSubPages
	{
	public:
		CHomePage()
		{
			AddSubPage( "home" , std::make_unique<CHomeSubPage>() );
		}

	public:
		auto GetName() const -> const char* override { return "Home##Home"; }
		auto GetDisplayName() const -> const char* override { return "Home"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf015"; }
	};
}
