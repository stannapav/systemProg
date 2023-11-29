#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exitCode;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (argc < 2)
    {
        printf("Use: run prog1 arg1 arg2 next prog2 arg1 arg2... (run3 tasm32 /ml hello.asm next tlink32 /ap hello.obj)\n");
        return 1;
    }

    int prog2 = 0;
    char comLine1[MAX_PATH] = "";
    wsprintf(comLine1, "%hs", argv[1]);
    for (int i = 2; i < argc; ++i)
    {
        if (argv[i][0] == 'n' && argv[i][1] == 'e' && argv[i][2] == 'x' && argv[i][3] == 't')
        {
            prog2 = i;
            break;
        }
        else
            wsprintf(comLine1, "%hs %hs", comLine1, argv[i]);
    }

    char comLine2[MAX_PATH] = "";
    wsprintf(comLine2, "%hs", argv[prog2 + 1]);
    for (int i = prog2 + 2; i < argc; ++i)
        wsprintf(comLine2, "%hs %hs", comLine2, argv[i]);

    if (!CreateProcess(NULL,
        comLine1,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi))
    {
        printf("Failed to start the process.\n");
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    GetExitCodeProcess(pi.hProcess, &exitCode);
    printf("Exit Code: %d\n", exitCode);

    if (!CreateProcess(NULL,
        comLine2,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi))
    {
        printf("Failed to start the process.\n");
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    GetExitCodeProcess(pi.hProcess, &exitCode);
    printf("Exit Code: %d\n", exitCode);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    return 0;
}