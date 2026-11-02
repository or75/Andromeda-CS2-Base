#include "CComboBoxWidget.hpp"

#include "../Core/CStyleManager.hpp"

namespace GitMenu
{
	CComboBoxWidget::CComboBoxWidget( const char* name , const char* description , int* value , std::vector<std::string> items , bool separatorAfter )
		: IWidget( name ? name : "" , description ? description : "" )
		, m_Value( value )
		, m_Items( std::move( items ) )
		, m_SeparatorAfter( separatorAfter )
	{
	}

	auto CComboBoxWidget::OnRenderImGui() -> void
	{
		const auto scale = GetStyleManager()->GetDpiScale();
		const auto& palette = GetStyleManager()->GetNavigationColors();
		auto* font = GetAndromedaGUI()->GetDefaultFont();

		ImGui::PushID( this );
		ImGui::BeginGroup();
		ImGui::PushTextWrapPos( ImGui::GetCursorPosX() + ImMax( 1.f , ImGui::GetContentRegionAvail().x ) );
		ImGui::PushStyleColor( ImGuiCol_Text , palette.Text );

		if ( !m_Name.empty() )
		{
			ImGui::PushFont( font , 16.f * scale );
			ImGui::TextUnformatted( m_Name.c_str() );
			ImGui::PopFont();
		}

		if ( !m_Description.empty() )
		{
			ImGui::PushFont( font , 14.f * scale );
			ImGui::PushStyleColor( ImGuiCol_Text , palette.Muted );
			ImGui::TextUnformatted( m_Description.c_str() );
			ImGui::PopStyleColor();
			ImGui::PopFont();
		}

		ImGui::PopTextWrapPos();
		ImGui::PushFont( font , 14.f * scale );

		const auto drawIcon = [&]( ImDrawList* drawList , const std::u8string& icon , ImVec2 center )
		{
			auto* icons = GetAndromedaGUI()->GetFontAwesome7ProIcons();
			if ( !icons || icon.empty() )
				return;

			const auto* text = reinterpret_cast<const char*>( icon.c_str() );
			auto fontSize = CAndromedaGUI::m_IconsFontSize * scale;
			auto textSize = icons->CalcTextSizeA( fontSize , FLT_MAX , 0.f , text );
			if ( textSize.x <= 0.f || textSize.y <= 0.f )
				return;

			fontSize *= ImMin( 1.f , ImMin( 16.f * scale / textSize.x , 16.f * scale / textSize.y ) );
			textSize = icons->CalcTextSizeA( fontSize , FLT_MAX , 0.f , text );
			drawList->AddText( icons , fontSize , ImVec2( center.x - textSize.x * 0.5f , center.y - textSize.y * 0.5f ) , ImGui::GetColorU32( palette.Muted ) , text );
		};

		const auto validSelection = m_Value && *m_Value >= 0 && static_cast<size_t>( *m_Value ) < m_Items.size();
		const auto* preview = validSelection ? m_Items[*m_Value].c_str() : "Select...";
		const auto position = ImGui::GetCursorScreenPos();
		const auto width = ImMin( ImGui::CalcTextSize( preview ).x + 40.f * scale , ImMax( 1.f , ImGui::GetContentRegionAvail().x ) );
		const auto size = ImVec2( width , 28.f * scale );

		ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , scale );
		ImGui::PushStyleColor( ImGuiCol_Border , palette.Border );
		ImGui::PushStyleColor( ImGuiCol_ButtonHovered , palette.Hovered );
		ImGui::PushStyleColor( ImGuiCol_ButtonActive , palette.Active );
		ImGui::BeginDisabled( !m_Value || m_Items.empty() );

		const auto opening = ImGui::Button( "##ComboBox" , size );
		const auto anchor = ImRect( position , ImVec2( position.x + size.x , position.y + size.y ) );
		auto* drawList = ImGui::GetWindowDrawList();
		const auto textMin = ImVec2( position.x + 8.f * scale , position.y );
		const auto textMax = ImVec2( ImMax( textMin.x , anchor.Max.x - 28.f * scale ) , anchor.Max.y );
		drawList->PushClipRect( textMin , textMax , true );
		drawList->AddText( ImVec2( textMin.x , position.y + ( size.y - ImGui::GetFontSize() ) * 0.5f ) , ImGui::GetColorU32( palette.Text ) , preview );
		drawList->PopClipRect();
		drawIcon( drawList , m_DropdownIcon , ImVec2( anchor.Max.x - 14.f * scale , position.y + size.y * 0.5f ) );

		ImGui::EndDisabled();
		ImGui::PopStyleColor( 3 );
		ImGui::PopStyleVar();

