#include "CNavigationBar.hpp"
#include "Custom/CTollTip.hpp"

#include "Core/CResourceManager.hpp"
#include "Core/CStyleManager.hpp"

#include <algorithm>
#include <utility>

auto CNavigationBar::SetSearchIcon( SIcon icon ) -> void
{
	m_SearchIcon = std::move( icon );
}

auto CNavigationBar::SetHistoryIcon( SIcon icon ) -> void
{
	m_HistoryIcon = std::move( icon );
}

auto CNavigationBar::DrawIcon( ImDrawList* drawList , const SIcon& icon , ImVec2 center , float scale , ImVec2 maxSize , bool round ) const -> void
{
	const auto texture = icon.Resource != EResource::Count ? GetResourceManager()->GetTexture( icon.Resource ) : ImTextureID_Invalid;

	if ( texture._TexData || texture._TexID != ImTextureID_Invalid )
	{
		const auto size = ImVec2( ImClamp( icon.ImageSize.x * scale , 0.f , maxSize.x ) , ImClamp( icon.ImageSize.y * scale , 0.f , maxSize.y ) );

		const auto imageMin = ImVec2( center.x - size.x * 0.5f , center.y - size.y * 0.5f );
		const auto imageMax = ImVec2( imageMin.x + size.x , imageMin.y + size.y );

		drawList->AddImageRounded( texture , imageMin , imageMax , icon.Uv0 , icon.Uv1 , ImGui::GetColorU32( icon.Tint ) , round ? ImMin( size.x , size.y ) * 0.5f : 0.f );
	}
	else if ( auto* font = GetAndromedaGUI()->GetFontAwesome7ProIcons(); font && icon.AwesomeIcon && icon.AwesomeIcon[0] != u8'\0' )
	{
		const auto* text = reinterpret_cast<const char*>( icon.AwesomeIcon );

		auto fontSize = CAndromedaGUI::m_IconsFontSize * scale;

		if ( fontSize <= 0.f )
			return;

		auto textSize = font->CalcTextSizeA( fontSize , FLT_MAX , 0.f , text );

		const auto size = ImVec2( ImClamp( icon.ImageSize.x * scale , 0.f , maxSize.x ) , ImClamp( icon.ImageSize.y * scale , 0.f , maxSize.y ) );

		if ( textSize.x <= 0.f || textSize.y <= 0.f || size.x <= 0.f || size.y <= 0.f )
			return;

		const auto fit = ImMin( 1.f , ImMin( size.x / textSize.x , size.y / textSize.y ) );

		fontSize *= fit;
		textSize = font->CalcTextSizeA( fontSize , FLT_MAX , 0.f , text );

		const auto& color = GetStyleManager()->GetNavigationColors().Muted;
		const auto tint = ImVec4( color.x * icon.Tint.x , color.y * icon.Tint.y , color.z * icon.Tint.z , color.w * icon.Tint.w );

		drawList->AddText( font , fontSize , ImVec2( center.x - textSize.x * 0.5f , center.y - textSize.y * 0.5f ) , ImGui::GetColorU32( tint ) , text );
	}
}

auto CNavigationBar::AddDefaultButton( const char* id , const char* tooltip , SIcon& icon , EAction action , float minWidth , std::vector<ImGuiKeyChord> shortcut , SDropdown menu ) -> SButton&
{
	auto button = SButton{};

	button.Id = id;
	button.Tooltip = tooltip;
	button.Icon = icon;
	button.Shortcut = std::move( shortcut );
	button.Action = action;
	button.MinBarWidth = minWidth;
	button.Dropdown = !menu.Items.empty();
	button.Menu = std::move( menu );

	m_Buttons.push_back( std::move( button ) );

	return m_Buttons.back();
}

CNavigationBar::CNavigationBar()
{
	m_MenuButton.Id = "Menu";
	m_MenuButton.Tooltip = "Open/close menu";
	m_MenuButton.Shortcut = { ImGuiKey_Tab };
	m_MenuButton.Icon = { .AwesomeIcon = u8"\uf0c9" };

	SetSearchIcon( { .AwesomeIcon = u8"\uf002" } );
	SetHistoryIcon( { .AwesomeIcon = u8"\uf1da" } );

	auto createMenu = SDropdown{};

	createMenu.Items =
	{
		{ .Text = "New Script" , .Icon = { .AwesomeIcon = u8"\ue178" } , .Action = EAction::None },
		SMenuItem::MakeSeparator(),
		{ .Text = "New Config" , .Icon = { .AwesomeIcon = u8"\ue178" } , .Action = EAction::None },
	};

	SIcon CreateIcon = { .AwesomeIcon = u8"\u002b" };

	auto& create = AddDefaultButton( "Create" , "Create new" , CreateIcon , EAction::None , 700.f , {} , std::move( createMenu ) );

	create.Size.x = 48.f;
	create.Dropdown = true;

	SIcon AndromedaIcon = { .Resource = EResource::AndromedaIcon };

	AddDefaultButton( "Profile" , "Your profile" , AndromedaIcon , EAction::None , 0.f ).Round = true;
}

