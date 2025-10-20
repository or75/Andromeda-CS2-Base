#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/CBasePattern.hpp>
#include <CS2/SDK/Math/Vector4.hpp>

#define MATERIAL_SYSTEM2_INTERFACE_VERSION "VMaterialSystem2_001"

namespace CMaterialSystem2_Search
{
    inline CBasePattern CreateMaterialFn = { VmpStr( "CMaterialSystem2::CreateMaterial" ) , VmpStr( "48 89 5C 24 08 48 89 6C 24 18 56 57 41 56 48 81 EC ? ? ? ?" ) , MATERIALSYSTEM2_DLL };
}

class CMaterial2
{
public:
    auto GetName() -> const char*
    {
		VirtualFn( const char* )( CMaterial2* );
		return vget< Fn >( this , 0 )( this );
    }
};

class CMaterialSystem2
{
public:
	// Index -> "29"
	DECLARATE_CS2_FUNCTION( CMaterial2** , CreateMaterial , ( CMaterial2*** pEmptyMaterial , const char* szNewMaterialName , void* pMaterialData ) , CMaterialSystem2 , ( CMaterialSystem2* , CMaterial2*** , const char* , void* , int , int , int , int , int , int ) , ( this , pEmptyMaterial , szNewMaterialName , pMaterialData , 0 , 1 , 0 , 0 , 0 , 1 ) );
};
