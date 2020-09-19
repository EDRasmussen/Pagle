#pragma once

#include <Windows.h>
#include <cstdint>

class Offsets
{
public:
    Offsets() { };
    ~Offsets() { };

    static DWORD ObjectManager;
    static DWORD OM_LocalGuid;
    static DWORD OM_FirstObject;
    static DWORD OM_NextObject;
    static DWORD OM_GUID;
    static DWORD OM_Type;
    static DWORD OM_X;
    static DWORD OM_Y;
    static DWORD OM_Z;
    static DWORD OM_R;
    static DWORD OM_FieldOffset;

    static DWORD Lua_DoString;
    
    static DWORD ClientConnection;

    static DWORD LastHardwareAction;

    static DWORD OnRightClickObject;
    static DWORD OnRightClickUnit;
    static DWORD CastSpellByID;
    static DWORD LootUnit;
};