auto CNavigationBar::SetHomeShortcut( std::vector<ImGuiKeyChord> shortcut ) -> void
{
	m_HomeShortcut = std::move( shortcut );
	m_ShortcutPrefix.clear();
}

auto CNavigationBar::TriggerAction( EAction action ) -> void
{
	if ( action == EAction::None )
		return;

	for ( const auto& button : m_Buttons )
	{
		if ( button.Action == action && button.Visible && button.Enabled && !button.Menu.Items.empty() )
		{
			m_RequestedDropdown = button.Id;
			return;
		}
	}

	m_PendingAction = action;
}

auto CNavigationBar::ActivateButton( const SButton& button , std::function<void()>& onClick ) -> void
{
	if ( !button.Menu.Items.empty() )
		m_RequestedDropdown = button.Id;
	else if ( button.Action != EAction::None )
		TriggerAction( button.Action );

	onClick = button.OnClick;
}

auto CNavigationBar::HandleShortcuts( std::function<void()>& onClick , bool additionalShortcutFocus ) -> void
{
	const auto& io = ImGui::GetIO();

	if ( ( !ImGui::IsWindowFocused( ImGuiFocusedFlags_RootAndChildWindows ) && !additionalShortcutFocus ) || io.WantTextInput || ImGui::IsAnyItemActive() || ImGui::IsPopupOpen( nullptr , ImGuiPopupFlags_AnyPopupId | ImGuiPopupFlags_AnyPopupLevel ) )
	{
		m_ShortcutPrefix.clear();
		return;
	}

	if ( ImGui::GetTime() - m_flLastShortcutTime > 1.0 )
		m_ShortcutPrefix.clear();

	for ( auto button = 0; button < ImGuiMouseButton_COUNT; ++button )
	{
		if ( ImGui::IsMouseClicked( button ) )
		{
			m_ShortcutPrefix.clear();
			return;
		}
	}

	const auto fnMatches = [&]( const std::vector<ImGuiKeyChord>& shortcut )
	{
		return !shortcut.empty() && m_ShortcutPrefix.size() <= shortcut.size() &&
			std::equal( m_ShortcutPrefix.begin() , m_ShortcutPrefix.end() , shortcut.begin() );
	};

	const auto fnHasPrefix = [&]()
	{
		if ( fnMatches( m_HomeShortcut ) || ( m_MenuButton.Enabled && fnMatches( m_MenuButton.Shortcut ) ) )
			return true;

		for ( const auto& button : m_Buttons )
			if ( button.Visible && button.Enabled && fnMatches( button.Shortcut ) )
				return true;

		return false;
	};

	for ( auto value = static_cast<int>( ImGuiKey_Tab ); value <= ImGuiKey_Oem102; ++value )
	{
		const auto key = static_cast<ImGuiKey>( value );

		if ( ( key >= ImGuiKey_LeftCtrl && key <= ImGuiKey_RightSuper ) || !ImGui::IsKeyPressed( key , false ) )
			continue;

		const auto chord = static_cast<ImGuiKeyChord>( key ) | io.KeyMods;

		m_ShortcutPrefix.push_back( chord );

		if ( !fnHasPrefix() )
		{
			m_ShortcutPrefix.clear();
			m_ShortcutPrefix.push_back( chord );

			if ( !fnHasPrefix() )
			{
				m_ShortcutPrefix.clear();
				continue;
			}
		}

		m_flLastShortcutTime = ImGui::GetTime();

		if ( fnMatches( m_HomeShortcut ) && m_ShortcutPrefix.size() == m_HomeShortcut.size() )
		{
			TriggerAction( EAction::Home );
			m_ShortcutPrefix.clear();

			return;
		}

		if ( m_MenuButton.Enabled && fnMatches( m_MenuButton.Shortcut ) && m_ShortcutPrefix.size() == m_MenuButton.Shortcut.size() )
		{
			m_bMenuToggled = !m_bMenuToggled;
			m_ShortcutPrefix.clear();

			return;
		}

		for ( const auto& button : m_Buttons )
		{
			if ( button.Visible && button.Enabled && fnMatches( button.Shortcut ) && m_ShortcutPrefix.size() == button.Shortcut.size() )
			{
				ActivateButton( button , onClick );
				m_ShortcutPrefix.clear();

				return;
			}
		}
	}
}

auto CNavigationBar::FindButton( const char* id ) -> SButton*
{
	if ( !id )
		return nullptr;

	const auto found = std::find_if( m_Buttons.begin() , m_Buttons.end() ,
		[id]( const SButton& button )
		{
			return button.Id == id;
		} );

	return found != m_Buttons.end() ? &*found : nullptr;
}

