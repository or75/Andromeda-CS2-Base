#pragma once

#include <Common/Common.hpp>

#include <ImGui/imgui.h>
#include <FW1FontWrapper/FW1FontWrapper.h>

class CFont final
{
public:
	auto InitFont( IFW1Factory* pFW1Factory , std::wstring Name , float FontSize = 12.f ) -> void;

public:
	auto DrawString( int x , int y , ImColor Color , int Flags , const char* fmt , ... ) -> void;
	auto DrawString( ImVec2 Pos , ImColor Color , int Flags , const char* fmt , ... ) -> void;
	auto GetStringLayoutRect( int Flags , FW1_RECTF* pRECTF , const char* fmt , ... ) -> FW1_RECTF;

public:
	inline auto GetFontSize() -> float
	{
		return m_FontSize;
	}

private:
	IFW1FontWrapper* m_pFontWrapper = nullptr;
	std::wstring m_FontName;
	float m_FontSize = 0.f;

private:
	static constexpr auto g_BufferSize = 64;
};
