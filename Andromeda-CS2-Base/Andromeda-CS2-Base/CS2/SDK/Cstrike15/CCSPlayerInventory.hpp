#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/GCSDK/CGCClientSharedObjectCache.hpp>
#include <CS2/SDK/Types/CUtlVector.hpp>

class CSharedObject;
class C_EconItemView;
class CGCClientSharedObjectCache;
class CGCClientSharedObjectTypeCache;
class CEconItem;

class CPlayerInventory : public ISharedObjectListener
{
public:
};

class CCSPlayerInventory : public CPlayerInventory
{
public:
	static auto Get() -> CCSPlayerInventory*;

public:
	auto AddEconItem( CEconItem* pItem ) -> bool;
	auto RemoveEconItem( CEconItem* pItem ) -> void;

public:
	// Vmt Index -> "8"
	/* Client.dll -> Strings:
	00007FF8F71C4D7 | 48:8D15 C521C800         | lea rdx,qword ptr ds:[0x7FF8F7E46F48]                                      | 00007FF8F7E46F48:"item_sub_position2"
	00007FF8F71C4D8 | FF15 A767B500            | call qword ptr ds:[<public: char const * __cdecl KeyValues::GetString(char |
	00007FF8F71C4D8 | 48:8D0D BC12C800         | lea rcx,qword ptr ds:[0x7FF8F7E4604C]                                      | 00007FF8F7E4604C:"spray0"
	*/
	auto GetItemInLoadout( int iClass , int iSlot ) -> C_EconItemView*;

public:
	auto GetHighestIDs() -> std::pair<uint64_t , uint32_t>;
	auto GetItemViewForItem( uint64_t itemID ) -> C_EconItemView*;
	auto GetSOCDataForItem( uint64_t itemID ) -> CEconItem*;

public:
	auto GetOwner() -> GCSDK::SOID_t;
	auto GetItemVector() -> CUtlVector<C_EconItemView*>;

private:
	auto GetBaseTypeCache() -> CGCClientSharedObjectTypeCache*;
};
