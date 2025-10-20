#include "CGCClientSharedObjectTypeCache.hpp"

#include <Common/MemoryEngine.hpp>

auto CGCClientSharedObjectTypeCache::AddObject( CSharedObject* pObject ) -> bool
{
	VirtualFn( bool )( CGCClientSharedObjectTypeCache* , CSharedObject* );

	return vget< Fn >( this , Idx_AddObject )( this , pObject );
}

auto CGCClientSharedObjectTypeCache::RemoveObject( CSharedObject* pObject ) -> bool
{
	VirtualFn( bool )( CGCClientSharedObjectTypeCache* , CSharedObject* );

	return vget< Fn >( this , Idx_RemoveObject )( this , pObject );
}
