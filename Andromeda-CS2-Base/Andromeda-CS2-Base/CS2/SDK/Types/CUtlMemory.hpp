#pragma once

#include <cstdint>
#include <CS2/SDK/Types/TIer0Memory.hpp>

inline int UtlMemory_CalcNewAllocationCount( int nAllocationCount , int nGrowSize , int nNewSize , int nBytesItem )
{
	if ( nGrowSize )
		nAllocationCount = ( ( 1 + ( ( nNewSize - 1 ) / nGrowSize ) ) * nGrowSize );
	else
	{
		if ( !nAllocationCount )
			nAllocationCount = ( 31 + nBytesItem ) / nBytesItem;

		while ( nAllocationCount < nNewSize )
			nAllocationCount *= 2;
	}

	return nAllocationCount;
}

template< class T , class I = int >
class CUtlMemory
{
	enum
	{
		EXTERNAL_BUFFER_MARKER = -1 ,
		EXTERNAL_CONST_BUFFER_MARKER = -2 ,
	};

public:
	class Iterator_t
	{
	public:
		Iterator_t( const I nIndex ) :
			nIndex( nIndex )
		{
		}

		bool operator==( const Iterator_t it ) const
		{
			return nIndex == it.nIndex;
		}

		bool operator!=( const Iterator_t it ) const
		{
			return nIndex != it.nIndex;
		}

		I nIndex;
	};

public:
	CUtlMemory( int nGrowSize = 0 , int nInitSize = 0 ) : m_pMemory( 0 ) , m_nAllocationCount( nInitSize ) , m_nGrowSize( nGrowSize )
	{
		if ( m_nAllocationCount )
		{
			m_pMemory = (T*)malloc( m_nAllocationCount * sizeof( T ) );
		}
	}

	void Init( int nGrowSize = 0 , int nInitSize = 0 )
	{
		Purge();

		m_nGrowSize = nGrowSize;
		m_nAllocationCount = nInitSize;

		if ( m_nAllocationCount )
		{
			m_pMemory = (T*)malloc( m_nAllocationCount * sizeof( T ) );
		}
	}

	T& operator[]( I i )
	{
		return m_pMemory[i];
	}

	const T& operator[]( I i ) const
	{
		return m_pMemory[i];
	}

	T* Base()
	{
		return m_pMemory;
	}

	const T* Base() const
	{
		return m_pMemory;
	}

	void ConvertToGrowableMemory( int nGrowSize )
	{
		if ( !IsExternallyAllocated() )
			return;

		m_nGrowSize = nGrowSize;
		if ( m_nAllocationCount )
		{
			int nNumBytes = m_nAllocationCount * sizeof( T );
			T* pMemory = (T*)malloc( nNumBytes );
			memcpy( pMemory , m_pMemory , nNumBytes );
			m_pMemory = pMemory;
		}
		else
		{
			m_pMemory = NULL;
		}
	}

	int NumAllocated() const
	{
		return m_nAllocationCount;
	}

	void Grow( int num = 1 )
	{
		if ( IsExternallyAllocated() )
			return;

		int nAllocationRequested = m_nAllocationCount + num;
		int nNewAllocationCount = UtlMemory_CalcNewAllocationCount( m_nAllocationCount , m_nGrowSize , nAllocationRequested , sizeof( T ) );

		if ( (int)(I)nNewAllocationCount < nAllocationRequested )
		{
			if ( (int)(I)nNewAllocationCount == 0 && (int)(I)( nNewAllocationCount - 1 ) >= nAllocationRequested )
				--nNewAllocationCount;
			else
			{
				if ( (int)(I)nAllocationRequested != nAllocationRequested )
					return;

				while ( (int)(I)nNewAllocationCount < nAllocationRequested )
					nNewAllocationCount = ( nNewAllocationCount + nAllocationRequested ) / 2;
			}
		}

		m_nAllocationCount = nNewAllocationCount;

		if ( m_pMemory )
			m_pMemory = (T*)realloc( m_pMemory , m_nAllocationCount * sizeof( T ) );
		else
			m_pMemory = (T*)malloc( m_nAllocationCount * sizeof( T ) );
	}

	void Purge()
	{
		if ( m_pMemory )
		{
			GetMemAlloc()->Free( m_pMemory );

			//static const auto g_pMemAlloc = *reinterpret_cast<std::uintptr_t**>( GetProcAddress( GetModuleHandleA( "tier0.dll" ) , "g_pMemAlloc" ) );
			// free memory
			//( *( __int64( __fastcall** )( std::uintptr_t* , T* ) )( *g_pMemAlloc + 3i64 ) )( g_pMemAlloc , m_pMemory );

			m_pMemory = nullptr;
		}

		m_nAllocationCount = 0;
	}

	[[nodiscard]] bool IsExternallyAllocated() const
	{
		return m_nGrowSize <= EXTERNAL_BUFFER_MARKER;
	}

	[[nodiscard]] static I InvalidIndex()
	{
		return static_cast<I>( -1 );
	}

	[[nodiscard]] bool IsValidIndex( I nIndex ) const
	{
		return ( nIndex >= 0 ) && ( nIndex < m_nAllocationCount );
	}

	[[nodiscard]] Iterator_t First() const
	{
		return Iterator_t( IsValidIndex( 0 ) ? 0 : InvalidIndex() );
	}

	[[nodiscard]] Iterator_t Next( const Iterator_t& it ) const
	{
		return Iterator_t( IsValidIndex( it.nIndex + 1 ) ? it.nIndex + 1 : InvalidIndex() );
	}

	[[nodiscard]] I GetIndex( const Iterator_t& it ) const
	{
		return it.nIndex;
	}

	[[nodiscard]] bool IsIndexAfter( I nIndex , const Iterator_t& it ) const
	{
		return nIndex > it.nIndex;
	}

	[[nodiscard]] bool IsValidIterator( const Iterator_t& it ) const
	{
		return IsValidIndex( it.index );
	}

	[[nodiscard]] Iterator_t InvalidIterator() const
	{
		return Iterator_t( InvalidIndex() );
	}

protected:
	T* m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
};

template <class T>
inline T* Construct( T* pMemory )
{
	return ::new( pMemory ) T;
}

template <class T>
inline void Destruct( T* pMemory )
{
	pMemory->~T();
}

template< class T , size_t SIZE , class I = int >
class CUtlMemoryFixedGrowable : public CUtlMemory< T , I >
{
	typedef CUtlMemory< T , I > BaseClass;

public:
	CUtlMemoryFixedGrowable( int nGrowSize = 0 , int nInitSize = SIZE ) : BaseClass( m_pFixedMemory , SIZE )
	{
		Assert( nInitSize == 0 || nInitSize == SIZE );
		m_nMallocGrowSize = nGrowSize;
	}

	void Grow( int nCount = 1 )
	{
		if ( this->IsExternallyAllocated() )
		{
			this->ConvertToGrowableMemory( m_nMallocGrowSize );
		}
		BaseClass::Grow( nCount );
	}

	void EnsureCapacity( int num )
	{
		if ( CUtlMemory<T>::m_nAllocationCount >= num )
			return;

		if ( this->IsExternallyAllocated() )
		{
			// Can't grow a buffer whose memory was externally allocated 
			this->ConvertToGrowableMemory( m_nMallocGrowSize );
		}

		BaseClass::EnsureCapacity( num );
	}

private:
	int m_nMallocGrowSize;
	T m_pFixedMemory[SIZE];
};
