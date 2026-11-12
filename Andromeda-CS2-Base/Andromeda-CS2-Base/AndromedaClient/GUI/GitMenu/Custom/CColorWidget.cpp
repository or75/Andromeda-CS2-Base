#include "CColorWidget.hpp"

#include "../Core/CStyleManager.hpp"

namespace GitMenu
{
	CColorWidget::CColorWidget( const char* name , const char* description , ImVec4* value , bool separatorAfter )
		: IWidget( name ? name : "" , description ? description : "" )
		, m_Value( value )
		, m_SeparatorAfter( separatorAfter )
	{
	}

	auto CColorWidget::OnRenderImGui() -> void
	{
		const auto scale = GetStyleManager()->GetDpiScale();
		const auto& palette = GetStyleManager()->GetNavigationColors();
		auto* font = GetAndromedaGUI()->GetDefaultFont();

		ImGui::PushID( this );
		ImGui::BeginGroup();
		const auto rowPosition = ImGui::GetCursorScreenPos();
		const auto rowWidth = ImGui::GetContentRegionAvail().x;
		ImGui::PushFont( font , 14.f * scale );
		const auto colorSize = ImGui::GetFrameHeight();
		ImGui::PopFont();
		const auto textWidth = ImMax( 1.f , rowWidth - colorSize - ImGui::GetStyle().ItemSpacing.x );

		ImGui::BeginGroup();
		ImGui::PushStyleColor( ImGuiCol_Text , palette.Text );
		ImGui::PushTextWrapPos( ImGui::GetCursorPosX() + textWidth );

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
		ImGui::EndGroup();
		const auto rowHeight = ImMax( ImGui::GetItemRectSize().y , colorSize );
		ImGui::SetCursorScreenPos( ImVec2( rowPosition.x + ImMax( 0.f , rowWidth - colorSize ) , rowPosition.y + ( rowHeight - colorSize ) * 0.5f ) );
		ImGui::PushFont( font , 14.f * scale );

		auto color = m_Value ? *m_Value : ImVec4( 0.f , 0.f , 0.f , 1.f );
		
		if ( ImGui::ColorEdit4( "##Color" , &color.x , ImGuiColorEditFlags_NoInputs ) && m_Value )
			*m_Value = color;

		ImGui::PopFont();
		ImGui::PopStyleColor();
		ImGui::SetCursorScreenPos( rowPosition );
		ImGui::Dummy( ImVec2( ImMax( 0.f , rowWidth ) , rowHeight ) );

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
