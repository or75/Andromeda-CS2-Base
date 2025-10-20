#pragma once

#include "CBaseTypes.hpp"

#define UTL_INVAL_SYMBOL_LARGE 0

using UtlSymLargeId_t = intp;

class CUtlSymbolLarge
{
public:
	// constructor, destructor
	CUtlSymbolLarge()
	{
		u.m_Id = UTL_INVAL_SYMBOL_LARGE;
	}

	CUtlSymbolLarge( UtlSymLargeId_t id )
	{
		u.m_Id = id;
	}
	CUtlSymbolLarge( CUtlSymbolLarge const& sym )
	{
		u.m_Id = sym.u.m_Id;
	}

	// operator=
	CUtlSymbolLarge& operator=( CUtlSymbolLarge const& src )
	{
		u.m_Id = src.u.m_Id;
		return *this;
	}

	// operator==
	bool operator==( CUtlSymbolLarge const& src ) const
	{
		return u.m_Id == src.u.m_Id;
	}

	// operator==
	bool operator==( UtlSymLargeId_t const& src ) const
	{
		return u.m_Id == src;
	}

	// operator==
	bool operator!=( CUtlSymbolLarge const& src ) const
	{
		return u.m_Id != src.u.m_Id;
	}

	// operator==
	bool operator!=( UtlSymLargeId_t const& src ) const
	{
		return u.m_Id != src;
	}

	// Gets at the symbol
	operator UtlSymLargeId_t const( ) const
	{
		return u.m_Id;
	}

	// Gets the string associated with the symbol
	inline const char* String() const
	{
		if ( u.m_Id == UTL_INVAL_SYMBOL_LARGE || u.m_pAsString == nullptr )
			return "";

		return u.m_pAsString;
	}

	inline bool IsValid() const
	{
		return u.m_Id != UTL_INVAL_SYMBOL_LARGE ? true : false;
	}

private:
	// Disallowed
	CUtlSymbolLarge( const char* pStr );

	union
	{
		UtlSymLargeId_t m_Id;
		char const* m_pAsString = nullptr;
	} u;
};