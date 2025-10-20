#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/FunctionListSDK.hpp>

class C_BaseEntity;
class CCSPlayerController;

class CGameEntitySystem
{
public:
	template<typename T = C_BaseEntity>
	auto GetBaseEntity( int iIndex ) -> T*
	{
		return (T*)CGameEntitySystem_GetBaseEntity( this , iIndex );
	}

public:
	auto GetHighestEntityIndex() -> int
	{
		auto HighestIdx = -1;

		CGameEntitySystem_GetHighestEntityIndex( this , HighestIdx );

		return HighestIdx;
	}

public:
	/*
	00007FF9BBF1312 | E8 B6EBDDFF                     | call client.7FF9BBCF1CE0                         | GetLocalPlayerController
	00007FF9BBF1312 | 45:8B4E 78                      | mov r9d,dword ptr ds:[r14+0x78]                  |
	00007FF9BBF1312 | 4C:8D05 1B2FBA00                | lea r8,qword ptr ds:[0x7FF9BCAB6050]             | 00007FF9BCAB6050:"preentitypacket:ack %d cmds"
	00007FF9BBF1313 | 33D2                            | xor edx,edx                                      |
	00007FF9BBF1313 | 49:8946 08                      | mov qword ptr ds:[r14+0x8],rax                   |
	00007FF9BBF1313 | 48:8D4C24 20                    | lea rcx,qword ptr ss:[rsp+0x20]                  |
	00007FF9BBF1314 | E8 2BF8E8FF                     | call client.7FF9BBDA2970                         |
	*/
	static auto GetLocalPlayerController() -> CCSPlayerController*
	{
		return CGameEntitySystem_GetLocalPlayerController( -1 );
	}
};

#define FOR_EACH_ENTITY( idx_name ) \
	for ( auto idx_name = 0; idx_name <= SDK::Interfaces::GameEntitySystem()->GetHighestEntityIndex(); idx_name++ )
