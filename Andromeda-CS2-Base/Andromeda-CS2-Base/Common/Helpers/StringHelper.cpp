#include "StringHelper.hpp"

auto unicode_to_utf8( const std::wstring& str ) -> std::string
{
	char utf8[2048] = { 0 };
	WideCharToMultiByte( CP_UTF8 , 0u , str.c_str() , -1 , utf8 , 2048 , nullptr , nullptr);
	return utf8;
}

auto unicode_to_ansi( const std::wstring& str ) -> std::string
{
	char ansi[2048] = { 0 };
	WideCharToMultiByte( CP_ACP , 0u , str.c_str() , -1 , ansi , 2048 , nullptr , nullptr);
	return ansi;
}

auto ansi_to_unicode( const std::string& str )->std::wstring
{
	wchar_t unicode[2048] = { 0 };
	MultiByteToWideChar( CP_UTF8 , 0 , str.c_str() , -1 , unicode , 2048 );
	return unicode;
}

auto ansi_to_utf8( const std::string& str ) -> std::string
{
	// ansi to unicode
	wchar_t unicode[2048] = { 0 };
	MultiByteToWideChar( CP_ACP , 0u , str.c_str() , -1 , unicode , 2048 );
	// unicode to utf8
	return unicode_to_utf8( unicode );
}

auto utf8_to_ansi( const std::string& str ) -> std::string
{
	// utf8 to unicode
	wchar_t unicode[2048] = { 0 };
	MultiByteToWideChar( CP_UTF8 , 0u , str.c_str() , -1 , unicode , 2048 );
	// unicode to ansi
	return unicode_to_ansi( unicode );
}

auto SplitString( const std::string& text , const std::string& delims ) -> std::vector<std::string>
{
	std::vector<std::string> tokens;
	size_t start = text.find_first_not_of( delims ) , end = 0;

	while ( ( end = text.find_first_of( delims , start ) ) != std::string::npos )
	{
		tokens.push_back( text.substr( start , end - start ) );
		start = text.find_first_not_of( delims , end );
	}

	if ( start != std::string::npos )
		tokens.push_back( text.substr( start ) );

	return tokens;
}

auto GetBufferFmtString( const char* fmt , ... ) -> std::string
{
	char Buffer[256] = { 0 };

	va_list va_alist;
	va_start( va_alist , fmt );
	vsnprintf( Buffer , sizeof( Buffer ) , fmt , va_alist );
	va_end( va_alist );

	return std::string( Buffer );
}
