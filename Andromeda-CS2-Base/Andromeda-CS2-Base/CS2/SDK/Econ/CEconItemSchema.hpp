#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/Types/CUtlMap.hpp>
#include <CS2/SDK/Update/Offsets.hpp>

class CEconItemDefinition;

class CPaintKit
{
public:
    int nID;
    const char* sName;
    const char* sDescriptionString;
    const char* sDescriptionTag;
    char pad0[0x8];  // no idea
    char pad1[0x8];  // no idea
    char pad2[0x8];  // no idea
    char pad3[0x8];  // no idea
    char pad4[0x4];  // no idea
    int nRarity;
};

class CMusicKit
{
public:
    int32_t nID;
    int32_t unk0;
    const char* sName;
    const char* sNameLocToken;
    const char* sLocDescription;
    const char* sPedestalDisplayModel;
    const char* sInventoryImage;
private:
    PAD( 0x10 );
};

class CEconItemSchema
{
public:
    // Index -> "27"
    auto GetAttributeDefinitionInterface( int iAttribIndex ) -> void*;

public:
    auto& GetSortedItemDefinitionMap()
    {
        return *reinterpret_cast<CUtlMap<int , CEconItemDefinition*>*>( (uintptr_t)( this ) + g_CEconItemSchema_GetSortedItemDefinitionMap );
    }

    auto& GetPaintKits()
    {
        return *reinterpret_cast<CUtlMap<int , CPaintKit*>*>( (uintptr_t)( this ) + g_CEconItemSchema_GetPaintKits );
    }

    auto& GetMusicKitDefinitions()
    {
        return *reinterpret_cast<CUtlMap<int , CMusicKit*>*>( (uintptr_t)( this ) + g_CEconItemSchema_GetMusicKitDefinitions );
    }
};
