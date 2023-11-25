#include <windows.h>
#include <stdio.h>

int main(int argc, LPTSTR argv[])
{
	WIN32_FIND_DATA fileFound;
	CHAR fileType[10];
	HANDLE hSearch;
	BOOL finished = FALSE;

	if (argc != 3) {
		printf("Usage: cpW dir fileType(txt)\n");
		return 1;
	}

	if (SetCurrentDirectory(argv[1]) != 0)
		printf("Dir exists\n");
	else
	{
		printf("Cannot open directory. Error: %x\n", GetLastError());
		return 0;
	}

	wsprintf(fileType, "*.%s", argv[2]);
	hSearch = FindFirstFileA(fileType, &fileFound);

	if(hSearch == INVALID_HANDLE_VALUE)
	{
		printf("Cannot find file. Error: %x\n", GetLastError());
		return 2;
	}

	while (!finished)
	{
		printf("%s\n", fileFound.cFileName);
		if (!FindNextFile(hSearch, &fileFound))
		{
			if (GetLastError() == ERROR_NO_MORE_FILES)
			{
				printf("No more files %s\n", fileType);
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