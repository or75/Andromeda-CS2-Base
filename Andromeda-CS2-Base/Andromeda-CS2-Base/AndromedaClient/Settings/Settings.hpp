#pragma once

#include <Common/Common.hpp>
#include <ImGui/imgui.h>

namespace Settings
{
	namespace Visual
	{
		inline auto Active = true;
		inline auto Team = true;
		inline auto Enemy = true;
		inline auto OnlyVisible = false;
		inline auto PlayerBox = true;
		inline auto BoneESP = true;
		inline auto BoneESPTeam = true;
		inline auto BoneESPEnemy = true;
		inline auto Glow = true;
		inline auto GlowTeam = true;
		inline auto GlowEnemy = true;

		inline auto PlayerBoxType = 3;
	}
	namespace Menu
	{
		inline auto MenuAlpha = 200;
		inline auto MenuStyle = 0;
	}
	namespace Colors
	{
		namespace Visual
		{
			inline ImVec4 PlayerBoxTT = { 255.f / 255.f , 75.f / 255.f , 75.f / 255.f  , 1.f };
			inline ImVec4 PlayerBoxTT_Visible = { 0 , 1.f , 0.f , 1.f };
			inline ImVec4 PlayerBoxCT = { 65.f / 255.f , 200 / 255.f , 255.f / 255.f , 1.f };
			inline ImVec4 PlayerBoxCT_Visible = { 0 , 1.f , 0.f , 1.f };
			inline ImVec4 BoneESPTT = { 255.f / 255.f , 75.f / 255.f , 75.f / 255.f  , 1.f };
			inline ImVec4 BoneESPTT_Visible = { 0 , 1.f , 0.f , 1.f };
			inline ImVec4 BoneESPCT = { 65.f / 255.f , 200 / 255.f , 255.f / 255.f , 1.f };
			inline ImVec4 BoneESPCT_Visible = { 0 , 1.f , 0.f , 1.f };
			inline ImVec4 GlowTT = { 255.f / 255.f , 75.f / 255.f , 75.f / 255.f  , 1.f };
			inline ImVec4 GlowTT_Visible = { 0 , 1.f , 0.f , 1.f };
			inline ImVec4 GlowCT = { 65.f / 255.f , 200 / 255.f , 255.f / 255.f , 1.f };
			inline ImVec4 GlowCT_Visible = { 0 , 1.f , 0.f , 1.f };
		}
	}
}
