#pragma once

#include <Common/Common.hpp>

class IVEngineToClient;
class CInputStackSystem;
class CGameEntitySystem;
class CSchemaSystem;
class CSource2Client;
class CLocalize;
class CSoundOpSystem;
class IBaseFileSystem;
class CMaterialSystem2;
class CInputSystem;

class CGlobalVarsBase;
class IVPhysics2World;
class IEngineCVar;
class CUserCmd;

#define CLIENT_DLL				"client.dll"
#define ENGINE2_DLL				"engine2.dll"
#define INPUTSYSTEM_DLL			"inputsystem.dll"
#define NAVSYSTEM_DLL			"navsystem.dll"
#define GAMEOVERLAYRENDER64_DLL "gameoverlayrenderer64.dll"
#define SCHEMASYSTEM_DLL		"schemasystem.dll"
#define LOCALIZE_DLL			"localize.dll"
#define NETWORKSYSTEM_DLL		"networksystem.dll"
#define SOUNDSYSTEM_DLL			"soundsystem.dll"
#define FILESYSTEM_STDIO_DLL	"filesystem_stdio.dll"
#define SCENESYSTEM_DLL			"scenesystem.dll"
#define MATERIALSYSTEM2_DLL		"materialsystem2.dll"
#define PARTICLES_DLL			"particles.dll"
#define TIER0_DLL				"tier0.dll"
#define DXGI_DLL				"dxgi.dll"
#define ANIMATIONSYSTEM_DLL		"animationsystem.dll"
#define V8_DLL					"v8.dll"
#define PANORAMA_DLL			"panorama.dll"
#define WORLDRENDERER_DLL		"worldrenderer.dll"

namespace SDK
{
	class Interfaces
	{
	public:
		static IVEngineToClient* EngineToClient();
		static CGameEntitySystem* GameEntitySystem();
		static CSchemaSystem* SchemaSystem();
		static CSource2Client* Source2Client();
		static CLocalize* Localize();
		static CSoundOpSystem* SoundOpSystem();
		static IBaseFileSystem* BaseFileSystem();
		static CMaterialSystem2* MaterialSystem2();
		static IEngineCVar* EngineCvar();
		static CInputSystem* InputSystem();

	private:
		static IVEngineToClient* g_pEngineToClient;
		static CGameEntitySystem* g_pGameEntitySystem;
		static CSchemaSystem* g_pSchemaSystem;
		static CSource2Client* g_pSource2Client;
		static CLocalize* g_pLocalize;
		static CSoundOpSystem* g_pSoundOpSystem;
		static IBaseFileSystem* g_pBaseFileSystem;
		static CMaterialSystem2* g_pMaterialSystem2;
		static IEngineCVar* g_pEngineCvar;
		static CInputSystem* g_pInputSystem;
	};

	class Pointers
	{
	public:
		static auto GlobalVarsBase() -> CGlobalVarsBase*;
		static auto CVPhys2World() -> IVPhysics2World**;
		static auto GetFirstCUserCmdArray() -> CUserCmd**;

	private:
		static CGlobalVarsBase** g_ppCGlobalVarsBase;
		static IVPhysics2World** g_ppIVPhysics2World;
		static CUserCmd** g_ppCUserCmd;
	};
}
