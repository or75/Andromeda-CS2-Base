// Headless integration test: stub only the ImGui calls used to lay out search results.
#include <AndromedaClient/GUI/GitMenu/CPageManager.hpp>
#include <AndromedaClient/GUI/GitMenu/Pages/ISubPage.hpp>
#include <AndromedaClient/GUI/GitMenu/Custom/CSidebarItem.hpp>

#undef NDEBUG
#include <cassert>
#include <array>
#include <cstdlib>

static int g_HeaderCount = 0;
static int g_CollapsedHeader = -1;

namespace ImGui
{
	void PushID( const char* ) {}
	void PushID( const void* ) {}
	void PushID( int ) {}
	void PopID() {}
	void TextDisabled( const char* , ... ) {}
	void Separator() {}
	bool CollapsingHeader( const char* , ImGuiTreeNodeFlags flags )
	{
		assert( flags & ImGuiTreeNodeFlags_DefaultOpen );
		return g_HeaderCount++ != g_CollapsedHeader;
	}
	// Navigation layout is outside this test and must never be called.
	ImGuiStyle& GetStyle() { std::abort(); }
	void PushFont( ImFont* , float ) { std::abort(); }
	void PopFont() { std::abort(); }
	float GetFontSize() { std::abort(); }
	void PushStyleVar( ImGuiStyleVar , const ImVec2& ) { std::abort(); }
	void PopStyleVar( int ) { std::abort(); }
	void Dummy( const ImVec2& ) { std::abort(); }
}

auto GitMenu::CSidebarItem::Render( const char* , const char* , ImTextureRef , bool , float , const char8_t* ) -> bool { std::abort(); }

namespace
{
	struct TestWidget final : GitMenu::IWidget
	{
		TestWidget( const char* name , const char* description , int& renders )
			: IWidget( name , description ) , Renders( renders ) {}
		void OnRenderImGui() override { ++Renders; }
		int& Renders;
	};

	struct TestContainer final : GitMenu::IWidget
	{
		void OnRenderImGui() override
		{
			++Renders;
			for ( const auto& child : Children )
				if ( child ) child->OnRenderImGui();
		}
		auto GetChildren() const -> const std::vector<std::unique_ptr<IWidget>>& override { return Children; }
		std::vector<std::unique_ptr<IWidget>> Children;
		int Renders = 0;
	};

	struct TestSubPage final : GitMenu::ISubPage
	{
		using ISubPage::AddWidget;
		auto GetDisplayName() const -> const char* override { return "Subpage"; }
		void OnRender() override { ++Renders; ISubPage::OnRender(); }
		int Renders = 0;
	};

	struct TestPage final : GitMenu::IPage
	{
		auto GetName() const -> const char* override { return "Page"; }
		auto GetDisplayName() const -> const char* override { return "Page"; }
		auto GetSubPageCount() const -> int override { return 2; }
		auto GetSubPageId( int index ) const -> const char* override { return index == 0 ? "first" : "second"; }
		auto GetSubPage( int index ) const -> GitMenu::ISubPage* override { return Subs[index].get(); }
		void OnRender() override {}
		std::array<std::unique_ptr<TestSubPage>, 2> Subs;
	};
}

