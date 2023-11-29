#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

using namespace std;

DWORD WINAPI SecondaryThread(LPVOID lpParam) 
{
    SYSTEMTIME time;
    while (true) 
    {
        GetLocalTime(&time);
        printf("Time: %04d-%02d-%02d %02d:%02d:%02d\n",
            time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);

        Sleep(1000);
    }

    ExitThread(0);
}

int main() {
    char command = ' ';
    HANDLE thread = CreateThread(NULL, 0, SecondaryThread, NULL, 0, NULL);

    while (command != 'e' || command != 'E')
    {
        printf("s - suspend\nr - resume\nt - terminate\ne - exit \nEnter: ");
        int scaned = scanf("%c", &command);

        if (thread == NULL) 
        {
            printf("Error\n");
            return 1;
        }

        switch (command) 
        {
        case 'S':
        case 's':
            SuspendThread(thread);
            break;

        case 'R':
        case 'r':
            ResumeThread(thread);
            break;

        case 'T':
        case 't':
            TerminateThread(thread, false);
            break;

        case 'E':
        case 'e':
            CloseHandle(thread);
            return 0;

        default:
            printf("Unknown input\n");
            break;
        }
    }

    return 0;
}