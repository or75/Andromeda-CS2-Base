#pragma once

#include <Common/Common.hpp>

#include <CS2/CBasePattern.hpp>

#define SOURCE2_CLIENT_INTERFACE_VERSION "Source2Client002"

class CEconItemSystem;

namespace CSource2Client_Search
{
	inline CBasePattern GetEconItemSystemFn = { VmpStr( "CSource2Client::GetEconItemSystem" ) , VmpStr( "48 83 EC 28 48 8B 05 ? ? ? ? 48 85 C0 0F 85 81" ) , CLIENT_DLL };
}

class CSource2Client
{
public:
	DECLARATE_CS2_FUNCTION( CEconItemSystem* , GetEconItemSystem , ( ) , CSource2Client , ( CSource2Client* ) , ( this ) );
};
