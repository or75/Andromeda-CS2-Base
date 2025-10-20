#pragma once

#include <Common/Common.hpp>

namespace Settings
{
	namespace Visual
	{
		inline auto Active = true;
		inline auto Team = true;
		inline auto Enemy = true;
		inline auto PlayerBox = true;

		inline auto PlayerBoxType = 3;
	}
	namespace Misc
	{
		inline auto MenuAlpha = 200;
		inline auto MenuStyle = 0;
	}
	namespace Colors
	{
		namespace Visual
		{
			inline float PlayerBoxTT[4] = { 255.f / 255.f , 75.f / 255.f , 75.f / 255.f  , 1.f };
			inline float PlayerBoxTT_Visible[4] = { 0 , 1.f , 0.f , 1.f };
			inline float PlayerBoxCT[4] = { 65.f / 255.f , 200 / 255.f , 255.f / 255.f , 1.f };
			inline float PlayerBoxCT_Visible[4] = { 0 , 1.f , 0.f , 1.f };
		}
	}
}