int main()
{
	CPageManager manager;
	std::array<int, 4> renders{};
	std::array<TestContainer*, 4> containers{};
	std::array<TestSubPage*, 4> subs{};
	for ( int pageIndex = 0; pageIndex < 2; ++pageIndex )
	{
		auto page = std::make_unique<TestPage>();
		for ( int subIndex = 0; subIndex < 2; ++subIndex )
		{
			const auto index = pageIndex * 2 + subIndex;
			auto sub = std::make_unique<TestSubPage>();
			auto container = std::make_unique<TestContainer>();
			auto widget = std::make_unique<TestWidget>( index == 1 ? "UniqueName" : "Control" , "Shared description" , renders[index] );
			widget->AddTag( index == 0 || index == 3 ? "selected" : "other" );
			widget->AddTag( index == 0 || index == 3 ? "#SELECTED" : "#OTHER" );
			assert( widget->GetTags().size() == 1 );
			containers[index] = container.get();
			subs[index] = sub.get();
			container->Children.push_back( nullptr );
			container->Children.push_back( std::move( widget ) );
			sub->AddWidget( std::move( container ) );
			page->Subs[subIndex] = std::move( sub );
		}
		manager.RegisterPage( pageIndex == 0 ? "one" : "two" , std::move( page ) );
	}

	manager.SetSearchQuery( "  #SELECTED  " );
	assert( manager.IsPageVisible( 0 ) && manager.IsPageVisible( 1 ) );
	assert( manager.IsSubPageVisible( 0 ) && !manager.IsSubPageVisible( 1 ) );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 1, 0, 0, 1 } ) );
	assert( g_HeaderCount == 2 );
	assert( manager.GetActivePageId() == "one" && manager.GetActiveSubPageId() == "first" );
	for ( auto* sub : subs ) assert( sub->Renders == 0 );
	for ( auto* container : containers ) assert( container->Renders == 0 );

	// Collapsing one source group must not hide matches from another subpage.
	renders.fill( 0 );
	g_HeaderCount = 0;
	g_CollapsedHeader = 0;
	manager.RenderActivePage();
	assert( g_HeaderCount == 2 );
	assert( ( renders == std::array<int, 4>{ 0, 0, 0, 1 } ) );
	g_CollapsedHeader = -1;

	renders.fill( 0 );
	manager.SetSearchQuery( "shared DESCRIPTION" );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 1, 1, 1, 1 } ) );
	renders.fill( 0 );
	manager.SetSearchQuery( "uniquename" );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 0, 1, 0, 0 } ) );

	renders.fill( 0 );
	for ( const auto* query : { "#sel", "#", "missing" } )
	{
		manager.SetSearchQuery( query );
		manager.RenderActivePage();
		assert( ( renders == std::array<int, 4>{ 0, 0, 0, 0 } ) );
	}

	containers[2]->AddTag( "group" );
	manager.SetSearchQuery( "#group" );
	manager.RenderActivePage();
	assert( containers[2]->Renders == 1 && renders[2] == 1 );

	renders.fill( 0 );
	manager.SetSearchQuery( "   " );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 1, 0, 0, 0 } ) );
	assert( subs[0]->Renders == 1 );

	// Invalid navigation preserves search. Valid navigation exits it, even for
	// the page/subpage that is already selected, and requests a one-shot UI reset.
	manager.SetSearchQuery( "#selected" );
	manager.SetActivePage( "missing" );
	assert( !manager.ConsumeSearchReset() );
	renders.fill( 0 );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 1, 0, 0, 1 } ) );

	manager.SetActivePage( "two" );
	assert( manager.ConsumeSearchReset() && !manager.ConsumeSearchReset() );
	assert( manager.GetActivePageId() == "two" && manager.GetActiveSubPageId() == "first" );
	renders.fill( 0 );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 0, 0, 1, 0 } ) );

	manager.SetSearchQuery( "#selected" );
	manager.SetActivePage( "two" );
	assert( manager.ConsumeSearchReset() );
	renders.fill( 0 );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 0, 0, 1, 0 } ) );

	manager.SetSearchQuery( "#selected" );
	manager.SetActiveSubPage( "missing" );
	assert( !manager.ConsumeSearchReset() );
	manager.SetActiveSubPage( "second" );
	assert( manager.ConsumeSearchReset() );
	manager.SetSearchQuery( "#selected" );
	manager.SetActiveSubPage( "second" );
	assert( manager.ConsumeSearchReset() && !manager.ConsumeSearchReset() );
	renders.fill( 0 );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 0, 0, 0, 1 } ) );

	manager.SetSearchQuery( "#selected" );
	manager.SetActivePage( "one" );
	assert( manager.ConsumeSearchReset() );
	renders.fill( 0 );
	manager.RenderActivePage();
	assert( ( renders == std::array<int, 4>{ 1, 0, 0, 0 } ) );
}
