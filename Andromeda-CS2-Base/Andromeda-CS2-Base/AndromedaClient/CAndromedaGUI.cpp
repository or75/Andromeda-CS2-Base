#include "CAndromedaGUI.hpp"

#include <ShlObj_core.h>

#include <ImGui/imgui_impl_win32.h>
#include <ImGui/imgui_impl_dx11.h>

#include <DllLauncher.hpp>
#include <Common/Helpers/StringHelper.hpp>

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/IEngineToClient.hpp>
#include <CS2/SDK/SDL3/SDL3_Functions.hpp>

#include <CS2/Hook/Hook_IsRelativeMouseMode.hpp>

#include <AndromedaClient/CAndromedaClient.hpp>
#include <AndromedaClient/Settings/Settings.hpp>
#include <AndromedaClient/Fonts/FontAwesomeIcon.hpp>

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

	m_GuiFile = GetDllDir() + XorStr( GUI_FILE );

	if ( !m_pFreeType_Font )
		m_pFreeType_Font = new FreeTypeBuild();

	ImGui::SetCurrentContext( m_pImGuiContext );

	ImGui::GetIO().IniFilename = m_GuiFile.c_str();
	ImGui::GetIO().LogFilename = "";

	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	ImGui::GetIO().BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	ImGui_ImplWin32_Init( m_hCS2Window );
	ImGui_ImplDX11_Init( m_pDevice , m_pDeviceContext );

	InitFont();
	UpdateStyle();

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

	static const ImWchar AwesomeIconRanges[] =
	{
		0x002D, 0x007A,
		ICON_MIN_FA, ICON_MAX_FA,
		0
	};

	wchar_t* szWindowsFontPath = nullptr;

	if ( SHGetKnownFolderPath( FOLDERID_Fonts , 0 , 0 , &szWindowsFontPath ) == S_OK )
	{
		std::wstring TahomaFont = std::wstring( szWindowsFontPath ) + L"\\tahoma.ttf";
		io.Fonts->AddFontFromFileTTF( unicode_to_utf8( TahomaFont ).c_str() , 15.f , nullptr , TahomaRanges );
	}

	m_pFontAwesomeIcons = io.Fonts->AddFontFromMemoryCompressedTTF( FontAwesomeIcon_compressed_data , FontAwesomeIcon_compressed_size , 25.f , nullptr , AwesomeIconRanges );

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

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();

		GetAndromedaClient()->OnRender();

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

