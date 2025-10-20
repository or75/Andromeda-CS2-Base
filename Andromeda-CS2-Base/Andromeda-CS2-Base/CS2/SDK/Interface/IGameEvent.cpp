#include "IGameEvent.hpp"

#include <CS2/SDK/FunctionListSDK.hpp>
#include <CS2/SDK/Types/CUtlStringToken.hpp>

auto IGameEvent::GetName() -> const char*
{
	return IGameEvent_GetName( this );
}

auto IGameEvent::GetInt64( const std::string_view Name ) -> int64_t
{
	return IGameEvent_GetInt64( this , Name.data() );
}

auto IGameEvent::GetPlayerController( const std::string_view Name ) -> CCSPlayerController*
{
	CUtlStringToken Token( Name.data() );

	return IGameEvent_GetPlayerController( this , &Token );
}

auto IGameEvent::GetString( const std::string_view Name ) -> const char*
{
	CUtlStringToken Token( Name.data() );

	return IGameEvent_GetString( this , &Token );
}

auto IGameEvent::SetString( const std::string_view Name , const std::string_view Value ) -> const char*
{
	CUtlStringToken Token( Name.data() );

	return IGameEvent_SetString( this , &Token , Value.data() );
}
