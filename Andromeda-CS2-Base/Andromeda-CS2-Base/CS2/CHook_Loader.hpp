#pragma once

#include <Common/Common.hpp>
#include <vector>

#include <CS2/CBasePattern.hpp>

struct HookData_t
{
	CBasePattern m_Pattern;
	LPVOID m_pDetour = nullptr;
	LPVOID* m_pOriginal = nullptr;
	bool m_bSkipIfNotFound = false;
	bool m_bSkipError = false;
};

class CHook_Loader final
{
public:
	auto InitalizeMH() -> bool;

public:
	auto InstallFirstHook() -> bool;
	auto InstallSecondHook() -> bool;

private:
	auto InstallHooks() -> bool;

public:
	auto DestroyHooks() -> void;

private:
	std::vector<HookData_t> m_Hooks = {};
};

auto GetHook_Loader() -> CHook_Loader*;
