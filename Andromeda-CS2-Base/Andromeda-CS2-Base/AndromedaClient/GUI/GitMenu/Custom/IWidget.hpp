#pragma once

#include <Common/Common.hpp>

namespace GitMenu
{
	class IWidget
	{
	public:
		virtual ~IWidget() = default;
		virtual auto OnRenderImGui() -> void = 0;
	};
}
