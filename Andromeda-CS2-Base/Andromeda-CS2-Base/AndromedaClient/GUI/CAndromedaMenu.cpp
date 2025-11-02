#include "CAndromedaMenu.hpp"

#include <ImGui/imgui.h>

#include <AndromedaClient/Settings/Settings.hpp>
#include <AndromedaClient/CAndromedaGUI.hpp>

static CAndromedaMenu g_CAndromedaMenu{};

auto CAndromedaMenu::OnRenderMenu() -> void
{
	const float MenuAlpha = static_cast<float>( Settings::Menu::MenuAlpha ) / 255.f;

	ImGui::PushStyleVar( ImGuiStyleVar_Alpha , MenuAlpha );
	ImGui::SetNextWindowSize( ImVec2( 500 , 500 ) , ImGuiCond_FirstUseEver );

	if ( ImGui::Begin( XorStr( CHEAT_NAME ) , 0 ) )
	{
		if ( ImGui::CollapsingHeader( XorStr( "Visuals" ) ) )
		{
			RenderCheckBox( XorStr( "Active" ) , XorStr( "##Visual.Active" ) , Settings::Visual::Active );
			RenderCheckBox( XorStr( "Team" ) , XorStr( "##Visual.Team" ) , Settings::Visual::Team );
			RenderCheckBox( XorStr( "Enemy" ) , XorStr( "##Visual.Enemy" ) , Settings::Visual::Enemy );
			RenderCheckBox( XorStr( "OnlyVisible" ) , XorStr( "##Visual.OnlyVisible" ) , Settings::Visual::OnlyVisible );

			RenderCheckBox( XorStr( "Player Box" ) , XorStr( "##Visual.PlayerBox" ) , Settings::Visual::PlayerBox );

			const char* PlayerBoxTypeItems[] = 
			{ 
				"Box" , "Outline Box" , "Coal Box" , "Outline Coal Box" 
			};

			RenderComboBox( XorStr( "PlayerBox Type" ) , XorStr( "##Visual.PlayerBoxType" ) , Settings::Visual::PlayerBoxType , PlayerBoxTypeItems , IM_ARRAYSIZE( PlayerBoxTypeItems ) );
		}

		if ( ImGui::CollapsingHeader( XorStr( "Colors" ) ) )
		{
			RenderColorEdit( XorStr( "Player Box TT" ) , XorStr( "##Colors.Visual.PlayerBoxTT" ) , &Settings::Colors::Visual::PlayerBoxTT.x );
			RenderColorEdit( XorStr( "Player Box TT Visible" ) , XorStr( "##Colors.Visual.PlayerBoxTT_Visible" ) , &Settings::Colors::Visual::PlayerBoxTT_Visible.x );
			RenderColorEdit( XorStr( "Player Box CT" ) , XorStr( "##Colors.Visual.PlayerBoxCT" ) , &Settings::Colors::Visual::PlayerBoxCT.x );
			RenderColorEdit( XorStr( "Player Box CT Visible" ) , XorStr( "##Colors.Visual.PlayerBoxCT_Visible" ) , &Settings::Colors::Visual::PlayerBoxCT_Visible.x );
		}

		if ( ImGui::CollapsingHeader( XorStr( "Menu" ) ) )
		{
			RenderSliderInt( XorStr( "Menu Alpha" ) , XorStr( "##Menu.MenuAlpha" ) , Settings::Menu::MenuAlpha , 0 , 255 );

			const char* MenuStyleItems[] =
			{
				"Indigo" , "Vermillion" , "Classic Steam"
			};

			if ( RenderComboBox( XorStr( "Menu Style" ) , XorStr( "##Menu.MenuStyle" ) , Settings::Menu::MenuStyle , MenuStyleItems , IM_ARRAYSIZE( MenuStyleItems ) ) )
				GetAndromedaGUI()->UpdateStyle();
		}
	}

	ImGui::End();

	ImGui::PopStyleVar();
}

auto CAndromedaMenu::RenderCheckBox( const char* szTitle , const char* szStrID , bool& SettingsItem ) -> bool
{
	if ( szTitle )
	{
		ImGui::AlignTextToFramePadding();
		ImGui::Text( szTitle );
		ImGui::SameLine( ImGui::CalcTextSize( szTitle ).x + 10.f );
	}

	const auto LeftPadding = ImGui::GetStyle().FramePadding.x;

	ImGui::Dummy( ImVec2( ImGui::GetContentRegionAvail().x - 27.f - LeftPadding , 0.f ) );
	ImGui::SameLine();

	const auto Ret = ImGui::Checkbox( szStrID , &SettingsItem );

	return Ret;
}

auto CAndromedaMenu::RenderComboBox( const char* szTitle , const char* szStrID , int& v , const char* Items[] , int ItemsCount ) -> bool
{
	if ( szTitle )
	{
		ImGui::AlignTextToFramePadding();
		ImGui::Text( szTitle );
	}

	ImGui::SameLine();

	ImGui::PushItemWidth( -1.f );
	const auto Ret = ImGui::Combo( szStrID , &v , Items , ItemsCount );
	ImGui::PopItemWidth();

	return Ret;
}

auto CAndromedaMenu::RenderColorEdit( const char* szTitle , const char* szStrID , float* Color ) -> bool
{
	if ( szTitle )
	{
		ImGui::AlignTextToFramePadding();
		ImGui::Text( szTitle );
	}

	ImGui::SameLine();

	const auto Ret = ImGui::ColorEdit4( szStrID , Color );

	return Ret;
}

auto CAndromedaMenu::RenderSliderInt( const char* szTitle , const char* szStrID , int& Value , int Min , int Max ) -> bool
{
	if ( szTitle )
	{
		ImGui::AlignTextToFramePadding();
		ImGui::Text( szTitle );
	}

	ImGui::SameLine();

	ImGui::PushItemWidth( -1.f );
	const auto Ret = ImGui::SliderInt( szStrID , &Value , Min , Max );
	ImGui::PopItemWidth();

	return Ret;
}

auto GetAndromedaMenu() -> CAndromedaMenu*
{
	return &g_CAndromedaMenu;
}
