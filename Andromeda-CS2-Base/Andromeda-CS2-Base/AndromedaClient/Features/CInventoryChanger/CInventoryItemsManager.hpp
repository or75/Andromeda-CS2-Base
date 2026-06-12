#pragma once

#include <vector>
#include <Common/Common.hpp>
#include <unordered_map>
#include <string>

#include <ImGui/imgui.h>

class CCSPlayerInventory;
class CEconItem;
struct ID3D11ShaderResourceView;

class CInventoryItemsManager final
{
public:
    enum EInventoryPrefab_t : uint32_t
    {
        INVENTORY_PREFAB_MUSIC_KIT = 1314 ,
        INVENTORY_PREFAB_STICKER_KIT = 1209 ,
    };

    enum EDumpedItemType_t
    {
        DUMPED_ITEM_TYPE_NONE ,
        DUMPED_ITEM_TYPE_WEAPON ,
        DUMPED_ITEM_TYPE_KNIFE ,
        DUMPED_ITEM_TYPE_GLOVE ,
        DUMPED_ITEM_TYPE_AGENT ,
        DUMPED_ITEM_TYPE_MUSIC,
    };

    // Made public for UI access
    struct DumpedSkin_t
    {
        int m_ID = 0;
        int m_Rarity = 0;
        std::string m_PaintKitName = "";
        std::string m_DisplayName = "";  // Skin name for UI
		std::string m_IconPath = ""; // Path to icon for UI
        bool m_bLegacyModel = false;
    };

    struct DumpedItem_t
    {
        uint16_t m_DefIdx = 0;
        int m_Rarity = 0;
        bool m_UnusualItem = false;
        std::vector<DumpedSkin_t> m_DumpedSkins = {};
        EDumpedItemType_t m_ItemType = DUMPED_ITEM_TYPE_NONE;
        std::string m_PaintKitName = "";
        std::string m_DisplayName = "";  // Item name for UI
        std::string m_IconPath = ""; // Path to icon for UI
    };

    struct AddedItem_t
    {
        uint16_t m_DefIdx = 0;
        int m_PaintKit = 0;
        int m_Rarity = 0;
        float m_Wear = 0.0f;
        int m_Seed = 0;
        bool m_UnusualItem = false;
        bool m_bLegacyModel = false;
        std::string m_PaintKitName = "";
        std::string m_DisplayName = "";  // Skin/Item name for UI
        EDumpedItemType_t m_ItemType = DUMPED_ITEM_TYPE_NONE;
        CEconItem* m_pEconItem = nullptr;
	};

private:
    std::vector<DumpedItem_t> m_vecDumpedItems;
    std::unordered_map<uint64_t , AddedItem_t> m_AddedItems;

public:
    // Scan all available items (does NOT add to inventory)
    auto ScanAllItems() -> void;
    
    // Legacy function - now calls ScanAllItems + applies selected skins from config
    auto OnAddAllItems() -> void;

    // Add a specific selected skin to inventory
    auto AddSelectedSkinToInventory( uint16_t defIdx , int paintKit , float wear = 0.0f , bool equip = false , int seed = 0 , int statTrak = -1 ) -> bool;

public:
    auto AddMusicToInventory( uint16_t defIdx , int MusicId , bool equip = false ) -> bool;

public:
    auto RemoveItemFromInventoryByID( uint64_t ID ) -> bool;

public:
    inline auto IsItemIDAdded( uint64_t ID ) -> bool
    {
        if ( m_AddedItems.find( ID ) == m_AddedItems.end() )
            return false;

        return true;
    }

public:
    inline auto GetDumpedItems() -> std::vector<DumpedItem_t>&
    {
        return m_vecDumpedItems;
    }

    inline auto GetAddedItems()->std::unordered_map<uint64_t, AddedItem_t>&
    {
        return m_AddedItems;
    }
    
    // Helper to get skin name from paint kit ID
    auto GetSkinName( int paintKitId ) -> std::string;
    
    // Helper to get weapon name from def index
    auto GetWeaponName( uint16_t defIdx ) -> std::string;
    
    // Helper to get rarity name
    auto GetRarityName( int rarity ) -> std::string;

	// Helper to get rarity color
    auto GetRarityColor( int rarity ) -> ImU32;
};

auto GetInventoryItemsManager() -> CInventoryItemsManager*;
