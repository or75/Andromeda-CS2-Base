#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

#include "Resources/ResourceCatalog.hpp"

#include <functional>
#include <string>
#include <vector>

class CNavigationBar final
{
public:
	enum class EIcon
	{
		Menu, Search, History, Chevron, Plus, None
	};

	enum class EAction
	{
		None,
		Home,
		CreateScript,
		CreateConfig,
		CreateDropdown ,
		Profile,
	};

	struct SIcon
	{
		EIcon   DefaulIcon = EIcon::None;

		ImVec2  ImageSize = ImVec2( 32.f , 32.f );
		ImVec2  Uv0 = ImVec2( 0.f , 0.f );
		ImVec2  Uv1 = ImVec2( 1.f , 1.f );
		ImVec4  Tint = ImVec4( 1.f , 1.f , 1.f , 1.f );

		// Resolved through CResourceManager each frame; Count means no resource.
		EResource Resource = EResource::Count;
	};

	struct SMenuItem
	{
		std::string Text;
		SIcon Icon;
		EAction Action = EAction::None;

		std::function<void()> OnClick;

		bool Enabled = true;
		bool Separator = false;

		static auto MakeSeparator() -> SMenuItem { auto item = SMenuItem{}; item.Separator = true; return item; }
	};

	struct SDropdown
	{
		std::vector<SMenuItem> Items;
		float MinWidth = 192.f;
	};

	struct SButton
	{
		std::string Id;
		std::string Tooltip;

		std::vector<ImGuiKeyChord> Shortcut;
		std::function<void()> OnClick;

		ImVec2 Size = ImVec2( 32.f , 32.f );

		SIcon Icon;
		SIcon DropdownIcon = { EIcon::Chevron };

		float   GapAfter = 8.f;
		float   MinBarWidth = 0.f;

		bool    Visible = true;
		bool    Enabled = true;
		bool    Round = false;
		bool    Dropdown = false;
		bool    SeparatorAfter = false;

		EAction Action = EAction::None;
		SDropdown Menu;
	};

	CNavigationBar();

	auto OnRender() -> void;

	// IDs are unique; an invalid/duplicate ID or missing insertion target returns false.
	// Registration and changes belong in setup code or OnClick, not in image providers.
	auto AddButton( SButton button , const char* beforeId = nullptr ) -> bool;
	auto RemoveButton( const char* id ) -> bool;
	auto FindButton( const char* id ) -> SButton*;
	auto ClearButtons() -> void { m_Buttons.clear(); }

	// Search/history share the same icon description as buttons. Textures are not owned.
	auto SetSearchIcon( SIcon icon ) -> void;
	auto SetHistoryIcon( SIcon icon ) -> void;
	auto SetHomeShortcut( std::vector<ImGuiKeyChord> shortcut ) -> void;

	// Opens the dropdown bound to this action; otherwise emits the action as usual.
	auto TriggerAction( EAction action ) -> void;

	auto IsMenuToggled() const -> bool { return m_bMenuToggled; }
	auto ResetMenuToggle() -> void { m_bMenuToggled = false; }

	auto GetSearchQuery() const -> const char* { return m_InputSearchBuffer; }

	auto ConsumeAction() -> EAction
	{
		const auto action = m_PendingAction;
		m_PendingAction = EAction::None;

		return action;
	}

private:
	auto AddDefaultButton( const char* id , const char* tooltip , SIcon& icon , EAction action , float minWidth , std::vector<ImGuiKeyChord> shortcut = {} , SDropdown menu = {} ) -> SButton&;
	auto DrawIcon( ImDrawList* drawList , const SIcon& icon , ImVec2 center , float scale , ImVec2 maxSize = ImVec2( FLT_MAX , FLT_MAX ) , bool round = false ) const -> void;
	auto RenderButton( const SButton& button , ImVec2 position , float scale ) -> bool;
	auto RenderSearch( ImVec2 position , float width , float scale ) -> void;
	auto RenderSearchPopup( ImVec2 position , float width , float scale ) -> void;
	auto RememberSearch() -> void;
	auto HandleShortcuts( std::function<void()>& onClick ) -> void;
	auto ActivateButton( const SButton& button , std::function<void()>& onClick ) -> void;
	auto RenderDropdown( ImVec2 fallbackPosition , float scale , std::function<void()>& onClick ) -> void;

	struct SDropdownAnchor { std::string ButtonId; ImRect Bounds; };

	std::vector<SDropdownAnchor> m_DropdownAnchors;

	std::string m_RequestedDropdown;
	std::string m_ActiveDropdown;

	std::vector<SButton> m_Buttons;
	SButton              m_MenuButton;
	SIcon                m_SearchIcon{ EIcon::Search };
	SIcon                m_HistoryIcon{ EIcon::History };
	std::vector<ImGuiKeyChord> m_HomeShortcut{ ImGuiKey_G , ImGuiKey_D };
	std::vector<ImGuiKeyChord> m_ShortcutPrefix;
	double               m_flLastShortcutTime = 0.;
	char                 m_InputSearchBuffer[256] = { 0 };
	std::vector<std::string> m_RecentSearches;
	float                m_flSearchOpenTime = 0.f;
	bool                 m_bOpenSearchRequested = false;
	bool                 m_bSearchWasOpen = false;
	bool                 m_bMenuToggled = false;
	EAction              m_PendingAction = EAction::None;
};
