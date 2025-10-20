#pragma once

#include <stdint.h>

#if defined(__x86_64__) || defined(_WIN64)
#define X64BITS
#endif

typedef unsigned char uint8;
typedef signed char int8;
typedef float float32;

#if defined( _WIN32 )

typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

typedef uint32 uint;
typedef int64 lint64;
typedef uint64 ulint64;

#ifdef X64BITS
typedef __int64 intp;
typedef unsigned __int64 uintp;
#else
typedef __int32 intp;
typedef unsigned __int32 uintp;
#endif

#else // _WIN32

#ifdef X64BITS
typedef long long intp;
typedef unsigned long long uintp;
#else
typedef int intp;
typedef unsigned int uintp;
#endif

#endif

struct bf_read;
struct bf_write;

using HSequence = int;
using CEntityIndex = int;
using PlayerID_t = int;
using CGlobalSymbol = const char*;

#define C_NetworkUtlVectorBase CUtlVector
#define C_UtlVectorEmbeddedNetworkVar CUtlVector
#define CNetworkViewOffsetVector Vector3

enum NetChannelBufType_t : uint8
{
	BUF_DEFAULT = 0xFF,
	BUF_UNRELIABLE = 0x0,
	BUF_RELIABLE = 0x01,
	BUF_VOICE = 0x02,
};

enum ObserverMode_t : uint32_t
{
	OBS_MODE_NONE = 0x0 ,
	OBS_MODE_FIXED = 0x1 ,
	OBS_MODE_IN_EYE = 0x2 ,
	OBS_MODE_CHASE = 0x3 ,
	OBS_MODE_ROAMING = 0x4 ,
	OBS_MODE_DIRECTED = 0x5 ,
	NUM_OBSERVER_MODES = 0x6 ,
};

enum class CSWeaponType_t : int32_t
{
	WEAPONTYPE_KNIFE = 0 ,
	WEAPONTYPE_PISTOL = 1 ,
	WEAPONTYPE_SUBMACHINEGUN = 2 ,
	WEAPONTYPE_RIFLE = 3 ,
	WEAPONTYPE_SHOTGUN = 4 ,
	WEAPONTYPE_SNIPER_RIFLE = 5 ,
	WEAPONTYPE_MACHINEGUN = 6 ,
	WEAPONTYPE_C4 = 7 ,
	WEAPONTYPE_TASER = 8 ,
	WEAPONTYPE_GRENADE = 9 ,
	WEAPONTYPE_EQUIPMENT = 10 ,
	WEAPONTYPE_STACKABLEITEM = 11 ,
	WEAPONTYPE_FISTS = 12 ,
	WEAPONTYPE_BREACHCHARGE = 13 ,
	WEAPONTYPE_BUMPMINE = 14 ,
	WEAPONTYPE_TABLET = 15 ,
	WEAPONTYPE_MELEE = 16 ,
	WEAPONTYPE_SHIELD = 17 ,
	WEAPONTYPE_ZONE_REPULSOR = 18 ,
	WEAPONTYPE_UNKNOWN = 19
};

enum TeamNum_t : int32_t
{
	TEAM_UNKNOWN ,
	TEAM_SPECTATOR ,
    TEAM_TT = 2 ,
    TEAM_CT = 3 ,
};

