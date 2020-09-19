#include "CGObject.h"

uint64_t CGObject::GetCreator()
{
    return *(uint64_t*)((intptr_t)this + 0x2B8);
}

int CGObject::IsBobbing()
{
    return *(int*)((intptr_t)this + 0xF4);
}
