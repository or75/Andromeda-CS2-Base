#pragma once

#include <Common/Common.hpp>

#include <string>
#include <unordered_map>

struct SchemaOffset_t
{
	std::string m_ClassName;
	std::string m_PropertyName;
	uint32_t m_Offset = 0;
};

class CShcemaOffset final
{
public:
	auto Init() -> void;

public:
	auto GetOffset( std::string ClassName , std::string PropertyName ) -> uint32_t;

private:
	std::unordered_map<std::string , std::unordered_map<std::string , SchemaOffset_t>> m_SchemaData;
};

#define SCHEMA_OFFSET(class_name, property_name, function, type) \
__forceinline type& function() \
{ \
    uint32_t offset = GetSchemaOffset()->GetOffset(class_name, property_name);  \
    return *reinterpret_cast<type*>(reinterpret_cast<uint64_t>(this) + offset); \
}

#define PSCHEMA_OFFSET(class_name, property_name, function, type) \
__forceinline type* function() \
{ \
    uint32_t offset = GetSchemaOffset()->GetOffset(class_name, property_name);  \
    return reinterpret_cast<type*>(reinterpret_cast<uint64_t>(this) + offset); \
}

#define SCHEMA_OFFSET_CUSTOM(function, offset, type) \
__forceinline type& function() \
{ \
    return *reinterpret_cast<type*>(reinterpret_cast<uint64_t>(this) + offset); \
}

auto GetSchemaOffset() -> CShcemaOffset*;
