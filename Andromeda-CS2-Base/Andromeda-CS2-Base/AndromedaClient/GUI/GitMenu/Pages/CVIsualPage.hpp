#pragma once

#include "PageWithSubPages.hpp"

namespace GitMenu
{
	class CVIsualGlobalSubPage final : public ISubPage
	{
	public:
		CVIsualGlobalSubPage();

	public:
		auto GetDisplayName() const -> const char* override { return "Global"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf0ac"; }

	public:
		auto OnRender() -> void override;
	};

	class CVIsualPage final : public PageWithSubPages
	{
	public:
		CVIsualPage()
		{
			AddSubPage( "global" , std::make_unique<CVIsualGlobalSubPage>() );
		}

	public:
		auto GetName() const -> const char* override { return "Visual##Visual"; }
		auto GetDisplayName() const -> const char* override { return "Visual"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf06e"; }
	};
}
