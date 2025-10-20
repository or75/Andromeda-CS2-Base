#pragma once

#include <Common/Common.hpp>
#include <FW1FontWrapper/FW1FontWrapper.h>

#include <AndromedaClient/Fonts/CFont.hpp>

class CFontManager final
{
public:
	auto FirstInitFonts() -> void;

public:
	CFont m_VerdanaFont;

private:
	IFW1Factory* m_pFW1Factory = nullptr;

private:
	bool m_bInit = false;
};

auto GetFontManager() -> CFontManager*;
