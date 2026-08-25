#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <string>
#include <vector>

struct ManualMapParam_t
{
	uint64_t ArgsSize = 0;
	char DllPath[MAX_PATH] = { 0 };
};

struct ModuleInfo_t
{
private:
	PAD( 0xC );
public:
	uint32_t CRC32;
	uint32_t ImageSize;
	uint32_t EntryPoint;
	uint32_t TimeStamp;
private:
	PAD( 0x4 );
public:
	uint64_t ImageBase;
	char filename[260];
};

class CachedModule
{
public:
	HANDLE m_ModuleHandle = nullptr;
	uint32_t m_nCRC32 = 0;
};

auto Hook_AnalizePeModule( HANDLE ModuleHandle , ModuleInfo_t* pModuleInfo_t , bool CalculateHash ) -> bool;

using AnalizePeModule_t = decltype( &Hook_AnalizePeModule );
inline AnalizePeModule_t AnalizePeModule_o = nullptr;

class CDllLauncher final
{
	using vecCachedModules = std::vector<CachedModule>;

public:
	auto OnDllMain( LPVOID lpReserved , HINSTANCE hInstace ) -> void;
	auto OnDestroy() -> void;

public:
	inline auto GetDllImage() -> HINSTANCE
	{
		return m_hDllImage;
	}

public:
	inline auto GetSizeOfImage() -> DWORD
	{
		return m_SizeofImage;
	}

	inline auto GetBaseOfCode() -> DWORD
	{
		return m_BaseOfCode;
	}

	inline auto GetCachedModules() -> vecCachedModules&
	{
		return m_CachedModules;
	}

public:
	inline auto IsCheatAddress( void* pAddress )
	{
		auto StartCheatAddress = reinterpret_cast<uint64_t>( m_hDllImage );
		auto EndCheatAddress = reinterpret_cast<uint64_t>( reinterpret_cast<PBYTE>( m_hDllImage ) + GetSizeOfImage() );
		auto AddressCheck = reinterpret_cast<uint64_t>( pAddress );

		if ( AddressCheck >= StartCheatAddress && AddressCheck <= EndCheatAddress )
			return true;

		return false;
	}

private:
	inline auto GetSizeOfImageInternal() -> DWORD
	{
		const auto pDosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>( m_hDllImage );
		const auto pNtHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>( (BYTE*)pDosHeader + pDosHeader->e_lfanew );

		return pNtHeaders->OptionalHeader.SizeOfImage;
	}

	inline auto GetBaseOfCodeInternal() -> DWORD
	{
		const auto pDosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>( m_hDllImage );
		const auto pNtHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>( (BYTE*)pDosHeader + pDosHeader->e_lfanew );

		return pNtHeaders->OptionalHeader.BaseOfCode;
	}

public:
	static auto WINAPI StartCheatTheard( LPVOID lpThreadParameter )->DWORD;

private:
	friend auto GetDllDir()->std::string&;
	friend auto GetCS2Dir()->std::string;

private:
	std::string m_DllDir;
	std::string m_CS2Dir;

private:
	HINSTANCE m_hDllImage = nullptr;

private:
	DWORD m_SizeofImage = 0;
	DWORD m_BaseOfCode = 0;

private:
	bool m_bDestroyed = false;

private:
	vecCachedModules m_CachedModules;
};

auto GetDllDir() -> std::string&;
auto GetCS2Dir() -> std::string;
auto GetDllLauncher() -> CDllLauncher*;
