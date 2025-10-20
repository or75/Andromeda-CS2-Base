#pragma once

#include <Common/Common.hpp>
#include <d3d11.h>

#include <ImGui/imgui.h>
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

private:
	auto SetIndigoStyle() -> void;
	auto SetVermillionStyle() -> void;
	auto SetClassicSteamStyle() -> void;

	enum EAndromedaGuiStyle_t : uint32_t
	{
		ANDROMEDA_GUI_STYLE_INDIGO,
		ANDROMEDA_GUI_STYLE_VERMILLION,
		ANDROMEDA_GUI_STYLE_CLASSIC_STEAM,
	};

public:
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

private:
	ImVec2 m_vecMousePosSave;

public:
	ImFont* m_pFontAwesomeIcons = nullptr;

private:
	struct FreeTypeBuild
	{
		enum class FontBuildMode { FreeType };
		FontBuildMode BuildMode = FontBuildMode::FreeType;

		bool WantRebuild = true;
		float RasterizerMultiply = 1.0f;
		unsigned int FreeTypeBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_MonoHinting;

		bool PreNewFrame();
		void ResetBuildFont() { WantRebuild = true; };
	};

	FreeTypeBuild* m_pFreeType_Font = nullptr;
};

auto GetAndromedaGUI() -> CAndromedaGUI*;
