#pragma once

#include "Common.hpp"

#include <Windows.h>
#include <stdint.h>

#define CONCAT_IMPL(x, y) x##y
#define CONCAT(x, y) CONCAT_IMPL(x, y)
#define PAD(size) private: [[maybe_unused]] std::byte CONCAT(pad, __COUNTER__)[size]{ }; public:

#define VirtualFn( cast ) using Fn = cast(__thiscall*)

#define CUSTOM_OFFSET( type , offset ) \
	*( type* )( (uintptr_t)this + offset );

#define CUSTOM_OFFSET_RAW( type , offset ) \
	( type* )( (uintptr_t)this + offset );

#define CUSTOM_OFFSET_FIELD( type , name , offset ) \
	inline type& name() { return *( type* )( (uintptr_t)this + offset ); }

auto FindPattern( const char* szPattern , uintptr_t StartAddr , uintptr_t EndAddr , uint32_t offset = 0 )->PVOID;
auto FindPattern( const char* szModuleName , const char* szPattern , uint32_t offset = 0 )->PVOID;

// Example: mov rcx, qword ptr ds:[0x00007FFB91D11FA0]
template<typename T = intptr_t>
inline auto GetPtrAddress( intptr_t Address ) -> T
{
	auto IntData = *(int32_t*)( Address + 3 );
	auto PtrData = Address + 7;

	return (T)( IntData + PtrData );
}

// Call,Jmp
inline auto GetCallAddress( intptr_t Address ) -> PVOID
{
	auto IntData = *(int32_t*)( Address + 1 );
	auto PtrData = Address + 5;

	return (PVOID)( IntData + PtrData );
}

template< typename T >
inline auto vget( PVOID instance , unsigned int index ) -> T
{
	auto procedure_array = *reinterpret_cast<PDWORD_PTR*>( instance );
	return (T)( procedure_array )[index];
}
