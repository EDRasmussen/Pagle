#pragma once
#include <windows.h>
#include <cstdint>

#include "Common.h"

class CGUnit
{
public:
    char unknown0[8];
    UnitFields* unitFields;
    char unknown12[8];
    int32_t Type;
    char unknown24[24];
    int64_t GUID;
    char unknown54[4];
    int32_t nextObject;

    int GetFaction();
};
