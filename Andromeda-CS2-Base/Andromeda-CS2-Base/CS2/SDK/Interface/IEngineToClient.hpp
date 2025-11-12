#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/CBasePattern.hpp>

#define IVENGINE_TO_CLIENT_INTERFACE_VERSION "Source2EngineToClient001"

namespace IVEngineToClient_Search
{
	inline CBasePattern IsInGameFn = { VmpStr( "IVEngineToClient::IsInGame" ) , VmpStr( "48 8B ? ? ? ? ? 48 85 C0 74 15 80 B8 ? ? ? ? ? 75 0C 83 B8 ? ? ? ? 06" ) , ENGINE2_DLL };
	inline CBasePattern GetLevelNameFn = { VmpStr( "IVEngineToClient::GetLevelName" ) , VmpStr( "48 83 EC 28 E8 ? ? ? ? 84 C0 74 0C 48 8D ? ? ? ? ? 48 83 C4 28 C3 48 8B ? ? ? ? ? 48 85 C9 74 23 83 B9 20 02 00 00 02 7C 1A 48 8B 89 00 02 00 00 48 8D ? ? ? ? ? 48 85 C9 48 0F 45 C1 48 83 C4 28 C3 48 8D ? ? ? ? ? 48 83 C4 28 C3" ) , ENGINE2_DLL };
	inline CBasePattern GetLevelNameShortFn = { VmpStr( "IVEngineToClient::GetLevelNameShort" ) , VmpStr( "48 83 EC 28 E8 ? ? ? ? 84 C0 74 0C 48 8D ? ? ? ? ? 48 83 C4 28 C3 48 8B ? ? ? ? ? 48 85 C9 74 23 83 B9 20 02 00 00 02 7C 1A 48 8B 89 08 02 00 00 48 8D ? ? ? ? ? 48 85 C9 48 0F 45 C1 48 83 C4 28 C3 48 8D ? ? ? ? ? 48 83 C4 28 C3" ) , ENGINE2_DLL };
}

class IVEngineToClient
{
public:
	DECLARATE_CS2_FUNCTION( bool , IsInGame , ( ) , IVEngineToClient , ( IVEngineToClient* ) , ( this ) );
	// Index -> "62"
	DECLARATE_CS2_FUNCTION( const char* , GetLevelName , ( ) , IVEngineToClient , ( IVEngineToClient* ) , ( this ) );
	// Index -> "63"
	DECLARATE_CS2_FUNCTION( const char* , GetLevelNameShort , ( ) , IVEngineToClient , ( IVEngineToClient* ) , ( this ) );

public:
	auto GetScreenSize( int& width , int& height ) -> void
	{
		VirtualFn( void )( IVEngineToClient* , int& , int& );
		return vget< Fn >( this , 59 )( this , width , height );
	}
};
