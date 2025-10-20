#pragma once

#include <Common/Common.hpp>
#include <vector>

enum ItemDefinitionIndex : int
{
	WEAPON_INVALID = -1 ,
	WEAPON_NONE ,
	WEAPON_DESERT_EAGLE ,
	WEAPON_DUAL_BERETTAS ,
	WEAPON_FIVE_SEVEN ,
	WEAPON_GLOCK_18 ,
	WEAPON_AK_47 = 7 ,
	WEAPON_AUG ,
	WEAPON_AWP ,
	WEAPON_FAMAS ,
	WEAPON_G3SG1 ,
	WEAPON_GALIL_AR = 13 ,
	WEAPON_M249 ,
	WEAPON_M4A1 = 16 ,
	WEAPON_MAC_10 ,
	WEAPON_P90 = 19 ,
	WEAPON_REPULSOR_DEVICE ,
	WEAPON_MP5_SD = 23 ,
	WEAPON_UMP_45 ,
	WEAPON_XM1014 ,
	WEAPON_PP_BIZON ,
	WEAPON_MAG_7 ,
	WEAPON_NEGEV ,
	WEAPON_SAWED_OFF ,
	WEAPON_TEC_9 ,
	WEAPON_ZEUS_X27 ,
	WEAPON_P2000 ,
	WEAPON_MP7 ,
	WEAPON_MP9 ,
	WEAPON_NOVA ,
	WEAPON_P250 ,
	WEAPON_RIOT_SHIELD ,
	WEAPON_SCAR_20 ,
	WEAPON_SG_553 ,
	WEAPON_SSG_08 ,
	WEAPON_KNIFE0 ,
	WEAPON_KNIFE1 ,
	WEAPON_FLASHBANG ,
	WEAPON_HIGH_EXPLOSIVE_GRENADE ,
	WEAPON_SMOKE_GRENADE ,
	WEAPON_MOLOTOV ,
	WEAPON_DECOY_GRENADE ,
	WEAPON_INCENDIARY_GRENADE ,
	WEAPON_C4_EXPLOSIVE ,
	WEAPON_KEVLAR_VEST ,
	WEAPON_KEVLAR_and_HELMET ,
	WEAPON_HEAVY_ASSAULT_SUIT ,
	WEAPON_NO_LOCALIZED_NAME0 = 54 ,
	WEAPON_DEFUSE_KIT ,
	WEAPON_RESCUE_KIT ,
	WEAPON_MEDI_SHOT ,
	WEAPON_MUSIC_KIT ,
	WEAPON_KNIFE2 ,
	WEAPON_M4A1_S ,
	WEAPON_USP_S ,
	WEAPON_TRADE_UP_CONTRACT ,
	WEAPON_CZ75_AUTO ,
	WEAPON_R8_REVOLVER ,
	WEAPON_TACTICAL_AWARENESS_GRENADE = 68 ,
	WEAPON_BARE_HANDS ,
	WEAPON_BREACH_CHARGE ,
	WEAPON_TABLET = 72 ,
	WEAPON_KNIFE3 = 74 ,
	WEAPON_AXE ,
	WEAPON_HAMMER ,
	WEAPON_WRENCH = 78 ,
	WEAPON_SPECTRAL_SHIV = 80 ,
	WEAPON_FIRE_BOMB ,
	WEAPON_DIVERSION_DEVICE ,
	WEAPON_FRAG_GRENADE ,
	WEAPON_SNOWBALL ,
	WEAPON_BUMP_MINE ,
	// GLOVES
	STUDDED_BLOODHOUND_GLOVES = 5027,
	SPORTY_GLOVES = 5030 ,
	SLICK_GLOVES = 5031 ,
	LEATHER_HANDWRAPS = 5032 ,
	MOTORCYCLE_GLOVES = 5033 ,
	SPECIALIST_GLOVES = 5034 ,
	STUDDED_HYDRA_GLOVES = 5035 ,
	STUDDED_BROKEN_FANG = 4725,
	// KNIFES
	WEAPON_KNIFE_BAYONET = 500 ,
	WEAPON_KNIFE_CSS = 503 ,
	WEAPON_KNIFE_FLIP = 505 ,
	WEAPON_KNIFE_GUT = 506 ,
	WEAPON_KNIFE_KARAMBIT = 507 ,
	WEAPON_KNIFE_M9_BAYONET = 508 ,
	WEAPON_KNIFE_TACTICAL = 509 ,
	WEAPON_KNIFE_FALCHION = 512 ,
	WEAPON_KNIFE_SURVIVAL_BOWIE = 514 ,
	WEAPON_KNIFE_BUTTERFLY = 515 ,
	WEAPON_KNIFE_PUSH = 516 ,
	WEAPON_KNIFE_CORD = 517 ,
	WEAPON_KNIFE_CANIS = 518 ,
	WEAPON_KNIFE_URSUS = 519 ,
	WEAPON_KNIFE_GYPSY_JACKKNIFE = 520 ,
	WEAPON_KNIFE_OUTDOOR = 521 ,
	WEAPON_KNIFE_STILETTO = 522 ,
	WEAPON_KNIFE_WIDOWMAKER = 523 ,
	WEAPON_KNIFE_SKELETON = 525 ,
	WEAPON_KNIFE_KUKRI = 526 ,
};

struct WeaponName_t
{
	int m_WeaponDefinitionIndex = 0;
	const char* m_pszName = nullptr;
	const char* m_pszDesc = nullptr;
};

struct GloveName_t
{
	int m_WeaponDefinitionIndex = 0;
	const char* m_pszName = nullptr;
	const char* m_pszDesc = nullptr;
};

struct KnifeName_t
{
	int m_WeaponDefinitionIndex = 0;
	const char* m_pszName = nullptr;
	const char* m_pszDesc = nullptr;
};

struct GrenadeName_t
{
	int m_WeaponDefinitionIndex = 0;
	const char* m_pszName = nullptr;
};

// Items Info
extern std::vector<WeaponName_t> g_WeaponsNames;
extern std::vector<GloveName_t> g_GlovesNames;
extern std::vector<KnifeName_t> g_KnifesNames;
extern std::vector<GrenadeName_t> g_GrenadeNames;

// Weapon Info
auto GetWeaponDescFromDefinitionIndex( int DefinitionIndex ) -> const char*;
auto GetGloveDescFromDefinitionIndex( int DefinitionIndex ) -> const char*;
auto GetKnifeDescFromDefinitionIndex( int DefinitionIndex ) -> const char*;
auto GetKnifeIconNameFromDefinitionIndex( int DefinitionIndex ) -> const char*;
auto GetGrenadeNameFromDefinitionIndex( int DefinitionIndex ) -> const char*;
auto GetGrenadeDefinitionIndexFromIndex( int Index ) -> int;
