#pragma once

#include "Windows.h"
#include <cinttypes>
#include <stdio.h>
#include <iostream>
#include <chrono>

#include "Common.h"
#include "Offsets.h"
#include "ObjectManager.h"
#include "Lua.h"

using namespace std::chrono;

enum Actions
{
    ACTION_NONE,
    ACTION_CAST_FISHING,
    ACTION_LOOT_BOBBER
};

class Pagle
{
public:
    Pagle();
    void Fish();

private:
    ObjectManager* objectManager;
    bool m_bShouldLoot = false;
    int m_iNextAction = ACTION_NONE;
    int m_iHasFalseBobbed = false;
    long long m_llNextActionTime = 0;
    long long m_llNextCheckTime = 0;
};
