#pragma once

#include <cstdint>
#include <CS2/SDK/Types/CBaseTypes.hpp>

namespace GCSDK
{
	struct SOID_t
	{
		SOID_t()
			: m_type( 0 )
			, m_id( 0 )
			, m_padding( 0 )
		{
		}

		SOID_t( std::uint32_t type , std::uint64_t id )
			: m_type( type )
			, m_id( id )
			, m_padding( 0 )
		{
		}

		//initializes the soid fields
		void Init( std::uint32_t type , std::uint64_t id )
		{
			m_type = type;
			m_id = id;
		}

		uint64 ID() const
		{
			return m_id;
		}

		uint32 Type() const
		{
			return m_type;
		}

		bool IsValid()
		{
			return m_type != 0;
		}

		bool operator==( const SOID_t& rhs ) const
		{
			return m_type == rhs.m_type && m_id == rhs.m_id;
		}

		bool operator!=( const SOID_t& rhs ) const
		{
			return m_type != rhs.m_type || m_id != rhs.m_id;
		}

		bool operator<( const SOID_t& rhs ) const
		{
			if ( m_type == rhs.m_type )
			{
				return m_id < rhs.m_id;
			}
			return m_type < rhs.m_type;
		}

		std::uint64_t m_id;
		std::uint32_t m_type;
		std::uint32_t m_padding;
	};
}
