#include "CColorsPage.hpp"

#include "../Custom/CColorWidget.hpp"
#include "../Custom/CSectionBar.hpp"

#include <AndromedaClient/Settings/Settings.hpp>

namespace GitMenu
{
	CColorsVisualSubPage::CColorsVisualSubPage()
	{
		const auto addColor = []( CSectionBar& section , const char* name , const char* description , ImVec4* value , const char* tag , bool separatorAfter = true )
		{
			auto widget = std::make_unique<CColorWidget>( name , description , value , separatorAfter );

			widget->AddTag( "colors" );
			widget->AddTag( "visual" );
			widget->AddTag( tag );

			section.AddWidget( std::move( widget ) );
		};

		auto boxes = std::make_unique<CSectionBar>( "Player Boxes" );
		
		addColor( *boxes , "Player Box TT" , "Box color for Terrorist players." , &Settings::Colors::Visual::PlayerBoxTT , "box" );
		addColor( *boxes , "Player Box TT Visible" , "Box color for visible Terrorist players." , &Settings::Colors::Visual::PlayerBoxTT_Visible , "box" );
		addColor( *boxes , "Player Box CT" , "Box color for Counter-Terrorist players." , &Settings::Colors::Visual::PlayerBoxCT , "box" );
		addColor( *boxes , "Player Box CT Visible" , "Box color for visible Counter-Terrorist players." , &Settings::Colors::Visual::PlayerBoxCT_Visible , "box" , true );
		
		AddWidget( std::move( boxes ) );

		auto bones = std::make_unique<CSectionBar>( "Bone ESP" );
		
		addColor( *bones , "Bone ESP TT" , "Bone outline color for Terrorist players." , &Settings::Colors::Visual::BoneESPTT , "bones" );
		addColor( *bones , "Bone ESP TT Visible" , "Bone outline color for visible Terrorist players." , &Settings::Colors::Visual::BoneESPTT_Visible , "bones" );
		addColor( *bones , "Bone ESP CT" , "Bone outline color for Counter-Terrorist players." , &Settings::Colors::Visual::BoneESPCT , "bones" );
		addColor( *bones , "Bone ESP CT Visible" , "Bone outline color for visible Counter-Terrorist players." , &Settings::Colors::Visual::BoneESPCT_Visible , "bones" , true );
		
		AddWidget( std::move( bones ) );

		auto glow = std::make_unique<CSectionBar>( "Glow" );
		
		addColor( *glow , "Glow TT" , "Glow color for Terrorist players." , &Settings::Colors::Visual::GlowTT , "glow" );
		addColor( *glow , "Glow TT Visible" , "Glow color for visible Terrorist players." , &Settings::Colors::Visual::GlowTT_Visible , "glow" );
		addColor( *glow , "Glow CT" , "Glow color for Counter-Terrorist players." , &Settings::Colors::Visual::GlowCT , "glow" );
		addColor( *glow , "Glow CT Visible" , "Glow color for visible Counter-Terrorist players." , &Settings::Colors::Visual::GlowCT_Visible , "glow" , false );
		
		AddWidget( std::move( glow ) );
	}
}
