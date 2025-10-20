#include "SDK.hpp"

#include <DllLauncher.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/Interface/Interface.hpp>

#include <CS2/SDK/Interface/IEngineToClient.hpp>
#include <CS2/SDK/Interface/CShemaSystemSDK.hpp>
#include <CS2/SDK/Interface/CSource2Client.hpp>
#include <CS2/SDK/Interface/CLocalize.hpp>
#include <CS2/SDK/Interface/CSoundOpSystem.hpp>
#include <CS2/SDK/Interface/IBaseFileSystem.hpp>
#include <CS2/SDK/Interface/CMaterialSystem2.hpp>
#include <CS2/SDK/Interface/IEngineCvar.hpp>
#include <CS2/SDK/Interface/CInputSystem.hpp>

#define INCLUDE_CS2_SEARCH_FUNCTION(Interface,FuncName)\
if ( !##Interface##_Search::##FuncName##Fn.Search() )\
	bIsReady = false;

namespace SDK
{
	IVEngineToClient* Interfaces::g_pEngineToClient = nullptr;
	CGameEntitySystem* Interfaces::g_pGameEntitySystem = nullptr;
	CSchemaSystem* Interfaces::g_pSchemaSystem = nullptr;
	CSource2Client* Interfaces::g_pSource2Client = nullptr;
	CLocalize* Interfaces::g_pLocalize = nullptr;
	CSoundOpSystem* Interfaces::g_pSoundOpSystem = nullptr;
	IBaseFileSystem* Interfaces::g_pBaseFileSystem = nullptr;
	CMaterialSystem2* Interfaces::g_pMaterialSystem2 = nullptr;
	IEngineCVar* Interfaces::g_pEngineCvar = nullptr;
	CInputSystem* Interfaces::g_pInputSystem = nullptr;

	CGlobalVarsBase** Pointers::g_ppCGlobalVarsBase = nullptr;
	IVPhysics2World** Pointers::g_ppIVPhysics2World = nullptr;
	CUserCmd** Pointers::g_ppCUserCmd = nullptr;

	IVEngineToClient* Interfaces::EngineToClient()
	{
		if ( !g_pEngineToClient )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( ENGINE2_DLL );
			g_pEngineToClient = CaptureInterface<IVEngineToClient>( pfnFactory , XorStr( IVENGINE_TO_CLIENT_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_CS2_SEARCH_FUNCTION( IVEngineToClient , IsInGame );
			INCLUDE_CS2_SEARCH_FUNCTION( IVEngineToClient , GetLevelName );
			INCLUDE_CS2_SEARCH_FUNCTION( IVEngineToClient , GetLevelNameShort );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pEngineToClient;
	}

	CGameEntitySystem* Interfaces::GameEntitySystem()
	{
		if ( !g_pGameEntitySystem )
		{
			/*
			00007FFBA0D9B6E | E8 817AEBFF              | call client.7FFBA0C53170                          | CGameEntitySystem->GetHighestEntityIndex
			00007FFBA0D9B6E | 8B08                     | mov ecx,dword ptr ds:[rax]                        |
			00007FFBA0D9B6F | FFC1                     | inc ecx                                           |
			00007FFBA0D9B6F | 85C9                     | test ecx,ecx                                      |
			00007FFBA0D9B6F | 0F8E FC000000            | jle client.7FFBA0D9B7F7                           |
			00007FFBA0D9B6F | 48:89BC24 40020000       | mov qword ptr ss:[rsp+0x240],rdi                  |
			00007FFBA0D9B70 | 0F1F40 00                | nop dword ptr ds:[rax],eax                        |
			00007FFBA0D9B70 | 66:0F1F8400 00000000     | nop word ptr ds:[rax+rax],ax                      |
			00007FFB90DBB71 | 48:8B0D 8968F500         | mov rcx,qword ptr ds:[0x7FFB91D11FA0]             | ppCGameEntitySystem
			00007FFB90DBB71 | 8BD3                     | mov edx,ebx                                       |
			00007FFB90DBB71 | E8 E22FECFF              | call client.7FFB90C7E700                          | CGameEntitySystem->GetBaseEntity
			00007FFB90DBB71 | 48:8BF8                  | mov rdi,rax                                       |
			00007FFB90DBB72 | 48:85C0                  | test rax,rax                                      |
			00007FFB90DBB72 | 74 76                    | je client.7FFB90DBB79C                            |
			00007FFB90DBB72 | C64424 30 00             | mov byte ptr ss:[rsp+0x30],0x0                    |
			00007FFB90DBB72 | 48:8BC8                  | mov rcx,rax                                       |
			00007FFB90DBB72 | 48:8B10                  | mov rdx,qword ptr ds:[rax]                        |
			00007FFB90DBB73 | FF92 20010000            | call qword ptr ds:[rdx+0x120]                     |
			00007FFB90DBB73 | 4C:8D05 6AAD9500         | lea r8,qword ptr ds:[0x7FFB917164A8]              | 00007FFB917164A8:"'%s'"
			00007FFB90DBB73 | BA 00010000              | mov edx,0x100                                     |
			00007FFB90DBB74 | 48:8D8C24 30010000       | lea rcx,qword ptr ss:[rsp+0x130]                  |
			00007FFB90DBB74 | 4C:8B48 08               | mov r9,qword ptr ds:[rax+0x8]                     |
			00007FFB90DBB74 | FF15 7B2A9100            | call qword ptr ds:[<V_snprintf>]                  |
			00007FFB90DBB75 | 48:8B47 10               | mov rax,qword ptr ds:[rdi+0x10]                   |
			00007FFB90DBB75 | 48:8D15 20199200         | lea rdx,qword ptr ds:[0x7FFB916DD080]             |
			00007FFB90DBB76 | 4C:8D8C24 30010000       | lea r9,qword ptr ss:[rsp+0x130]                   |
			00007FFB90DBB76 | 4C:8D4424 30             | lea r8,qword ptr ss:[rsp+0x30]                    |
			00007FFB90DBB76 | 48:8B48 18               | mov rcx,qword ptr ds:[rax+0x18]                   |
			00007FFB90DBB77 | 48:8D05 08199200         | lea rax,qword ptr ds:[0x7FFB916DD080]             |
			00007FFB90DBB77 | 48:85C9                  | test rcx,rcx                                      |
			00007FFB90DBB77 | 48:0F45D1                | cmovne rdx,rcx                                    |
			00007FFB90DBB77 | 48:8D0D 92E8A800         | lea rcx,qword ptr ds:[0x7FFB9184A018]             | 00007FFB9184A018:"Ent %3d: %s class %s name %s\n"
			*/

			auto ppGameEntitySystem = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B 0D ? ? ? ? 8B D3 E8 ? ? ? ? 48 8B F0" ) ) );

			if ( !ppGameEntitySystem )
				return nullptr;

GetGameEntitySystemPointer:;

			g_pGameEntitySystem = *GetPtrAddress<CGameEntitySystem**>( ppGameEntitySystem );

			if ( !g_pGameEntitySystem )
			{
				Sleep( 500 );
				goto GetGameEntitySystemPointer;
			}
		}

		return g_pGameEntitySystem;
	}

	CSchemaSystem* Interfaces::SchemaSystem()
	{
		if ( !g_pSchemaSystem )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( SCHEMASYSTEM_DLL );
			g_pSchemaSystem = CaptureInterface<CSchemaSystem>( pfnFactory , XorStr( SCHEMA_SYSTEM_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_CS2_SEARCH_FUNCTION( CSchemaSystem , GetAllTypeScope );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pSchemaSystem;
	}

	CSource2Client* Interfaces::Source2Client()
	{
		if ( !g_pSource2Client )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( CLIENT_DLL );
			g_pSource2Client = CaptureInterface<CSource2Client>( pfnFactory , XorStr( SOURCE2_CLIENT_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_CS2_SEARCH_FUNCTION( CSource2Client , GetEconItemSystem );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pSource2Client;
	}

	CLocalize* Interfaces::Localize()
	{
		if ( !g_pLocalize )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( LOCALIZE_DLL );
			g_pLocalize = CaptureInterface<CLocalize>( pfnFactory , XorStr( LOCALIZE_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_CS2_SEARCH_FUNCTION( CLocalize , FindSafe );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pLocalize;
	}

	CSoundOpSystem* Interfaces::SoundOpSystem()
	{
		if ( !g_pSoundOpSystem )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( SOUNDSYSTEM_DLL );
			g_pSoundOpSystem = CaptureInterface<CSoundOpSystem>( pfnFactory , XorStr( INTERFACE_SOUNDOPSYSTEM ) );
		}

		return g_pSoundOpSystem;
	}

	IBaseFileSystem* Interfaces::BaseFileSystem()
	{
		if ( !g_pBaseFileSystem )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( FILESYSTEM_STDIO_DLL );
			g_pBaseFileSystem = CaptureInterface<IBaseFileSystem>( pfnFactory , XorStr( FILE_SYSTEM_INTERFACE_VERSION ) );
		}

		return g_pBaseFileSystem;
	}

	CMaterialSystem2* Interfaces::MaterialSystem2()
	{
		if ( !g_pMaterialSystem2 )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( MATERIALSYSTEM2_DLL );
			g_pMaterialSystem2 = CaptureInterface<CMaterialSystem2>( pfnFactory , XorStr( MATERIAL_SYSTEM2_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_CS2_SEARCH_FUNCTION( CMaterialSystem2 , CreateMaterial );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pMaterialSystem2;
	}

	IEngineCVar* Interfaces::EngineCvar()
	{
		if ( !g_pEngineCvar )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( TIER0_DLL );
			g_pEngineCvar = CaptureInterface<IEngineCVar>( pfnFactory , XorStr( ENGINE_CVAR_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_CS2_SEARCH_FUNCTION( IEngineCVar , GetFirstCvarIterator );
			INCLUDE_CS2_SEARCH_FUNCTION( IEngineCVar , GetNextCvarIterator );
			INCLUDE_CS2_SEARCH_FUNCTION( IEngineCVar , FindVarByIndex );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pEngineCvar;
	}

	CInputSystem* Interfaces::InputSystem()
	{
		if ( !g_pInputSystem )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( INPUTSYSTEM_DLL );
			g_pInputSystem = CaptureInterface<CInputSystem>( pfnFactory , XorStr( INPUT_SYSTEM_INTERFACE_VERSION ) );
		}

		return g_pInputSystem;
	}

	auto Pointers::GlobalVarsBase() -> CGlobalVarsBase*
	{
		if ( !g_ppCGlobalVarsBase )
		{
			auto ppCGlobalVarsBase = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B ? ? ? ? ? 44 8B B7 08 01 00 00 8B 70 04 B8 FF FF 00 00 89 B7 08 01 00 00 66 01 87 FC 00 00 00" ) ) );

			if ( !ppCGlobalVarsBase )
				return nullptr;

			g_ppCGlobalVarsBase = GetPtrAddress<CGlobalVarsBase**>( ppCGlobalVarsBase );
		}

		return *g_ppCGlobalVarsBase;
	}

	auto Pointers::CVPhys2World() -> IVPhysics2World**
	{
		if ( !g_ppIVPhysics2World )
		{
			auto ppIVPhysics2World = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B 0D ? ? ? ? 48 8D 45 ? 48 89 44 24 ? 4C 8D 4C 24 ? 48 8D 45 ? 4C 8D 44 24 ? 48 89 44 24 ? 48 8D 95 ? ? ? ? E8 ? ? ? ? F2 0F 10 45" ) ) );

			if ( !ppIVPhysics2World )
				return nullptr;

			g_ppIVPhysics2World = *GetPtrAddress<IVPhysics2World***>( ppIVPhysics2World );
		}

		return g_ppIVPhysics2World;
	}

	// 48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8B CF 4C 8B F8
	/*
	00007FFC70ED89BC | mov rcx,qword ptr ds:[0x7FFC7228C710]                                 | CUserCmd**
	00007FFC70ED89C3 | call client.7FFC70CF0BD0                                              | GetCUserCmdArray
	00007FFC70ED89C8 | mov rcx,rdi                                                           |
	00007FFC70ED89CB | mov r15,rax                                                           |
	00007FFC70ED89CE | mov r14d,dword ptr ds:[rax+0x59A8]                                    | offset SequenceNumber
	00007FFC70ED89D5 | mov edx,r14d                                                          |
	00007FFC70ED89D8 | call client.7FFC70CF0960                                              | GetUserCmdBySequenceNumber
	*/
	auto Pointers::GetFirstCUserCmdArray() -> CUserCmd**
	{
		if ( !g_ppCUserCmd )
		{
			auto ppCUserCmd = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8B CF 4C 8B F8" ) ) );

			if ( !ppCUserCmd )
				return nullptr;

			g_ppCUserCmd = *GetPtrAddress<CUserCmd***>( ppCUserCmd );
		}

		return g_ppCUserCmd;
	}
}
