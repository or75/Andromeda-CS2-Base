#include "CTollTip.hpp"

#include "../Core/CStyleManager.hpp"

namespace GitMenu
{
	auto CTollTip::Render( const char* szText , ImGuiHoveredFlags hoverFlags ) -> void
	{
		Render( szText , std::span<const ImGuiKeyChord>{} , hoverFlags );
	}

	auto CTollTip::Render( const char* szText , std::span<const ImGuiKeyChord> shortcut , ImGuiHoveredFlags hoverFlags ) -> void
	{
		if ( !szText || !szText[0] || !ImGui::IsItemHovered( hoverFlags ) )
			return;

		const auto scale = ImGui::GetFontSize() / ImGui::GetStyle().FontSizeBase;
		const auto& colors = GetStyleManager()->GetTooltipColors();

		ImGui::PushFont( nullptr , 14.f );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding , ImVec2( 8.f * scale , 6.f * scale ) );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowRounding , 6.f * scale );
		ImGui::PushStyleVar( ImGuiStyleVar_PopupBorderSize , 0.f );
		ImGui::PushStyleColor( ImGuiCol_PopupBg , colors.Background );
		ImGui::PushStyleColor( ImGuiCol_Text , colors.Text );

		if ( ImGui::BeginTooltip() )
		{
			ImGui::TextUnformatted( szText );
			const auto fnKeycap = [&]( const char* label )
			{
				ImGui::SameLine( 0.f , 4.f * scale );
				ImGui::PushFont( nullptr , 12.f );
				const auto textSize = ImGui::CalcTextSize( label );
				const auto size = ImVec2( ImMax( 14.f * scale , textSize.x + 6.f * scale ) , textSize.y + 2.f * scale );
				const auto position = ImGui::GetCursorScreenPos();
				ImGui::Dummy( size );
				auto* drawList = ImGui::GetWindowDrawList();
				drawList->AddRectFilled( position , ImVec2( position.x + size.x , position.y + size.y ) ,
					ImGui::GetColorU32( colors.KeyBackground ) , 3.f * scale );
				drawList->AddText( ImVec2( position.x + ( size.x - textSize.x ) * 0.5f , position.y + scale ) ,
					ImGui::GetColorU32( colors.KeyText ) , label );
				ImGui::PopFont();
			};
			for ( const auto chord : shortcut )
			{
				if ( chord & ImGuiMod_Ctrl ) fnKeycap( "Ctrl" );
				if ( chord & ImGuiMod_Alt ) fnKeycap( "Alt" );
				if ( chord & ImGuiMod_Shift ) fnKeycap( "Shift" );
				if ( chord & ImGuiMod_Super ) fnKeycap( "Super" );
				const auto key = static_cast<ImGuiKey>( chord & ~ImGuiMod_Mask_ );
				if ( key != ImGuiKey_None )
					fnKeycap( key == ImGuiKey_Slash ? "/" : ImGui::GetKeyName( key ) );
			}
			ImGui::EndTooltip();
		}

		ImGui::PopStyleColor( 2 );
		ImGui::PopStyleVar( 3 );
		ImGui::PopFont();
	}
}
