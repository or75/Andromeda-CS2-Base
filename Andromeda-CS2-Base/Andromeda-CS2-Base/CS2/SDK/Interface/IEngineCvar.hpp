#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/CBasePattern.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Types/Color.hpp>

#include <CS2/SDK/Math/Vector2.hpp>
#include <CS2/SDK/Math/Vector3.hpp>
#include <CS2/SDK/Math/Vector4.hpp>
#include <CS2/SDK/Math/QAngle.hpp>

#define ENGINE_CVAR_INTERFACE_VERSION "VEngineCvar007"

// command to convars and concommands
enum EConVarFlag : int
{
	// convar systems
	FCVAR_NONE = 0 ,
	FCVAR_UNREGISTERED = ( 1 << 0 ) ,	// if this is set, don't add to linked list, etc
	FCVAR_DEVELOPMENTONLY = ( 1 << 1 ) ,	// hidden in released products. flag is removed automatically if allow_development_cvars is defined
	FCVAR_GAMEDLL = ( 1 << 2 ) ,	// defined by the game dll
	FCVAR_CLIENTDLL = ( 1 << 3 ) ,	// defined by the client dll
	FCVAR_HIDDEN = ( 1 << 4 ) ,	// hidden. doesn't appear in find or autocomplete. like developmentonly, but can't be compiled out

	// convar only
	FCVAR_PROTECTED = ( 1 << 5 ) ,	// it's a server cvar, but we don't send the data since it's a password, etc. sends 1 if it's not bland/zero, 0 otherwise as value
	FCVAR_SPONLY = ( 1 << 6 ) ,	// this cvar cannot be changed by clients connected to a multiplayer server
	FCVAR_ARCHIVE = ( 1 << 7 ) ,	// set to cause it to be saved to vars.rc
	FCVAR_NOTIFY = ( 1 << 8 ) ,	// notifies players when changed
	FCVAR_USERINFO = ( 1 << 9 ) ,	// changes the client's info string
	FCVAR_CHEAT = ( 1 << 14 ) ,	// only useable in singleplayer/debug/multiplayer & sv_cheats
	FCVAR_PRINTABLEONLY = ( 1 << 10 ) ,	// this cvar's string cannot contain unprintable characters (e.g., used for player name etc)
	FCVAR_UNLOGGED = ( 1 << 11 ) ,	// if this is a fcvar_server, don't log changes to the log file / console if we are creating a log
	FCVAR_NEVER_AS_STRING = ( 1 << 12 ) ,	// never try to print that cvar

	// it's a convar that's shared between the client and the server.
	// at signon, the values of all such convars are sent from the server to the client (skipped for local client, ofc)
	// if a change is requested it must come from the console (i.e., no remote client changes)
	// if a value is changed while a server is active, it's replicated to all connected clients
	FCVAR_REPLICATED = ( 1 << 13 ) ,	// server setting enforced on clients, replicated
	// @todo: (1 << 14) used by the game, probably used as modification detection
	FCVAR_DEMO = ( 1 << 16 ) ,	// record this cvar when starting a demo file
	FCVAR_DONTRECORD = ( 1 << 17 ) ,	// don't record these command in demofiles
	FCVAR_RELOAD_MATERIALS = ( 1 << 20 ) ,	// if this cvar changes, it forces a material reload
	FCVAR_RELOAD_TEXTURES = ( 1 << 21 ) ,	// if this cvar changes, if forces a texture reload
	FCVAR_NOT_CONNECTED = ( 1 << 22 ) ,	// cvar cannot be changed by a client that is connected to a server
	FCVAR_MATERIAL_SYSTEM_THREAD = ( 1 << 23 ) ,	// indicates this cvar is read from the material system thread
	FCVAR_ARCHIVE_XBOX = ( 1 << 24 ) ,	// cvar written to config.cfg on the xbox
	FCVAR_ACCESSIBLE_FROM_THREADS = ( 1 << 25 ) ,	// used as a debugging tool necessary to check material system thread convars
	FCVAR_SERVER_CAN_EXECUTE = ( 1 << 28 ) ,	// the server is allowed to execute this command on clients via clientcommand/net_stringcmd/cbaseclientstate::processstringcmd
	FCVAR_SERVER_CANNOT_QUERY = ( 1 << 29 ) ,	// if this is set, then the server is not allowed to query this cvar's value (via iserverpluginhelpers::startquerycvarvalue)
	FCVAR_CLIENTCMD_CAN_EXECUTE = ( 1 << 30 ) ,	// ivengineclient::clientcmd is allowed to execute this command
	FCVAR_MATERIAL_THREAD_MASK = ( FCVAR_RELOAD_MATERIALS | FCVAR_RELOAD_TEXTURES | FCVAR_MATERIAL_SYSTEM_THREAD )
};

