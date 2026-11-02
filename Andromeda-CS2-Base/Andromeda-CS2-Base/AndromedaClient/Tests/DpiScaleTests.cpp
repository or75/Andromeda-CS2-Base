// Headless regression test for fractional software cursor scaling.
#include <AndromedaClient/GUI/GitMenu/Core/CStyleManager.hpp>

#undef NDEBUG
#include <cassert>
#include <cmath>

int main()
{
	ImGui::CreateContext();
	auto* manager = GetStyleManager();
	for ( const auto theme : { CStyleManager::ETheme::Light , CStyleManager::ETheme::Dark } )
	{
		manager->ApplyTheme( theme , 1.f );
		// Repeated transitions exercise shrinking, growing and fractional values.
		for ( const auto dpi : { 0.5f , 0.75f , 0.99f , 1.f , 1.5f , 3.f , 0.5f } )
		{
			manager->SetDpiScale( dpi );
			manager->ApplyPendingDpiScale();
			assert( ImGui::GetStyle().MouseCursorScale > 0.f );
			assert( std::abs( ImGui::GetStyle().MouseCursorScale - dpi ) < 0.0001f );
			assert( std::abs( ImGui::GetStyle().FontScaleDpi - dpi ) < 0.0001f );
		}
	}
	ImGui::DestroyContext();
}
