#include "CAndromedaGUI.hpp"

#include <ShlObj_core.h>

#include <ImGui/imgui_impl_win32.h>
#include <ImGui/imgui_impl_dx11.h>
#include <ImGui/im_anim.h>

#include <DllLauncher.hpp>
#include <Common/Helpers/StringHelper.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/IEngineToClient.hpp>
#include <CS2/SDK/SDL3/SDL3_Functions.hpp>

#include <CS2/Hook/Hook_IsRelativeMouseMode.hpp>

#include <AndromedaClient/CAndromedaClient.hpp>
#include <AndromedaClient/Settings/Settings.hpp>
#include <AndromedaClient/Fonts/FontAwesome7ProIcons.hpp>

#include <AndromedaClient/GUI/GitMenu/GitMenu.hpp>
#include <AndromedaClient/GUI/GitMenu/Core/CStyleManager.hpp>
#include <AndromedaClient/GUI/GitMenu/Core/CResourceManager.hpp>

static CAndromedaGUI g_AndromedaGUI{};

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler( HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam );

auto CAndromedaGUI::OnInit( IDXGISwapChain* pSwapChain ) -> void
{
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;

	if ( FAILED( pSwapChain->GetDevice( IID_PPV_ARGS( &m_pDevice ) ) ) )
	{
		DEV_LOG( "[error] CAndromedaGUI::OnInit: #1\n" );
		return;
	}

	m_pDevice->GetImmediateContext( &m_pDeviceContext );

	if ( FAILED( pSwapChain->GetDesc( &SwapChainDesc ) ) )
	{
		DEV_LOG( "[error] CAndromedaGUI::OnInit: #2\n" );
		return;
	}

	m_hCS2Window = SwapChainDesc.OutputWindow;

	m_pImGuiContext = ImGui::CreateContext();

	m_GuiFile = GetDllDir() + GUI_FILE;

	if ( !m_pFreeType_Font )
		m_pFreeType_Font = new FreeTypeBuild();

	ImGui::SetCurrentContext( m_pImGuiContext );

	ImGui::GetIO().IniFilename = m_GuiFile.c_str();
	ImGui::GetIO().LogFilename = "";

	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NavEnableKeyboard;

	ImGui::GetIO().BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	ImGui_ImplWin32_Init( m_hCS2Window );
	ImGui_ImplDX11_Init( m_pDevice , m_pDeviceContext );

	InitFont();
	UpdateStyle();

	GetResourceManager()->LoadAll();
	GetGitMenu()->Init();

	m_WndProc_o = (WNDPROC)SetWindowLongPtrA( m_hCS2Window , GWLP_WNDPROC , (LONG_PTR)GUI_WndProc );

	m_bInit = true;
}

auto CAndromedaGUI::OnDestroy() -> void
{
	SetWindowLongPtrA( m_hCS2Window , GWLP_WNDPROC , (LONG_PTR)GetAndromedaGUI()->m_WndProc_o );

	m_bVisible = false;

	if ( m_pFreeType_Font )
	{
		delete m_pFreeType_Font;
		m_pFreeType_Font = nullptr;
	}

	ClearRenderTargetView();

	GetGitMenu()->Shutdown();
	GetResourceManager()->Shutdown();

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();

	m_bInit = false;
}

auto CAndromedaGUI::InitFont() -> void
{
	ImGuiIO& io = ImGui::GetIO();

	static const ImWchar TahomaRanges[] =
	{
		0x0020, 0xFFFC,
		0,
	};

	static const ImWchar FontAwesome7ProIconsRanges[] =
	{
		0x0021, 0xFFFE,
		0,
	};

	wchar_t* szWindowsFontPath = nullptr;

	if ( SHGetKnownFolderPath( FOLDERID_Fonts , 0 , 0 , &szWindowsFontPath ) == S_OK )
	{
		std::wstring TahomaFont = std::wstring( szWindowsFontPath ) + L"\\Arial.ttf";

		m_pFontDefault = io.Fonts->AddFontFromFileTTF( unicode_to_utf8( TahomaFont ).c_str() , m_DefaulFontSize , nullptr , TahomaRanges );
	}

	m_pFontAwesome7ProIcons = io.Fonts->AddFontFromMemoryCompressedTTF( FontAwesome7ProIcons_compressed_data , FontAwesome7ProIcons_compressed_size , m_IconsFontSize , nullptr , FontAwesome7ProIconsRanges );

	CoTaskMemFree( szWindowsFontPath );
}

void CAndromedaGUI::OnPresent( IDXGISwapChain* pSwapChain )
{
	if ( !m_bInit )
		OnInit( pSwapChain );
	else
		OnRender( pSwapChain );
}

void CAndromedaGUI::OnResizeBuffers( IDXGISwapChain* pSwapChain )
{
	OnDestroy();
}
 