enum EConVarType : short
{
	EConVarType_Invalid = -1 ,
	EConVarType_Bool ,
	EConVarType_Int16 ,
	EConVarType_UInt16 ,
	EConVarType_Int32 ,
	EConVarType_UInt32 ,
	EConVarType_Int64 ,
	EConVarType_UInt64 ,
	EConVarType_Float32 ,
	EConVarType_Float64 ,
	EConVarType_String ,
	EConVarType_Color ,
	EConVarType_Vector2 ,
	EConVarType_Vector3 ,
	EConVarType_Vector4 ,
	EConVarType_Qangle ,
	EConVarType_MAX
};

#pragma endregion

union CVValue_t
{
	bool i1;
	short i16;
	uint16_t u16;
	int i32;
	uint32_t u32;
	int64_t i64;
	uint64_t u64;
	float fl;
	double db;
	const char* sz;
	Color clr;
	Vector2 vec2;
	Vector3 vec3;
	Vector4 vec4;
	QAngle ang;
};

class CConVar
{
public:
	const char* szName; // 0x0000
	CVValue_t* m_pDefaultValue; // 0x0008
	PAD( 0x10 ); // 0x0010
	const char* szDescription; // 0x0020
	uint32_t nType; // 0x28
	uint32_t nRegistered; // 0x2C
	uint32_t nFlags; // 0x30
	PAD( 0x1C ); // 0x34
	CVValue_t value; // 0x50
};

namespace IEngineCVar_Search
{
	inline CBasePattern GetFirstCvarIteratorFn = { VmpStr( "IEngineCVar::GetFirstCvarIterator" ) , VmpStr( "48 89 74 24 10 57 48 83 EC 30 0F B7 41 50 48 8B F1 B9 FF FF 00 00" ) , TIER0_DLL };
	inline CBasePattern GetNextCvarIteratorFn = { VmpStr( "IEngineCVar::GetNextCvarIterator" ) , VmpStr( "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 30 BD FF FF 00 00 49 8B D8 4C 8B F2 48 8B F1 66 44 3B C5 74 5B 41 BF FF 7F 00 00 66 44 85 7E 42" ) , TIER0_DLL };
	inline CBasePattern FindVarByIndexFn = { VmpStr( "IEngineCVar::FindVarByIndex" ) , VmpStr( "B8 FF FF 00 00 66 3B D0 74 27 B8 FF 7F 00 00 66 85 41 42 75 0D 33 C9 0F B7 C2 48 03 C0 48 8B 04 C1 C3" ) , TIER0_DLL };
}

class IEngineCVar
{
public:
	DECLARATE_CS2_FUNCTION( void , GetFirstCvarIterator , ( uint64_t& idx ) , IEngineCVar , ( IEngineCVar* , uint64_t& ) , ( this , idx ) );
	DECLARATE_CS2_FUNCTION( void , GetNextCvarIterator , ( uint64_t& idx ) , IEngineCVar , ( IEngineCVar* , uint64_t* , uint64_t ) , ( this , &idx , idx ) );
	DECLARATE_CS2_FUNCTION( CConVar* , FindVarByIndex , ( uint64_t idx ) , IEngineCVar , ( IEngineCVar* , uint64_t ) , ( this , idx ) );
	
public:
	auto Find( const char* pszName ) -> CConVar*
	{
		uint64_t i = 0;
		GetFirstCvarIterator( i );

		while ( i != 0xFFFFFFFF )
		{
			auto* pConVar = FindVarByIndex( i );

			if ( pConVar && strcmp( pConVar->szName , pszName ) == 0 )
				return pConVar;

			GetNextCvarIterator( i );
		}

		return nullptr;
	}

	void UnlockHiddenCVars()
	{
		uint64_t i = 0;
		GetFirstCvarIterator( i );

		while ( i != 0xFFFFFFFF )
		{
			auto* pConVar = FindVarByIndex( i );

			if ( pConVar )
			{
				if ( pConVar->nFlags & FCVAR_HIDDEN )
				{
					pConVar->nFlags &= ~FCVAR_HIDDEN;

					//DEV_LOG( "Unlocked ConVar FCVAR_HIDDEN: %s\n" , pConVar->szName );
				}
			}

			GetNextCvarIterator( i );
		}
	}
};
