#include "CStyleManager.hpp"

#include <ImGui/imgui_internal.h>

static auto g_StyleManager = CStyleManager{};

auto CStyleManager::ApplyLightTheme( float dpiScale ) -> void
{
	ApplyTheme( ETheme::Light , dpiScale );
}

auto CStyleManager::ApplyDarkTheme( float dpiScale ) -> void
{
	ApplyTheme( ETheme::Dark , dpiScale );
}

auto CStyleManager::ApplyTheme( ETheme theme , float dpiScale ) -> void
{
	accentColor = ImVec4( 0.06f , 0.45f , 0.86f , 1.f );
	m_Theme = theme;
	ApplyDpiScale( dpiScale );
}

auto CStyleManager::SetDpiScale( float dpiScale ) -> void
{
	m_flDpiScale = ImClamp( dpiScale , 0.5f , 3.f );
}

auto CStyleManager::ApplyPendingDpiScale() -> void
{
	if ( m_flDpiScale != ImGui::GetStyle().FontScaleDpi )
		ApplyDpiScale( m_flDpiScale );
}

auto CStyleManager::ApplyDpiScale( float dpiScale ) -> void
{
	auto& style = ImGui::GetStyle();

	const auto fontSizeBase = style.FontSizeBase;
	const auto fontScaleMain = style.FontScaleMain;
	const auto nextFrameFontSizeBase = style._NextFrameFontSizeBase;

	// Reset layout metrics to avoid compounding DPI, preserving LoadFonts settings.
	style = ImGuiStyle();

	style.FontSizeBase = fontSizeBase;
	style.FontScaleMain = fontScaleMain;
	style._NextFrameFontSizeBase = nextFrameFontSizeBase;

	SetupColors();
	SetupRounding();
	SetupPadding();
	SetupScaling( dpiScale );
}

auto CStyleManager::SetTheme( ETheme theme ) -> void
{
	m_Theme = theme;
	SetupColors();
}

auto CStyleManager::SetupColors() -> void
{
	if ( m_Theme == ETheme::Dark )
	{
		ImGui::StyleColorsDark();
		SetupDarkColors();
		return;
	}

	ImGui::StyleColorsLight();
	m_DebugLogColors = { ImColor( 190 , 35 , 45 ) , ImColor( 9 , 105 , 218 ) ,
		ImColor( 154 , 103 , 0 ) , ImColor( 26 , 127 , 55 ) };
	m_TooltipColors = { ImColor( 37 , 41 , 46 ) , ImColor( 255 , 255 , 255 ) ,
		ImColor( 101 , 109 , 118 ) , ImColor( 255 , 255 , 255 ) };

	m_NavigationColors = {
		ImColor( 246 , 248 , 250 ) , ImColor( 209 , 217 , 224 ) ,
		ImColor( 89 , 101 , 116 ) , ImColor( 31 , 35 , 40 ) ,
		ImColor( 236 , 238 , 240 ) , ImColor( 242 , 243 , 244 )
	};

	auto* colors = ImGui::GetStyle().Colors;

	const auto background = ImColor( 255 , 255 , 255 ).Value;
	const auto surface = ImColor( 246 , 248 , 250 ).Value;
	const auto hovered = ImColor( 236 , 238 , 240 ).Value;
	const auto active = ImColor( 224 , 228 , 232 ).Value;
	const auto border = ImColor( 209 , 217 , 224 ).Value;

	colors[ImGuiCol_Text] = m_NavigationColors.Text;
	colors[ImGuiCol_TextDisabled] = m_NavigationColors.Muted;
	colors[ImGuiCol_WindowBg] = background;
	colors[ImGuiCol_ChildBg] = ImVec4( 0.f , 0.f , 0.f , 0.f );
	colors[ImGuiCol_PopupBg] = surface;
	colors[ImGuiCol_Border] = border;
	colors[ImGuiCol_BorderShadow] = ImVec4( 0.f , 0.f , 0.f , 0.f );
	colors[ImGuiCol_FrameBg] = surface;
	colors[ImGuiCol_FrameBgHovered] = hovered;
	colors[ImGuiCol_FrameBgActive] = active;
	colors[ImGuiCol_TitleBg] = m_NavigationColors.Background;
	colors[ImGuiCol_TitleBgActive] = surface;
	colors[ImGuiCol_TitleBgCollapsed] = background;
	colors[ImGuiCol_MenuBarBg] = m_NavigationColors.Background;
	colors[ImGuiCol_ScrollbarBg] = background;
	colors[ImGuiCol_ScrollbarGrab] = active;
	colors[ImGuiCol_ScrollbarGrabHovered] = border;
	colors[ImGuiCol_ScrollbarGrabActive] = m_NavigationColors.Muted;
	colors[ImGuiCol_CheckMark] = accentColor;
	colors[ImGuiCol_SliderGrab] = accentColor;
	colors[ImGuiCol_SliderGrabActive] = accentColor;
	colors[ImGuiCol_Button] = surface;
	colors[ImGuiCol_ButtonHovered] = hovered;
	colors[ImGuiCol_ButtonActive] = active;
	colors[ImGuiCol_Header] = hovered;
	colors[ImGuiCol_HeaderHovered] = active;
	colors[ImGuiCol_HeaderActive] = border;
	colors[ImGuiCol_Separator] = border;
	colors[ImGuiCol_SeparatorHovered] = accentColor;
	colors[ImGuiCol_SeparatorActive] = accentColor;
	colors[ImGuiCol_ResizeGrip] = active;
	colors[ImGuiCol_ResizeGripHovered] = border;
	colors[ImGuiCol_ResizeGripActive] = accentColor;
	colors[ImGuiCol_Tab] = surface;
	colors[ImGuiCol_TabHovered] = hovered;
	colors[ImGuiCol_TabActive] = active;
	colors[ImGuiCol_TabUnfocused] = background;
	colors[ImGuiCol_TabUnfocusedActive] = surface;
}

