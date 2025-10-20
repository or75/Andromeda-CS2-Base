#pragma once

#include <Common/MemoryEngine.hpp>

class IMemAlloc
{
public:
	void* Alloc( std::size_t size )
	{
		return vget<void* ( __thiscall* )( IMemAlloc* , std::size_t )>( this , 1 )( this , size );
	}

	void* ReAlloc( const void* p , std::size_t size )
	{
		return vget<void* ( __thiscall* )( IMemAlloc* , const void* , std::size_t )>( this , 2 )( this , p , size );
	}

	void Free( const void* p )
	{
		return vget<void( __thiscall* )( IMemAlloc* , const void* )>( this , 3 )( this , p );
	}

	std::size_t GetSize( const void* p )
	{
		return vget<std::size_t( __thiscall* )( IMemAlloc* , const void* )>( this , 21 )( this , p );
	}
};

inline IMemAlloc* GetMemAlloc()
{
	static auto p_mem_alloc = *reinterpret_cast<IMemAlloc**>( GetProcAddress( GetModuleHandleA( "tier0.dll" ) , "g_pMemAlloc" ) );
	return p_mem_alloc;
}
