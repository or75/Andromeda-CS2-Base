#include "TIER0_Functions.hpp"

static CTIER0Functions g_CTIER0Functions{};

auto CTIER0Functions::OnInit() -> bool
{
	auto hTier0Module = GetModuleHandleA( XorStr( "tier0.dll" ) );

	if ( !hTier0Module )
	{
		DEV_LOG( "[error] tier0.dll Module\n" );
		return false;
	}

	RandomFloat_o = (RandomFloat_t)GetProcAddress( hTier0Module , XorStr( "RandomFloat" ) );

	if ( !RandomFloat_o )
	{
		DEV_LOG( "[error] tier0 RandomFloat\n" );
		return false;
	}

	return true;
}

auto GetTIER0Functions() -> CTIER0Functions*
{
	return &g_CTIER0Functions;
}
