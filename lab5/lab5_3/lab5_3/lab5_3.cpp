#include <windows.h>
#include <stdio.h>

int main(int argc, LPTSTR argv[])
{
	if (argc != 2) {
		printf("Usage: cpW file\n");
		return 1;
	}

	if (CopyFile(argv[1], "newFile.txt", false))
		printf("File copied");
	else
	{
		printf("Cannot open input file. Error: %x\n", GetLastError());
		return 2;
	}

	return 0;
}