#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/Network/CNetworkMessages.hpp>

class CCSGOInput;

auto Hook_CreateMove( CCSGOInput* pInput , uint32_t split_screen_index , char a3 ) -> bool;

using CreateMove_t = decltype( &Hook_CreateMove );
inline CreateMove_t CreateMove_o = nullptr;

auto Hook_MessageLite_SerializePartialToArray( google::protobuf::Message* pMsg , void* out_buffer , int size ) -> bool;

using MessageLite_SerializePartialToArray_t = decltype( &Hook_MessageLite_SerializePartialToArray );
inline MessageLite_SerializePartialToArray_t MessageLite_SerializePartialToArray_o = nullptr;
