#pragma once

#include <Common/Common.hpp>
#include <string>

struct ManualMapParam_t
{
	uint64_t ArgsSize = 0;
	DWORD64 DllLoaderCode = 0;
	char DllPath[MAX_PATH] = { 0 };
};

class CDllLauncher final
{
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
	friend auto GetCSGODir()->std::string;

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
};

auto GetDllDir() -> std::string&;
auto GetCSGODir() -> std::string;
auto GetDllLauncher() -> CDllLauncher*;
