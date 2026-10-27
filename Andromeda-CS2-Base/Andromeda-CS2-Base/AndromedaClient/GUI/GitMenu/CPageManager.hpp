#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

#include "Pages/IPage.hpp"

#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>

class CPageManager final
{
public:
	auto RegisterPage( std::string id , std::unique_ptr<GitMenu::IPage> pPage , ImTextureRef icon = ImTextureRef() , bool bSeparatorBefore = false ) -> void;
	auto SetPageIcon( std::string_view id , ImTextureRef icon ) -> void;
	auto SetActivePage( std::string_view id ) -> void;
	auto SetActiveSubPage( std::string_view subPageId ) -> void;
	auto RenderSubPages() -> void;
	auto RenderActivePage() -> void;

	auto SetSearchQuery( std::string_view query ) -> void;
	auto ConsumeSearchReset() -> bool
	{
		const auto reset = m_bSearchReset;
		m_bSearchReset = false;
		return reset;
	}
	auto IsPageVisible( int index ) const -> bool;
	auto IsSubPageVisible( int index ) const -> bool;

	auto GetPageCount() const -> int { return static_cast<int>( m_Pages.size() ); }
	auto GetPageId( int index ) const -> const std::string& { return m_Pages[index].Id; }
	auto GetPageName( int index ) const -> const char* { return m_Pages[index].Page->GetName(); }
	auto GetPageDisplayName( int index ) const -> const char* { return m_Pages[index].Page->GetDisplayName(); }
	auto GetPageIcon( int index ) const -> ImTextureRef;
	auto GetPageFontAwesomeIcon( int index ) const -> const char8_t*;
	auto HasPageSeparator( int index ) const -> bool;
	auto GetActivePageId() const -> const std::string& { return m_strActivePageId; }
	auto GetActivePageDisplayName() const -> const char*;

	auto GetActiveSubPageCount() const -> int;
	auto GetActiveSubPageId( int index ) const -> const char*;
	auto GetActiveSubPageDisplayName( int index ) const -> const char*;
	auto GetActiveSubPageIcon( int index ) const -> ImTextureRef;
	auto GetActiveSubPageFontAwesomeIcon( int index ) const -> const char8_t*;
	auto GetActiveSubPageId() const -> const std::string&;

private:
	struct PageEntry
	{
		std::string                     Id;
		std::unique_ptr<GitMenu::IPage> Page;
		ImTextureRef                   Icon;
		bool                           bSeparatorBefore = false;
	};

	auto FindPageEntry( std::string_view id ) -> PageEntry*;
	auto FindPageEntry( std::string_view id ) const -> const PageEntry*;
	auto GetActivePageEntry() -> PageEntry*;
	auto GetActivePageEntry() const -> const PageEntry*;
	auto SelectDefaultSubPage( const PageEntry& entry ) -> void;
	auto ClearSearchForNavigation() -> void;
	auto FindSubPageIndex( const GitMenu::IPage& page , std::string_view subPageId ) const -> int;
	auto RenderSubPageSelectable( int index , float scale ) -> void;
	auto RenderWidgetSearchResults() -> void;

	std::vector<PageEntry>                              m_Pages;
	std::string                                         m_strActivePageId;
	std::unordered_map<std::string, std::string>        m_ActiveSubPageIdByPageId;
	std::string                                         m_strSearchQuery;
	bool                                                m_bSearchReset = false;
};

auto GetPageManager() -> CPageManager*;
