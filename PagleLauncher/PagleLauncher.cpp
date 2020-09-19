#include <string>
#include <iostream>

#include <Windows.h>
#include <TlHelp32.h>
#include <comdef.h>

using namespace std;

const char* ConvertWChar(WCHAR* wc)
{
    _bstr_t b(wc);
    const char* c = b;
    return c;
}

bool GetProcessEntryByName(string name, PROCESSENTRY32* pe) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE || snapshot == NULL) 
    {
        cerr << "Cannot generate snapshot of process" << endl;
        return false;
    }

    if (!Process32First(snapshot, pe)) 
    {
        cerr << "Can't retrieve modules" << endl;
        return false;
    }

    while (Process32Next(snapshot, pe))
    {
        if (ConvertWChar(pe->szExeFile) == name) 
        {
            CloseHandle(snapshot);
            return true;
        }
    }

    CloseHandle(snapshot);
    return false;
}

int SetDebugPrivileges()
{
    TOKEN_PRIVILEGES tp;
    HANDLE hToken;

    if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid))
    {
        if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
        {
            if (hToken != INVALID_HANDLE_VALUE)
            {
                tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
                tp.PrivilegeCount = 1;
                if (AdjustTokenPrivileges(hToken, FALSE, &tp, 0, 0, 0))
                {
                    CloseHandle(hToken);
                    return 1;
                }

                CloseHandle(hToken);
            }
        }
    }

    return 0;
}

int main(int argc, const char* argv[]) 
{
    PROCESSENTRY32 pe = { sizeof(PROCESSENTRY32) };
    string fullPath;

    const char* processName = "Wow.exe";
    const char* dllPath = "Pagle.dll";

    char buf[MAX_PATH] = { 0 };
    GetFullPathNameA(dllPath, MAX_PATH, buf, nullptr);  
    fullPath = string(buf, MAX_PATH);

    cout << "Waiting for " << processName << "..." << endl;

    for (; !GetProcessEntryByName(processName, &pe); Sleep(100));

    cout << processName << " found" << endl;

    if (!SetDebugPrivileges())
    {
        cerr << "Cannot set debug privileges: " << GetLastError() << endl;
        system("pause");
        return 1;
    }

    HANDLE process = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, pe.th32ProcessID);
    if (!process) 
    {
        cerr << "Process " << pe.th32ProcessID << " cannot be opened: " << GetLastError() << endl;
        system("pause");
        return 1;
    }

    LPVOID mem = VirtualAllocEx(process, NULL, fullPath.length() + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!mem) {
        cerr << "Library name cannot be allocated" << endl;
        system("PAUSE");
        return 1;
    }

    if (!WriteProcessMemory(process, mem, fullPath.c_str(), fullPath.length() + 1, nullptr)) 
    {
        cerr << "Library name cannot be written" << endl;
        system("PAUSE");
        return 1;
    }
    
    if (!CreateRemoteThread(process, nullptr, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, mem, 0, nullptr)) 
    {
        cerr << "Thread cannot be created" << endl;
        system("PAUSE");
        return 1;
    }
    else 
    {
        cout << "Succesfully injected Pagle" << endl;
    }

    CloseHandle(process);
    return 0;
}
