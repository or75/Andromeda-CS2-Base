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

# Link:
[UnknownCheats Thread](https://www.unknowncheats.me/forum/counter-strike-2-a/722929-andromeda-cs2-internal-base.html)
