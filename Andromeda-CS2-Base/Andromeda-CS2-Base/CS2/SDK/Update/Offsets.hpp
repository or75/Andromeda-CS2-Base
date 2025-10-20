#pragma once

static constexpr auto g_CDemorecorder_ParseMessage = 0x30;

// 0F B7 40 ? 48 83 C4 20 5B C3 33 C0 48 83 C4 20 5B C3
static constexpr auto g_CCollisionProperty_UnknownMask = 0x38;

// Client.dll -> UpdateCompositeMaterial + offset == 48 81 C1 ? ? ? ? B2 ? E8 ? ? ? ? 48 8D 8B
static constexpr auto g_CompositeMaterialOffset = 0x5F8;

// 48 8D 58 ? 49 89 4B
static constexpr auto g_CEconItemSchema_GetSortedItemDefinitionMap = 0x128;
static constexpr auto g_CEconItemSchema_GetPaintKits = 0x2F0;

// E8 ? ? ? ? 48 85 C0 74 ? 48 8B 40 ? 4C 8B C7
static constexpr auto g_CEconItemSchema_GetMusicKitDefinitions = 0x4D8;

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

// Vmt Index -> "67" -> "mov rax, qword ptr ds:[rcx+0x3FC60]"
static constexpr auto g_CCSInventoryManager_GetLocalInventory = 0x3FC60;

static constexpr auto g_CCSPlayerInventory_CGCClientSharedObjectCache = 0x68;

// 44 38 67 ? 0F 84 ? ? ? ? 48 8B 05
static constexpr auto g_CCSGOInput_m_bInThirdPerson = 0x251;

// 44 8B B0 ? ? ? ? 41 8B D6
static constexpr auto g_CUserCmdArray_m_nSequenceNumber = 0x59A8;

// 48 8B 8F ? ? ? ? 48 69 D0
static constexpr auto g_CCSGOInput_m_pInputMoves = 0xB80;

// F2 0F 11 84 1F
static constexpr auto g_CCSInputMoves_m_vecViewAngles = 0x430;

/*
* CViewSetup:
00007FFD92B5A41 | 48:8D96 F8040000               | lea rdx,qword ptr ds:[rsi+0x4F8]                                           | offset angView
00007FFD92B5A41 | 48:8D8E E0040000               | lea rcx,qword ptr ds:[rsi+0x4E0]                                           | offset vecOrigin
00007FFD92B5A42 | E8 2850FFFF                    | call client.7FFD92B4F450                                                   |
00007FFD92B5A42 | EB 38                          | jmp client.7FFD92B5A462                                                    |
00007FFD92B5A42 | F2:0F1086 E0040000             | movsd xmm0,qword ptr ds:[rsi+0x4E0]                                        |
00007FFD92B5A43 | F2:0F1105 D6302301             | movsd qword ptr ds:[0x7FFD93D8D510],xmm0                                   |
00007FFD92B5A43 | 8B86 E8040000                  | mov eax,dword ptr ds:[rsi+0x4E8]                                           |
*/
// 48 8D 96 ? ? ? ? 48 8D 8E ? ? ? ? E8 ? ? ? ? EB 38 F2 0F 10 86 ? ? ? ? F2 0F 11 ? ? ? ? ? 8B 86
static constexpr auto g_CViewSetup_vecOrigin = 0x04E0;
static constexpr auto g_CViewSetup_angView = 0x04F8;

// client.dll -> FF 81 ? ? ? ? 48 85 D2
static constexpr auto g_OFFSET_CGameEntitySystem_GetHighestEntityIndex = 0x20F0;