enum EFlags : int
{
	FL_ONGROUND = ( 1 << 0 ) , // entity is at rest / on the ground
	FL_DUCKING = ( 1 << 1 ) , // player is fully crouched/uncrouched
	FL_ANIMDUCKING = ( 1 << 2 ) , // player is in the process of crouching or uncrouching but could be in transition
	FL_WATERJUMP = ( 1 << 3 ) , // player is jumping out of water
	FL_ONTRAIN = ( 1 << 4 ) , // player is controlling a train, so movement commands should be ignored on client during prediction
	FL_INRAIN = ( 1 << 5 ) , // entity is standing in rain
	FL_FROZEN = ( 1 << 6 ) , // player is frozen for 3rd-person camera
	FL_ATCONTROLS = ( 1 << 7 ) , // player can't move, but keeps key inputs for controlling another entity
	FL_CLIENT = ( 1 << 8 ) , // entity is a client (player)
	FL_FAKECLIENT = ( 1 << 9 ) , // entity is a fake client, simulated server side; don't send network messages to them
	FL_INWATER = ( 1 << 10 ) , // entity is in water
	FL_FLY = ( 1 << 11 ) ,
	FL_SWIM = ( 1 << 12 ) ,
	FL_CONVEYOR = ( 1 << 13 ) ,
	FL_NPC = ( 1 << 14 ) ,
	FL_GODMODE = ( 1 << 15 ) ,
	FL_NOTARGET = ( 1 << 16 ) ,
	FL_AIMTARGET = ( 1 << 17 ) ,
	FL_PARTIALGROUND = ( 1 << 18 ) , // entity is standing on a place where not all corners are valid
	FL_STATICPROP = ( 1 << 19 ) , // entity is a static property
	FL_GRAPHED = ( 1 << 20 ) ,
	FL_GRENADE = ( 1 << 21 ) ,
	FL_STEPMOVEMENT = ( 1 << 22 ) ,
	FL_DONTTOUCH = ( 1 << 23 ) ,
	FL_BASEVELOCITY = ( 1 << 24 ) , // entity have applied base velocity this frame
	FL_WORLDBRUSH = ( 1 << 25 ) , // entity is not moveable/removeable brush (part of the world, but represented as an entity for transparency or something)
	FL_OBJECT = ( 1 << 26 ) ,
	FL_KILLME = ( 1 << 27 ) , // entity is marked for death and will be freed by the game
	FL_ONFIRE = ( 1 << 28 ) ,
	FL_DISSOLVING = ( 1 << 29 ) ,
	FL_TRANSRAGDOLL = ( 1 << 30 ) , // entity is turning into client-side ragdoll
	FL_UNBLOCKABLE_BY_PLAYER = ( 1 << 31 )
};

enum MoveType_t : uint8_t
{
	MOVETYPE_NONE = 0x00 ,
	MOVETYPE_OBSOLETE = 0x01 ,
	MOVETYPE_WALK = 0x02 ,
	MOVETYPE_FLY = 0x03 ,
	MOVETYPE_FLYGRAVITY = 0x04 ,
	MOVETYPE_VPHYSICS = 0x05 ,
	MOVETYPE_PUSH = 0x06 ,
	MOVETYPE_NOCLIP = 0x07 ,
	MOVETYPE_OBSERVER = 0x08 ,
	MOVETYPE_LADDER = 0x09 ,
	MOVETYPE_CUSTOM = 0x0A ,
	MOVETYPE_LAST = 0x0B ,
	MOVETYPE_INVALID = 0x0B ,
	MOVETYPE_MAX_BITS = 0x05 ,
};

enum EBoneFlags : uint32_t
{
	FLAG_NO_BONE_FLAGS = 0x0 ,
	FLAG_BONEFLEXDRIVER = 0x4 ,
	FLAG_CLOTH = 0x8 ,
	FLAG_PHYSICS = 0x10 ,
	FLAG_ATTACHMENT = 0x20 ,
	FLAG_ANIMATION = 0x40 ,
	FLAG_MESH = 0x80 ,
	FLAG_HITBOX = 0x100 ,
	FLAG_BONE_USED_BY_VERTEX_LOD0 = 0x400 ,
	FLAG_BONE_USED_BY_VERTEX_LOD1 = 0x800 ,
	FLAG_BONE_USED_BY_VERTEX_LOD2 = 0x1000 ,
	FLAG_BONE_USED_BY_VERTEX_LOD3 = 0x2000 ,
	FLAG_BONE_USED_BY_VERTEX_LOD4 = 0x4000 ,
	FLAG_BONE_USED_BY_VERTEX_LOD5 = 0x8000 ,
	FLAG_BONE_USED_BY_VERTEX_LOD6 = 0x10000 ,
	FLAG_BONE_USED_BY_VERTEX_LOD7 = 0x20000 ,
	FLAG_BONE_MERGE_READ = 0x40000 ,
	FLAG_BONE_MERGE_WRITE = 0x80000 ,
	FLAG_ALL_BONE_FLAGS = 0xfffff ,
	BLEND_PREALIGNED = 0x100000 ,
	FLAG_RIGIDLENGTH = 0x200000 ,
	FLAG_PROCEDURAL = 0x400000 ,
};

class GameTime_t // (0 , server , 0x0004)
{
public:
	float32 m_Value; // 0x0000
};

class GameTick_t // server
{
public:
	int32 m_Value; // 0x0000
};

class CSWeaponType
{
public:
    CSWeaponType_t m_Type; // 0x0000
};

struct ResourceBindingBase_t
{
	void* data;
};
