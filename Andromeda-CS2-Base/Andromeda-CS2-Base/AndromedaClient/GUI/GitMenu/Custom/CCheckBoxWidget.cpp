#include "CCheckBoxWidget.hpp"

#include "../Core/CStyleManager.hpp"

#include <ImGui/im_anim.h>

namespace GitMenu
{
	CCheckBoxWidget::CCheckBoxWidget( const char* name , const char* description , bool* value , bool separatorAfter )
		: IWidget( name ? name : "" , description ? description : "" )
		, m_Value( value )
		, m_SeparatorAfter( separatorAfter )
	{
	}

	auto CCheckBoxWidget::OnRenderImGui() -> void
	{
		const auto scale = GetStyleManager()->GetDpiScale();
		const auto& palette = GetStyleManager()->GetNavigationColors();
		auto* font = GetAndromedaGUI()->GetDefaultFont();

		ImGui::PushID( this );
		ImGui::BeginGroup();
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
		ImGui::BeginDisabled( !m_Value );

		const auto animationId = ImGui::GetID( "##ToggleAnimation" );
		const auto ease = iam_ease_preset( iam_ease_out_cubic );
		const auto deltaTime = ImGui::GetIO().DeltaTime;

		if ( !m_AnimationInitialized )
		{
			iam_tween_float( animationId , 0 , m_Value && *m_Value ? 1.f : 0.f , 0.f , ease , iam_policy_cut , deltaTime );
			m_AnimationInitialized = true;
		}

		const auto position = ImGui::GetCursorScreenPos();
		const auto size = ImVec2( 48.f * scale , 24.f * scale );

		ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding , 6.f * scale );

		if ( ImGui::Button( "##Toggle" , size ) && m_Value )
			*m_Value = !*m_Value;

		ImGui::PopStyleVar();

		const auto enabled = m_Value && *m_Value;
		const auto progress = ImClamp( iam_tween_float( animationId , 0 , enabled ? 1.f : 0.f , m_ToggleDuration , ease , iam_policy_crossfade , deltaTime ) , 0.f , 1.f );
		const auto backgroundOff = ImGui::GetStyleColorVec4( ImGui::IsItemHovered() ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg );
		const auto background = ImLerp( backgroundOff , ImGui::GetStyleColorVec4( ImGuiCol_CheckMark ) , progress );

		auto* drawList = ImGui::GetWindowDrawList();

		drawList->AddRectFilled( position , position + size , ImGui::GetColorU32( background ) , 6.f * scale );
		drawList->AddRect( position , position + size , ImGui::GetColorU32( ImLerp( palette.Border , background , progress ) ) , 6.f * scale );

		drawList->AddLine( position + ImVec2( 12.f * scale , 7.f * scale ) , position + ImVec2( 12.f * scale , 17.f * scale ) , ImGui::GetColorU32( ImVec4( 1.f , 1.f , 1.f , progress ) ) , scale );
		
		auto offColor = palette.Muted;
		offColor.w *= 1.f - progress;
		
		drawList->AddCircle( position + ImVec2( 36.f * scale , 12.f * scale ) , 4.f * scale , ImGui::GetColorU32( offColor ) , 16 , scale );

		const auto thumbMin = position + ImVec2( ImLerp( 3.f , 25.f , progress ) * scale , 3.f * scale );
		const auto thumbMax = thumbMin + ImVec2( 20.f * scale , 18.f * scale );

		drawList->AddRectFilled( thumbMin , thumbMax , ImGui::GetColorU32( ImVec4( 1.f , 1.f , 1.f , 1.f ) ) , 3.f * scale );
		
		auto thumbBorder = palette.Border;
		
		thumbBorder.w *= 1.f - progress;
		drawList->AddRect( thumbMin , thumbMax , ImGui::GetColorU32( thumbBorder ) , 3.f * scale );

		ImGui::SameLine( 0.f , 8.f * scale );	
		ImGui::PushFont( font , 12.f * scale );
		
		const auto* label = enabled ? "On" : "Off";
		const auto labelSize = ImGui::CalcTextSize( label );
		const auto labelPosition = ImVec2( ImGui::GetCursorScreenPos().x , position.y + ( size.y - labelSize.y ) * 0.5f );
		
		ImGui::Dummy( ImVec2( labelSize.x , size.y ) );
		
		drawList->AddText( ImGui::GetFont() , ImGui::GetFontSize() , labelPosition , ImGui::GetColorU32( ImGuiCol_Text ) , label );
		
		ImGui::PopFont();	
		ImGui::EndDisabled();

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
