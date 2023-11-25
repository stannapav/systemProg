#include <windows.h>
#include <stdio.h>

int main(int argc, LPTSTR argv[])
{
	WIN32_FIND_DATA fileFound;
	HANDLE hSearch;
	BOOL finished = FALSE;

	if (argc != 2) {
		printf("Usage: cpW dir\n");
		return 1;
	}

	if (SetCurrentDirectory(argv[1]) != 0)
		printf("Dir exists\n");
	else
	{
		printf("Cannot open directory. Error: %x\n", GetLastError());
		return 0;
	}

	if (CreateDirectory("newDir", NULL))
		printf("Create new dir\n");
	else
	{
		printf("Cannot create directory. Error: %x\n", GetLastError());
		return 0;
	}

	hSearch = FindFirstFileA("*.txt", &fileFound);

	if (hSearch == INVALID_HANDLE_VALUE)
	{
		printf("Cannot find file. Error: %x\n", GetLastError());
		return 2;
	}

	while (!finished)
	{
		CHAR newFile[40];
		wsprintf(newFile, "newDir\\%s", fileFound.cFileName);
		if (CopyFile(fileFound.cFileName, newFile, false))
			printf("File copied\n");
		else
		{
			printf("Cannot open input file. Error: %x\n", GetLastError());
			return 2;
		}


		if (!FindNextFile(hSearch, &fileFound))
		{
			if (GetLastError() == ERROR_NO_MORE_FILES)
			{
				printf("No more files");
				finished = TRUE;
			}
			else
			{
				printf("Could not find next file.\n");
				break;
			}
		}
	}

	FindClose(hSearch);
	return 0;
}