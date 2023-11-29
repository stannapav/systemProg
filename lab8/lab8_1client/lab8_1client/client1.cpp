#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
int main(int argc, char* argv[]) {
	HANDLE hPipe;
	DWORD dwWritten;
	DWORD dwRead;
	char lpPipe[80];
	char msg[MAX_PATH] = "";
	char rmsg[MAX_PATH] = "";

	if (argc != 2)
	{
		printf("Usage: %s hostname\n", argv[0]);
		return 1;
	}

	sprintf(lpPipe, "\\\\%s\\pipe\\hello", argv[1]);
	WaitNamedPipe(lpPipe, NMPWAIT_WAIT_FOREVER);
	hPipe = CreateFile(lpPipe, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);

	do
	{
		printf("Enter msg for server: ");
		scanf("%[^\n]%*c", &msg);
		WriteFile(hPipe, msg, strlen(msg) + 1, &dwWritten, NULL);

		ReadFile(hPipe, rmsg, MAX_PATH * sizeof(char), &dwRead, NULL);
		printf("Msg from server: %hs\n", rmsg);
	} while ((msg[0] != '$' && msg[1] != 'q' && msg[2] != 'u' && msg[3] != 'i' && msg[4] != 't') ||
		(rmsg[0] != '$' && rmsg[1] != 'q' && rmsg[2] != 'u' && rmsg[3] != 'i' && rmsg[4] != 't'));

	CloseHandle(hPipe);
	return 0;
}