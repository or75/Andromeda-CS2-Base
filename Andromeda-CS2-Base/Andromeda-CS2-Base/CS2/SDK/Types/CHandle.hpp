#pragma once

#include <cstdint>

#define INVALID_EHANDLE_INDEX 0xFFFFFFFF
#define ENT_ENTRY_MASK 0x7fff

class C_BaseEntity;

class CHandle
{
private:
	auto GetBaseEntity() const -> C_BaseEntity*;

public:
	auto operator==( CHandle rhs ) const -> bool { return m_Index == rhs.m_Index; }

public:
	auto IsValid() const -> bool { return m_Index != INVALID_EHANDLE_INDEX; }
	auto GetEntryIndex() const -> int { return m_Index & ENT_ENTRY_MASK; }

public:
	template <typename T = C_BaseEntity>
	T* Get() const
	{
		return reinterpret_cast<T*>( GetBaseEntity() );
	}

	uint32_t m_Index;
};
