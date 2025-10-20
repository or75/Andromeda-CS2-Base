#include "CEconItemDefinition.hpp"

#include <Common/Include/Fnv1a/Hash_Fnv1a_Constexpr.hpp>

auto CEconItemDefinition::IsWeapon() -> bool
{
	return m_nStickerSupportCount() >= 4;
}

auto CEconItemDefinition::IsKnife( bool excludeDefault ) -> bool
{
    static constexpr auto CSGO_Type_Knife = hash_32_fnv1a_const( "#CSGO_Type_Knife" );

    if ( hash_32_fnv1a_const( m_pszItemTypeName() ) != CSGO_Type_Knife )
        return false;

    return excludeDefault ? m_nDefIndex() >= 500 : true;
}

auto CEconItemDefinition::IsGlove( bool excludeDefault ) -> bool
{
    static constexpr auto Type_Hands = hash_32_fnv1a_const( "#Type_Hands" );

    if ( hash_32_fnv1a_const( m_pszItemTypeName() ) != Type_Hands )
        return false;

    const bool defaultGlove = m_nDefIndex() == 5028 || m_nDefIndex() == 5029;

    return excludeDefault ? !defaultGlove : true;
}

auto CEconItemDefinition::IsAgent( bool excludeDefault ) -> bool
{
    static constexpr auto Type_CustomPlayer = hash_32_fnv1a_const( "#Type_CustomPlayer" );

    if ( hash_32_fnv1a_const( m_pszItemTypeName() ) != Type_CustomPlayer )
        return false;

    const bool defaultGlove = m_nDefIndex() == 5036 || m_nDefIndex() == 5037;

    return excludeDefault ? !defaultGlove : true;
}
