#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>

#include "Offsets.h"
#include "CGObject.h"
#include "CGPlayer.h"
#include "Common.h"


class ObjectManager 
{
public:
    void Scan();
    void Clear();
    void ClearBobber();

    std::vector<WowObject*> GetPlayers();
    std::vector<WowObject*> GetCreatures();
    std::vector<WowObject*> GetGameObjects();
    CGPlayer* GetLocalPlayer();
    CGObject* GetFishingBobber();
    
private:
    std::vector<WowObject*> m_woPlayers;
    std::vector<WowObject*> m_woCreatures;
    std::vector<WowObject*> m_woGameObjects;
    CGPlayer* m_cgpLocalPlayer = nullptr;
    CGObject* m_cgoFishingBobber = nullptr;
};
