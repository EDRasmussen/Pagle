#include "ObjectManager.h"

void ObjectManager::Scan()
{
    Clear();
    DWORD clientConnection = *(DWORD*)(Offsets::ClientConnection);
    DWORD objectManager = *(DWORD*)(clientConnection + (uint32_t)Offsets::ObjectManager);

    uint64_t localGuid = *(uint64_t*)(objectManager + Offsets::OM_LocalGuid);
    uint32_t nextObject = *(DWORD*)(objectManager + (DWORD)Offsets::OM_FirstObject);

    while ((nextObject != 0) && ((nextObject & 1) == 0))
    {
        WowObject* wo = new WowObject();
        wo->GUID = *(uint64_t*)(nextObject + (uint32_t)Offsets::OM_GUID);
        wo->ObjectType = *(uint32_t*)(nextObject + (uint32_t)Offsets::OM_Type);

        if (wo->ObjectType == GAMEOBJECT)
        {
            CGObject* GObj = (CGObject*)(nextObject);
            if (strcmp(GObj->GetObjectName(), "Fishing Bobber") == 0 && GObj->GetCreator() == localGuid)
            {
                this->m_cgoFishingBobber = GObj;
            }

            this->m_woGameObjects.push_back(wo);
        }
        else if (wo->ObjectType == PLAYER)
        {
            if (wo->GUID == localGuid)
            {
                this->m_cgpLocalPlayer = (CGPlayer*)wo;
            }

            this->m_woPlayers.push_back(wo);
        }
        else if (wo->ObjectType == UNIT)
        {
            this->m_woCreatures.push_back(wo);
        }

        nextObject = *(DWORD*)(nextObject + (DWORD)Offsets::OM_NextObject);
    }
}

void ObjectManager::Clear()
{
    m_woPlayers.clear();
    m_woCreatures.clear();
    m_woGameObjects.clear();
    m_cgoFishingBobber = nullptr;
    m_cgpLocalPlayer = nullptr;
}

void ObjectManager::ClearBobber()
{
    m_cgoFishingBobber = nullptr;
}

std::vector<WowObject*> ObjectManager::GetPlayers()
{
    return this->m_woPlayers;
}

std::vector<WowObject*> ObjectManager::GetCreatures()
{
    return this->m_woPlayers;
}

std::vector<WowObject*> ObjectManager::GetGameObjects()
{
    return this->m_woPlayers;
}

CGPlayer* ObjectManager::GetLocalPlayer()
{
    return this->m_cgpLocalPlayer;
}

CGObject* ObjectManager::GetFishingBobber()
{
    return m_cgoFishingBobber;
}
