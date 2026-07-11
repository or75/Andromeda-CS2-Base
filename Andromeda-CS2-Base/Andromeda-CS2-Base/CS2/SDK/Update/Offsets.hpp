#pragma once

// 0F B7 40 ? 48 83 C4 20 5B C3 33 C0 48 83 C4 20 5B C3
static constexpr auto g_CCollisionProperty_UnknownMask = 0x38;

// Hook_SendNetMessage,Hook_CDemoRecorder
static constexpr auto g_ProtobufMsgOffset = 0x30;

// Client.dll -> UpdateCompositeMaterial + offset == 48 81 C1 ? ? ? ? B2 ? E8 ? ? ? ? 48 8D 8B
static constexpr auto g_CompositeMaterialOffset = 0x608;

// 48 8D 58 ? 49 89 4B
static constexpr auto g_CEconItemSchema_GetSortedItemDefinitionMap = 0x128;
static constexpr auto g_CEconItemSchema_GetPaintKits = 0x2F0;

// E8 ? ? ? ? 48 85 C0 74 ? 48 8B 40 ? 4C 8B C7
/*
00007FFB3AF2FE2B | movsxd r8,dword ptr ds:[rax+0x4]                |
00007FFB3AF2FE2F | cmp r8d,dword ptr ds:[rbx+0x4D8]                | offset in function call
*/
static constexpr auto g_CEconItemSchema_GetMusicKitDefinitions = 0x500;

// Client.dll
/*
00007FFC381C3E9 | mov esi,dword ptr ds:[rax+0x2D8]                                 | offset
00007FFC381C3E9 | cmp ebp,0x38                                                     | 38:'8'
00007FFC381C3EA | jne client.7FFC381C3F12                                          |
00007FFC381C3EA | cmp esi,0x37                                                     | 37:'7'
00007FFC381C3EA | jne client.7FFC381C3F12                                          |
00007FFC381C3EA | mov rcx,rdi                                                      |
00007FFC381C3EA | call client.7FFC38910F00                                         |
00007FFC381C3EA | mov rcx,rax                                                      |
00007FFC381C3EB | mov rdx,qword ptr ds:[rax]                                       |
00007FFC381C3EB | call qword ptr ds:[rdx+0x48]                                     |
00007FFC381C3EB | mov rcx,rax                                                      |
00007FFC381C3EB | lea rdx,qword ptr ds:[0x7FFC38FE39F8]                            | 00007FFC38FE39F8:"item_sub_position2"
*/
// 8B B0 ? ? ? ? 83 FD ? 75 70 83 FE ? 75 6B 48 8B CF E8
static constexpr auto g_CEconItemDefinition_GetLoadoutSlot = 0x338;

// Vmt Index -> "70" -> "mov rax,qword ptr ds:[rcx+0x3F540]"
static constexpr auto g_CCSInventoryManager_GetLocalInventory = 0x3F540;

static constexpr auto g_CCSPlayerInventory_CGCClientSharedObjectCache = 0x68;

// 44 38 67 ? 0F 84 ? ? ? ? 48 8B 05
static constexpr auto g_CCSGOInput_m_bInThirdPerson = 0x229;

// 44 8B B0 ? ? ? ? 41 8B D6
static constexpr auto g_CUserCmdArray_m_nSequenceNumber = 0x5910;

// 49 8B 8E ? ? ? ? 48 69 D0
static constexpr auto g_CCSGOInput_m_pInputMoves = 0xB58;

// F2 0F 11 84 1F
static constexpr auto g_CCSInputMoves_m_vecViewAngles = 0x430;

// client.dll -> FF 81 ? ? ? ? 48 85 D2
static constexpr auto g_OFFSET_CGameEntitySystem_GetHighestEntityIndex = 0x2090;

static constexpr auto g_CCPaintKit_IsUseLegacyModel = 0xAE;
