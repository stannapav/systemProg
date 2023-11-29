#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdio.h>

int main(void) {
	HANDLE hPipe;
	DWORD dwRead;
	DWORD dwWritten;
	char msg[MAX_PATH] = "";
	char rmsg[MAX_PATH] = "";

	hPipe = CreateNamedPipe("\\\\.\\pipe\\hello", PIPE_ACCESS_DUPLEX, 
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES, 256, 256, 1000, NULL);
	ConnectNamedPipe(hPipe, NULL);

	do
	{
		ReadFile(hPipe, rmsg, MAX_PATH * sizeof(char), &dwRead, NULL);
		printf("Msg from client: %hs\n", rmsg);

		printf("Enter msg for client: ");
		scanf("%[^\n]%*c", &msg);
		WriteFile(hPipe, msg, strlen(msg) + 1, &dwWritten, NULL);
	} while ((msg[0] != '$' && msg[1] != 'q' && msg[2] != 'u' && msg[3] != 'i' && msg[4] != 't') ||
		(rmsg[0] != '$' && rmsg[1] != 'q' && rmsg[2] != 'u' && rmsg[3] != 'i' && rmsg[4] != 't'));

	DisconnectNamedPipe(hPipe);
	CloseHandle(hPipe);
	return 0;
}