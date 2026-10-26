#pragma once

#include <Common/Common.hpp>

class CGitMenu final
{
public:
	auto Init() -> void;
	auto Shutdown() -> void;
	auto ShowGitMenu( bool* bOpen = nullptr ) -> void;

private:
	bool m_bInitialized = false;
};

auto GetGitMenu() -> CGitMenu*;