auto CNavigationBar::AddButton( SButton button , const char* beforeId ) -> bool
{
	if ( button.Id.empty() || FindButton( button.Id.c_str() ) )
		return false;

	if ( beforeId )
	{
		const auto before = std::find_if( m_Buttons.begin() , m_Buttons.end() ,
			[beforeId]( const SButton& entry )
			{
				return entry.Id == beforeId;
			} );

		if ( before == m_Buttons.end() )
			return false;

		m_Buttons.insert( before , std::move( button ) );
	}
	else
	{
		m_Buttons.push_back( std::move( button ) );
	}

	return true;
}

auto CNavigationBar::RemoveButton( const char* id ) -> bool
{
	if ( !id )
		return false;

	const auto found = std::find_if( m_Buttons.begin() , m_Buttons.end() ,
		[id]( const SButton& button )
		{
			return button.Id == id;
		} );

	if ( found == m_Buttons.end() )
		return false;

	m_Buttons.erase( found );

	return true;
}

auto CNavigationBar::RenderButton( const SButton& button , ImVec2 position , float scale ) -> bool
{
	const auto size = ImVec2( ImMax( 1.f , button.Size.x ) * scale , ImClamp( button.Size.y , 1.f , 64.f ) * scale );

	if ( !button.Menu.Items.empty() )
		m_DropdownAnchors.push_back( { button.Id , ImRect( position , ImVec2( position.x + size.x , position.y + size.y ) ) } );

	const auto rounding = button.Round ? ImMin( size.x , size.y ) * 0.5f : ImGui::GetStyle().FrameRounding;

	ImGui::SetCursorScreenPos( position );

	ImGui::PushID( button.Id.c_str() );
	ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding , rounding );

	ImGui::BeginDisabled( !button.Enabled );

	const auto bPressed = ImGui::Button( "##Button" , size );
	const auto dropdown = button.Dropdown || !button.Menu.Items.empty();
	const auto iconArea = dropdown ? ImMax( 0.f , size.x - 20.f * scale ) : size.x;
	const auto center = ImVec2( position.x + iconArea * 0.5f , position.y + size.y * 0.5f );

	auto* pDrawList = ImGui::GetWindowDrawList();

	DrawIcon( pDrawList , button.Icon , center , scale , ImVec2( iconArea , size.y ) , button.Round );

	if ( dropdown )
		DrawIcon( pDrawList , button.DropdownIcon , ImVec2( position.x + size.x - 14.f * scale , center.y ) , scale , ImVec2( 16.f * scale , size.y ) );

	ImGui::EndDisabled();

	GitMenu::CTollTip::Render( button.Tooltip.c_str() , button.Shortcut , ImGuiHoveredFlags_AllowWhenDisabled );

	ImGui::PopStyleVar();
	ImGui::PopID();

	return bPressed;
}

auto CNavigationBar::RenderSearch( ImVec2 position , float width , float scale ) -> void
{
	const auto& palette = GetStyleManager()->GetNavigationColors();
	const auto Border = ImGui::GetColorU32( palette.Border );

	auto bFocusSearch = ImGui::IsWindowFocused( ImGuiFocusedFlags_RootAndChildWindows ) && !ImGui::GetIO().WantTextInput && !ImGui::GetIO().KeyCtrl && !ImGui::GetIO().KeyAlt && ImGui::IsKeyPressed( ImGuiKey_Slash , false );

	ImGui::SetCursorScreenPos( ImVec2( position.x + 28.f * scale , position.y + scale ) );
	ImGui::SetNextItemWidth( width - 28.f * scale );

	ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , 0 );

	ImGui::PushStyleColor( ImGuiCol_FrameBg , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
	ImGui::PushStyleColor( ImGuiCol_TextDisabled , palette.Muted );

	if ( bFocusSearch )
		ImGui::SetKeyboardFocusHere();

	const auto fnFilterShortcut = []( ImGuiInputTextCallbackData* pData ) -> int
	{
		return *static_cast<bool*>( pData->UserData ) && pData->EventChar == '/';
	};

	ImGui::InputTextWithHint( "##Search" , "" , m_InputSearchBuffer , sizeof( m_InputSearchBuffer ) , ImGuiInputTextFlags_CallbackCharFilter , fnFilterShortcut , &bFocusSearch );

	const auto bActive = ImGui::IsItemActive();

	// Focus restored after closing a popup must not open it again.
	if ( bFocusSearch || ( ImGui::IsWindowHovered( ImGuiHoveredFlags_AllowWhenBlockedByActiveItem ) && ImGui::IsMouseHoveringRect( position , ImVec2( position.x + width , position.y + 32.f * scale ) ) && ImGui::IsMouseClicked( ImGuiMouseButton_Left ) ) )
		m_bOpenSearchRequested = true;

	GitMenu::CTollTip::Render( "Search or jump to..." , { ImGuiKey_Slash } );

	ImGui::PopStyleColor( 2 );
	ImGui::PopStyleVar();

	auto* pDrawList = ImGui::GetWindowDrawList();

	if ( m_InputSearchBuffer[0] == '\0' && !bActive )
	{
		const auto hintColor = ImGui::GetColorU32( palette.Muted );

		const auto textY = position.y + ( 32.f * scale - ImGui::GetFontSize() ) * 0.5f;
		const auto textX = position.x + 32.f * scale;

		const auto keyX = textX + ImGui::CalcTextSize( "Type " ).x;
		const auto keyFontSize = ImGui::GetFontSize() + 2.f * scale;
		const auto keyTextSize = ImGui::GetFont()->CalcTextSizeA( keyFontSize , FLT_MAX , 0.f , "/" );
		const auto keyWidth = keyTextSize.x + 8.f * scale;
		const auto keyHeight = keyTextSize.y + 2.f * scale;
		const auto keyY = position.y + ( 32.f * scale - keyHeight ) * 0.5f;

		pDrawList->PushClipRect( position , ImVec2( position.x + width - 4.f * scale , position.y + 32.f * scale ) , true );

		pDrawList->AddText( ImVec2( textX , textY ) , hintColor , "Type " );
		pDrawList->AddRect( ImVec2( keyX , keyY ) , ImVec2( keyX + keyWidth , keyY + keyHeight ) , Border , 2.f * scale );
		pDrawList->AddText( ImGui::GetFont() , keyFontSize , ImVec2( keyX + 4.f * scale , keyY + scale ) , hintColor , "/" );
		pDrawList->AddText( ImVec2( keyX + keyWidth , textY ) , hintColor , " to search" );

		pDrawList->PopClipRect();
	}

	pDrawList->AddRect( position , ImVec2( position.x + width , position.y + 32.f * scale ) ,bActive ? ImGui::GetColorU32( ImGuiCol_CheckMark ) : Border , ImGui::GetStyle().FrameRounding , 0 , ( bActive ? 2.f : 1.f ) * scale );

	DrawIcon( pDrawList , m_SearchIcon , ImVec2( position.x + 14.f * scale , position.y + 16.f * scale ) , scale );
}

