#pragma once

#include "PageWithSubPages.hpp"

namespace GitMenu
{
	class CHomePage final : public PageWithSubPages
	{
	public:
		CHomePage();

		auto GetName() const -> const char* override { return "Home##Home"; }
		auto GetDisplayName() const -> const char* override { return "Home"; }
		auto GetIcon() const -> ImTextureRef override;
	};
}
