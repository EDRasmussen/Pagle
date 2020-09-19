#pragma once
#include <string>

#include "CGUnit.h"
#include "Offsets.h"
#include "Lua.h"

class CGPlayer : public CGUnit
{
public:
    int LootUnit(void* target);
    int CastSpellByID(int spellID, uint64_t targetGUID);
    int InteractWithUnit(void* target);
    int InteractWithObject(void* target);
};