auto CNavigationBar::ClearSearch() -> void
{
	RememberSearch();
	m_InputSearchBuffer[0] = '\0';
	m_bOpenSearchRequested = false;
	m_bSearchWasOpen = false;
}

auto CNavigationBar::RememberSearch() -> void
{
	auto query = std::string( m_InputSearchBuffer );

	const auto first = query.find_first_not_of( " \t\r\n" );

	if ( first == std::string::npos )
		return;

	query = query.substr( first , query.find_last_not_of( " \t\r\n" ) - first + 1 );

	m_RecentSearches.erase( std::remove( m_RecentSearches.begin() , m_RecentSearches.end() , query ) , m_RecentSearches.end() );
	m_RecentSearches.insert( m_RecentSearches.begin() , std::move( query ) );

	if ( m_RecentSearches.size() > 5 )
		m_RecentSearches.resize( 5 );
}

auto CNavigationBar::RenderSearchPopup( ImVec2 position , float width , float scale ) -> void
{
	constexpr auto popupId = "##RecentSearches";
	const auto bOpening = m_bOpenSearchRequested;

	m_bOpenSearchRequested = false;

	if ( bOpening )
	{
		ImGui::OpenPopup( popupId );

		m_flSearchOpenTime = 0.f;
	}

	if ( !ImGui::IsPopupOpen( popupId ) )
	{
		if ( m_bSearchWasOpen )
			RememberSearch();

		m_bSearchWasOpen = false;

		return;
	}

	m_bSearchWasOpen = true;

	const auto& palette = GetStyleManager()->GetNavigationColors();

	m_flSearchOpenTime = ImMin( 0.18f , m_flSearchOpenTime + ImGui::GetIO().DeltaTime );

	const auto progress = m_flSearchOpenTime / 0.18f;
	const auto eased = 1.f - ( 1.f - progress ) * ( 1.f - progress ) * ( 1.f - progress );
	const auto rows = ImMax( 1 , static_cast<int>( m_RecentSearches.size() ) );
	const auto headerHeight = 56.f * scale;
	const auto fullHeight = headerHeight + ( 28.f + rows * 33.f + 8.f ) * scale;

	const auto* viewport = ImGui::GetWindowViewport();

	width = ImMin( width , viewport->WorkSize.x - 8.f * scale );
	position.x = ImClamp( position.x , viewport->WorkPos.x + 4.f * scale , viewport->WorkPos.x + viewport->WorkSize.x - width - 4.f * scale );

	const auto availableHeight = viewport->WorkPos.y + viewport->WorkSize.y - position.y - 4.f * scale;
	const auto height = ImMin( headerHeight + ( fullHeight - headerHeight ) * eased , ImMax( headerHeight , availableHeight ) );

	// Dismiss before drawing so even middle/right clicks outside have no closing frame.
	auto bOutsideClick = false;

	for ( auto button = 0; button < ImGuiMouseButton_COUNT; ++button )
		bOutsideClick |= ImGui::IsMouseClicked( button );

	bOutsideClick = !bOpening && bOutsideClick && !ImGui::IsMouseHoveringRect( position , ImVec2( position.x + width , position.y + height ) , false );

	if ( bOutsideClick || ImGui::IsKeyPressed( ImGuiKey_Escape ) )
	{
		RememberSearch();

		// Close before BeginPopup: Alpha=0 makes BeginPopup return false,
		// which would skip CloseCurrentPopup and leave the popup open.
		ImGui::ClosePopupToLevel( GImGui->BeginPopupStack.Size , true );
		m_bSearchWasOpen = false;

		return;
	}

	ImGui::SetNextWindowPos( position );
	ImGui::SetNextWindowSize( ImVec2( width , height ) );

	ImGui::PushFont( nullptr , 14.f );

	ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding , ImVec2( 12.f * scale , 12.f * scale ) );
	ImGui::PushStyleVar( ImGuiStyleVar_PopupBorderSize , scale );
	ImGui::PushStyleVar( ImGuiStyleVar_FramePadding , ImVec2( 8.f * scale , 8.f * scale ) );
	ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , 0.f );
	ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing , ImVec2( 0.f , 0.f ) );
	ImGui::PushStyleColor( ImGuiCol_PopupBg , palette.Background );
	ImGui::PushStyleColor( ImGuiCol_Border , palette.Border );
	ImGui::PushStyleColor( ImGuiCol_Text , palette.Text );
	ImGui::PushStyleColor( ImGuiCol_TextDisabled , palette.Muted );
	ImGui::PushStyleColor( ImGuiCol_FrameBg , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
	ImGui::PushStyleColor( ImGuiCol_Button , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
	ImGui::PushStyleColor( ImGuiCol_ButtonHovered , palette.Hovered );
	ImGui::PushStyleColor( ImGuiCol_ButtonActive , palette.Active );

	if ( ImGui::BeginPopup( popupId , ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse ) )
	{
		{
			const auto inputPos = ImGui::GetCursorScreenPos();
			const auto inputWidth = ImGui::GetContentRegionAvail().x;

			ImGui::SetCursorScreenPos( ImVec2( inputPos.x + 28.f * scale , inputPos.y ) );
			ImGui::SetNextItemWidth( inputWidth - 28.f * scale );

			if ( bOpening )
				ImGui::SetKeyboardFocusHere();

			const auto fnFilterShortcut = []( ImGuiInputTextCallbackData* data ) -> int
			{
				return *static_cast<const bool*>( data->UserData ) && data->EventChar == '/';
			};

			auto bFilterSlash = bOpening && ImGui::IsKeyPressed( ImGuiKey_Slash , false );

			const auto bSubmit = ImGui::InputTextWithHint( "##ExpandedSearch" , "Search by name, description, or #tag" , m_InputSearchBuffer , sizeof( m_InputSearchBuffer ) , ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCharFilter , fnFilterShortcut , &bFilterSlash );
			const auto inputHeight = ImGui::GetItemRectSize().y;

			auto* drawList = ImGui::GetWindowDrawList();

			drawList->AddRect( inputPos , ImVec2( inputPos.x + inputWidth , inputPos.y + inputHeight ) , ImGui::GetColorU32( ImGuiCol_CheckMark ) , ImGui::GetStyle().FrameRounding , 0 , 2.f * scale );

			DrawIcon( drawList , m_SearchIcon , ImVec2( inputPos.x + 14.f * scale , inputPos.y + inputHeight * 0.5f ) , scale );

			auto selectedQuery = std::string{};

			ImGui::SetCursorScreenPos( ImVec2( inputPos.x , position.y + headerHeight ) );

			if ( height > headerHeight + 2.f * scale )
			{
				if ( ImGui::BeginChild( "##SearchHistory" , ImVec2( inputWidth , height - headerHeight - scale ) ) )
				{
					ImGui::TextDisabled( "Recent" );
					ImGui::Dummy( ImVec2( 0.f , 10.f * scale ) );

					if ( m_RecentSearches.empty() )
						ImGui::TextDisabled( "No recent searches" );

					for ( auto i = size_t{ 0 }; i < m_RecentSearches.size(); ++i )
					{
						ImGui::PushID( static_cast<int>( i ) );

						const auto rowPos = ImGui::GetCursorScreenPos();

						if ( ImGui::Button( "##Query" , ImVec2( ImGui::GetContentRegionAvail().x , 33.f * scale ) ) )
							selectedQuery = m_RecentSearches[i];

						auto* rowDrawList = ImGui::GetWindowDrawList();

						DrawIcon( rowDrawList , m_HistoryIcon , ImVec2( rowPos.x + 12.f * scale , rowPos.y + 16.5f * scale ) , scale );

						rowDrawList->AddText( ImVec2( rowPos.x + 28.f * scale , rowPos.y + ( 33.f * scale - ImGui::GetFontSize() ) * 0.5f ) , ImGui::GetColorU32( palette.Text ) , m_RecentSearches[i].c_str() );

						ImGui::PopID();
					}
				}

				ImGui::EndChild();
			}

			if ( !selectedQuery.empty() )
				ImStrncpy( m_InputSearchBuffer , selectedQuery.c_str() , sizeof( m_InputSearchBuffer ) );

			if ( bSubmit || !selectedQuery.empty() )
			{
				RememberSearch();
				ImGui::CloseCurrentPopup();
			}
		}

		ImGui::EndPopup();
	}

	ImGui::PopStyleColor( 8 );
	ImGui::PopStyleVar( 5 );
	ImGui::PopFont();
}

auto CNavigationBar::RenderDropdown( ImVec2 fallbackPosition , float scale , std::function<void()>& onClick ) -> void
{
	constexpr auto popupId = "##NavigationDropdown";
	const auto opening = !m_RequestedDropdown.empty();

	if ( opening )
	{
		m_ActiveDropdown = std::move( m_RequestedDropdown );
		m_RequestedDropdown.clear();

		ImGui::OpenPopup( popupId );
	}

	if ( !ImGui::IsPopupOpen( popupId ) )
	{
		m_ActiveDropdown.clear();
		return;
	}

	const auto* button = FindButton( m_ActiveDropdown.c_str() );

	if ( !button || !button->Visible || !button->Enabled || button->Menu.Items.empty() )
	{
		ImGui::ClosePopupToLevel( GImGui->BeginPopupStack.Size , true );
		m_ActiveDropdown.clear();

		return;
	}

	ImGui::PushFont( nullptr , 14.f );

	const auto& palette = GetStyleManager()->GetNavigationColors();
	const auto* viewport = ImGui::GetWindowViewport();

	const auto margin = 4.f * scale;
	auto width = ImMax( 80.f , button->Menu.MinWidth ) * scale;
	auto fullHeight = 16.f * scale;

	for ( const auto& item : button->Menu.Items )
	{
		fullHeight += ( item.Separator ? 16.f : 32.f ) * scale;

		if ( !item.Separator )
			width = ImMax( width , ImGui::CalcTextSize( item.Text.c_str() ).x + 56.f * scale );
	}

	width = ImMin( width , ImMax( 1.f , viewport->WorkSize.x - margin * 2.f ) );

	const auto height = ImMin( fullHeight , ImMax( 1.f , viewport->WorkSize.y - margin * 2.f ) );
	auto anchor = ImRect( fallbackPosition , fallbackPosition );

	for ( const auto& entry : m_DropdownAnchors )
		if ( entry.ButtonId == m_ActiveDropdown )
			anchor = entry.Bounds;

	auto position = ImVec2( anchor.Max.x - width , anchor.Max.y + margin );

	if ( position.y + height > viewport->WorkPos.y + viewport->WorkSize.y - margin )
		position.y = anchor.Min.y - height - margin;

	position.x = ImClamp( position.x , viewport->WorkPos.x + margin , viewport->WorkPos.x + viewport->WorkSize.x - width - margin );
	position.y = ImClamp( position.y , viewport->WorkPos.y + margin , viewport->WorkPos.y + viewport->WorkSize.y - height - margin );

	auto outsideClick = false;

	for ( auto mouse = 0; mouse < ImGuiMouseButton_COUNT; ++mouse )
		outsideClick |= ImGui::IsMouseClicked( mouse );

	outsideClick = !opening && outsideClick && !ImGui::IsMouseHoveringRect( position , ImVec2( position.x + width , position.y + height ) , false );

	if ( outsideClick || ImGui::IsKeyPressed( ImGuiKey_Escape ) )
	{
		ImGui::ClosePopupToLevel( GImGui->BeginPopupStack.Size , true );
		m_ActiveDropdown.clear();
		ImGui::PopFont();

		return;
	}

	ImGui::SetNextWindowPos( position );
	ImGui::SetNextWindowSize( ImVec2( width , height ) );

	ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding , ImVec2( 8.f * scale , 8.f * scale ) );
	ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing , ImVec2( 0.f , 0.f ) );
	ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , 0.f );
	ImGui::PushStyleVar( ImGuiStyleVar_PopupBorderSize , scale );
	ImGui::PushStyleColor( ImGuiCol_PopupBg , ImGui::GetStyleColorVec4( ImGuiCol_WindowBg ) );
	ImGui::PushStyleColor( ImGuiCol_Border , palette.Border );
	ImGui::PushStyleColor( ImGuiCol_Text , palette.Text );
	ImGui::PushStyleColor( ImGuiCol_Button , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
	ImGui::PushStyleColor( ImGuiCol_ButtonHovered , palette.Hovered );
	ImGui::PushStyleColor( ImGuiCol_ButtonActive , palette.Active );

	if ( ImGui::BeginPopup( popupId , ImGuiWindowFlags_NoMove ) )
	{
		for ( auto i = size_t{ 0 }; i < button->Menu.Items.size(); ++i )
		{
			const auto& item = button->Menu.Items[i];
			const auto rowPosition = ImGui::GetCursorScreenPos();

			if ( item.Separator )
			{
				ImGui::GetWindowDrawList()->AddLine( ImVec2( position.x + scale , rowPosition.y + 8.f * scale ) , ImVec2( position.x + width - scale , rowPosition.y + 8.f * scale ) , ImGui::GetColorU32( palette.Border ) );
				ImGui::Dummy( ImVec2( 0.f , 16.f * scale ) );

				continue;
			}

			ImGui::PushID( static_cast<int>( i ) );
			ImGui::BeginDisabled( !item.Enabled );

			const auto rowSize = ImVec2( ImGui::GetContentRegionAvail().x , 32.f * scale );
			const auto selected = ImGui::Button( "##MenuItem" , rowSize );

			auto* drawList = ImGui::GetWindowDrawList();

			DrawIcon( drawList , item.Icon , ImVec2( rowPosition.x + 12.f * scale , rowPosition.y + 16.f * scale ) , scale , ImVec2( 16.f * scale , 16.f * scale ) );

			drawList->PushClipRect( rowPosition , ImVec2( rowPosition.x + rowSize.x , rowPosition.y + rowSize.y ) , true );
			drawList->AddText( ImVec2( rowPosition.x + 32.f * scale , rowPosition.y + ( rowSize.y - ImGui::GetFontSize() ) * 0.5f ) , ImGui::GetColorU32( palette.Text ) , item.Text.c_str() );
			drawList->PopClipRect();

			ImGui::EndDisabled();
			ImGui::PopID();

			if ( selected )
			{
				if ( item.Action != EAction::None )
					m_PendingAction = item.Action;

				onClick = item.OnClick;
				ImGui::CloseCurrentPopup();

				break;
			}
		}

		ImGui::EndPopup();
	}

	ImGui::PopStyleColor( 6 );
	ImGui::PopStyleVar( 4 );
	ImGui::PopFont();
}

