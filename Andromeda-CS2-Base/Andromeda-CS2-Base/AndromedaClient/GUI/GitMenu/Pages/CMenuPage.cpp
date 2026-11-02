#include "CMenuPage.hpp"

#include "../Custom/CComboBoxWidget.hpp"
#include "../Custom/CSectionBar.hpp"
#include "../Custom/CSliderFloatWidget.hpp"

#include <AndromedaClient/Settings/Settings.hpp>

namespace GitMenu
{
	CMenuGeneralSubPage::CMenuGeneralSubPage()
	{
		auto section = std::make_unique<CSectionBar>( "Appearance" );
		auto style = std::make_unique<CComboBoxWidget>( "Menu Style" , "Choose the light or dark menu theme." , &Settings::Menu::MenuStyle , std::vector<std::string>{ "Light" , "Dark" } , true );
		
		style->AddTag( "theme" );
		section->AddWidget( std::move( style ) );

		auto dpi = std::make_unique<CSliderFloatWidget>( "Menu DPI" , "Adjust the scale of the menu text and controls." , &Settings::Menu::MenuDPI , 0.5f , 3.f , "%.2fx" );
		
		dpi->AddTag( "dpi" );
		dpi->AddTag( "scale" );
		
		section->AddWidget( std::move( dpi ) );

		for ( const auto& widget : section->GetChildren() )
			widget->AddTag( "menu" );

		AddWidget( std::move( section ) );
	}
}