auto CAndromedaGUI::SetIndigoStyle() -> void
{
	auto& style = ImGui::GetStyle();
	auto& colors = style.Colors;

	float roundness = 2.0f;

	style.WindowBorderSize = 1.0f;
	style.FrameBorderSize = 1.0f;
	style.WindowMinSize = ImVec2( 75.f , 50.f );
	style.FramePadding = ImVec2( 5 , 5 );
	style.ItemSpacing = ImVec2( 6 , 5 );
	style.ItemInnerSpacing = ImVec2( 2 , 4 );
	style.Alpha = 1.0f;
	style.WindowRounding = 0.f;
	style.FrameRounding = roundness;
	style.PopupRounding = 0;
	style.PopupBorderSize = 1.f;
	style.IndentSpacing = 6.0f;
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = roundness;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = roundness;

	style.AntiAliasedFill = true;
	style.AntiAliasedLines = true;
	style.AntiAliasedLinesUseTex = true;

	colors[ImGuiCol_Text] = ImVec4( 1.00f , 1.00f , 1.00f , 1.00f );
	colors[ImGuiCol_TextDisabled] = ImVec4( 0.50f , 0.50f , 0.50f , 1.00f );

	colors[ImGuiCol_WindowBg] = ImVec4( 0.20f , 0.23f , 0.31f , 1.00f );
	colors[ImGuiCol_ChildBg] = ImVec4( 0.20f , 0.23f , 0.31f , 1.00f );
	colors[ImGuiCol_PopupBg] = ImVec4( 0.20f , 0.23f , 0.31f , 1.00f );

	colors[ImGuiCol_Border] = ImVec4( 0.f , 0.f , 0.f , 1.00f );
	colors[ImGuiCol_BorderShadow] = ImVec4( 0.00f , 0.00f , 0.00f , 0.00f );

	colors[ImGuiCol_FrameBg] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );
	colors[ImGuiCol_FrameBgHovered] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );
	colors[ImGuiCol_FrameBgActive] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );

	colors[ImGuiCol_TitleBg] = ImVec4( 0.00f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_TitleBgActive] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4( 0.10f , 0.69f , 1.00f , 1.00f );

	colors[ImGuiCol_MenuBarBg] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );

	colors[ImGuiCol_ScrollbarBg] = ImVec4( 0.00f , 0.00f , 0.00f , 0.00f );
	colors[ImGuiCol_ScrollbarGrab] = ImVec4( 0.39f , 0.44f , 0.56f , 1.00f );
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.12f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );

	colors[ImGuiCol_CheckMark] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );

	colors[ImGuiCol_SliderGrab] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );
	colors[ImGuiCol_SliderGrabActive] = ImVec4( 0.10f , 0.69f , 1.00f , 1.00f );

	colors[ImGuiCol_Button] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );
	colors[ImGuiCol_ButtonHovered] = ImVec4( 0.12f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_ButtonActive] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );

	colors[ImGuiCol_Header] = ImVec4( 0.00f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_HeaderHovered] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );
	colors[ImGuiCol_HeaderActive] = ImVec4( 0.00f , 0.43f , 1.00f , 1.00f );

	colors[ImGuiCol_Separator] = ImVec4( 0.43f , 0.43f , 0.50f , 0.50f );
	colors[ImGuiCol_SeparatorHovered] = ImVec4( 0.10f , 0.40f , 0.75f , 0.78f );
	colors[ImGuiCol_SeparatorActive] = ImVec4( 0.10f , 0.40f , 0.75f , 1.00f );

	colors[ImGuiCol_ResizeGrip] = ImVec4( 0.26f , 0.59f , 0.98f , 0.25f );
	colors[ImGuiCol_ResizeGripHovered] = ImVec4( 0.26f , 0.59f , 0.98f , 0.67f );
	colors[ImGuiCol_ResizeGripActive] = ImVec4( 0.26f , 0.59f , 0.98f , 0.95f );

	colors[ImGuiCol_Tab] = ImVec4( 0.00f , 0.50f , 1.00f , 1.00f );
	colors[ImGuiCol_TabHovered] = ImVec4( 0.12f , 0.69f , 1.00f , 1.00f );

	colors[ImGuiCol_TabActive] = ImVec4( 0.12f , 0.69f , 1.00f , 1.00f );
	colors[ImGuiCol_TabUnfocused] = ImVec4( 0.07f , 0.10f , 0.15f , 0.97f );
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4( 0.14f , 0.26f , 0.42f , 1.00f );

	colors[ImGuiCol_PlotLines] = ImVec4( 0.61f , 0.61f , 0.61f , 1.00f );
	colors[ImGuiCol_PlotLinesHovered] = ImVec4( 1.00f , 0.43f , 0.35f , 1.00f );
	colors[ImGuiCol_PlotHistogram] = ImVec4( 0.10f , 0.69f , 1.00f , 1.00f );
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 1.00f , 0.60f , 0.00f , 1.00f );

	colors[ImGuiCol_TextSelectedBg] = ImVec4( 0.26f , 0.59f , 0.98f , 0.35f );
	colors[ImGuiCol_DragDropTarget] = ImVec4( 1.00f , 1.00f , 0.00f , 0.90f );

	colors[ImGuiCol_NavHighlight] = ImVec4( 0.26f , 0.59f , 0.98f , 1.00f );
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 1.00f , 1.00f , 1.00f , 0.70f );
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.20f );

	colors[ImGuiCol_ModalWindowDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.35f );
	colors[ImGuiCol_WindowShadow] = ImVec4( 0.f , 0.f , 1.f , 1.f );
}

