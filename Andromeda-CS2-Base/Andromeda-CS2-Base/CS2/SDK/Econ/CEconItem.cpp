#include "CEconItem.hpp"

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/CSource2Client.hpp>

#include <CS2/SDK/Econ/CEconItemSystem.hpp>
#include <CS2/SDK/Econ/CEconItemSchema.hpp>

#include <CS2/SDK/FunctionListSDK.hpp>

auto CEconItem::SetDynamicAttributeValue( int index , void* value ) -> void
{
	auto* pEconItemSchema = SDK::Interfaces::Source2Client()->GetEconItemSystem()->GetEconItemSchema();

	if ( !pEconItemSchema )
	{
		DEV_LOG( "[error] GetEconItemSchema\n" );
		return;
	}

	auto* pAttributeDefinitionInterface = pEconItemSchema->GetAttributeDefinitionInterface( index );

	if ( !pAttributeDefinitionInterface )
	{
		DEV_LOG( "[error] GetAttributeDefinitionInterface\n" );
		return;
	}

	return CEconItem_SetDynamicAttributeValueUint( this , pAttributeDefinitionInterface , value );
}

auto CEconItem::Create() -> CEconItem*
{
	return CreateSharedObjectSubclassEconItem();
}

auto CEconItem::SerializeToProtoBufItem( CSOEconItem* pCSOEconItem ) -> void*
{
	return CEconItem_SerializeToProtoBufItem( this , pCSOEconItem );
}

auto CEconItem::Destruct() -> void
{
	VirtualFn( void )( CEconItem* , bool );

	return vget< Fn >( this , Idx_Destruct )( this , true );
}
