# Features:
- There's a crashlog in case of an apocalypse (load the dll in x64dbg and hit home, then subtract 0x1000 from the starting address and add the crash offset and look at the location).
- Schema dumper (in Common/Include/Config.hpp) -> DUMP_SCHEMA_ALL_OFFSET to 1
- Blackbone mm support (I'll post the injector with the database when I have time).
- There's a move_crc bypass (all actions are done in AndromedaClient.cpp -> OnCreateMove.GetCL_Bypass()->SetViewAngles).
- There's everything you need for inventory management; you just need to save it from the UC, for example. All patterns, etc., are working (maybe if this becomes popular, I'll post an article on how to do it).
- There are basic visuals with a visual check.
- Easy logs via DEV_LOG("pasters server\n");
- There's a protobuff message parser. An example for sound esp is in Hook_ParseMessage.cpp with sound positions.
- Normal working rendering of all the [removed] and fonts (Example in AndromedaClient.cpp, CVIsual.cpp)
- Possibly something else, but I can't remember. Good luck to everyone.

# Links:
[UnknownCheats Thread](https://www.unknowncheats.me/forum/counter-strike-2-a/722929-andromeda-cs2-internal-base.html)<br>
[Powered by Andromeda Cheats](https://forum.andromeda-cheats.com/)
[Powered by Andromeda SDK](https://andromeda-sdk.com/)

[OFFICIAL Andromeda SDK DISCORD](https://discord.gg/mu6pZ27FdC)

[SHIT RU DISCORD GROUP FOR ANDROMEDA BASES](https://discord.gg/WWhSe7JbSR)

# ScreenShots:

<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/0f68ec06-cec5-4188-a668-62da16b979af" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/09f77648-5bff-40fe-82fe-01f11ffe04a7" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/41bc9635-6019-41a3-9135-a7246ce17a94" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/a1057f09-0c9d-4276-943c-d84ff4a1806b" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/c81763e6-0657-4011-8e6a-4827f6c2a29d" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/e78cd8f2-64d2-4eeb-8f14-748a5c0cbaef" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/08f79265-84c1-4f59-a67e-6d591d716b6f" />