auto CAndromedaGUI::SetVermillionStyle() -> void
{
	auto& style = ImGui::GetStyle();
	auto& colors = style.Colors;

	float roundness = 2.0f;

	style.WindowBorderSize = 1.0f;
	style.FrameBorderSize = 1.0f;
	style.WindowMinSize = ImVec2( 75.f , 50.f );
	style.FramePadding = ImVec2( 5 , 5 );
	style.ItemSpacing = ImVec2( 6 , 5 );
	style.ItemInnerSpacing = ImVec2( 2 , 4 );
	style.Alpha = 1.0f;
	style.WindowRounding = 0.f;
	style.FrameRounding = roundness;
	style.PopupRounding = 0;
	style.PopupBorderSize = 1.f;
	style.IndentSpacing = 6.0f;
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = roundness;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = roundness;

	style.AntiAliasedFill = true;
	style.AntiAliasedLines = true;
	style.AntiAliasedLinesUseTex = true;

	colors[ImGuiCol_Text] = ImVec4( 1.00f , 1.00f , 1.00f , 0.75f );
	colors[ImGuiCol_TextDisabled] = ImVec4( 1.00f , 0.18f , 0.29f , 0.78f );

	colors[ImGuiCol_WindowBg] = ImVec4( 0.17f , 0.20f , 0.25f , 1.00f );
	colors[ImGuiCol_ChildBg] = ImVec4( 0.20f , 0.22f , 0.27f , 0.57f );
	colors[ImGuiCol_PopupBg] = ImVec4( 0.17f , 0.20f , 0.25f , 1.00f );

	colors[ImGuiCol_Border] = ImVec4( 0.00f , 0.00f , 0.00f , 1.00f );
	colors[ImGuiCol_BorderShadow] = ImVec4( 0.00f , 0.00f , 0.00f , 0.00f );

	colors[ImGuiCol_FrameBg] = ImVec4( 0.37f , 0.36f , 0.46f , 0.24f );
	colors[ImGuiCol_FrameBgHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.78f );
	colors[ImGuiCol_FrameBgActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_TitleBg] = ImVec4( 0.20f , 0.22f , 0.27f , 1.00f );
	colors[ImGuiCol_TitleBgActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4( 0.20f , 0.22f , 0.27f , 0.75f );

	colors[ImGuiCol_MenuBarBg] = ImVec4( 0.20f , 0.22f , 0.27f , 0.47f );

	colors[ImGuiCol_ScrollbarBg] = ImVec4( 0.20f , 0.22f , 0.27f , 1.00f );
	colors[ImGuiCol_ScrollbarGrab] = ImVec4( 0.09f , 0.15f , 0.16f , 1.00f );
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.78f );
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_CheckMark] = ImVec4( 0.71f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_SliderGrab] = ImVec4( 0.78f , 0.18f , 0.29f , 0.37f );
	colors[ImGuiCol_SliderGrabActive] = ImVec4( 0.92f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Button] = ImVec4( 0.65f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_ButtonHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.86f );
	colors[ImGuiCol_ButtonActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Header] = ImVec4( 0.78f , 0.18f , 0.29f , 0.76f );
	colors[ImGuiCol_HeaderHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.86f );
	colors[ImGuiCol_HeaderActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Separator] = ImVec4( 0.15f , 0.00f , 0.00f , 0.35f );
	colors[ImGuiCol_SeparatorHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.59f );
	colors[ImGuiCol_SeparatorActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_ResizeGrip] = ImVec4( 0.78f , 0.18f , 0.29f , 0.63f );
	colors[ImGuiCol_ResizeGripHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.78f );
	colors[ImGuiCol_ResizeGripActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Tab] = ImVec4( 0.78f , 0.18f , 0.29f , 0.76f );
	colors[ImGuiCol_TabHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.86f );
	colors[ImGuiCol_TabActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_TabUnfocused] = ImVec4( 0.07f , 0.10f , 0.15f , 0.97f );
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4( 0.14f , 0.26f , 0.42f , 1.00f );

	colors[ImGuiCol_PlotLines] = ImVec4( 0.78f , 0.93f , 0.89f , 0.63f );
	colors[ImGuiCol_PlotLinesHovered] = ImVec4( 0.92f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_PlotHistogram] = ImVec4( 0.86f , 0.93f , 0.89f , 0.63f );
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 0.92f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_TextSelectedBg] = ImVec4( 0.92f , 0.18f , 0.29f , 0.43f );
	colors[ImGuiCol_DragDropTarget] = ImVec4( 1.00f , 1.00f , 0.00f , 0.90f );

	colors[ImGuiCol_NavHighlight] = ImVec4( 0.45f , 0.45f , 0.90f , 0.80f );
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 1.00f , 1.00f , 1.00f , 0.70f );
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.20f );

	colors[ImGuiCol_ModalWindowDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.35f );
	colors[ImGuiCol_WindowShadow] = ImVec4( 1.f , 0.f , 0.f , 1.f );
}

