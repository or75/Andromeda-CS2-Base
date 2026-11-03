#include "CDebugPage.hpp"

#include "../Custom/CSectionBar.hpp"
#include "../Core/CStyleManager.hpp"

#include <string_view>

namespace
{
	class CDebugLogWidget final : public GitMenu::IWidget
	{
	public:
		CDebugLogWidget() : IWidget( "Log output" , "Select and copy logs. Filter by text." ) {}

		auto OnRenderImGui() -> void override
		{
			const auto source = GetDevLog()->GetBuffer();
			const auto changed = source != m_Source || m_FilterChanged;
			
			if ( changed )
			{
				m_Source = source;
				RebuildText();
				m_FilterChanged = false;
			}

			ImGui::PushID( this );

			auto* parent = ImGui::GetCurrentWindow();
			
			const auto id = parent->GetID( "##log_output" );
			const auto editorHeight = ImMax( 1.f , ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeight() - ImGui::GetStyle().ItemSpacing.y );
			
			// Native read-only editing provides mouse/keyboard selection and clipboard
			// support. Draw the text ourselves to color individual severity prefixes.
			ImGui::PushStyleColor( ImGuiCol_Text , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
			ImGui::InputTextMultiline( "##log_output" , m_Text.data() , m_Text.size() + 1 , ImVec2( -1.f , editorHeight ) , ImGuiInputTextFlags_ReadOnly );
			ImGui::PopStyleColor();

			for ( auto* child : parent->DC.ChildWindows )
			{
				if ( child->ChildId != id || !child->Active || child->SkipItems )
					continue;

				RenderText( child , id );
				
				if ( changed && !ImGui::IsItemActive() && child->Scroll.y >= child->ScrollMax.y - 1.f )
					ImGui::SetScrollY( child , static_cast<float>( m_Lines.size() ) * ImGui::GetFontSize() );
				
				break;
			}

			ImGui::SetNextItemWidth( -1.f );
			m_FilterChanged = ImGui::InputTextWithHint( "##log_filter" , "Filter logs..." , m_Filter , sizeof( m_Filter ) );
			ImGui::PopID();
		}

	private:
		auto RebuildText() -> void
		{
			m_Text.clear();
			m_Lines.clear();
			
			const auto source = std::string_view( m_Source );
			
			for ( auto start = size_t{ 0 }; start < source.size(); )
			{
				const auto newline = source.find( '\n' , start );
				const auto end = newline == std::string_view::npos ? source.size() : newline;
				
				auto line = source.substr( start , end - start );
				
				if ( !line.empty() && line.back() == '\r' )
					line.remove_suffix( 1 );

				if ( m_Filter[0] == '\0' || ImStristr( line.data() , line.data() + line.size() , m_Filter , nullptr ) )
				{
					m_Lines.push_back( m_Text.size() );
					m_Text.append( line );
					
					if ( newline != std::string_view::npos )
						m_Text.push_back( '\n' );
				}
				
				start = newline == std::string_view::npos ? source.size() : newline + 1;
			}
		}

		auto RenderText( ImGuiWindow* child , ImGuiID id ) -> void
		{
			const auto fontSize = ImGui::GetFontSize();
			auto origin = child->DC.CursorStartPos + ImGui::GetStyle().FramePadding;
			
			if ( const auto* state = ImGui::GetInputTextState( id ); state && ImGui::GetActiveID() == id )
				origin.x -= state->Scroll.x;

			const auto& colors = GetStyleManager()->GetDebugLogColors();
			const auto textColor = ImGui::GetColorU32( ImGuiCol_Text );
			const auto firstLine = ImMax( 0 , static_cast<int>( ( child->ClipRect.Min.y - origin.y ) / fontSize ) );
			const auto lastLine = ImMin( static_cast<int>( m_Lines.size() ) , static_cast<int>( ( child->ClipRect.Max.y - origin.y ) / fontSize ) + 1 );
			
			child->DrawList->PushClipRect( child->ClipRect.Min , child->ClipRect.Max , true );
			
			for ( auto index = firstLine; index < lastLine; ++index )
			{
				const auto start = m_Lines[index];
				const auto end = m_Text.find( '\n' , start );
				const auto line = std::string_view( m_Text ).substr( start , end == std::string::npos ? m_Text.size() - start : end - start );
				
				auto prefixSize = size_t{ 0 };
				auto prefixColor = textColor;
				
				if ( line.starts_with( GitMenu::CDebugPage::ErrorPrefix ) ) { prefixSize = GitMenu::CDebugPage::ErrorPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Error ); }
				else if ( line.starts_with( GitMenu::CDebugPage::MinusPrefix ) ) { prefixSize = GitMenu::CDebugPage::MinusPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Info ); }
				else if ( line.starts_with( GitMenu::CDebugPage::InfoPrefix ) ) { prefixSize = GitMenu::CDebugPage::InfoPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Info ); }
				else if ( line.starts_with( GitMenu::CDebugPage::DebugPrefix ) ) { prefixSize = GitMenu::CDebugPage::DebugPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Info ); }
				else if ( line.starts_with( GitMenu::CDebugPage::WarningPrefix ) ) { prefixSize = GitMenu::CDebugPage::WarningPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Warning ); }
				else if ( line.starts_with( GitMenu::CDebugPage::SuccessPrefix ) ) { prefixSize = GitMenu::CDebugPage::SuccessPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Success ); }
				else if ( line.starts_with( GitMenu::CDebugPage::PlusPrefix ) ) { prefixSize = GitMenu::CDebugPage::PlusPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Success ); }

				auto position = ImVec2( origin.x , origin.y + index * fontSize );
				
				if ( prefixSize > 0 )
				{
					child->DrawList->AddText( position , prefixColor , line.data() , line.data() + prefixSize );
					position.x += ImGui::CalcTextSize( line.data() , line.data() + prefixSize ).x;
				}
				
				child->DrawList->AddText( position , textColor , line.data() + prefixSize , line.data() + line.size() );
			}

			child->DrawList->PopClipRect();
		}

		char m_Filter[256]{};
		bool m_FilterChanged = true;

		std::string m_Source;
		std::string m_Text;

		std::vector<size_t> m_Lines;
	};
}

namespace GitMenu
{
	CDebugLogsSubPage::CDebugLogsSubPage()
	{
		auto section = std::make_unique<CSectionBar>( "Debug Logs" , ImVec2( 0.f , 0.f ) );

		section->AddTag( "debug" );
		section->AddTag( "logs" );

		section->AddWidget( std::make_unique<CDebugLogWidget>() );

		AddWidget( std::move( section ) );
	}
}
