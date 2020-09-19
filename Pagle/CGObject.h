#pragma once
#include <Windows.h>
#include <cstdint>

#include "Vector3.h"
#include "Common.h"
#include "CGMovementInfo.h"
#include "CGModelInfo.h"

class CGObject
{
public:
    virtual void function0();
    virtual void function1();
    virtual void function2();
    virtual void function3();
    virtual void function4();
    virtual void function5();
    virtual void function6();
    virtual void function7();
    virtual void GetObjectPos(Vector3* Pos);
    virtual float GetFacing();
    virtual float GetScale();
    virtual void function11();
    virtual void function12();
    virtual void function13();
    virtual void function14();
    virtual void function15();
    virtual const char* GetModel();
    virtual void function17();
    virtual void function18();
    virtual void function19();
    virtual void function20();
    virtual void function21();
    virtual void function22();
    virtual void function23();
    virtual float GetFacingAngle();
    virtual void function25();
    virtual void function26();
    virtual void function27();
    virtual void function28();
    virtual void function29();
    virtual void function30();
    virtual void function31();
    virtual void function32();
    virtual void function33();
    virtual void Interact();
    virtual void function35();
    virtual void function36();
    virtual void function37();
    virtual void function38();
    virtual void function39();
    virtual void function40();
    virtual void function41();
    virtual const char* GetObjectName();
    virtual void function43();
    virtual void function44();
    virtual void function45();
    virtual void function46();
    virtual void function47();
    virtual void function48();
    virtual void function49();
    virtual void function50();
    virtual void function51();
    virtual void function52();
    virtual void function53();
    virtual void function54();
    virtual void function55();
    virtual void function56();
    virtual void function57();
    virtual void function58();
    virtual void function59();
    virtual void function60();
    virtual void function61();

    char unknown4[4];
    DWORD m_dwStorage01;
    DWORD m_dwStorage02;
    char unknown16[4];
    int m_dwType;
    char unknown24[24];
    uint64_t wLocalGUID;
    char unknown56[232];
    DWORD m_dwStorage3;
    char unknown292[4];
    CGMovementInfo* m_pMoveInfo;
    char unknown300[3224];
    CGModelInfo* m_pModelInfo;

    uint64_t GetCreator();
    int IsBobbing();
};
