# Featues:
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
[Powered by Vermillion Hack](https://vermillion-hack.ru/)

# ScreenShots:

<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/e887801e-97bd-4645-a381-f430b717cd40" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/eb62cf17-7f0a-47f7-875f-9924b73f6836" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/fbe96991-01c5-40aa-a9ad-dc2477d6cf6d" />
