#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/Types/CUtlVector.hpp>

class CSharedObject;

class CGCClientSharedObjectTypeCache
{
	constexpr static auto Idx_AddObject = 1;
	constexpr static auto Idx_RemoveObject = 3;

public:
	auto AddObject( CSharedObject* pObject ) -> bool;
	auto RemoveObject( CSharedObject* pObject ) -> bool;

public:
	template <typename T>
	auto& GetVecObjects()
	{
		return CUSTOM_OFFSET( CUtlVector<T> , 0x8 );
	}
};
