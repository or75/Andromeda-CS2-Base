#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

namespace GitMenu
{
	class ISubPage;

	class IPage
	{
	public:
		virtual ~IPage() = default;

		virtual auto GetName() const -> const char* = 0;
		virtual auto GetDisplayName() const -> const char* = 0;
		virtual auto GetIcon() const -> ImTextureRef { return ImTextureRef(); }

		// UTF-8 glyph literal, e.g. u8"\uf015"; used when no texture is available.
		virtual auto GetFontAwesomeIcon() const -> const char8_t* { return nullptr; }

		virtual auto GetSubPageCount() const -> int { return 0; }
		virtual auto GetSubPageId( int index ) const -> const char* { (void)index; return nullptr; }
		virtual auto GetSubPage( int index ) const -> ISubPage* { (void)index; return nullptr; }

		virtual auto OnRender() -> void = 0;
		virtual auto OnEnter() -> void {}   // Called when page becomes active
		virtual auto OnLeave() -> void {}   // Called when page becomes inactive
	};
}