auto CAndromedaGUI::SetClassicSteamStyle() -> void
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.6000000238418579f;
	style.WindowPadding = ImVec2( 8.0f , 8.0f );
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2( 32.0f , 32.0f );
	style.WindowTitleAlign = ImVec2( 0.0f , 0.5f );
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2( 4.0f , 3.0f );
	style.FrameRounding = 0.0f;
	style.FrameBorderSize = 1.0f;
	style.ItemSpacing = ImVec2( 8.0f , 4.0f );
	style.ItemInnerSpacing = ImVec2( 4.0f , 4.0f );
	style.CellPadding = ImVec2( 4.0f , 2.0f );
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 14.0f;
	style.ScrollbarRounding = 0.0f;
	style.GrabMinSize = 10.0f;
	style.GrabRounding = 0.0f;
	style.TabRounding = 0.0f;
	style.TabBorderSize = 0.0f;
	style.TabCloseButtonMinWidthUnselected = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2( 0.5f , 0.5f );
	style.SelectableTextAlign = ImVec2( 0.0f , 0.0f );

	style.Colors[ImGuiCol_Text] = ImVec4( 1.0f , 1.0f , 1.0f , 1.0f );
	style.Colors[ImGuiCol_TextDisabled] = ImVec4( 0.4980392158031464f , 0.4980392158031464f , 0.4980392158031464f , 1.0f );
	style.Colors[ImGuiCol_WindowBg] = ImVec4( 0.2862745225429535f , 0.3372549116611481f , 0.2588235437870026f , 1.0f );
	style.Colors[ImGuiCol_ChildBg] = ImVec4( 0.2862745225429535f , 0.3372549116611481f , 0.2588235437870026f , 1.0f );
	style.Colors[ImGuiCol_PopupBg] = ImVec4( 0.239215686917305f , 0.2666666805744171f , 0.2000000029802322f , 1.0f );
	style.Colors[ImGuiCol_Border] = ImVec4( 0.5372549295425415f , 0.5686274766921997f , 0.5098039507865906f , 0.5f );
	style.Colors[ImGuiCol_BorderShadow] = ImVec4( 0.1372549086809158f , 0.1568627506494522f , 0.1098039224743843f , 0.5199999809265137f );
	style.Colors[ImGuiCol_FrameBg] = ImVec4( 0.239215686917305f , 0.2666666805744171f , 0.2000000029802322f , 1.0f );
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4( 0.2666666805744171f , 0.2980392277240753f , 0.2274509817361832f , 1.0f );
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4( 0.2980392277240753f , 0.3372549116611481f , 0.2588235437870026f , 1.0f );
	style.Colors[ImGuiCol_TitleBg] = ImVec4( 0.239215686917305f , 0.2666666805744171f , 0.2000000029802322f , 1.0f );
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4( 0.2862745225429535f , 0.3372549116611481f , 0.2588235437870026f , 1.0f );
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4( 0.0f , 0.0f , 0.0f , 0.5099999904632568f );
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4( 0.239215686917305f , 0.2666666805744171f , 0.2000000029802322f , 1.0f );
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4( 0.3490196168422699f , 0.4196078479290009f , 0.3098039329051971f , 1.0f );
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4( 0.2784313857555389f , 0.3176470696926117f , 0.239215686917305f , 1.0f );
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.2470588237047195f , 0.2980392277240753f , 0.2196078449487686f , 1.0f );
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( 0.2274509817361832f , 0.2666666805744171f , 0.2078431397676468f , 1.0f );
	style.Colors[ImGuiCol_CheckMark] = ImVec4( 0.5882353186607361f , 0.5372549295425415f , 0.1764705926179886f , 1.0f );
	style.Colors[ImGuiCol_SliderGrab] = ImVec4( 0.3490196168422699f , 0.4196078479290009f , 0.3098039329051971f , 1.0f );
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4( 0.5372549295425415f , 0.5686274766921997f , 0.5098039507865906f , 0.5f );
	style.Colors[ImGuiCol_Button] = ImVec4( 0.2862745225429535f , 0.3372549116611481f , 0.2588235437870026f , 0.4000000059604645f );
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4( 0.3490196168422699f , 0.4196078479290009f , 0.3098039329051971f , 1.0f );
	style.Colors[ImGuiCol_ButtonActive] = ImVec4( 0.5372549295425415f , 0.5686274766921997f , 0.5098039507865906f , 0.5f );
	style.Colors[ImGuiCol_Header] = ImVec4( 0.3490196168422699f , 0.4196078479290009f , 0.3098039329051971f , 1.0f );
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4( 0.3490196168422699f , 0.4196078479290009f , 0.3098039329051971f , 0.6000000238418579f );
	style.Colors[ImGuiCol_HeaderActive] = ImVec4( 0.5372549295425415f , 0.5686274766921997f , 0.5098039507865906f , 0.5f );
	style.Colors[ImGuiCol_Separator] = ImVec4( 0.1372549086809158f , 0.1568627506494522f , 0.1098039224743843f , 1.0f );
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4( 0.5372549295425415f , 0.5686274766921997f , 0.5098039507865906f , 1.0f );
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4( 0.5882353186607361f , 0.5372549295425415f , 0.1764705926179886f , 1.0f );
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4( 0.1882352977991104f , 0.2274509817361832f , 0.1764705926179886f , 0.0f );
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4( 0.5372549295425415f , 0.5686274766921997f , 0.5098039507865906f , 1.0f );
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4( 0.5882353186607361f , 0.5372549295425415f , 0.1764705926179886f , 1.0f );
	style.Colors[ImGuiCol_Tab] = ImVec4( 0.3490196168422699f , 0.4196078479290009f , 0.3098039329051971f , 1.0f );
	style.Colors[ImGuiCol_TabHovered] = ImVec4( 0.5372549295425415f , 0.5686274766921997f , 0.5098039507865906f , 0.7799999713897705f );
	style.Colors[ImGuiCol_TabActive] = ImVec4( 0.5882353186607361f , 0.5372549295425415f , 0.1764705926179886f , 1.0f );
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4( 0.239215686917305f , 0.2666666805744171f , 0.2000000029802322f , 1.0f );
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4( 0.3490196168422699f , 0.4196078479290009f , 0.3098039329051971f , 1.0f );
	style.Colors[ImGuiCol_PlotLines] = ImVec4( 0.6078431606292725f , 0.6078431606292725f , 0.6078431606292725f , 1.0f );
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4( 0.5882353186607361f , 0.5372549295425415f , 0.1764705926179886f , 1.0f );
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4( 1.0f , 0.7764706015586853f , 0.2784313857555389f , 1.0f );
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 1.0f , 0.6000000238418579f , 0.0f , 1.0f );
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4( 0.1882352977991104f , 0.1882352977991104f , 0.2000000029802322f , 1.0f );
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4( 0.3098039329051971f , 0.3098039329051971f , 0.3490196168422699f , 1.0f );
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4( 0.2274509817361832f , 0.2274509817361832f , 0.2470588237047195f , 1.0f );
	style.Colors[ImGuiCol_TableRowBg] = ImVec4( 0.0f , 0.0f , 0.0f , 0.0f );
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4( 1.0f , 1.0f , 1.0f , 0.05999999865889549f );
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4( 0.5882353186607361f , 0.5372549295425415f , 0.1764705926179886f , 1.0f );
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4( 0.729411780834198f , 0.6666666865348816f , 0.239215686917305f , 1.0f );
	style.Colors[ImGuiCol_NavHighlight] = ImVec4( 0.5882353186607361f , 0.5372549295425415f , 0.1764705926179886f , 1.0f );
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 1.0f , 1.0f , 1.0f , 0.699999988079071f );
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4( 0.800000011920929f , 0.800000011920929f , 0.800000011920929f , 0.2000000029802322f );
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4( 0.800000011920929f , 0.800000011920929f , 0.800000011920929f , 0.3499999940395355f );
	style.Colors[ImGuiCol_WindowShadow] = ImVec4( 1.f , 1.f , 0.f , 1.f );
}

