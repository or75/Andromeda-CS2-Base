#include "CEntityCache.hpp"

static CEntityCache g_CEntityCache{};

void CEntityCache::OnAddEntity( CEntityInstance* pInst , CHandle handle )
{
	std::scoped_lock Lock( m_Lock );

	auto pBaseEntity = pInst->pEntityIdentity()->pBaseEntity();

	if ( pBaseEntity )
	{
		auto it = std::find_if( m_CachedEntity.begin() , m_CachedEntity.end() , [handle]( const CachedEntity_t& i )
		{
			return i.m_Handle == handle;
		} );

		if ( it == m_CachedEntity.end() )
		{
			CachedEntity_t CachedBoxEntity;

			CachedBoxEntity.m_Handle = handle;
			CachedBoxEntity.m_Type = GetEntityType( pBaseEntity );

			if ( CachedBoxEntity.m_Type != CachedEntity_t::UNKNOWN )
				m_CachedEntity.emplace_back( CachedBoxEntity );
		}
		else
		{
			it->m_Handle = handle;
			it->m_Type = GetEntityType( pBaseEntity );
		}
	}
}

void CEntityCache::OnRemoveEntity( CEntityInstance* pInst , CHandle handle )
{
	std::scoped_lock lock( m_Lock );

	auto it = std::find_if( m_CachedEntity.begin() , m_CachedEntity.end() , [handle]( const CachedEntity_t& i )
	{
		return i.m_Handle == handle;
	} );

	if ( it != m_CachedEntity.end() )
	{
		it->m_bDraw = false;
		it->m_Type = CachedEntity_t::UNKNOWN;

		auto NewEnd = std::remove_if( m_CachedEntity.begin() , m_CachedEntity.end() , []( const CachedEntity_t& i )
		{
			return i.m_Type == CachedEntity_t::UNKNOWN;
		} );

		m_CachedEntity.erase( NewEnd , m_CachedEntity.end() );
	}
}

auto CEntityCache::GetEntityType( C_BaseEntity* pBaseEntity ) -> CachedEntity_t::Type
{
	if ( pBaseEntity->IsBasePlayerController() )
		return CachedEntity_t::PLAYER_CONTROLLER;
	else if ( pBaseEntity->IsBasePlayerWeapon() )
		return CachedEntity_t::BASE_WEAPON;
	else if ( pBaseEntity->IsPlantedC4() )
		return CachedEntity_t::PLANTED_C4;
	else if ( pBaseEntity->IsGrenadeProjectile() )
		return CachedEntity_t::GRENADE_PROJECTILE;

	return CachedEntity_t::UNKNOWN;
}

auto GetEntityCache() -> CEntityCache*
{
	return &g_CEntityCache;
}
