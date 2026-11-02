#pragma once

#include "IWidget.hpp"

namespace GitMenu
{
	class CComboBoxWidget final : public IWidget
	{
	public:
		// value is a zero-based index and must outlive the widget; -1 means no selection.
		CComboBoxWidget( const char* name , const char* description , int* value , std::vector<std::string> items , bool separatorAfter = false );

		auto OnRenderImGui() -> void override;
		auto SetItems( std::vector<std::string> items ) -> void { m_Items = std::move( items ); }
		auto SetSelectionIcon( std::u8string icon ) -> void { m_SelectionIcon = std::move( icon ); }
		auto SetDropdownIcon( std::u8string icon ) -> void { m_DropdownIcon = std::move( icon ); }

		// Logical pixels, before DPI scaling. The popup also expands to fit its items.
		auto SetMinDropdownWidth( float width ) -> void { m_MinDropdownWidth = width; }
		auto SetSeparatorAfter( bool enabled ) -> void { m_SeparatorAfter = enabled; }

	private:
		int* m_Value;
		std::vector<std::string> m_Items;

		std::u8string m_SelectionIcon = u8"\uf00c";
		std::u8string m_DropdownIcon = u8"\uf0d7";

		float m_MinDropdownWidth = 256.f;
		bool m_SeparatorAfter;
	};
}
