#include<Windows.h> 

using namespace std;
int main() 
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	DWORD write, read, color;
	char inputBuffer[10], str[300];
	SYSTEM_INFO sysInfo;
	char procArchitecture[20], colors[50], processorType[30];

	GetSystemInfo(&sysInfo);
	DWORD numberOfProcessors = sysInfo.dwNumberOfProcessors;

	color = GetSysColor(COLOR_WINDOW);
	wsprintf(colors, "color window: %x\n", color);
	WriteConsole(hOut, colors, strlen(colors), &write, NULL);
	
	bool loop = true;
	do
	{
		wsprintf(str, "What system metric you want to know?\n1: SM_CMONITORS\n2: SM_CMOUSEBUTTONS\n3: SM_CXCURSOR\n4: SM_CXFULLSCREEN\nn0: End\nInput: ");
		WriteConsole(hOut, &str, strlen(str), &write, NULL);
		ReadConsole(hIn, &inputBuffer, strlen(inputBuffer), &read, NULL);
		system("cls");
		int out;
		switch (inputBuffer[0])
		{
		case '0':
			loop = false;
			break;
		case '1':
			out = GetSystemMetrics(SM_CMONITORS);
			wsprintf(str, "Monitor count: %i\n", out);
			WriteConsole(hOut, str, strlen(str), &write, NULL);
			break;
		case '2':
			out = GetSystemMetrics(SM_CMOUSEBUTTONS);
			wsprintf(str, "Mouse button count: %i\n", out);
			WriteConsole(hOut, str, strlen(str), &write, NULL);
			break;
		case '3':
			out = GetSystemMetrics(SM_CXCURSOR);
			wsprintf(str, "Nominal width of a cursor, in pixels: %i\n", out);
			WriteConsole(hOut, str, strlen(str), &write, NULL);
			break;
		case '4':
			out = GetSystemMetrics(SM_CXFULLSCREEN);
			wsprintf(str, "Width of the full-screen window on display monitor, in pixels: %i\n", out);
			WriteConsole(hOut, str, strlen(str), &write, NULL);
			break;
		default:
			wsprintf(str, "Wrong input\n");
			WriteConsole(hOut, str, strlen(str), &write, NULL);
			break;
		}

	} while (loop);

	switch (sysInfo.wProcessorArchitecture)
	{
	case 9:
		wsprintf(procArchitecture, "x64 (AMD or Intel)");
		break;
	case 5:
		wsprintf(procArchitecture, "ARM");
		break;
	case 12:
		wsprintf(procArchitecture, "ARM64");
		break;
	case 6:
		wsprintf(procArchitecture, "Intel Itanium-based");
		break;
	case 0:
		wsprintf(procArchitecture, "x86");
		break;
	default:
		wsprintf(procArchitecture, "Unknown");
		break;
	}

	switch (sysInfo.dwProcessorType)
	{
	case 386:
		wsprintf(processorType, "PROCESSOR_INTEL_386");
		break;
	case 486:
		wsprintf(processorType, "PROCESSOR_INTEL_486");
		break;
	case 586:
		wsprintf(processorType, "PROCESSOR_INTEL_PENTIUM ");
		break;
	case 2200:
		wsprintf(processorType, "PROCESSOR_INTEL_IA64 ");
		break;
	case 8664:
		wsprintf(processorType, "PROCESSOR_AMD_X8664 ");
		break;
	default:
		wsprintf(processorType, "PROCESSOR_ARM ");
		break;
	}

	wsprintf(str, "System info:\nProcessor ArArchitecture: %s\nProcessor Type: %s\nNumber of processors: %i\n", procArchitecture, processorType, numberOfProcessors);
	WriteConsole(hOut, str, strlen(str), &write, NULL);

	return 0;
}