#pragma once

#include <Common/Common.hpp>

class CAndromedaMenu final
{
public:
	auto OnRenderMenu() -> void;
};

auto GetAndromedaMenu() -> CAndromedaMenu*;
