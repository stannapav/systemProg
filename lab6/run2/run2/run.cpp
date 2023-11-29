#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exitCode;
    HANDLE hOut;
    SECURITY_ATTRIBUTES sa;

    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    hOut = CreateFile("out.log",
        FILE_APPEND_DATA,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &sa,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.dwFlags |= STARTF_USESTDHANDLES;
    si.hStdInput = NULL;
    si.hStdError = hOut;
    si.hStdOutput = hOut;

    if (argc < 2)
    {
        printf("Use: run2 prog arg1 arg2 ... (run2 tasm32 /ml hello.asm)\n");
        return 1;
    }

    char comLine[MAX_PATH] = "";
    wsprintf(comLine, "%hs", argv[1]);
    for (int i = 2; i < argc; ++i)
        wsprintf(comLine, "%hs %hs", comLine, argv[i]);
        
    if (!CreateProcess(NULL,
        comLine,
        NULL,
        NULL,
        TRUE,
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