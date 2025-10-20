#pragma once

#include <CS2/SDK/Types/CBaseTypes.hpp>
#include <google/protobuf/message.h>

struct NetMessageInfo_t;
class CNetMessagePB;

class CNetMessagePB : public google::protobuf::Message
{
public:
};

class CNetworkSerializerPB
{
public:
	virtual ~CNetworkSerializerPB() = 0;
	virtual const char* GetUnscopedName() = 0;
	virtual NetMessageInfo_t* GetNetMessageInfo() = 0;
	virtual void SetMessageID( unsigned int messageID ) = 0;
	virtual void AddCategoryMask( unsigned int bitflag , bool applyToAnotherMember ) = 0;
	virtual void SwitchMode( int networkValidationMode_t ) = 0;
	virtual google::protobuf::Message* AllocateMessage() = 0;
	virtual void DeallocateMessage( void* protobuff_msg ) = 0;
	virtual void* AllocateAndCopyConstructNetMessage( google::protobuf::Message* ) = 0;
	virtual bool Serialize( bf_write& buffer , void* InputProtobuffMessage , int NetworkSerializationMode_t ) = 0;
	virtual bool UnSerialize( bf_read& buffer , void* OutputProtobuffMessage , int NetworkSerializationMode_t ) = 0;

	const char* unscopedName;
	uint32_t categoryMask;
	int unk;
	CNetMessagePB* protobuffBinding;
	const char* groupName;
	short messageID;
	uint8_t groupID;
	uint8_t defaultBufferType;
};
