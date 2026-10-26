#pragma once

#include "IPage.hpp"
#include "ISubPage.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace GitMenu
{
	class PageWithSubPages : public IPage
	{
	public:
		auto GetSubPageCount() const -> int override { return static_cast<int>( m_SubPages.size() ); }
		auto GetSubPageId( int index ) const -> const char* override;
		auto GetSubPage( int index ) const -> ISubPage* override;

		auto OnRender() -> void override {}

	protected:
		auto AddSubPage( std::string id , std::unique_ptr<ISubPage> pSubPage ) -> void;

	private:
		struct SubPageEntry
		{
			std::string                Id;
			std::unique_ptr<ISubPage>  Page;
		};

		std::vector<SubPageEntry> m_SubPages;
	};
}
