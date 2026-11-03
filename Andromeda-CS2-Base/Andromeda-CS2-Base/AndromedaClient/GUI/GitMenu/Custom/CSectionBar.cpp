#include "CSectionBar.hpp"

namespace GitMenu
{
    CSectionBar::CSectionBar( const char* szSectionName , ImVec2 SectionSize )
        : IWidget( szSectionName ? szSectionName : "" )
        , m_szSectionName( szSectionName )
        , m_SectionSize( SectionSize )
    {
    }

    auto CSectionBar::OnRenderImGui() -> void
    {
        const auto CursorScreenPos = ImGui::GetCursorScreenPos();
        const auto HasHeader = m_szSectionName && m_szSectionName[0] != '\0';

        ImGui::PushFont( GetAndromedaGUI()->GetDefaultFont() , CAndromedaGUI::m_DefaulFontSize + 2.f );
        const auto FontSize = ImGui::GetFontSize();
        const auto TextSize = HasHeader ? ImGui::CalcTextSize( m_szSectionName ) : ImVec2( 0.f , 0.f );
        ImGui::PopFont();

        const auto Scale = FontSize / ( CAndromedaGUI::m_DefaulFontSize + 2.f );
        const auto TextPadding = m_SectionTextPadding * Scale;
        const auto ItemsPadding = m_SectionItemsPadding * Scale;
        const auto HeaderHeight = HasHeader ? TextSize.y + TextPadding.y : 0.f;
        const auto HeaderSpacing = HasHeader ? ImGui::GetStyle().ItemSpacing.y : 0.f;

        auto SectionSize = m_SectionSize;
        const auto AvailableSize = ImGui::GetContentRegionAvail();

        SectionSize.x = ImMax( 1.f , SectionSize.x <= 0.f ? AvailableSize.x : ImMin( SectionSize.x , AvailableSize.x ) );

        if ( SectionSize.y == 0.f )
            SectionSize.y = ImMax( 1.f , AvailableSize.y );
        else if ( SectionSize.y < 0.f )
        {
            if ( m_HasMeasured )
                SectionSize.y = m_AutoContentSize.y + HeaderHeight + ItemsPadding.y * 2.f + HeaderSpacing;
            else
                SectionSize.y = ImMax( 1.f , AvailableSize.y );
        }

        ImGui::PushID( this );
        ImGui::BeginGroup();
        ImGui::InvisibleButton( "##section_bar" , SectionSize );

        const auto BorderColor = ImGui::GetStyleColorVec4( ImGuiCol_Border );
        const auto Rounding = ImGui::GetStyle().WindowRounding;

        ImGui::GetWindowDrawList()->AddRect( CursorScreenPos , CursorScreenPos + SectionSize , ImGui::GetColorU32( BorderColor ) , Rounding );

        if ( HasHeader )
        {
            const auto HeaderFillMax = ImVec2( SectionSize.x , TextPadding.y ) + ImVec2( 0.f , ImGui::GetStyle().ItemSpacing.y * 2.f + TextSize.y );

            ImGui::GetWindowDrawList()->AddRectFilled( CursorScreenPos + ImVec2( 1.f , 1.f ) , CursorScreenPos + HeaderFillMax - ImVec2( 1.f , 3.f ) , ImGui::GetColorU32( ImGuiCol_TitleBgActive ) , Rounding , ImDrawFlags_RoundCornersTop );
            ImGui::GetWindowDrawList()->AddText( GetAndromedaGUI()->GetDefaultFont() , FontSize , CursorScreenPos + TextPadding - ImVec2( 0.f , ( ImGui::GetStyle().ItemSpacing.y * 2.f + TextSize.y ) / 2.f ) , ImGui::GetColorU32( ImGuiCol_Text ) , m_szSectionName );

            const auto HeaderLineStart = ImVec2( CursorScreenPos.x , CursorScreenPos.y + TextSize.y + TextPadding.y + ImGui::GetStyle().ItemSpacing.y );
            const auto HeaderLineEnd = ImVec2( CursorScreenPos.x + SectionSize.x , CursorScreenPos.y + TextSize.y + TextPadding.y + ImGui::GetStyle().ItemSpacing.y );

            ImGui::GetWindowDrawList()->AddLine( HeaderLineStart , HeaderLineEnd , ImGui::GetColorU32( BorderColor ) );
        }

        ImGui::SetCursorScreenPos( ImVec2( CursorScreenPos.x + ItemsPadding.x , CursorScreenPos.y + HeaderHeight + ItemsPadding.y ) );

        const auto ContentSize = ImVec2(
            ImMax( 1.f , SectionSize.x - ItemsPadding.x * 2.f ) ,
            ImMax( 1.f , SectionSize.y - HeaderHeight - ItemsPadding.y * 2.f - HeaderSpacing ) );

        const auto AutoHeight = m_SectionSize.y < 0.f;
        const auto NeedsMeasurement = !m_HasMeasured || m_MeasuredWidth != SectionSize.x || m_MeasuredScale != Scale;
        
        // Measure automatic sections before they first enter the viewport, and
        // again after width/DPI changes. Otherwise retain normal child clipping.
        const auto ChildFlags = AutoHeight && NeedsMeasurement
            ? ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_AlwaysAutoResize
            : ImGuiChildFlags_None;
        
        const auto WindowFlags = AutoHeight
            ? ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse
            : ImGuiWindowFlags_None;
       
        const auto ChildSize = ImVec2( ContentSize.x , AutoHeight && NeedsMeasurement ? 0.f : ContentSize.y );

        if ( ImGui::BeginChild( "##content" , ChildSize , ChildFlags , WindowFlags ) )
        {
            ImGui::BeginGroup();

            for ( const auto& pWidget : m_Widgets )
            {
                if ( pWidget )
                    pWidget->OnRenderImGui();
            }

            ImGui::EndGroup();

            // A clipped child skips layout; keep its last valid measurement.
            m_AutoContentSize = ImGui::GetItemRectSize();
            m_HasMeasured = true;
            m_MeasuredWidth = SectionSize.x;
            m_MeasuredScale = Scale;
        }

        ImGui::EndChild();
        ImGui::EndGroup();
        ImGui::PopID();
    }

    auto CSectionBar::AddWidget( std::unique_ptr<IWidget> pWidget ) -> IWidget*
    {
        m_Widgets.push_back( std::move( pWidget ) );
        m_HasMeasured = false;
        return m_Widgets.back().get();
    }
}
