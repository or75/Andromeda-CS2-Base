#include "PageWithSubPages.hpp"

namespace GitMenu
{
	auto PageWithSubPages::GetSubPageId( int index ) const -> const char*
	{
		if ( index < 0 || index >= GetSubPageCount() )
			return nullptr;

		return m_SubPages[index].Id.c_str();
	}

	auto PageWithSubPages::GetSubPage( int index ) const -> ISubPage*
	{
		if ( index < 0 || index >= GetSubPageCount() )
			return nullptr;

		return m_SubPages[index].Page.get();
	}

	auto PageWithSubPages::AddSubPage( std::string id , std::unique_ptr<ISubPage> pSubPage ) -> void
	{
		m_SubPages.push_back( { std::move( id ) , std::move( pSubPage ) } );
	}
}
