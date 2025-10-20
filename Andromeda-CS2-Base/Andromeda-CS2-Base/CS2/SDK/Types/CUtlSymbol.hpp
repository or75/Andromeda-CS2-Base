#pragma once

typedef unsigned short UtlSymId_t;

#define UTL_INVAL_SYMBOL  ((UtlSymId_t)~0)

class CUtlSymbol
{
public:
	// constructor, destructor
	CUtlSymbol() : m_Id( UTL_INVAL_SYMBOL ) {}
	CUtlSymbol( UtlSymId_t id ) : m_Id( id ) {}
	CUtlSymbol( CUtlSymbol const& sym ) : m_Id( sym.m_Id ) {}

	// operator=
	CUtlSymbol& operator=( CUtlSymbol const& src ) { m_Id = src.m_Id; return *this; }

	// operator==
	bool operator==( CUtlSymbol const& src ) const { return m_Id == src.m_Id; }

	// Is valid?
	bool IsValid() const { return m_Id != UTL_INVAL_SYMBOL; }

	// Gets at the symbol
	operator UtlSymId_t const( ) const { return m_Id; }

	UtlSymId_t GetID() const { return m_Id; }

protected:
	UtlSymId_t m_Id;
};
