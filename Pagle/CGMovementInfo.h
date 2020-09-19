#pragma once
#include <Windows.h>
#include <cstdint>

#include "Vector3.h"

class CGMovementInfo
{
public:
    char unknown0[16];
    Vector3 m_vecPos;
    float m_fHeading;
    char unknown32[24];
    uint64_t m_wTransportGuid;
    DWORD m_dwMoveFlags;
    DWORD m_dwMoveFlags2;
    char unknown72[20];
    DWORD m_dwTimeMoved;
    char unknown96[12];
    float m_fSinAngle;
    float m_fCosAngle;
    char unknown116[8];
    DWORD m_dwFallTime;
    float m_fFallStartHeight;
    char unknown132[8];
    float m_fWalkSpeed;
    float m_fRunSpeed;
    float m_fSwimBackSpeed;
    float m_fSwimSpeed;
    float m_fWalkBackSpeed;
    float m_fFlySpeed;
    float m_fFlyBackSpeed;
    float m_fTurnSpeed;
    float m_fJumpVelocity;
};
