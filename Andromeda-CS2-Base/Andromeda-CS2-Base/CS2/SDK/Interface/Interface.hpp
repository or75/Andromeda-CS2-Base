#pragma once

#include <Common/Common.hpp>

// All interfaces derive from this.
class IBaseInterface
{
public:
	virtual	~IBaseInterface() {}
};

#define CREATEINTERFACE_PROCNAME	"CreateInterface"

typedef void* ( *CreateInterfaceFn )( const char* pName , int* pReturnCode );
typedef void* ( *InstantiateInterfaceFn )( );

// Used internally to register classes.
class InterfaceReg
{
public:
	InterfaceReg( InstantiateInterfaceFn fn , const char* pName );

public:
	InstantiateInterfaceFn	m_CreateFn;
	const char* m_pName;

	InterfaceReg* m_pNext; // For the global list.
};

CreateInterfaceFn CaptureFactory( const char* FactoryModule );

template<typename T>
T* CaptureInterface( CreateInterfaceFn Interface , const char* InterfaceName )
{
	T* dwPointer = (T*)( Interface( InterfaceName , 0 ) );
	return dwPointer;
}
