#include "CSidebarItem.hpp"

#include "../Core/CStyleManager.hpp"

#include "CTollTip.hpp"

namespace GitMenu
{
	auto CSidebarItem::Render( const char* id , const char* displayName , ImTextureRef icon , bool bIsActive , float scale ) -> bool
	{
		const auto width = ImGui::GetContentRegionAvail().x;
		const auto height = 34.f * scale;
		const auto gutter = ImMin( 8.f * scale , width * 0.25f );

		const auto origin = ImGui::GetCursorScreenPos();
		const auto rowMin = ImVec2( origin.x + gutter , origin.y );
		const auto rowMax = ImVec2( origin.x + width - gutter , origin.y + height );

		if ( !id || !displayName || width <= 0.f )
			return false;

		ImGui::PushID( id );

		ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding , 6.f * scale );
		ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , 0.f );
		ImGui::PushStyleVar( ImGuiStyleVar_FramePadding , ImVec2( 0.f , 0.f ) );
		ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing , ImVec2( ImGui::GetStyle().ItemSpacing.x , 0.f ) );
		ImGui::PushStyleColor( ImGuiCol_Button , bIsActive ? ImGui::GetStyleColorVec4( ImGuiCol_Header ) : ImVec4( 0.f , 0.f , 0.f , 0.f ) );
		ImGui::PushStyleColor( ImGuiCol_ButtonHovered , bIsActive ? ImGui::GetStyleColorVec4( ImGuiCol_Header ) : ImGui::GetStyleColorVec4( ImGuiCol_HeaderHovered ) );
		ImGui::PushStyleColor( ImGuiCol_ButtonActive , ImGui::GetStyleColorVec4( ImGuiCol_HeaderActive ) );

		ImGui::SetCursorScreenPos( rowMin );

		const auto bPressed = ImGui::Button( "##Item" , ImVec2( rowMax.x - rowMin.x , height ) );

		ImGui::PopStyleColor( 3 );
		ImGui::PopStyleVar( 4 );

		if ( ImGui::IsItemVisible() )
		{
			auto* pDrawList = ImGui::GetWindowDrawList();

			if ( bIsActive )
			{
				pDrawList->AddRectFilled(
					ImVec2( origin.x , origin.y + 5.f * scale ) ,
					ImVec2( origin.x + 4.f * scale , origin.y + height - 5.f * scale ) ,
					ImGui::GetColorU32( ImGuiCol_CheckMark ) , 2.f * scale );
			}

			pDrawList->PushClipRect( rowMin , rowMax , true );

			const auto iconMin = ImVec2( rowMin.x + 8.f * scale , rowMin.y + ( height - 16.f * scale ) * 0.5f );
			const auto iconMax = ImVec2( iconMin.x + 16.f * scale , iconMin.y + 16.f * scale );

			if ( icon._TexData || icon._TexID != ImTextureID_Invalid )
			{
				pDrawList->AddImage( icon , iconMin , iconMax , ImVec2( 0.f , 0.f ) , ImVec2( 1.f , 1.f ) ,
					ImGui::GetColorU32( ImVec4( 1.f , 1.f , 1.f , 1.f ) ) );
			}
			else
			{
				const auto iconColor = ImGui::GetColorU32( ImGuiCol_TextDisabled );

				pDrawList->AddRect( ImVec2( iconMin.x + 3.f * scale , iconMin.y + scale ) ,
					ImVec2( iconMax.x - 3.f * scale , iconMax.y - scale ) , iconColor , 2.f * scale , 0 , 1.3f * scale );
				pDrawList->AddLine( ImVec2( iconMin.x + 6.f * scale , iconMin.y + 6.f * scale ) ,
					ImVec2( iconMax.x - 6.f * scale , iconMin.y + 6.f * scale ) , iconColor , scale );
				pDrawList->AddLine( ImVec2( iconMin.x + 6.f * scale , iconMin.y + 10.f * scale ) ,
					ImVec2( iconMax.x - 6.f * scale , iconMin.y + 10.f * scale ) , iconColor , scale );
			}

			ImGui::PushFont( GetAndromedaGUI()->GetDefaultFont() , CAndromedaGUI::m_DefaulFontSize + 2.f );
			const auto fontSize = ImGui::GetFontSize();
			const auto textSize = ImGui::CalcTextSize( displayName );
			ImGui::PopFont();

			const auto textPos = ImVec2( iconMax.x + 8.f * scale , rowMin.y + ( height - textSize.y ) * 0.5f );

			pDrawList->AddText( GetAndromedaGUI()->GetDefaultFont() , fontSize , textPos , ImGui::GetColorU32( ImGuiCol_Text ) , displayName );

			pDrawList->PopClipRect();

			if ( textPos.x + textSize.x > rowMax.x )
				CTollTip::Render( displayName );
		}

		ImGui::PopID();

		return bPressed;
	}
}
