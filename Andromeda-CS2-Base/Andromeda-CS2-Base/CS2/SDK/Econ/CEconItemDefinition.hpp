#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/Types/CUtlVector.hpp>
#include <CS2/SDK/Update/Offsets.hpp>

/*
Simple Dump:

DEV_LOG( "pItem: %p , %d , %d , %s , %s , %s , %d , %s , %s , %d\n" , pItem ,
    pItem->m_nDefIndex() ,
    pItem->m_nItemRarity() ,
    pItem->m_pszItemBaseName() ? pItem->m_pszItemBaseName() : "null" ,
    pItem->m_pszItemTypeName() ? pItem->m_pszItemTypeName() : "null" ,
    pItem->m_pszModelName() ? pItem->m_pszModelName() : "null" ,
    pItem->m_nStickerSupportCount() ,
    pItem->m_pszIconName() ? pItem->m_pszIconName() : "null" ,
    pItem->m_pszWeaponName() ? pItem->m_pszWeaponName() : "null" ,
    pItem->LoadoutSlot()
);

pItem: 000005F0BC74B400 , 1 , 2 , #SFUI_WPNHUD_DesertEagle , #CSGO_Type_Pistol , weapons/models/deagle/weapon_pist_deagle.vmdl , 5 , pist_deagle , weapon_deagle , 6
pItem: 000005F0BC74BC00 , 2 , 1 , #SFUI_WPNHUD_Elites , #CSGO_Type_Pistol , weapons/models/elite/weapon_pist_elite.vmdl , 5 , pist_elite , weapon_elite , 3
pItem: 000005F0BC74C000 , 3 , 1 , #SFUI_WPNHUD_FiveSeven , #CSGO_Type_Pistol , weapons/models/fiveseven/weapon_pist_fiveseven.vmdl , 5 , pist_fiveseven , weapon_fiveseven , 5
pItem: 000005F0BC74C400 , 4 , 2 , #SFUI_WPNHUD_Glock18 , #CSGO_Type_Pistol , weapons/models/glock18/weapon_pist_glock18.vmdl , 5 , pist_glock18 , weapon_glock , 2
pItem: 000005F0BC74C800 , 7 , 2 , #SFUI_WPNHUD_AK47 , #CSGO_Type_Rifle , weapons/models/ak47/weapon_rif_ak47.vmdl , 5 , rif_ak47 , weapon_ak47 , 15
pItem: 000005F0BC74CC00 , 8 , 1 , #SFUI_WPNHUD_Aug , #CSGO_Type_Rifle , weapons/models/aug/weapon_rif_aug.vmdl , 5 , rif_aug , weapon_aug , 17
pItem: 000005F0BC74D000 , 9 , 2 , #SFUI_WPNHUD_AWP , #CSGO_Type_SniperRifle , weapons/models/awp/weapon_snip_awp.vmdl , 5 , snip_awp , weapon_awp , 18
pItem: 000005F0BC74D400 , 10 , 1 , #SFUI_WPNHUD_Famas , #CSGO_Type_Rifle , weapons/models/famas/weapon_rif_famas.vmdl , 5 , rif_famas , weapon_famas , 14
pItem: 000005F0BC74D800 , 11 , 1 , #SFUI_WPNHUD_G3SG1 , #CSGO_Type_SniperRifle , weapons/models/g3sg1/weapon_snip_g3sg1.vmdl , 5 , snip_g3sg1 , weapon_g3sg1 , 14
pItem: 000005F0BC74DC00 , 13 , 1 , #SFUI_WPNHUD_GalilAR , #CSGO_Type_Rifle , weapons/models/galilar/weapon_rif_galilar.vmdl , 5 , rif_galilar , weapon_galilar , 14
pItem: 000005F0BC74E000 , 14 , 1 , #SFUI_WPNHUD_M249 , #CSGO_Type_Machinegun , weapons/models/m249/weapon_mach_m249.vmdl , 5 , mach_m249para , weapon_m249 , 8
pItem: 000005F0BC74E400 , 16 , 2 , #SFUI_WPNHUD_M4A1 , #CSGO_Type_Rifle , weapons/models/m4a4/weapon_rif_m4a4.vmdl , 5 , rif_m4a1 , weapon_m4a1 , 14
pItem: 000005F0BC74E800 , 17 , 1 , #SFUI_WPNHUD_MAC10 , #CSGO_Type_SMG , weapons/models/mac10/weapon_smg_mac10.vmdl , 5 , smg_mac10 , weapon_mac10 , 12
pItem: 000005F0BC74EC00 , 19 , 1 , #SFUI_WPNHUD_P90 , #CSGO_Type_SMG , weapons/models/p90/weapon_smg_p90.vmdl , 5 , smg_p90 , weapon_p90 , 11
pItem: 000005F0BC74F000 , 23 , 1 , #SFUI_WPNHUD_MP5SD , #CSGO_Type_SMG , weapons/models/mp5sd/weapon_smg_mp5sd.vmdl , 5 , smg_mp5sd , weapon_mp5sd , 10
pItem: 000005F0BC74F400 , 24 , 1 , #SFUI_WPNHUD_UMP45 , #CSGO_Type_SMG , weapons/models/ump45/weapon_smg_ump45.vmdl , 5 , smg_ump45 , weapon_ump45 , 8
pItem: 000005F0BC74F800 , 25 , 1 , #SFUI_WPNHUD_xm1014 , #CSGO_Type_Shotgun , weapons/models/xm1014/weapon_shot_xm1014.vmdl , 5 , shot_xm1014 , weapon_xm1014 , 9
pItem: 000005F09A55A000 , 26 , 1 , #SFUI_WPNHUD_Bizon , #CSGO_Type_SMG , weapons/models/bizon/weapon_smg_bizon.vmdl , 5 , smg_bizon , weapon_bizon , 8
pItem: 000005F080E49400 , 27 , 1 , #SFUI_WPNHUD_Mag7 , #CSGO_Type_Shotgun , weapons/models/mag7/weapon_shot_mag7.vmdl , 5 , shot_mag7 , weapon_mag7 , 8
pItem: 000005F080660C00 , 28 , 1 , #SFUI_WPNHUD_Negev , #CSGO_Type_Machinegun , weapons/models/negev/weapon_mach_negev.vmdl , 5 , mach_negev , weapon_negev , 8
pItem: 000005F0BCF51000 , 29 , 1 , #SFUI_WPNHUD_Sawedoff , #CSGO_Type_Shotgun , weapons/models/sawedoff/weapon_shot_sawedoff.vmdl , 5 , shot_sawedoff , weapon_sawedoff , 8
pItem: 000005F0BCF50C00 , 30 , 1 , #SFUI_WPNHUD_Tec9 , #CSGO_Type_Pistol , weapons/models/tec9/weapon_pist_tec9.vmdl , 5 , pist_tec9 , weapon_tec9 , 5
pItem: 000005F0BCF59400 , 31 , 1 , #SFUI_WPNHUD_Taser , #CSGO_Type_Equipment , weapons/models/taser/weapon_pist_taser.vmdl , 5 , null , weapon_taser , 34
pItem: 000005F0BCF53800 , 32 , 2 , #SFUI_WPNHUD_HKP2000 , #CSGO_Type_Pistol , weapons/models/hkp2000/weapon_pist_hkp2000.vmdl , 5 , pist_hkp2000 , weapon_hkp2000 , 2
pItem: 000005F0BCF52800 , 33 , 1 , #SFUI_WPNHUD_MP7 , #CSGO_Type_SMG , weapons/models/mp7/weapon_smg_mp7.vmdl , 5 , smg_mp7 , weapon_mp7 , 8
pItem: 000005F0BCF52C00 , 34 , 1 , #SFUI_WPNHUD_MP9 , #CSGO_Type_SMG , weapons/models/mp9/weapon_smg_mp9.vmdl , 5 , smg_mp9 , weapon_mp9 , 12
pItem: 000005F0BCF56400 , 35 , 1 , #SFUI_WPNHUD_Nova , #CSGO_Type_Shotgun , weapons/models/nova/weapon_shot_nova.vmdl , 5 , shot_nova , weapon_nova , 8
pItem: 000005F0BCF56000 , 36 , 1 , #SFUI_WPNHUD_P250 , #CSGO_Type_Pistol , weapons/models/p250/weapon_pist_p250.vmdl , 5 , pist_p250 , weapon_p250 , 4
pItem: 000005F0BCF57400 , 38 , 1 , #SFUI_WPNHUD_SCAR20 , #CSGO_Type_SniperRifle , weapons/models/scar20/weapon_snip_scar20.vmdl , 5 , snip_scar20 , weapon_scar20 , 14
pItem: 000005F0BCF57000 , 39 , 1 , #SFUI_WPNHUD_SG556 , #CSGO_Type_Rifle , weapons/models/sg556/weapon_rif_sg556.vmdl , 5 , rif_sg556 , weapon_sg556 , 17
pItem: 000005F0BCF56C00 , 40 , 1 , #SFUI_WPNHUD_SSG08 , #CSGO_Type_SniperRifle , weapons/models/ssg08/weapon_snip_ssg08.vmdl , 5 , snip_ssg08 , weapon_ssg08 , 16
pItem: 000005F0BCF53000 , 60 , 2 , #SFUI_WPNHUD_M4_SILENCER , #CSGO_Type_Rifle , weapons/models/m4a1_silencer/weapon_rif_m4a1_silencer.vmdl , 5 , rif_m4a1_s , weapon_m4a1_silencer , 15
pItem: 000005F0C55CA800 , 61 , 2 , #SFUI_WPNHUD_USP_SILENCER , #CSGO_Type_Pistol , weapons/models/usp_silencer/weapon_pist_usp_silencer.vmdl , 5 , pist_223 , weapon_usp_silencer , 2
pItem: 000005F0C55C9C00 , 63 , 1 , #SFUI_WPNHUD_CZ75 , #CSGO_Type_Pistol , weapons/models/cz75a/weapon_pist_cz75a.vmdl , 5 , pist_cz_75 , weapon_cz75a , 3
pItem: 000005F0C55CE000 , 64 , 1 , #SFUI_WPNHUD_REVOLVER , #CSGO_Type_Pistol , weapons/models/revolver/weapon_pist_revolver.vmdl , 5 , pist_revolver , weapon_revolver , 3
pItem: 000005F0C55C8800 , 500 , 6 , #SFUI_WPNHUD_KnifeBayonet , #CSGO_Type_Knife , weapons/models/knife/knife_bayonet/weapon_knife_bayonet.vmdl , 0 , knife_bayonet , weapon_bayonet , 0
*/

class CEconItemDefinition
{
public:
    auto IsWeapon() -> bool;
    auto IsKnife( bool excludeDefault ) -> bool;
    auto IsGlove( bool excludeDefault ) -> bool;
    auto IsAgent( bool excludeDefault ) -> bool;

public:
    CUSTOM_OFFSET_FIELD( uint16_t , m_nDefIndex , 0x10 );
    CUSTOM_OFFSET_FIELD( uint8_t , m_nItemRarity , 0x42 );
    CUSTOM_OFFSET_FIELD( const char* , m_pszItemBaseName , 0x70 );
    CUSTOM_OFFSET_FIELD( const char* , m_pszItemTypeName , 0x80 );
    CUSTOM_OFFSET_FIELD( const char* , m_pszModelName , 0x148 );
    CUSTOM_OFFSET_FIELD( int32_t , m_nStickerSupportCount , 0x168 );
    CUSTOM_OFFSET_FIELD( const char* , m_pszIconName , 0x230 );
    CUSTOM_OFFSET_FIELD( const char* , m_pszWeaponName , 0x260 );
    CUSTOM_OFFSET_FIELD( uint32_t , LoadoutSlot , g_CEconItemDefinition_GetLoadoutSlot );
};