auto CNavigationBar::OnRender( bool additionalShortcutFocus ) -> void
{
	m_DropdownAnchors.clear();

	const auto& palette = GetStyleManager()->GetNavigationColors();
	const auto Background = ImGui::GetColorU32( palette.Background );
	const auto Border = ImGui::GetColorU32( palette.Border );

	// Invoke after rendering: handlers may safely add/remove their own buttons.
	auto fnOnClick = std::function<void()>{};

	ImGui::PushID( this );

	const auto scale = ImGui::GetFontSize() / 16.f;
	const auto height = 64.f * scale;

	auto origin = ImGui::GetCursorScreenPos();

	origin.y -= ImGui::GetStyle().WindowPadding.y;
	ImGui::SetCursorScreenPos( origin );

	const auto windowPos = ImGui::GetWindowPos();
	const auto windowRight = windowPos.x + ImGui::GetWindowSize().x;
	const auto rounding = origin.y <= windowPos.y + 1.f ? ImGui::GetCurrentWindow()->WindowRounding : 0.f;

	auto* pParentDrawList = ImGui::GetWindowDrawList();

	// The full-width background must leave the outer resize border visible.
	const auto borderInset = ImMax( 2.f , ImGui::GetStyle().WindowBorderSize );

	pParentDrawList->PushClipRect( ImVec2( windowPos.x + borderInset , origin.y ) , ImVec2( windowRight - borderInset , origin.y + height ) , true );
	pParentDrawList->AddRectFilled( ImVec2( windowPos.x , origin.y ) , ImVec2( windowRight , origin.y + height ) , Background , rounding , ImDrawFlags_RoundCornersTop );
	pParentDrawList->AddLine( ImVec2( windowPos.x , origin.y + height ) , ImVec2( windowRight , origin.y + height ) , Border );
	pParentDrawList->PopClipRect();

	ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding , ImVec2( 0.f , 0.f ) );

	const auto bVisible = ImGui::BeginChild( "##NavigationBar" , ImVec2( 0.f , height ) , ImGuiChildFlags_None , ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse );

	if ( bVisible )
	{
		ImGui::PushFont( nullptr , 14.f );

		ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , scale );
		ImGui::PushStyleVar( ImGuiStyleVar_FramePadding , ImVec2( 8.f * scale , 8.f * scale ) );
		ImGui::PushStyleColor( ImGuiCol_Button , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
		ImGui::PushStyleColor( ImGuiCol_ButtonHovered , palette.Hovered );
		ImGui::PushStyleColor( ImGuiCol_ButtonActive , palette.Active );
		ImGui::PushStyleColor( ImGuiCol_Border , palette.Border );
		ImGui::PushStyleColor( ImGuiCol_Text , palette.Text );

		auto* pDrawList = ImGui::GetWindowDrawList();
		const auto start = ImGui::GetCursorScreenPos();
		const auto width = ImGui::GetContentRegionAvail().x;
		const auto y = start.y + 16.f * scale;
		const auto gap = 8.f * scale;

		ImGui::PushID( "##MenuSection" );

		if ( RenderButton( m_MenuButton , ImVec2( start.x + gap , y ) , scale ) )
			m_bMenuToggled = !m_bMenuToggled;

		ImGui::PopID();

		const auto bShowTitle = width >= 700.f * scale;
		const auto bShowLogo = width >= 360.f * scale;

		if ( bShowLogo )
		{
			ImGui::SetCursorScreenPos( ImVec2( start.x + 52.f * scale , y ) );
			ImGui::Image( GetResourceManager()->GetTexture( EResource::DashBoardIcon ) , ImVec2( 32.f * scale , 32.f * scale ) );
		}

		auto titleRight = 210.f * scale;

		if ( bShowTitle )
		{
			ImGui::SetCursorScreenPos( ImVec2( start.x + 90.f * scale , y ) );

			ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize , 0.f );

			const auto titleWidth = ImGui::CalcTextSize( "Dashboard" ).x + 16.f * scale;

			if ( ImGui::Button( "Dashboard##Home" , ImVec2( titleWidth , 32.f * scale ) ) )
				TriggerAction( EAction::Home );

			GitMenu::CTollTip::Render( "Homepage" , m_HomeShortcut );

			titleRight = ImMax( titleRight , 90.f * scale + titleWidth + gap );

			ImGui::PopStyleVar();
		}

		auto buttons = std::vector<const SButton*>{};

		for ( const auto& button : m_Buttons )
		{
			if ( button.Visible && width >= button.MinBarWidth * scale )
				buttons.push_back( &button );
		}

		const auto fnMeasureButtons = [&]()
		{
			auto result = 0.f;

			for ( auto i = size_t{ 0 }; i < buttons.size(); ++i )
			{
				result += ImMax( 1.f , buttons[i]->Size.x ) * scale;

				if ( i + 1 < buttons.size() )
					result += ImMax( 0.f , buttons[i]->GapAfter ) * scale;
			}

			return result;
		};

		const auto leftWidth = bShowTitle ? titleRight : ( bShowLogo ? 100.f : 56.f ) * scale;

		// Keep space for search; drop tools from the left if a custom list grows too wide.
		const auto toolsBudget = ImMax( 0.f , width - leftWidth - 100.f * scale - 3 * gap );
		auto toolsWidth = fnMeasureButtons();

		while ( buttons.size() > 1 && toolsWidth > toolsBudget )
		{
			buttons.erase( buttons.begin() );
			toolsWidth = fnMeasureButtons();
		}

		// Even the last tool must fit without covering the left menu/identity.
		if ( toolsWidth > ImMax( 0.f , width - leftWidth - 2 * gap ) )
		{
			buttons.clear();
			toolsWidth = 0.f;
		}

		const auto toolsX = start.x + width - gap - toolsWidth;
		const auto searchSpace = toolsX - gap - ( start.x + leftWidth );

		if ( searchSpace >= 100.f * scale )
		{
			const auto searchWidth = ImMin( 190.f * scale , searchSpace );
			RenderSearch( ImVec2( toolsX - gap - searchWidth , y ) , searchWidth , scale );
		}

		auto x = toolsX;

		for ( auto i = size_t{ 0 }; i < buttons.size(); ++i )
		{
			const auto& button = *buttons[i];
			const auto buttonHeight = ImClamp( button.Size.y , 1.f , 64.f ) * scale;

			if ( RenderButton( button , ImVec2( x , start.y + ( height - buttonHeight ) * 0.5f ) , scale ) )
			{
				ActivateButton( button , fnOnClick );
			}

			x += ImMax( 1.f , button.Size.x ) * scale;

			if ( i + 1 < buttons.size() )
			{
				const auto spacing = ImMax( 0.f , button.GapAfter ) * scale;

				if ( button.SeparatorAfter )
					pDrawList->AddLine( ImVec2( x + spacing * 0.5f , y + 4.f * scale ) , ImVec2( x + spacing * 0.5f , y + 28.f * scale ) , Border );

				x += spacing;
			}
		}

		ImGui::PopStyleColor( 5 );
		ImGui::PopStyleVar( 2 );
		ImGui::PopFont();
	}

	ImGui::EndChild();
	ImGui::PopStyleVar();

	RenderSearchPopup( ImVec2( windowPos.x + 4.f * scale , origin.y + 4.f * scale ) , windowRight - windowPos.x - 8.f * scale , scale );
	HandleShortcuts( fnOnClick , additionalShortcutFocus );
	RenderDropdown( ImVec2( windowRight - 8.f * scale , origin.y + height ) , scale , fnOnClick );

	ImGui::PopID();

	if ( fnOnClick )
		fnOnClick();
}
