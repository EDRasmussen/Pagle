#include "Lua.h"

void Lua::DoString(const char* command)
{
    static const auto FramescriptExecute = reinterpret_cast<void(__cdecl*)(const char*, const char*, int)>(Offsets::Lua_DoString);
    FramescriptExecute(command, "", 0);
}
