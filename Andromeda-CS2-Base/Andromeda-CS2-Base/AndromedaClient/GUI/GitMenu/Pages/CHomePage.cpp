#include "CHomePage.hpp"

namespace GitMenu
{
	auto CHomeSubPage::OnRender() -> void
	{
		ImGui::TextUnformatted( "Welcome to Andromeda CS2 Base !!!" );
		ImGui::Separator();
		ImGui::TextWrapped( "Credits: GPT 6.1 Sol Medium, _or_75" );
		ImGui::Separator();
		ImGui::TextWrapped( "Web Site: https://forum.andromeda-cheats.com/" );
		ImGui::TextWrapped( "Dota 2 Base: https://github.com/or75/Andromeda-Dota2-Base" );
		ImGui::TextWrapped( "Deadlock Base: https://github.com/or75/Andromeda-DeadLock-Base" );
		ImGui::TextWrapped( "Discord: https://discord.gg/andromedasdk" );
		ImGui::Separator();
		ImGui::TextWrapped( "Click 'tab' to Open Menu, click '/' to search by functionality" );
		ImGui::Separator();
		ImGui::TextWrapped( "GL & HF !!!" );
	}
}