auto CStyleManager::SetupDarkColors() -> void
{
	m_DebugLogColors = { ImColor( 255 , 123 , 114 ) , ImColor( 88 , 166 , 255 ) ,
		ImColor( 227 , 179 , 65 ) , ImColor( 63 , 185 , 80 ) };
	m_TooltipColors = { ImColor( 61 , 68 , 77 ) , ImColor( 240 , 246 , 252 ) ,
		ImColor( 101 , 109 , 118 ) , ImColor( 240 , 246 , 252 ) };

	// GitHub dark palette; navigation uses the near-black header from the reference.
	m_NavigationColors = {
		ImColor( 1 , 4 , 9 ) , ImColor( 61 , 68 , 77 ) ,
		ImColor( 145 , 152 , 161 ) , ImColor( 240 , 246 , 252 ) ,
		ImColor( 21 , 27 , 35 ) , ImColor( 33 , 40 , 48 )
	};

	auto* colors = ImGui::GetStyle().Colors;

	const auto background = ImColor( 13 , 17 , 23 ).Value;
	const auto surface = ImColor( 21 , 27 , 35 ).Value;
	const auto hovered = ImColor( 33 , 40 , 48 ).Value;
	const auto active = ImColor( 48 , 54 , 61 ).Value;
	const auto border = ImColor( 61 , 68 , 77 ).Value;

	colors[ImGuiCol_Text] = m_NavigationColors.Text;
	colors[ImGuiCol_TextDisabled] = m_NavigationColors.Muted;
	colors[ImGuiCol_WindowBg] = background;
	colors[ImGuiCol_ChildBg] = ImVec4( 0.f , 0.f , 0.f , 0.f );
	colors[ImGuiCol_PopupBg] = surface;
	colors[ImGuiCol_Border] = border;
	colors[ImGuiCol_BorderShadow] = ImVec4( 0.f , 0.f , 0.f , 0.f );
	colors[ImGuiCol_FrameBg] = surface;
	colors[ImGuiCol_FrameBgHovered] = hovered;
	colors[ImGuiCol_FrameBgActive] = active;
	colors[ImGuiCol_TitleBg] = m_NavigationColors.Background;
	colors[ImGuiCol_TitleBgActive] = surface;
	colors[ImGuiCol_TitleBgCollapsed] = background;
	colors[ImGuiCol_MenuBarBg] = m_NavigationColors.Background;
	colors[ImGuiCol_ScrollbarBg] = background;
	colors[ImGuiCol_ScrollbarGrab] = active;
	colors[ImGuiCol_ScrollbarGrabHovered] = border;
	colors[ImGuiCol_ScrollbarGrabActive] = m_NavigationColors.Muted;
	colors[ImGuiCol_CheckMark] = accentColor;
	colors[ImGuiCol_SliderGrab] = accentColor;
	colors[ImGuiCol_SliderGrabActive] = accentColor;
	colors[ImGuiCol_Button] = surface;
	colors[ImGuiCol_ButtonHovered] = hovered;
	colors[ImGuiCol_ButtonActive] = active;
	colors[ImGuiCol_Header] = hovered;
	colors[ImGuiCol_HeaderHovered] = active;
	colors[ImGuiCol_HeaderActive] = border;
	colors[ImGuiCol_Separator] = border;
	colors[ImGuiCol_SeparatorHovered] = accentColor;
	colors[ImGuiCol_SeparatorActive] = accentColor;
	colors[ImGuiCol_ResizeGrip] = active;
	colors[ImGuiCol_ResizeGripHovered] = border;
	colors[ImGuiCol_ResizeGripActive] = accentColor;
	colors[ImGuiCol_Tab] = surface;
	colors[ImGuiCol_TabHovered] = hovered;
	colors[ImGuiCol_TabActive] = active;
	colors[ImGuiCol_TabUnfocused] = background;
	colors[ImGuiCol_TabUnfocusedActive] = surface;
}

auto CStyleManager::SetupRounding() -> void
{
	auto& style = ImGui::GetStyle();

	style.FrameRounding = 5.0f;
	style.GrabRounding = 10.0f;
	style.WindowRounding = 10.0f;
	style.ScrollbarRounding = 10.0f;
	style.ChildRounding = 10.0f;
	style.PopupRounding = 10.0f;
}

auto CStyleManager::SetupPadding() -> void
{
	auto& style = ImGui::GetStyle();

	style.FrameBorderSize = 1.0f;
	style.FramePadding = ImVec2( 4.0f , 4.0f );
}

auto CStyleManager::SetupScaling( float dpiScale ) -> void
{
	auto& style = ImGui::GetStyle();

	style.ScaleAllSizes( dpiScale );
	// ScaleAllSizes truncates MouseCursorScale to an integer (zero below 1x).
	style.MouseCursorScale = dpiScale;
	style.FontScaleDpi = dpiScale;

	m_flDpiScale = dpiScale;
}

auto GetStyleManager() -> CStyleManager*
{
	return &g_StyleManager;
}
