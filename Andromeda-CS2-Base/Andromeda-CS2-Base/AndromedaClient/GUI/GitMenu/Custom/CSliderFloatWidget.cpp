#include "CSliderFloatWidget.hpp"

#include "../Core/CStyleManager.hpp"

namespace GitMenu
{
	CSliderFloatWidget::CSliderFloatWidget( const char* name , const char* description , float* value , float minValue , float maxValue , const char* format , bool separatorAfter )
		: IWidget( name ? name : "" , description ? description : "" )
		, m_Value( value )
		, m_MinValue( minValue )
		, m_MaxValue( maxValue )
		, m_Format( format ? format : "%.2f" )
		, m_SeparatorAfter( separatorAfter )
	{
	}

	auto CSliderFloatWidget::OnRenderImGui() -> void
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
		ImGui::BeginDisabled( !m_Value || m_MinValue >= m_MaxValue );
		ImGui::SetNextItemWidth( ImMax( 1.f , ImGui::GetContentRegionAvail().x ) );

		auto fallback = m_MinValue;
		ImGui::SliderFloat( "##Value" , m_Value ? m_Value : &fallback , m_MinValue , m_MaxValue , m_Format.c_str() , ImGuiSliderFlags_AlwaysClamp );

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
