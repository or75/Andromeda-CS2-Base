#pragma once

#include "CUtlMemory.hpp"

class CUtlString
{
public:
    CUtlString() = default;

    ~CUtlString()
    {
        m_Memory.Purge();
        m_nActualLength = 0;
    }

    const char* Get()
    {
        return reinterpret_cast<const char*>( m_Memory.Base() );
    }

    CUtlMemory<unsigned char> m_Memory;
    int m_nActualLength;
};
