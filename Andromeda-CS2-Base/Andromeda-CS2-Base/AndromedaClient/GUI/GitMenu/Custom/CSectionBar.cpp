#include "CSectionBar.hpp"

namespace GitMenu
{
    CSectionBar::CSectionBar( const char* szSectionName , ImVec2 SectionSize )
        : m_szSectionName( szSectionName )
        , m_SectionSize( SectionSize )
    {
    }

    auto CSectionBar::OnRenderImGui() -> void
    {
        const auto CursorScreenPos = ImGui::GetCursorScreenPos();

        ImGui::PushFont( GetAndromedaGUI()->GetDefaultFont() , CAndromedaGUI::m_DefaulFontSize + 2.f );
        const auto FontSize = ImGui::GetFontSize();
        const auto TextSize = ImGui::CalcTextSize( m_szSectionName );
        ImGui::PopFont();

        const auto Scale = FontSize / ( CAndromedaGUI::m_DefaulFontSize + 2.f );
        const auto TextPadding = m_SectionTextPadding * Scale;
        const auto ItemsPadding = m_SectionItemsPadding * Scale;

        auto SectionSize = m_SectionSize;
        const auto AvailableSize = ImGui::GetContentRegionAvail();

        SectionSize.x = ImMax( 1.f , SectionSize.x <= 0.f ? AvailableSize.x : ImMin( SectionSize.x , AvailableSize.x ) );

        if ( SectionSize.y <= 0.f )
        {
            if ( m_HasMeasured )
                SectionSize.y = m_AutoContentSize.y + TextSize.y + TextPadding.y + ItemsPadding.y * 2.f + ImGui::GetStyle().ItemSpacing.y;
            else
                SectionSize.y = ImGui::GetContentRegionAvail().y;
        }

        const auto HashId = std::string( "##section_bar_" ) + m_szSectionName;

        ImGui::BeginGroup();
        ImGui::InvisibleButton( HashId.c_str() , SectionSize );

        const auto BorderColor = ImGui::GetStyleColorVec4( ImGuiCol_Border );
        const auto Rounding = ImGui::GetStyle().WindowRounding;

        ImGui::GetWindowDrawList()->AddRect( CursorScreenPos , CursorScreenPos + SectionSize , ImGui::GetColorU32( BorderColor ) , Rounding );

        const auto HeaderFillMax = ImVec2( SectionSize.x , TextPadding.y ) + ImVec2( 0.f , ImGui::GetStyle().ItemSpacing.y * 2.f + TextSize.y );

        ImGui::GetWindowDrawList()->AddRectFilled( CursorScreenPos + ImVec2( 1.f , 1.f ) , CursorScreenPos + HeaderFillMax - ImVec2( 1.f , 3.f ) , ImGui::GetColorU32( ImGuiCol_TitleBgActive ) , Rounding , ImDrawFlags_RoundCornersTop );
        ImGui::GetWindowDrawList()->AddText( GetAndromedaGUI()->GetDefaultFont() , FontSize , CursorScreenPos + TextPadding - ImVec2( 0.f , ( ImGui::GetStyle().ItemSpacing.y * 2.f + TextSize.y ) / 2.f ) , ImGui::GetColorU32( ImGuiCol_Text ) , m_szSectionName );

        const auto HeaderLineStart = ImVec2( CursorScreenPos.x , CursorScreenPos.y + TextSize.y + TextPadding.y + ImGui::GetStyle().ItemSpacing.y );
        const auto HeaderLineEnd = ImVec2( CursorScreenPos.x + SectionSize.x , CursorScreenPos.y + TextSize.y + TextPadding.y + ImGui::GetStyle().ItemSpacing.y );

        ImGui::GetWindowDrawList()->AddLine( HeaderLineStart , HeaderLineEnd , ImGui::GetColorU32( BorderColor ) );

        ImGui::SetCursorScreenPos( ImVec2( CursorScreenPos.x + ItemsPadding.x , CursorScreenPos.y + TextSize.y + TextPadding.y + ItemsPadding.y ) );

        const auto ContentSize = ImVec2(
            ImMax( 1.f , SectionSize.x - ItemsPadding.x * 2.f ) ,
            ImMax( 1.f , SectionSize.y - TextSize.y - TextPadding.y - ItemsPadding.y * 2.f - ImGui::GetStyle().ItemSpacing.y ) );

        ImGui::BeginChild( m_szSectionName , ContentSize );

        ImGui::BeginGroup();

        for ( const auto& pWidget : m_Widgets )
        {
            if ( pWidget )
                pWidget->OnRenderImGui();
        }

        ImGui::EndGroup();

        // Cache the natural content size so the next frame can auto-fit any axis
        // that was left at 0.
        m_AutoContentSize = ImGui::GetItemRectSize();
        m_HasMeasured = true;

        ImGui::EndChild();
        ImGui::EndGroup();
    }

    auto CSectionBar::AddWidget( std::unique_ptr<IWidget> pWidget ) -> IWidget*
    {
        m_Widgets.push_back( std::move( pWidget ) );
        return m_Widgets.back().get();
    }
}
