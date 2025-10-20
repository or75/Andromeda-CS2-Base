#include "CEconItemSystem.hpp"

#include <Common/MemoryEngine.hpp>

auto CEconItemSystem::GetEconItemSchema() -> CEconItemSchema*
{
	return CUSTOM_OFFSET( CEconItemSchema* , 0x8 );
}