auto CAndromedaGUI::UpdateStyle() -> void
{
	ImGui::SetCurrentContext( m_pImGuiContext );

	if ( Settings::Misc::MenuStyle == EAndromedaGuiStyle_t::ANDROMEDA_GUI_STYLE_INDIGO )
		SetIndigoStyle();
	else if ( Settings::Misc::MenuStyle == EAndromedaGuiStyle_t::ANDROMEDA_GUI_STYLE_VERMILLION )
		SetVermillionStyle();
	else if ( Settings::Misc::MenuStyle == EAndromedaGuiStyle_t::ANDROMEDA_GUI_STYLE_CLASSIC_STEAM )
		SetClassicSteamStyle();
}

bool CAndromedaGUI::FreeTypeBuild::PreNewFrame()
{
	if ( !WantRebuild )
		return false;

	ImFontAtlas* atlas = ImGui::GetIO().Fonts;

	for ( int n = 0; n < atlas->Sources.Size; n++ )
		( (ImFontConfig*)&atlas->Sources[n] )->RasterizerMultiply = RasterizerMultiply;

#ifdef IMGUI_ENABLE_FREETYPE
	if ( BuildMode == FontBuildMode::FreeType )
	{
		atlas->FontBuilderIO = ImGuiFreeType::GetBuilderForFreeType();
		atlas->FontBuilderFlags = FreeTypeBuilderFlags;
	}
#endif

	atlas->Build();
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
