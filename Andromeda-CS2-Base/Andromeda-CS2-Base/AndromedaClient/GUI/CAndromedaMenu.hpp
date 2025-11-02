#pragma once

#include <Common/Common.hpp>

class CAndromedaMenu final
{
public:
	auto OnRenderMenu() -> void;

private:
	auto RenderCheckBox( const char* szTitle , const char* szStrID , bool& SettingsItem ) -> bool;
	auto RenderComboBox( const char* szTitle , const char* szStrID , int& v , const char* Items[] , int ItemsCount ) -> bool;
	auto RenderColorEdit( const char* szTitle , const char* szStrID , float* Color ) -> bool;
	auto RenderSliderInt( const char* szTitle , const char* szStrID , int& Value , int Min , int Max ) -> bool;
};

auto GetAndromedaMenu() -> CAndromedaMenu*;
