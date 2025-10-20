#pragma once

class CGCClientSharedObjectTypeCache;
class CSharedObject;

#include <CS2/SDK/GCSDK/GCSDKTypes/SOID_t.hpp>
#include <CS2/SDK/GCSDK/GCSDKTypes/ESOCacheEvent.hpp>

class ISharedObjectListener
{
public:

	/// Called when a new object is created in a cache we are currently subscribed to, or when we are added
	/// as a listener to a cache which already has objects in it
	///
	/// eEvent will be one of:
	/// - eSOCacheEvent_Subscribed
	/// - eSOCacheEvent_Resubscribed
	/// - eSOCacheEvent_Incremental
	/// - eSOCacheEvent_ListenerAdded
	virtual void SOCreated( GCSDK::SOID_t owner , const CSharedObject* pObject , GCSDK::ESOCacheEvent eEvent ) = 0;

	/// Called when an object is updated in a cache we are currently subscribed to.
	///
	/// eEvent will be one of:
	/// - eSOCacheEvent_Resubscribed
	/// - eSOCacheEvent_Incremental
	virtual void SOUpdated( GCSDK::SOID_t owner , const CSharedObject* pObject , GCSDK::ESOCacheEvent eEvent ) = 0;

	/// Called when an object is about to be deleted in a cache we are currently subscribed to.
	/// The object will have already been removed from the cache, but is still valid.
	///
	/// eEvent will be one of:
	/// - eSOCacheEvent_Incremental
	/// - eSOCacheEvent_Resubscribed
	virtual void SODestroyed( GCSDK::SOID_t owner , const CSharedObject* pObject , GCSDK::ESOCacheEvent eEvent ) = 0;
};

class CGCClientSharedObjectCache
{
public:
	auto CreateBaseTypeCache( int nClassID ) -> CGCClientSharedObjectTypeCache*;
	auto FindTypeCache( int nClassID ) -> CGCClientSharedObjectTypeCache*;
};
