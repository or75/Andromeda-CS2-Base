#pragma once

#include "CUtlMemory.hpp"

template< class T , class A = CUtlMemory<T> >
class CUtlVector
{
	typedef A CAllocator;
public:
	typedef T* iterator;
	typedef const T* const_iterator;

public:
	T& operator[]( int i )
	{
		return m_Memory[i];
	}

	const T& operator[]( int i ) const
	{
		return m_Memory[i];
	}

	T& Element( int i )
	{
		return m_Memory[i];
	}

	T* Base() { return m_Memory.Base(); }
	const T* Base() const { return m_Memory.Base(); }

	iterator begin() { return Base(); }
	const_iterator begin() const { return Base(); }
	iterator end() { return Base() + Count(); }
	const_iterator end() const { return Base() + Count(); }

	int Count() const
	{
		return m_Size;
	}

	inline bool IsEmpty( void ) const
	{
		return ( Count() == 0 );
	}

	inline bool IsValidIndex( int i ) const
	{
		return ( i >= 0 ) && ( i < m_Size );
	}

	static int InvalidIndex() { return -1; }

	inline bool Exists( T val ) const
	{
		for ( const auto& it : *this )
			if ( it == val ) return true;

		return false;
	}

	void RemoveAll()
	{
		if ( Count() )
		{
			for ( int i = m_Size; --i >= 0; )
				Destruct( &Element( i ) );

			m_Size = 0;
		}
	}

	int AddToTail()
	{
		return InsertBefore( m_Size );
	}

	int InsertBefore( int elem )
	{
		GrowVector();
		ShiftElementsRight( elem );
		Construct( &Element( elem ) );

		return elem;
	}

	void Purge()
	{
		RemoveAll();
		m_Memory.Purge();
	}

	void PurgeAndDeleteElements()
	{
		for ( int i = 0; i < m_Size; i++ )
			delete Element( i );

		Purge();
	}

protected:
	void GrowVector( int num = 1 )
	{
		if ( m_Size + num > m_Memory.NumAllocated() )
			m_Memory.Grow( m_Size + num - m_Memory.NumAllocated() );

		m_Size += num;
	}

	void ShiftElementsRight( int elem , int num = 1 )
	{
		int numToMove = m_Size - elem - num;

		if ( ( numToMove > 0 ) && ( num > 0 ) )
			memmove( &Element( elem + num ) , &Element( elem ) , numToMove * sizeof( T ) );
	}

	int m_Size;
	int m_DbgInfo;
	CAllocator m_Memory;
};

template< class T , size_t MAX_SIZE >
class CUtlVectorFixedGrowable : public CUtlVector< T , CUtlMemoryFixedGrowable<T , MAX_SIZE > >
{
	typedef CUtlVector< T , CUtlMemoryFixedGrowable<T , MAX_SIZE > > BaseClass;

public:
	// constructor, destructor
	explicit CUtlVectorFixedGrowable( int growSize = 0 ) : BaseClass( growSize , MAX_SIZE ) {}
};

#pragma pack(push, 1)
template< class T = void >
class CUtlVectorFixed
{
public:
	std::int32_t size; //0x0000 
private:
	char pad_0x0004[0x4]; //0x0004
public:
	T* m_pMemory; //0x0008 
private:
	char pad_0x0010[0x8]; //0x0010
public:
	CUtlVectorFixed()
	{
		size = 0;
		m_pMemory = nullptr;
	}

	T* begin() const
	{
		return m_pMemory;
	}

	T* end() const
	{
		return m_pMemory + size;
	}

	T operator []( int i ) const
	{
		return m_pMemory == nullptr ? T() : m_pMemory[i];
	}

	void purge()
	{
		if ( m_pMemory )
		{
			static const auto g_pMemAlloc = *reinterpret_cast<std::uintptr_t**>( GetProcAddress( GetModuleHandleA( "tier0.dll" ) , "g_pMemAlloc" ) );
			// free memory
			( *( __int64( __fastcall** )( std::uintptr_t* , T* ) )( *g_pMemAlloc + 40i64 ) )( g_pMemAlloc , m_pMemory );
			m_pMemory = nullptr;
		}
	}
}; //Size=0x0018
#pragma pack(pop)
