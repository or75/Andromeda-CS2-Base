#pragma once

#include "PageWithSubPages.hpp"

#include <string_view>

namespace GitMenu
{
	class CDebugSchemaEditorSubPage final : public ISubPage
	{
	public:
		auto GetDisplayName() const -> const char* override { return "Schema Editor"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf121"; }
	};

	class CDebugLogsSubPage final : public ISubPage
	{
	public:
		CDebugLogsSubPage();

		auto GetDisplayName() const -> const char* override { return "Debug Logs"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf03a"; }
	};

	class CDebugPage final : public PageWithSubPages
	{
	public:
		static constexpr std::string_view ErrorPrefix = "[error]";
		static constexpr std::string_view MinusPrefix = "[-]";
		static constexpr std::string_view InfoPrefix = "[info]";
		static constexpr std::string_view DebugPrefix = "[debug]";
		static constexpr std::string_view WarningPrefix = "[warning]";
		static constexpr std::string_view SuccessPrefix = "[success]";
		static constexpr std::string_view PlusPrefix = "[+]";

		CDebugPage()
		{
			AddSubPage( "schema_editor" , std::make_unique<CDebugSchemaEditorSubPage>() );
			AddSubPage( "debug_logs" , std::make_unique<CDebugLogsSubPage>() );
		}

		auto GetName() const -> const char* override { return "Debug##Debug"; }
		auto GetDisplayName() const -> const char* override { return "Debug"; }
		auto GetFontAwesomeIcon() const -> const char8_t* override { return u8"\uf188"; }
	};
}
