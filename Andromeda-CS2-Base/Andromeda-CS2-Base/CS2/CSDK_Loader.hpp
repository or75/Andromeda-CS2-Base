#pragma once

#include <Common/Common.hpp>

class CSDK_Loader final
{
public:
	auto LoadSDK() -> bool;
};

auto GetSDK_Loader() -> CSDK_Loader*;
