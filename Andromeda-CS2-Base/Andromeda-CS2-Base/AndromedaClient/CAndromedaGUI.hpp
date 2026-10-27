#pragma once

#include <Common/Common.hpp>
#include <d3d11.h>

#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>

#include <ImGui/Misc/freetype/imgui_freetype.h>

#include <CS2/SDK/SDK.hpp>

class IAndromedaGUI
{
public:
	virtual bool IsVisible() = 0;
	virtual bool IsInited() = 0;

public:
	virtual void OnPresent( IDXGISwapChain* pSwapChain ) = 0;
	virtual void OnResizeBuffers( IDXGISwapChain* pSwapChain ) = 0;
	virtual void OnRender( IDXGISwapChain* pSwapChain ) = 0;
};

class CAndromedaGUI final : public IAndromedaGUI
{
public:
	auto OnInit( IDXGISwapChain* pSwapChain ) -> void;
	auto OnDestroy() -> void;

public:
	auto InitFont() -> void;
	auto UpdateStyle() -> void;

public:
	virtual bool IsVisible() override
	{
		return m_bVisible;
	}

	virtual bool IsInited() override
	{
		return m_bInit;
	}

public:
	virtual void OnPresent( IDXGISwapChain* pSwapChain ) override;
	virtual void OnResizeBuffers( IDXGISwapChain* pSwapChain ) override;
	virtual void OnRender( IDXGISwapChain* pSwapChain ) override;

public:
	auto OnReopenGUI() -> void;

public:
	static LRESULT WINAPI GUI_WndProc( HWND hwnd , UINT uMsg , WPARAM wParam , LPARAM lParam );

public:
	auto GetDevice() -> ID3D11Device* { return m_pDevice; }
	auto GetDeviceContext() -> ID3D11DeviceContext* { return m_pDeviceContext; }

public:
	auto ClearRenderTargetView() -> void;

private:
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_pDeviceContext = nullptr;
	ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
	ID3D11RenderTargetView* m_pMainRenderTarget = nullptr;

private:
	ImGuiContext* m_pImGuiContext = nullptr;

public:
	auto GetDefaultFont() -> ImFont* { return m_pFontDefault; }
	auto GetFontAwesome7ProIcons() -> ImFont* { return m_pFontAwesome7ProIcons; }

	ImFont* m_pFontDefault = nullptr;
	ImFont* m_pFontAwesome7ProIcons = nullptr;

private:
	std::string m_GuiFile;

public:
	HWND m_hCS2Window = nullptr;

private:
	WNDPROC	m_WndProc_o = nullptr;

public:
	bool m_bInit = false;
	bool m_bMainActive = false;
	bool m_bVisible = false;

	static constexpr auto m_DefaulFontSize = 16.f;
	static constexpr auto m_IconsFontSize = 16.f;

private:
	ImVec2 m_vecMousePosSave;

private:
	struct FreeTypeBuild
	{
		enum class FontBuildMode { FreeType };
		FontBuildMode BuildMode = FontBuildMode::FreeType;

		bool WantRebuild = true;
		float RasterizerMultiply = 1.0f;
		unsigned int FreeTypeBuilderFlags = 0/*ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_MonoHinting*/;

		bool PreNewFrame();
		void ResetBuildFont() { WantRebuild = true; };
	};

	FreeTypeBuild* m_pFreeType_Font = nullptr;
};

auto GetAndromedaGUI() -> CAndromedaGUI*;
