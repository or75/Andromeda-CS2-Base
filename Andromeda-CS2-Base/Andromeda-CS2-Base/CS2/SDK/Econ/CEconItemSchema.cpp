#include "CEconItemSchema.hpp"

#include <CS2/SDK/FunctionListSDK.hpp>

auto CEconItemSchema::GetAttributeDefinitionInterface( int iAttribIndex ) -> void*
{
	return CEconItemSchema_GetAttributeDefinitionInterface( this , iAttribIndex );
}
