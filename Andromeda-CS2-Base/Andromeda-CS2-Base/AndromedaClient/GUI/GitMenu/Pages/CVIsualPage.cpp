#include "CVIsualPage.hpp"

#include "../Custom/CCheckBoxWidget.hpp"
#include "../Custom/CSectionBar.hpp"
#include "../Custom/CComboBoxWidget.hpp"

#include <AndromedaClient/Settings/Settings.hpp>

namespace GitMenu
{
	CVIsualGlobalSubPage::CVIsualGlobalSubPage()
	{
		auto pSectionGeneral = std::make_unique<CSectionBar>( "General" );

		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Active" , "Enable visual features." , &Settings::Visual::Active , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Team" , "Enable visual features for team members." , &Settings::Visual::Team , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Enemy" , "Enable visual features for enemy players." , &Settings::Visual::Enemy , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Only Visible" , "Show only visible players." , &Settings::Visual::OnlyVisible , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Player Box" , "Show player boxes for players." , &Settings::Visual::PlayerBox , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Bone ESP" , "Show bone outlines for players." , &Settings::Visual::BoneESP , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Bone ESP Team" , "Show bone outlines for team members." , &Settings::Visual::BoneESPTeam , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Bone ESP Enemy" , "Show bone outlines for enemy players." , &Settings::Visual::BoneESPEnemy , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Glow" , "Show glow effects for players." , &Settings::Visual::Glow , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Glow Team" , "Show glow effects for team members." , &Settings::Visual::GlowTeam , true ) );
		pSectionGeneral->AddWidget( std::make_unique<CCheckBoxWidget>( "Glow Enemy" , "Show glow effects for enemy players." , &Settings::Visual::GlowEnemy , true ) );

		auto PlayerBoxType = std::make_unique<GitMenu::CComboBoxWidget>( "Player Box Type" , "Select the type of player box to display." , &Settings::Visual::PlayerBoxType ,
			std::vector<std::string>{ "Default (Box)" , "Outlined Box" , "Coal Box" , "Outlined Coal Box" }
		);

		pSectionGeneral->AddWidget( std::move( PlayerBoxType ) );

		for ( const auto& widget : pSectionGeneral->GetChildren() )
			widget->AddTag( "visual" );

		AddWidget( std::move( pSectionGeneral ) );
	}

	auto CVIsualGlobalSubPage::OnRender() -> void
	{
		ISubPage::OnRender();
	}
}
