#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/CBasePattern.hpp>
#include <CS2/SDK/SDK.hpp>

#define SCHEMA_SYSTEM_INTERFACE_VERSION "SchemaSystem_001"

#pragma region CSchemaSystemIndex

namespace index
{
	namespace CSchemaSystem
	{
		constexpr auto GlobalTypeScope = 11;
		constexpr auto SchemaClassInfo = 42;
	}
}

#pragma endregion

#pragma region GeneratorOffset

namespace GeneratorOffset
{
	constexpr auto GetNumSchema = 0x74;
	constexpr auto GetClassContainer = 0x580; // 49 8D 9F ? ? ? ? 48 8B CB E8 ? ? ? ? 48 8B 43 ? 48 8B CB 48 89 43 ? E8 ? ? ? ? 48 83 C3 ? 48 83 EF
}

#pragma endregion

#pragma region CSchemaSystemClasses

class CSchemaClassBinding;
class CSchemaType;
class CSchemaSystemTypeScope;

#pragma endregion

#pragma region CSchemaSystemImpl

class SchemaClassFieldDataArray_t
{
public:
	char* FieldName;
	CSchemaType* FieldType;
	int FieldOffset;
private:
	PAD( 0xC );
};

class CSchemaClassBinding
{
public:
	class CBaseClass_t
	{
	public:
		CUSTOM_OFFSET_FIELD( CSchemaClassBinding* , m_classInfo , 0x8 );
	};

	CUSTOM_OFFSET_FIELD( const char* , m_bindingName , 0x8 );
	CUSTOM_OFFSET_FIELD( const char* , m_dllName , 0x10 );
	CUSTOM_OFFSET_FIELD( int , m_SizeOf , 0x18 );
	CUSTOM_OFFSET_FIELD( unsigned short int , m_DataArraySize , 0x1C );
	CUSTOM_OFFSET_FIELD( SchemaClassFieldDataArray_t* , m_DataArray , 0x28 );
	CUSTOM_OFFSET_FIELD( CBaseClass_t* , m_baseClass , 0x30 );
	CUSTOM_OFFSET_FIELD( CSchemaSystemTypeScope* , m_TypeScope , 0x48 );
	CUSTOM_OFFSET_FIELD( CSchemaType* , m_Type , 0x50 );
};

class CSchemaType
{
public:
	void* ptable;
	char* szTypeName;
};

template <class T = CSchemaClassBinding>
class CSchemaList
{
public:
	class SchemaBlock
	{
	public:
		SchemaBlock* Next() const
		{
			return m_nextBlock;
		}
		T* GetBinding() const
		{
			return m_classBinding;
		}
	private:
		void* unkn0;
		SchemaBlock* m_nextBlock;
		T* m_classBinding;
	};

	class BlockContainer
	{
	public:
		SchemaBlock* GetFirstBlock() const
		{
			return m_firstBlock;
		}
	private:
		void* unkn[2];
		SchemaBlock* m_firstBlock;
	};

	typedef std::array<BlockContainer , 256> BlockContainers;

	int GetNumSchema()
	{
		return CUSTOM_OFFSET( int , -GeneratorOffset::GetNumSchema );
	}

	const BlockContainers& GetBlockContainers()
	{
		return CUSTOM_OFFSET( const BlockContainers , 0x0 );
	}
};

#pragma endregion

class CSchemaSystemTypeScope
{
public:
	CSchemaList<CSchemaClassBinding>* GetClassContainer()
	{
		return CUSTOM_OFFSET_RAW( CSchemaList<CSchemaClassBinding> , GeneratorOffset::GetClassContainer );
	}
};

namespace CSchemaSystem_Search
{
	inline CBasePattern GetAllTypeScopeFn = { VmpStr( "CSchemaSystem::GetAllTypeScope" ) , VmpStr( "48 8B 05 ? ? ? ? 48 8B D6 0F B7 CB 48 8B 3C C8" ) , SCHEMASYSTEM_DLL , 0 , SEARCH_TYPE_PTR2 };
}

class CSchemaSystem
{
public:
	auto GlobalTypeScope() -> CSchemaSystemTypeScope*
	{
		VirtualFn( CSchemaSystemTypeScope* )( CSchemaSystem* );
		return vget< Fn >( this , index::CSchemaSystem::GlobalTypeScope )( this );
	}

	auto GetAllTypeScope() -> CSchemaSystemTypeScope**
	{
		return *reinterpret_cast<CSchemaSystemTypeScope***>( CSchemaSystem_Search::GetAllTypeScopeFn.GetFunction() );
	}

	auto GetAllTypeScopeSize() -> uint16_t
	{
		return *reinterpret_cast<uint16_t*>( (uintptr_t)CSchemaSystem_Search::GetAllTypeScopeFn.GetFunction() - 0x8 );
	}
};
