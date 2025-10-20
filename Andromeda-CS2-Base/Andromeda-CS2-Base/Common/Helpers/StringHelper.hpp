#pragma once

#include <Common/Common.hpp>
#include <vector>

auto unicode_to_utf8( const std::wstring& unicode )->std::string;
auto unicode_to_ansi( const std::wstring& str )->std::string;

auto ansi_to_unicode( const std::string& str )->std::wstring;

auto ansi_to_utf8( const std::string& str ) -> std::string;
auto utf8_to_ansi( const std::string& str ) -> std::string;

auto SplitString( const std::string& text , const std::string& delims ) -> std::vector<std::string>;
auto GetBufferFmtString( const char* fmt , ... ) -> std::string;
