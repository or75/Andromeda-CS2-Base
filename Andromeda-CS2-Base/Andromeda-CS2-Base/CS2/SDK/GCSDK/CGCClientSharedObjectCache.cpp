#include "CGCClientSharedObjectCache.hpp"

#include <CS2/SDK/FunctionListSDK.hpp>

auto CGCClientSharedObjectCache::CreateBaseTypeCache( int nClassID ) -> CGCClientSharedObjectTypeCache*
{
	return CGCClientSharedObjectCache_CreateBaseTypeCache( this , nClassID );
}

auto CGCClientSharedObjectCache::FindTypeCache( int nClassID ) -> CGCClientSharedObjectTypeCache*
{
	return CGCClientSharedObjectCache_FindTypeCache( this , nClassID );
}
