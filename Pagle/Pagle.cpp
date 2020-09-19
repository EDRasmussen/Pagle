#include "Pagle.h"

void UpdateLastHardwareAction()
{
    LARGE_INTEGER freq, li;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&li);
    *(int*)(Offsets::LastHardwareAction) = (int)((li.QuadPart * 1000) / freq.QuadPart);
}

Pagle::Pagle()
{
    objectManager = new ObjectManager();
}

void Pagle::Fish()
{
    objectManager->Scan();

    CGObject* fishingBobber = objectManager->GetFishingBobber();
    CGPlayer* localPlayer = objectManager->GetLocalPlayer();

    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    long long msCount = ms.count();

    // Performing action
    if (m_llNextActionTime != 0 && msCount >= m_llNextActionTime)
    {
        if (m_iNextAction == ACTION_CAST_FISHING)
        {
            Lua::DoString("CastSpellByName('Fishing')");
        }
        else if (m_iNextAction == ACTION_LOOT_BOBBER && fishingBobber != nullptr && fishingBobber->IsBobbing())
        {
            localPlayer->InteractWithObject((WowObject*)fishingBobber);
            m_iHasFalseBobbed = 0;
        }

        UpdateLastHardwareAction();
        m_iNextAction = ACTION_NONE;
        m_llNextActionTime = 0;
        m_llNextCheckTime = msCount + 1000;
        return;
    }

    // Ready for next action
    if (m_iNextAction == ACTION_NONE && msCount >= m_llNextCheckTime)
    {
        if (fishingBobber != nullptr && fishingBobber->IsBobbing() && m_iHasFalseBobbed == 1)
        {
            m_iNextAction = ACTION_LOOT_BOBBER;
            m_llNextActionTime = msCount + 500;
        }
        else if (fishingBobber != nullptr && !fishingBobber->IsBobbing() && m_iHasFalseBobbed == 0)
        {
            m_iHasFalseBobbed = 1;
        }
        else if (fishingBobber == nullptr)
        {
            m_iNextAction = ACTION_CAST_FISHING;
            m_llNextActionTime = msCount + 500;
        }
    }
}
