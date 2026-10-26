#include "CPageManager.hpp"
#include "Pages/ISubPage.hpp"
#include "Custom/CSidebarItem.hpp"

static auto g_PageManager = CPageManager{};

namespace
{
	auto ToLowerAscii( char c ) -> char
	{
		return static_cast<char>( std::tolower( static_cast<unsigned char>( c ) ) );
	}

	auto ContainsCaseInsensitive( std::string_view haystack , std::string_view needle ) -> bool
	{
		if ( needle.empty() )
			return true;

		if ( haystack.size() < needle.size() )
			return false;

		for ( auto i = size_t{ 0 }; i <= haystack.size() - needle.size(); ++i )
		{
			auto bMatch = true;

			for ( auto j = size_t{ 0 }; j < needle.size(); ++j )
			{
				if ( ToLowerAscii( haystack[i + j] ) != ToLowerAscii( needle[j] ) )
				{
					bMatch = false;
					break;
				}
			}

			if ( bMatch )
				return true;
		}

		return false;
	}
}

auto CPageManager::RegisterPage( std::string id , std::unique_ptr<GitMenu::IPage> pPage , ImTextureRef icon , bool bSeparatorBefore ) -> void
{
	m_Pages.push_back( { std::move( id ) , std::move( pPage ) , icon , bSeparatorBefore } );

	if ( m_strActivePageId.empty() && !m_Pages.empty() )
	{
		m_strActivePageId = m_Pages.front().Id;
		SelectDefaultSubPage( m_Pages.front() );
	}
}

auto CPageManager::SetPageIcon( std::string_view id , ImTextureRef icon ) -> void
{
	if ( auto* pEntry = FindPageEntry( id ) )
		pEntry->Icon = icon;
}

auto CPageManager::GetPageIcon( int index ) const -> ImTextureRef
{
	if ( index < 0 || index >= GetPageCount() )
		return ImTextureRef();

	const auto& entry = m_Pages[index];

	return ( entry.Icon._TexData || entry.Icon._TexID != ImTextureID_Invalid ) ? entry.Icon : entry.Page->GetIcon();
}

auto CPageManager::HasPageSeparator( int index ) const -> bool
{
	return index >= 0 && index < GetPageCount() && m_Pages[index].bSeparatorBefore;
}

auto CPageManager::FindPageEntry( std::string_view id ) -> PageEntry*
{
	for ( auto& entry : m_Pages )
	{
		if ( entry.Id == id )
			return &entry;
	}

	return nullptr;
}

auto CPageManager::FindPageEntry( std::string_view id ) const -> const PageEntry*
{
	for ( const auto& entry : m_Pages )
	{
		if ( entry.Id == id )
			return &entry;
	}

	return nullptr;
}

auto CPageManager::GetActivePageEntry() -> PageEntry*
{
	return FindPageEntry( m_strActivePageId );
}

auto CPageManager::GetActivePageEntry() const -> const PageEntry*
{
	return FindPageEntry( m_strActivePageId );
}

auto CPageManager::FindSubPageIndex( const GitMenu::IPage& page , std::string_view subPageId ) const -> int
{
	for ( auto i = 0; i < page.GetSubPageCount(); ++i )
	{
		const auto* id = page.GetSubPageId( i );

		if ( id && subPageId == id )
			return i;
	}

	return -1;
}

auto CPageManager::SelectDefaultSubPage( const PageEntry& entry ) -> void
{
	if ( entry.Page->GetSubPageCount() > 0 )
	{
		const auto* firstSubPageId = entry.Page->GetSubPageId( 0 );
		m_ActiveSubPageIdByPageId[entry.Id] = firstSubPageId ? firstSubPageId : "";
	}
	else
	{
		m_ActiveSubPageIdByPageId.erase( entry.Id );
	}
}

auto CPageManager::FocusSearchMatchedSubPage( PageEntry& entry ) -> void
{
	if ( m_strSearchQuery.empty() || entry.Page->GetSubPageCount() <= 0 )
		return;

	for ( auto i = 0; i < entry.Page->GetSubPageCount(); ++i )
	{
		const auto* subPageId = entry.Page->GetSubPageId( i );
		auto* pSubPage = entry.Page->GetSubPage( i );

		if ( !subPageId || !pSubPage )
			continue;

		if ( !ContainsCaseInsensitive( subPageId , m_strSearchQuery ) &&
			!ContainsCaseInsensitive( pSubPage->GetDisplayName() , m_strSearchQuery ) )
		{
			continue;
		}

		m_ActiveSubPageIdByPageId[entry.Id] = subPageId;
		return;
	}
}

