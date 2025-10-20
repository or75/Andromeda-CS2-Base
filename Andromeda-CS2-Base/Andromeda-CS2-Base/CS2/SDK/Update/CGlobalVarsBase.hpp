#pragma once

#include <Common/MemoryEngine.hpp>

// 44 89 7B ? 45 33 FF 44 89 7B ? F3 0F 11 73 ? F3 0F 11 73 ? F3 44 0F 11 5B ? 48 8B 06
/*
00007FFD2B4809E | 44:897B 48               | mov dword ptr ds:[rbx+0x48],r15d               | offset m_nTickCount
00007FFD2B4809F | 45:33FF                  | xor r15d,r15d                                  |
00007FFD2B4809F | 44:897B 54               | mov dword ptr ds:[rbx+0x54],r15d               |
00007FFD2B4809F | F3:0F1173 34             | movss dword ptr ds:[rbx+0x34],xmm6             | offset m_flCurrentTime
00007FFD2B4809F | F3:0F1173 38             | movss dword ptr ds:[rbx+0x38],xmm6             | offset m_flCurrentTime2
00007FFD2B480A0 | F344:0F115B 30           | movss dword ptr ds:[rbx+0x30],xmm11            | offset m_flIntervalPerSubTick
00007FFD2B480A0 | 48:8B06                  | mov rax,qword ptr ds:[rsi]                     |
*/

class CGlobalVarsBase
{
public:
	CUSTOM_OFFSET_FIELD( float , m_flCurrentTime , 0x30 );
	CUSTOM_OFFSET_FIELD( float , m_flIntervalPerSubTick , 0x34 );
	CUSTOM_OFFSET_FIELD( int32_t , m_nTickCount , 0x48 );
};
