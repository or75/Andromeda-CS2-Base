#include "CL_ItemDefinition.hpp"

std::vector<WeaponName_t> g_WeaponsNames =
{
	// CSWeaponType_t::Pistol 0 - 9

	{ WEAPON_GLOCK_18, "Glock-18" , "weapon_glock" },
	{ WEAPON_CZ75_AUTO, "CZ75-Auto" , "weapon_cz75a" },
	{ WEAPON_P250, "P250" , "weapon_p250" },
	{ WEAPON_FIVE_SEVEN, "Five-SeveN" , "weapon_fiveseven" },
	{ WEAPON_DESERT_EAGLE, "Desert-Eagle" , "weapon_deagle" },
	{ WEAPON_R8_REVOLVER, "R8-Revolver" , "weapon_revolver" },
	{ WEAPON_DUAL_BERETTAS, "Dual-Berettas" , "weapon_elite" },
	{ WEAPON_TEC_9, "Tec-9" , "weapon_tec9" },
	{ WEAPON_P2000, "P2000" , "weapon_hkp2000" },
	{ WEAPON_USP_S, "USP-S" , "weapon_usp_silencer" },

	// CSWeaponType_t::SubMachinegun 10 - 16

	{ WEAPON_MAC_10, "MAC-10" , "weapon_mac10" },
	{ WEAPON_MP9, "MP9" , "weapon_mp9" },
	{ WEAPON_MP7, "MP7" , "weapon_mp7" },
	{ WEAPON_MP5_SD, "MP5-SD" , "weapon_mp5sd" },
	{ WEAPON_UMP_45, "UMP-45" , "weapon_ump45" },
	{ WEAPON_PP_BIZON, "PP-Bizon" , "weapon_bizon" },
	{ WEAPON_P90, "P90" , "weapon_p90" },

	// CSWeaponType_t::Rifle 17 - 23

	{ WEAPON_GALIL_AR, "Galil AR" , "weapon_galilar" },
	{ WEAPON_FAMAS, "FAMAS" , "weapon_famas" },
	{ WEAPON_AK_47, "AK-47" , "weapon_ak47" },
	{ WEAPON_M4A1, "M4A1" , "weapon_m4a1" },
	{ WEAPON_M4A1_S, "M4A1-S" , "weapon_m4a1_silencer" },
	{ WEAPON_SG_553, "SG-553" , "weapon_sg556" },
	{ WEAPON_AUG, "AUG" , "weapon_aug" },

	// CSWeaponType_t::Shotgun 24 - 27

	{ WEAPON_NOVA, "Nova" , "weapon_nova" },
	{ WEAPON_XM1014, "XM1014" , "weapon_xm1014" },
	{ WEAPON_SAWED_OFF, "Sawed-Off" , "weapon_sawedoff" },
	{ WEAPON_MAG_7, "MAG-7" , "weapon_mag7" },

	// CSWeaponType_t::SniperRifle 28 - 31

	{ WEAPON_SSG_08, "SSG-08" , "weapon_ssg08" },
	{ WEAPON_AWP, "AWP" , "weapon_awp" },
	{ WEAPON_G3SG1, "G3SG1" , "weapon_g3sg1" },
	{ WEAPON_SCAR_20,  "SCAR-20" , "weapon_scar20" },

	// CSWeaponType_t::Machinegun 32 - 33

	{ WEAPON_M249, "M249" , "weapon_m249" },
	{ WEAPON_NEGEV, "Negev" , "weapon_negev" },

	// ZEUS X27
	{ WEAPON_ZEUS_X27, "Zeus-X27" , "weapon_taser" },
};

std::vector<GloveName_t> g_GlovesNames =
{
	{ STUDDED_BLOODHOUND_GLOVES , "Bloodhound" , "studded_bloodhound_gloves" },
	{ SPORTY_GLOVES , "Sporty" , "sporty_gloves" },
	{ SLICK_GLOVES , "Slick" , "slick_gloves" },
	{ LEATHER_HANDWRAPS , "Handwrap" , "leather_handwraps" },
	{ MOTORCYCLE_GLOVES , "Motorcycle" , "motorcycle_gloves" },
	{ SPECIALIST_GLOVES , "Specialist" , "specialist_gloves" },
	{ STUDDED_HYDRA_GLOVES , "Bloodhound Hydra" , "studded_hydra_gloves" },
	{ STUDDED_BROKEN_FANG , "Operation 10" , "studded_brokenfang_gloves" },
};