		constexpr auto popupId = "##ComboBoxDropdown";
		if ( opening )
			ImGui::OpenPopup( popupId );

		if ( ImGui::IsPopupOpen( popupId ) )
		{
			const auto* viewport = ImGui::GetWindowViewport();
			const auto margin = 4.f * scale;
			auto popupWidth = ImMax( width , ImMax( 80.f , m_MinDropdownWidth ) * scale );
			for ( const auto& item : m_Items )
				popupWidth = ImMax( popupWidth , ImGui::CalcTextSize( item.c_str() ).x + 56.f * scale );

			popupWidth = ImMin( popupWidth , ImMax( 1.f , viewport->WorkSize.x - 2.f * margin ) );
			const auto popupHeight = ImMin( ( 16.f + 32.f * static_cast<float>( m_Items.size() ) ) * scale , ImMax( 1.f , viewport->WorkSize.y - 2.f * margin ) );
			auto popupPosition = ImVec2( anchor.Min.x , anchor.Max.y + margin );
			if ( popupPosition.y + popupHeight > viewport->WorkPos.y + viewport->WorkSize.y - margin )
				popupPosition.y = anchor.Min.y - popupHeight - margin;

			popupPosition.x = ImClamp( popupPosition.x , viewport->WorkPos.x + margin , viewport->WorkPos.x + viewport->WorkSize.x - popupWidth - margin );
			popupPosition.y = ImClamp( popupPosition.y , viewport->WorkPos.y + margin , viewport->WorkPos.y + viewport->WorkSize.y - popupHeight - margin );

			ImGui::SetNextWindowPos( popupPosition );
			ImGui::SetNextWindowSize( ImVec2( popupWidth , popupHeight ) );
			ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding , ImVec2( 8.f * scale , 8.f * scale ) );
			ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing , ImVec2( 0.f , 0.f ) );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , 0.f );
			ImGui::PushStyleVar( ImGuiStyleVar_PopupBorderSize , scale );
			ImGui::PushStyleColor( ImGuiCol_PopupBg , ImGui::GetStyleColorVec4( ImGuiCol_WindowBg ) );
			ImGui::PushStyleColor( ImGuiCol_Border , palette.Border );
			ImGui::PushStyleColor( ImGuiCol_Button , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
			ImGui::PushStyleColor( ImGuiCol_ButtonHovered , palette.Hovered );
			ImGui::PushStyleColor( ImGuiCol_ButtonActive , palette.Active );

			if ( ImGui::BeginPopup( popupId , ImGuiWindowFlags_NoMove ) )
			{
				ImGui::BeginDisabled( !m_Value || m_Items.empty() );
				for ( auto i = size_t{ 0 }; i < m_Items.size(); ++i )
				{
					ImGui::PushID( static_cast<int>( i ) );
					const auto rowPosition = ImGui::GetCursorScreenPos();
					const auto rowSize = ImVec2( ImGui::GetContentRegionAvail().x , 32.f * scale );
					const auto selected = m_Value && *m_Value == static_cast<int>( i );
					const auto pressed = ImGui::Button( "##Item" , rowSize );
					auto* rowDrawList = ImGui::GetWindowDrawList();
					if ( selected )
					{
						drawIcon( rowDrawList , m_SelectionIcon , ImVec2( rowPosition.x + 12.f * scale , rowPosition.y + 16.f * scale ) );
						if ( ImGui::IsWindowAppearing() )
							ImGui::SetScrollHereY();
						ImGui::SetItemDefaultFocus();
					}

					rowDrawList->PushClipRect( rowPosition , ImVec2( rowPosition.x + rowSize.x , rowPosition.y + rowSize.y ) , true );
					rowDrawList->AddText( ImVec2( rowPosition.x + 32.f * scale , rowPosition.y + ( rowSize.y - ImGui::GetFontSize() ) * 0.5f ) , ImGui::GetColorU32( palette.Text ) , m_Items[i].c_str() );
					rowDrawList->PopClipRect();
					ImGui::PopID();

					if ( pressed && m_Value )
					{
						*m_Value = static_cast<int>( i );
						ImGui::CloseCurrentPopup();
						break;
					}
				}
				ImGui::EndDisabled();
				ImGui::EndPopup();
			}

			ImGui::PopStyleColor( 5 );
			ImGui::PopStyleVar( 4 );
		}

		ImGui::PopFont();
		ImGui::PopStyleColor();

		if ( m_SeparatorAfter )
		{
			ImGui::Dummy( ImVec2( 0.f , 12.f * scale ) );
			ImGui::Separator();
			ImGui::Dummy( ImVec2( 0.f , 8.f * scale ) );
		}

		ImGui::EndGroup();
		ImGui::PopID();
	}
}
