#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdio.h>

using namespace std;

DWORD WINAPI SecondThread(LPVOID param) {
	printf("Secondary thread\n");
	char* strcopy = (char*)param;
	char* next = NULL;
	char* word = strtok_s(strcopy, " ", &next);
		
	while (word != NULL)
	{
		printf("%hs\n", word);
		word = strtok_s(NULL, " ", &next);
	}

	ExitThread(0);
}

int main() {
	HANDLE thread;
	char str[100] = "";

	printf("First thread\n");
	printf("Enter your string: ");
	int scaned = scanf("%[^\n]%*c", &str)	;

	char* strcopy = new char[strlen(str)];
	*strcopy = 0;
	strncat(strcopy, str, strlen(str));

	thread = CreateThread(NULL, 0, SecondThread, (LPVOID)strcopy, 0, NULL);

	printf("str from first thread: %hs\n", str);
	int count = 1;
	for (int i = 0; i < strlen(str); i++) 
	{
		char letter = str[i];

		if (letter == ' ')
			count++;
	}

	printf("Words count: %d\n", count);
	return 0;
}