void CAndromedaGUI::OnRender( IDXGISwapChain* pSwapChain )
{
	if ( m_pFreeType_Font && m_pFreeType_Font->PreNewFrame() )
	{
		ImGui_ImplDX11_InvalidateDeviceObjects();
		ImGui_ImplDX11_CreateDeviceObjects();
	}
	else
	{
		if ( !m_pRenderTargetView )
		{
			ID3D11Texture2D* pBackBuffer = nullptr;

			pSwapChain->GetBuffer( 0 , IID_PPV_ARGS( &pBackBuffer ) );

			D3D11_RENDER_TARGET_VIEW_DESC RenderTargetDesc;

			memset( &RenderTargetDesc , 0 , sizeof( RenderTargetDesc ) );

			RenderTargetDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			RenderTargetDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2DMS;

			if ( pBackBuffer )
			{
				m_pDevice->CreateRenderTargetView( pBackBuffer , &RenderTargetDesc , &m_pRenderTargetView );
				pBackBuffer->Release();
			}
		}

		ImGui::SetCurrentContext( m_pImGuiContext );

		m_pDeviceContext->OMGetRenderTargets( 1 , &m_pMainRenderTarget , 0 );
		m_pDeviceContext->OMSetRenderTargets( 1 , &m_pRenderTargetView , 0 );

		auto* styleManager = GetStyleManager();
		const auto theme = Settings::Menu::MenuStyle == 1 ? CStyleManager::ETheme::Dark : CStyleManager::ETheme::Light;
		
		if ( styleManager->GetTheme() != theme )
			styleManager->SetTheme( theme );
		
		styleManager->SetDpiScale( Settings::Menu::MenuDPI );
		styleManager->ApplyPendingDpiScale();

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();

		iam_update_begin_frame();
		iam_clip_update( ImGui::GetIO().DeltaTime );

		GetAndromedaClient()->OnRender();

		if( IsVisible() )
			GetGitMenu()->ShowGitMenu( &m_bVisible );

		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData() );

		m_pDeviceContext->OMSetRenderTargets( 1 , &m_pMainRenderTarget , 0 );
	}
}

auto CAndromedaGUI::OnReopenGUI() -> void
{
	m_bVisible = !m_bVisible;

	ImGui::GetIO().MouseDrawCursor = m_bVisible;
	ShowCursor( !m_bVisible );

	IsRelativeMouseMode_o( SDK::Interfaces::InputSystem() , m_bVisible ? false : m_bMainActive );

	if ( m_bVisible )
	{
		if ( m_vecMousePosSave.x == 0.f && m_vecMousePosSave.y == 0.f )
			m_vecMousePosSave = ImGui::GetIO().DisplaySize / 2.f;

		ImGui::GetIO().MousePos = m_vecMousePosSave;

		if ( SDK::Interfaces::EngineToClient()->IsInGame() )
			GetSDL3Functions()->SDL_WarpMouseInWindow_o( nullptr , ImGui::GetIO().MousePos.x , ImGui::GetIO().MousePos.y );
	}
	else
	{
		m_vecMousePosSave = ImGui::GetIO().MousePos;
	}
}

LRESULT WINAPI CAndromedaGUI::GUI_WndProc( HWND hwnd , UINT uMsg , WPARAM wParam , LPARAM lParam )
{
	if ( uMsg == WM_QUIT || uMsg == WM_CLOSE || uMsg == WM_DESTROY )
	{
		GetDllLauncher()->OnDestroy();
		return true;
	}

	if ( GetAndromedaGUI()->m_bInit )
	{
		if ( uMsg == WM_KEYUP && wParam == VK_INSERT )
			GetAndromedaGUI()->OnReopenGUI();

		if ( GetAndromedaGUI()->IsVisible() && ImGui_ImplWin32_WndProcHandler( hwnd , uMsg , wParam , lParam ) == 0 )
			return true;
	}

	return CallWindowProcA( GetAndromedaGUI()->m_WndProc_o , hwnd , uMsg , wParam , lParam );
}

auto CAndromedaGUI::UpdateStyle() -> void
{
	ImGui::SetCurrentContext( m_pImGuiContext );

	auto* styleManager = GetStyleManager();
	styleManager->SetDpiScale( Settings::Menu::MenuDPI );
	styleManager->ApplyTheme( Settings::Menu::MenuStyle == 1 ? CStyleManager::ETheme::Dark : CStyleManager::ETheme::Light , styleManager->GetDpiScale() );
}

bool CAndromedaGUI::FreeTypeBuild::PreNewFrame()
{
	if ( !WantRebuild )
		return false;

	auto* atlas = ImGui::GetIO().Fonts;

	// Apply per-source settings (these are read at glyph bake time).
	for ( auto n = 0; n < atlas->Sources.Size; n++ )
		atlas->Sources[n].RasterizerMultiply = RasterizerMultiply;

	// IMPORTANT: With the 1.92 dynamic atlas we must NOT call atlas->Clear()/Build()
	// to re-apply loader settings - Clear() destroys all fonts and their sources,
	// which leaves the atlas empty and makes ImGui fall back to the default font.
	// Instead, refresh the loader output in place (same sequence as the ImGui demo):
	// destroy the baked output, swap the loader flags, then re-init the output.
	for ( auto* font : atlas->Fonts )
		ImFontAtlasFontDestroyOutput( atlas , font );

#ifdef IMGUI_ENABLE_FREETYPE
	if ( BuildMode == FontBuildMode::FreeType )
		atlas->SetFontLoader( ImGuiFreeType::GetFontLoader() );
#endif

	atlas->FontLoaderFlags = FreeTypeBuilderFlags;

	for ( auto* font : atlas->Fonts )
		ImFontAtlasFontInitOutput( atlas , font );

	WantRebuild = false;
	WantRebuild = false;

	return true;
}

auto CAndromedaGUI::ClearRenderTargetView() -> void
{
	if ( m_pRenderTargetView )
	{
		m_pRenderTargetView->Release();
		m_pRenderTargetView = nullptr;
	}
}

auto GetAndromedaGUI() -> CAndromedaGUI*
{
	return &g_AndromedaGUI;
}
