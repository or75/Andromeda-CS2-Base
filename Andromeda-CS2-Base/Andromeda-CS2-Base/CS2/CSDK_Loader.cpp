#include "CSDK_Loader.hpp"

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/IEngineToClient.hpp>
#include <CS2/SDK/Interface/CGameEntitySystem.hpp>
#include <CS2/SDK/Interface/CShemaSystemSDK.hpp>
#include <CS2/SDK/Interface/CSource2Client.hpp>

#include <CS2/SDK/CSchemaOffset.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>
#include <CS2/SDK/Econ/CEconItemSystem.hpp>
#include <CS2/SDK/Econ/CEconItemSchema.hpp>
#include <CS2/SDK/Cstrike15/CCSInventoryManager.hpp>
#include <CS2/SDK/Cstrike15/CCSPlayerInventory.hpp>

#include <Common/Helpers/ModuleLoaderHelper.hpp>

#define RETURN_FALSE_IF_INTERFACE_ERROR(Interface)\
if ( !Interface )\
{\
	DEV_LOG( "[error] Interface::%s\n" , #Interface );\
	return false;\
}

static CSDK_Loader g_SDK_Loader{};

auto CSDK_Loader::LoadSDK() -> bool
{
	// Wait for module load:
	if ( !IsModuleLoad( NAVSYSTEM_DLL ) )
		return false;

	// Log SDK:
#if LOG_SDK == 1
	DEV_LOG( "[+] CSDK_Loader::LoadSDK:\n\n" );
#endif

	// Interfaces:
	auto pEngineToClient = SDK::Interfaces::EngineToClient();
	auto pGameEntitySystem = SDK::Interfaces::GameEntitySystem();
	auto pSchemaSystem = SDK::Interfaces::SchemaSystem();
	auto pSource2Client = SDK::Interfaces::Source2Client();
	auto pLocalize = SDK::Interfaces::Localize();
	auto pBaseFileSystem = SDK::Interfaces::BaseFileSystem();

	// Return if error #1
	RETURN_FALSE_IF_INTERFACE_ERROR( pEngineToClient );
	RETURN_FALSE_IF_INTERFACE_ERROR( pGameEntitySystem );
	RETURN_FALSE_IF_INTERFACE_ERROR( pSchemaSystem );
	RETURN_FALSE_IF_INTERFACE_ERROR( pSource2Client );
	RETURN_FALSE_IF_INTERFACE_ERROR( pLocalize );
	RETURN_FALSE_IF_INTERFACE_ERROR( pBaseFileSystem );

	// Log:
#if LOG_SDK == 1
	DEV_LOG( "\n" );
#endif

	// Log:
#if LOG_SDK == 1
	DEV_LOG( "[+] pEngineToClient: %p\n" , pEngineToClient );
	DEV_LOG( "[+] pGameEntitySystem: %p\n" , pGameEntitySystem );
	DEV_LOG( "[+] pSchemaSystem: %p\n" , pSchemaSystem );
	DEV_LOG( "[+] pSource2Client: %p\n" , pSource2Client );
	DEV_LOG( "[+] pLocalize: %p\n" , pLocalize );
	DEV_LOG( "[+] pBaseFileSystem: %p\n" , pBaseFileSystem );
#endif

#if LOG_SDK == 1
	DEV_LOG( "\n" );

	DEV_LOG( "CCSInventoryManager::Get: %p\n" , CCSInventoryManager::Get() );
	DEV_LOG( "CCSPlayerInventory::Get: %p\n" , CCSPlayerInventory::Get() );
	DEV_LOG( "CSource2Client::GetEconItemSchema: %p\n" , pSource2Client->GetEconItemSystem()->GetEconItemSchema() );

	DEV_LOG( "GetSortedItemDefinitionMap: %p\n" , &pSource2Client->GetEconItemSystem()->GetEconItemSchema()->GetSortedItemDefinitionMap() );
	DEV_LOG( "GetPaintKits: %p\n" , &pSource2Client->GetEconItemSystem()->GetEconItemSchema()->GetPaintKits() );
	DEV_LOG( "GetMusicKitDefinitions: %p\n" , &pSource2Client->GetEconItemSystem()->GetEconItemSchema()->GetMusicKitDefinitions() );

	DEV_LOG( "\n" );
#endif

	GetSchemaOffset()->Init();

	return true;
}

auto GetSDK_Loader() -> CSDK_Loader*
{
	return &g_SDK_Loader;
}
