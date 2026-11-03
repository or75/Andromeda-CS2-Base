#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

class CStyleManager final
{
public:
	enum class ETheme { Light, Dark };

	struct SNavigationColors
	{
		ImVec4 Background;
		ImVec4 Border;
		ImVec4 Muted;
		ImVec4 Text;
		ImVec4 Hovered;
		ImVec4 Active;
	};

	struct STooltipColors
	{
		ImVec4 Background;
		ImVec4 Text;
		ImVec4 KeyBackground;
		ImVec4 KeyText;
	};

	struct SDebugLogColors
	{
		ImVec4 Error;
		ImVec4 Info;
		ImVec4 Warning;
		ImVec4 Success;
	};

	auto ApplyLightTheme( float dpiScale ) -> void;
	auto ApplyDarkTheme( float dpiScale ) -> void;
	auto ApplyTheme( ETheme theme , float dpiScale ) -> void;

	// Color-only switching is safe inside a settings widget and preserves DPI/layout.
	auto SetTheme( ETheme theme ) -> void;
	auto GetTheme() const -> ETheme { return m_Theme; }
	auto SetDpiScale( float dpiScale ) -> void;
	auto GetDpiScale() const -> float { return m_flDpiScale; }

	// Apply queued layout changes before ImGui::NewFrame().
	auto ApplyPendingDpiScale() -> void;
	auto GetNavigationColors() const -> const SNavigationColors& { return m_NavigationColors; }
	auto GetTooltipColors() const -> const STooltipColors& { return m_TooltipColors; }
	auto GetDebugLogColors() const -> const SDebugLogColors& { return m_DebugLogColors; }

public:
	ImVec4 accentColor;

public:
	auto SetupColors() -> void;

private:
	ETheme m_Theme = ETheme::Light;
	float m_flDpiScale = 1.f;
	SNavigationColors m_NavigationColors{};
	STooltipColors m_TooltipColors{};
	SDebugLogColors m_DebugLogColors{};

	auto SetupDarkColors() -> void;
	auto SetupRounding() -> void;
	auto SetupPadding() -> void;
	auto SetupScaling( float dpiScale ) -> void;
	auto ApplyDpiScale( float dpiScale ) -> void;
};

auto GetStyleManager() -> CStyleManager*;