std::vector<KnifeName_t> g_KnifesNames =
{
	{ WEAPON_KNIFE_BAYONET , "Knife Bayonet" , "weapon_bayonet" } ,
	{ WEAPON_KNIFE_CSS , "Knife CSS" , "weapon_knife_css" } ,
	{ WEAPON_KNIFE_FLIP , "Knife Flip" , "weapon_knife_flip" } ,
	{ WEAPON_KNIFE_GUT , "Knife Gut" , "weapon_knife_gut" } ,
	{ WEAPON_KNIFE_KARAMBIT , "Knife Karambit" , "weapon_knife_karambit" } ,
	{ WEAPON_KNIFE_M9_BAYONET , "Knife M9 Bayonet" , "weapon_knife_m9_bayonet" } ,
	{ WEAPON_KNIFE_TACTICAL , "Knife Tactical" , "weapon_knife_tactical" } ,
	{ WEAPON_KNIFE_FALCHION , "Knife Falchion Advanced" , "weapon_knife_falchion" } ,
	{ WEAPON_KNIFE_SURVIVAL_BOWIE , "Knife Survival Bowie" , "weapon_knife_survival_bowie" } ,
	{ WEAPON_KNIFE_BUTTERFLY , "Knife Butterfly" , "weapon_knife_butterfly" } ,
	{ WEAPON_KNIFE_PUSH , "Knife Push" , "weapon_knife_push"} ,
	{ WEAPON_KNIFE_CORD , "Knife Cord" , "weapon_knife_cord" } ,
	{ WEAPON_KNIFE_CANIS , "Knife Canis" , "weapon_knife_canis" } ,
	{ WEAPON_KNIFE_URSUS , "Knife Ursus" , "weapon_knife_ursus" } ,
	{ WEAPON_KNIFE_GYPSY_JACKKNIFE , "Knife Gypsy Jackknife" , "weapon_knife_gypsy_jackknife" } ,
	{ WEAPON_KNIFE_OUTDOOR , "Knife Outdoor" , "weapon_knife_outdoor" } ,
	{ WEAPON_KNIFE_STILETTO , "Knife Stiletto" , "weapon_knife_stiletto" } ,
	{ WEAPON_KNIFE_WIDOWMAKER , "Knife Widowmaker" , "weapon_knife_widowmaker" } ,
	{ WEAPON_KNIFE_SKELETON , "Knife Skeleton" , "weapon_knife_skeleton" } ,
	{ WEAPON_KNIFE_KUKRI , "Knife Kukri" , "weapon_knife_kukri" } ,
};

std::vector<GrenadeName_t> g_GrenadeNames =
{
	 { WEAPON_FLASHBANG , "FlashBang" } ,
	 { WEAPON_SMOKE_GRENADE , "Smoke" } ,
	 { WEAPON_MOLOTOV , "Molotov" } ,
	 { WEAPON_DECOY_GRENADE , "Decoy" } ,
	 { WEAPON_INCENDIARY_GRENADE , "Incendiary" } ,
};

auto GetWeaponDescFromDefinitionIndex( int DefinitionIndex ) -> const char*
{
	for ( size_t i = 0; i < g_WeaponsNames.size(); i++ )
	{
		if ( g_WeaponsNames[i].m_WeaponDefinitionIndex == DefinitionIndex )
			return g_WeaponsNames[i].m_pszDesc;
	}

	return "";
}

auto GetGloveDescFromDefinitionIndex( int DefinitionIndex ) -> const char*
{
	for ( size_t i = 0; i < g_GlovesNames.size(); i++ )
	{
		if ( g_GlovesNames[i].m_WeaponDefinitionIndex == DefinitionIndex )
			return g_GlovesNames[i].m_pszDesc;
	}

	return "";
}

auto GetKnifeDescFromDefinitionIndex( int DefinitionIndex ) -> const char*
{
	for ( size_t i = 0; i < g_KnifesNames.size(); i++ )
	{
		if ( g_KnifesNames[i].m_WeaponDefinitionIndex == DefinitionIndex )
			return g_KnifesNames[i].m_pszDesc;
	}

	return "";
}

auto GetKnifeIconNameFromDefinitionIndex( int DefinitionIndex ) -> const char*
{
	for ( size_t i = 0; i < g_KnifesNames.size(); i++ )
	{
		if ( g_KnifesNames[i].m_WeaponDefinitionIndex == DefinitionIndex )
		{
			return g_KnifesNames[i].m_pszDesc + 7;
		}
	}

	return "";
}

auto GetGrenadeNameFromDefinitionIndex( int DefinitionIndex ) -> const char*
{
	for ( size_t i = 0; i < g_GrenadeNames.size(); i++ )
	{
		if ( g_GrenadeNames[i].m_WeaponDefinitionIndex == DefinitionIndex )
			return g_GrenadeNames[i].m_pszName;
	}

	return "";
}

auto GetGrenadeDefinitionIndexFromIndex( int Index ) -> int
{
	for ( size_t i = 0; i < g_GrenadeNames.size(); i++ )
	{
		if ( i == Index )
			return g_GrenadeNames[i].m_WeaponDefinitionIndex;
	}

	return 0;
}
