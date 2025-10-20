#pragma once

#include <Common/Common.hpp>

class CCSPlayerController;

class IGameEvent
{
public:
	auto GetName() -> const char*;
	auto GetInt64( const std::string_view Name ) -> int64_t;
	auto GetPlayerController( const std::string_view Name ) -> CCSPlayerController*;
	auto GetString( const std::string_view Name ) -> const char*;
	auto SetString( const std::string_view Name, const std::string_view Value ) -> const char*;
};
