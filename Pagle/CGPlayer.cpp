#include "CGPlayer.h"

int CGPlayer::LootUnit(void* target)
{
    typedef int(__thiscall* oLootUnit)(PVOID _this, PVOID _target, PVOID unknown);
    oLootUnit _LootUnit = (oLootUnit)Offsets::LootUnit;
    return _LootUnit(this, target, NULL);
}

int CGPlayer::CastSpellByID(int spellID, uint64_t targetGUID)
{
    typedef int(__cdecl* dCastSpellByID)(int spellID, int unknown, uint64_t GUID);
    dCastSpellByID _CastSpellByID = (dCastSpellByID)Offsets::CastSpellByID;
    return _CastSpellByID(spellID, NULL, targetGUID);
}

int CGPlayer::InteractWithUnit(void* target)
{
    typedef int(__thiscall* dOnRightClickUnit)(PVOID _this);
    dOnRightClickUnit _OnRightClickUnit = (dOnRightClickUnit)Offsets::OnRightClickUnit;
    return _OnRightClickUnit(target);
}

int CGPlayer::InteractWithObject(void* target)
{
    typedef int(__thiscall* dOnRightClickObject)(PVOID _this);
    dOnRightClickObject _OnRightClickObject = (dOnRightClickObject)Offsets::OnRightClickObject;
    return _OnRightClickObject(target);
}
