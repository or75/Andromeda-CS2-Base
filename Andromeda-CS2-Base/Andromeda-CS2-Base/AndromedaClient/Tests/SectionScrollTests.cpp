// Headless regression: scrolling multiple sections must not change content height.
#include <AndromedaClient/GUI/GitMenu/Custom/CSectionBar.hpp>
#include <AndromedaClient/GUI/GitMenu/Custom/CColorWidget.hpp>
#include <AndromedaClient/GUI/GitMenu/Core/CStyleManager.hpp>

#include <array>
#include <cmath>
#include <cstdio>

void CAndromedaGUI::OnPresent( IDXGISwapChain* ) {}
void CAndromedaGUI::OnResizeBuffers( IDXGISwapChain* ) {}
void CAndromedaGUI::OnRender( IDXGISwapChain* ) {}
auto GetAndromedaGUI() -> CAndromedaGUI*
{
	static CAndromedaGUI gui;
	return &gui;
}

int main()
{
	ImGui::CreateContext();
	auto& io = ImGui::GetIO();
	io.IniFilename = nullptr;
	io.DisplaySize = ImVec2( 800.f , 600.f );
	io.DeltaTime = 1.f / 60.f;
	io.Fonts->AddFontDefault();
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32( &pixels , &width , &height );

	std::array<ImVec4, 12> colors{};
	std::array<GitMenu::CSectionBar, 3> sections{ "Boxes", "Bones", "Glow" };
	float pageWidth = 500.f;

	const auto frame = [&]( float scroll )
	{
		ImGui::NewFrame();
		ImGui::SetNextWindowPos( ImVec2( 0.f , 0.f ) );
		ImGui::SetNextWindowSize( ImVec2( pageWidth , 300.f ) );
		ImGui::Begin( "Test" , nullptr , ImGuiWindowFlags_NoSavedSettings );
		ImGui::BeginChild( "Page" , ImVec2( 0.f , 0.f ) );
		ImGui::SetScrollY( scroll );
		for ( auto& section : sections )
			section.OnRenderImGui();
		const auto contentHeight = ImGui::GetCurrentWindow()->DC.CursorMaxPos.y - ImGui::GetCurrentWindow()->DC.CursorStartPos.y;
		ImGui::EndChild();
		ImGui::End();
		ImGui::Render();
		return contentHeight;
	};

	for ( const auto dpi : { 0.5f , 1.f , 1.5f } )
	{
		GetStyleManager()->ApplyLightTheme( dpi );
		// Start fresh, without visiting lower sections before the first scroll.
		for ( auto& section : sections )
		{
			section = GitMenu::CSectionBar( "Colors" );
			for ( int i = 0; i < 4; ++i )
				section.AddWidget( std::make_unique<GitMenu::CColorWidget>( "Color" , "Color for visible players." , &colors[i] , true ) );
		}
		for ( const auto nextWidth : { 500.f , 300.f , 650.f } )
		{
			pageWidth = nextWidth;
			for ( int i = 0; i < 8; ++i ) frame( 0.f );
			const auto expected = frame( 0.f );
			for ( const auto scroll : { 0.f , 150.f , 450.f , 900.f , 450.f , 0.f } )
				for ( int i = 0; i < 8; ++i )
				{
					const auto actual = frame( scroll );
					if ( std::abs( actual - expected ) > 1.f )
					{
						std::fprintf( stderr , "Content height changed at DPI %.2f, width %.0f, scroll %.0f: %.1f -> %.1f\n" , dpi , pageWidth , scroll , expected , actual );
						return 1;
					}
				}
		}
	}
	ImGui::DestroyContext();
}
