#include"Printing.h"

int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD written = 100;
	WCHAR buffer[100];

	PrintMsg(hOut, L"Hi dude from PrintMsg\n\n");

	PrintStrings(hOut, L"Start of PrintStrings func:\n" L"Soo\n", L"this function can do this\n", L"cool ain't is?\n", L"That is the end of my msg\n\n", NULL);

	
	ConsolePrompt(L"Write something: ", buffer, written, TRUE);
	PrintMsg(hOut, buffer);
	return 0;
}