auto CPageManager::SetActivePage( std::string_view id ) -> void
{
	auto* pNewEntry = FindPageEntry( id );

	if ( !pNewEntry )
		return;

	if ( auto* pOldEntry = GetActivePageEntry() )
	{
		if ( pOldEntry->Id == pNewEntry->Id )
			return;

		if ( !m_ActiveSubPageIdByPageId[pOldEntry->Id].empty() )
		{
			const auto oldSubIndex = FindSubPageIndex( *pOldEntry->Page , m_ActiveSubPageIdByPageId[pOldEntry->Id] );

			if ( oldSubIndex >= 0 )
			{
				if ( auto* pOldSub = pOldEntry->Page->GetSubPage( oldSubIndex ) )
					pOldSub->OnLeave();
			}
		}

		pOldEntry->Page->OnLeave();
	}

	m_strActivePageId = std::string( id );

	if ( m_ActiveSubPageIdByPageId.find( pNewEntry->Id ) == m_ActiveSubPageIdByPageId.end() )
		SelectDefaultSubPage( *pNewEntry );

	FocusSearchMatchedSubPage( *pNewEntry );

	pNewEntry->Page->OnEnter();

	if ( !m_ActiveSubPageIdByPageId[pNewEntry->Id].empty() )
	{
		const auto newSubIndex = FindSubPageIndex( *pNewEntry->Page , m_ActiveSubPageIdByPageId[pNewEntry->Id] );

		if ( newSubIndex >= 0 )
		{
			if ( auto* pNewSub = pNewEntry->Page->GetSubPage( newSubIndex ) )
				pNewSub->OnEnter();
		}
	}
}

auto CPageManager::SetActiveSubPage( std::string_view subPageId ) -> void
{
	auto* pEntry = GetActivePageEntry();

	if ( !pEntry || pEntry->Page->GetSubPageCount() <= 0 )
		return;

	const auto newSubIndex = FindSubPageIndex( *pEntry->Page , subPageId );

	if ( newSubIndex < 0 )
		return;

	const auto& currentSubPageId = m_ActiveSubPageIdByPageId[pEntry->Id];

	if ( currentSubPageId == subPageId )
		return;

	if ( !currentSubPageId.empty() )
	{
		const auto oldSubIndex = FindSubPageIndex( *pEntry->Page , currentSubPageId );

		if ( oldSubIndex >= 0 )
		{
			if ( auto* pOldSub = pEntry->Page->GetSubPage( oldSubIndex ) )
				pOldSub->OnLeave();
		}
	}

	m_ActiveSubPageIdByPageId[pEntry->Id] = std::string( subPageId );

	if ( auto* pNewSub = pEntry->Page->GetSubPage( newSubIndex ) )
		pNewSub->OnEnter();
}

auto CPageManager::SetSearchQuery( std::string_view query ) -> void
{
	m_strSearchQuery.assign( query.begin() , query.end() );
}

auto CPageManager::IsPageVisible( int index ) const -> bool
{
	if ( index < 0 || index >= GetPageCount() )
		return false;

	if ( m_strSearchQuery.empty() )
		return true;

	const auto& entry = m_Pages[index];

	if ( ContainsCaseInsensitive( entry.Id , m_strSearchQuery ) ||
		ContainsCaseInsensitive( entry.Page->GetDisplayName() , m_strSearchQuery ) )
	{
		return true;
	}

	for ( auto subIndex = 0; subIndex < entry.Page->GetSubPageCount(); ++subIndex )
	{
		const auto* subPageId = entry.Page->GetSubPageId( subIndex );
		auto* pSubPage = entry.Page->GetSubPage( subIndex );

		if ( !subPageId || !pSubPage )
			continue;

		if ( ContainsCaseInsensitive( subPageId , m_strSearchQuery ) ||
			ContainsCaseInsensitive( pSubPage->GetDisplayName() , m_strSearchQuery ) )
		{
			return true;
		}
	}

	return false;
}

auto CPageManager::IsSubPageVisible( int index ) const -> bool
{
	const auto* pEntry = GetActivePageEntry();

	if ( !pEntry || index < 0 || index >= pEntry->Page->GetSubPageCount() )
		return false;

	if ( m_strSearchQuery.empty() )
		return true;

	const auto* subPageId = pEntry->Page->GetSubPageId( index );
	auto* pSubPage = pEntry->Page->GetSubPage( index );

	if ( !subPageId || !pSubPage )
		return false;

	return ContainsCaseInsensitive( subPageId , m_strSearchQuery ) ||
		ContainsCaseInsensitive( pSubPage->GetDisplayName() , m_strSearchQuery );
}

