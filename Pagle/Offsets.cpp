#include "Offsets.h"

DWORD Offsets::ObjectManager = 0x2218;
DWORD Offsets::OM_LocalGuid = 0xC0;
DWORD Offsets::OM_FirstObject = 0xAC;
DWORD Offsets::OM_NextObject = 0x3C;
DWORD Offsets::OM_GUID = 0x30;
DWORD Offsets::OM_Type = 0x14;
DWORD Offsets::OM_X = 0xBF0;
DWORD Offsets::OM_Y = 0xBF4;
DWORD Offsets::OM_Z = 0xBF8;
DWORD Offsets::OM_R = 0xBFC;
DWORD Offsets::OM_FieldOffset = 0x120;

DWORD Offsets::Lua_DoString = 0x706C80;

DWORD Offsets::ClientConnection = 0xD43318;

DWORD Offsets::LastHardwareAction = 0xBE10FC; // WoW.exe + 0x7E10FC

DWORD Offsets::OnRightClickObject = 0x600960;
DWORD Offsets::OnRightClickUnit = 0x619E00;
DWORD Offsets::CastSpellByID = 0x6FC520;
DWORD Offsets::LootUnit = 0x5E2460;
