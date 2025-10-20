#pragma once

#include <Common/Common.hpp>

class CEconItemSchema;

class CEconItemSystem
{
public:
	auto GetEconItemSchema() -> CEconItemSchema*;
};
