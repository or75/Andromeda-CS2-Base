#include "Interface.hpp"

InterfaceReg* s_pInterfaceRegs = nullptr;

InterfaceReg::InterfaceReg( InstantiateInterfaceFn fn , const char* pName ) : m_pName( pName )
{
	m_CreateFn = fn;
	m_pNext = s_pInterfaceRegs;
	s_pInterfaceRegs = this;
}

CreateInterfaceFn CaptureFactory( const char* FactoryModule )
{
	CreateInterfaceFn Interface = 0;

	HMODULE hFactoryModule = GetModuleHandleA( FactoryModule );

	if ( hFactoryModule )
		Interface = (CreateInterfaceFn)( GetProcAddress( hFactoryModule , XorStr( CREATEINTERFACE_PROCNAME ) ) );

	return Interface;
}