auto CPageManager::GetActivePageDisplayName() const -> const char*
{
	const auto* pEntry = GetActivePageEntry();

	return pEntry ? pEntry->Page->GetDisplayName() : "";
}

auto CPageManager::GetActiveSubPageCount() const -> int
{
	const auto* pEntry = GetActivePageEntry();

	return pEntry ? pEntry->Page->GetSubPageCount() : 0;
}

auto CPageManager::GetActiveSubPageId( int index ) const -> const char*
{
	const auto* pEntry = GetActivePageEntry();

	return pEntry ? pEntry->Page->GetSubPageId( index ) : nullptr;
}

auto CPageManager::GetActiveSubPageDisplayName( int index ) const -> const char*
{
	const auto* pEntry = GetActivePageEntry();

	if ( !pEntry )
		return "";

	if ( auto* pSubPage = pEntry->Page->GetSubPage( index ) )
		return pSubPage->GetDisplayName();

	return "";
}

auto CPageManager::GetActiveSubPageIcon( int index ) const -> ImTextureRef
{
	const auto* pEntry = GetActivePageEntry();

	if ( !pEntry || index < 0 || index >= pEntry->Page->GetSubPageCount() )
		return ImTextureRef();

	if ( auto* pSubPage = pEntry->Page->GetSubPage( index ) )
		return pSubPage->GetIcon();

	return ImTextureRef();
}

auto CPageManager::GetActiveSubPageId() const -> const std::string&
{
	static const auto emptyId = std::string{};

	const auto* pEntry = GetActivePageEntry();

	if ( !pEntry )
		return emptyId;

	const auto it = m_ActiveSubPageIdByPageId.find( pEntry->Id );

	if ( it == m_ActiveSubPageIdByPageId.end() )
		return emptyId;

	return it->second;
}

auto CPageManager::RenderSubPageSelectable( int index , float scale ) -> void
{
	const auto* subPageId = GetActiveSubPageId( index );
	const auto* displayName = GetActiveSubPageDisplayName( index );

	if ( !subPageId )
		return;

	const auto bIsActive = ( GetActiveSubPageId() == subPageId );

	if ( GitMenu::CSidebarItem::Render( subPageId , displayName , GetActiveSubPageIcon( index ) , bIsActive , scale ) )
		SetActiveSubPage( subPageId );
}

auto CPageManager::RenderSubPages() -> void
{
	const auto subPageCount = GetActiveSubPageCount();

	if ( subPageCount <= 0 )
	{
		ImGui::TextDisabled( "No sub pages" );
		return;
	}

	const auto scale = ImGui::GetFontSize() / 16.f;
	auto bHasVisibleSubPages = false;

	ImGui::PushID( this );
	ImGui::PushID( GetActivePageId().c_str() );
	ImGui::PushFont( nullptr , 14.f );
	ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing , ImVec2( ImGui::GetStyle().ItemSpacing.x , 0.f ) );

	for ( auto i = 0; i < subPageCount; ++i )
	{
		if ( !IsSubPageVisible( i ) || !GetActiveSubPageId( i ) )
			continue;

		bHasVisibleSubPages = true;
		RenderSubPageSelectable( i , scale );
	}

	ImGui::PopStyleVar();
	ImGui::PopFont();
	ImGui::PopID();
	ImGui::PopID();

	if ( !bHasVisibleSubPages )
	{
		ImGui::TextDisabled( "No matches" );
		return;
	}

	ImGui::Dummy( ImVec2( 0.f , ImGui::GetStyle().ItemSpacing.y * scale ) );
	ImGui::Separator();
}

auto CPageManager::RenderActivePage() -> void
{
	auto* pEntry = GetActivePageEntry();

	if ( !pEntry )
		return;

	if ( pEntry->Page->GetSubPageCount() > 0 )
	{
		const auto subIndex = FindSubPageIndex( *pEntry->Page , GetActiveSubPageId() );

		if ( subIndex >= 0 )
		{
			if ( auto* pSubPage = pEntry->Page->GetSubPage( subIndex ) )
			{
				pSubPage->OnRender();
				return;
			}
		}
	}

	pEntry->Page->OnRender();
}

auto GetPageManager() -> CPageManager*
{
	return &g_PageManager;
}
