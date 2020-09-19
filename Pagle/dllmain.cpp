#include <Windows.h>
#include <stdlib.h>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <cinttypes>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <iomanip>

#include "Offsets.h"
#include "Pagle.h"

HWND ProcessWindow;
WNDPROC ProcessWndProc;
Pagle* pagle;
bool IsPaused = false;

void Initialize()
{
    AllocConsole();
    SetConsoleTitleA("2.4.3 Pagle Console");
    typedef struct { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; } FILE_COMPLETE;
    *reinterpret_cast<FILE_COMPLETE*>(stdout) = *reinterpret_cast<FILE_COMPLETE*>(_fdopen(_open_osfhandle(reinterpret_cast<long>(GetStdHandle(STD_OUTPUT_HANDLE)), _O_TEXT), "w"));
    *reinterpret_cast<FILE_COMPLETE*>(stderr) = *reinterpret_cast<FILE_COMPLETE*>(_fdopen(_open_osfhandle(reinterpret_cast<long>(GetStdHandle(STD_ERROR_HANDLE)), _O_TEXT), "w"));
    *reinterpret_cast<FILE_COMPLETE*>(stdin) = *reinterpret_cast<FILE_COMPLETE*>(_fdopen(_open_osfhandle(reinterpret_cast<long>(GetStdHandle(STD_INPUT_HANDLE)), _O_TEXT), "r"));
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    pagle = new Pagle();
    std::cout << "  _____            _      \n"
                 " |  __ \\          | |     \n"
                 " | |__) |_ _  __ _| | ___ \n"
                 " |  ___/ _` |/ _` | |/ _ \\\n"
                 " | |  | (_| | (_| | |  __/\n"
                 " |_|   \\__,_|\\__, |_|\\___|\n"
                 "              __/ |       \n"
                 "             |___/        \n";


    SetTimer(ProcessWindow, 0x101, static_cast<uint32_t>((1 / 30) * 1000), nullptr);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_KEYDOWN:
        if (wParam == VK_F12)
        {
            IsPaused = !IsPaused;

            time_t cTime = time(NULL);
            tm fTime;
            localtime_s(&fTime, &cTime);
            std::cout << "[" << fTime.tm_hour << ":" << fTime.tm_min << ":" << fTime.tm_sec << "]" << "[Pagle]: Set pause status to " << IsPaused << std::endl;
        }
        break;
    case WM_TIMER:
    {
        if (wParam == 0x100)
        {
            Initialize();
        }
        else if (wParam == 0x101)
        {
            if (!IsPaused)
            {
                pagle->Fish();
            }
        }
        break;
    }
    }

    return CallWindowProc(ProcessWndProc, hwnd, msg, wParam, lParam);
}

void Attach()
{
    ProcessWindow = FindWindow(0, TEXT("World of Warcraft"));
    ProcessWndProc = (WNDPROC)SetWindowLongPtrA(ProcessWindow, (ULONG)GWLP_WNDPROC, (ULONG_PTR)&WndProc);
    SendMessage(ProcessWindow, WM_TIMER, 0x100, NULL);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Attach();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
