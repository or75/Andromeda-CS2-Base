#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/CBasePattern.hpp>

#define LOCALIZE_INTERFACE_VERSION "Localize_001"

namespace CLocalize_Search
{
	// string -> ds:[0000018CC7750E78]:"CLocalize::FindSafe"
	inline CBasePattern FindSafeFn = { VmpStr( "CLocalize::FindSafe" ) , VmpStr( "40 56 57 48 83 EC ? 48 8B F2 48 8B F9 48 85 D2 0F 84 ? ? ? ? 0F B6 02" ) , LOCALIZE_DLL };
}

class CLocalize
{
public:
	// Index -> "17"
	DECLARATE_CS2_FUNCTION( const char* , FindSafe , ( const char* TokenName ) , CLocalize , ( CLocalize* , const char* ) , ( this , TokenName ) );
};
