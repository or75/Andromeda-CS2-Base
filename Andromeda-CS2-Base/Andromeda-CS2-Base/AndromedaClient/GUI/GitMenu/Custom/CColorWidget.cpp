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
		ImGui::PushStyleColor( ImGuiCol_Text , palette.Text );
		ImGui::PushTextWrapPos( ImGui::GetCursorPosX() + ImMax( 1.f , ImGui::GetContentRegionAvail().x ) );

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
		ImGui::BeginDisabled( !m_Value );
		ImGui::SetNextItemWidth( ImMax( 1.f , ImGui::GetContentRegionAvail().x ) );

		auto color = m_Value ? *m_Value : ImVec4( 0.f , 0.f , 0.f , 1.f );
		
		if ( ImGui::ColorEdit4( "##Color" , &color.x , ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreviewHalf ) && m_Value )
			*m_Value = color;

		ImGui::EndDisabled();
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
