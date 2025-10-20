#pragma once

#include <Common/Common.hpp>
#include "CBaseTypes.hpp"

#define STRINGTOKEN_MURMURHASH_SEED 0x31415926

FORCEINLINE uint32_t MurmurHash2( const void* key , int len , uint32_t seed )
{
    /* 'm' and 'r' are mixing constants generated offline.
       They're not really 'magic', they just happen to work well.  */

    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    /* Initialize the hash to a 'random' value */

    uint32_t h = seed ^ len;

    /* Mix 4 bytes at a time into the hash */

    const unsigned char* data = (const unsigned char*)key;

    while ( len >= 4 )
    {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    /* Handle the last few bytes of the input array  */

    switch ( len )
    {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0];
            h *= m;
    };

    /* Do a few final mixes of the hash to ensure the last few
    // bytes are well-incorporated.  */

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

#define TOLOWERU( c ) ( ( uint32_t ) ( ( ( c >= 'A' ) && ( c <= 'Z' ) )? c + 32 : c ) )

FORCEINLINE uint32_t MurmurHash2LowerCaseA( char const* pString , int len , uint32_t nSeed )
{
    char* p = (char*)malloc( len + 1 );

    for ( int i = 0; i < len; i++ )
        p[i] = TOLOWERU( pString[i] );

    return MurmurHash2( p , len , nSeed );
}

class CUtlStringToken
{
public:
	uint32 m_nHashCode;
    const char* m_szDebugName;

    CUtlStringToken() { m_nHashCode = 0; m_szDebugName = nullptr;  }

    CUtlStringToken( char const* szString )
    {
        this->SetHashCode( this->MakeStringToken( szString ) );
        m_szDebugName = szString;
    }

    FORCEINLINE std::uint32_t MakeStringToken( char const* szString , int nLen )
    {
        std::uint32_t nHashCode = MurmurHash2LowerCaseA( szString , nLen , STRINGTOKEN_MURMURHASH_SEED );
        return nHashCode;
    }

    FORCEINLINE std::uint32_t MakeStringToken( char const* szString )
    {
        return MakeStringToken( szString , (int)strlen( szString ) );
    }

	FORCEINLINE bool operator==( CUtlStringToken const& other ) const
	{
		return ( other.m_nHashCode == m_nHashCode );
	}

	FORCEINLINE bool operator!=( CUtlStringToken const& other ) const
	{
		return ( other.m_nHashCode != m_nHashCode );
	}

	FORCEINLINE bool operator<( CUtlStringToken const& other ) const
	{
		return ( m_nHashCode < other.m_nHashCode );
	}

	FORCEINLINE uint32 GetHashCode( void ) const { return m_nHashCode; }
	FORCEINLINE void SetHashCode( uint32 nCode ) { m_nHashCode = nCode; }
};
