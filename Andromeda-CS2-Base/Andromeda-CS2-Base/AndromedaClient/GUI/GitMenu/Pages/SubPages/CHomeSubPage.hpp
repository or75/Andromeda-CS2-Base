#pragma once

#include "../ISubPage.hpp"

namespace GitMenu
{
	class CHomeSubPage final : public ISubPage
	{
	public:
		auto GetDisplayName() const -> const char* override { return "Home"; }
		auto GetIcon() const -> ImTextureRef override;
		auto OnRender() -> void override;
	};
}
