#define BUILD_WINDOWS
#include<Windows.h> 

using namespace std;
int main() 
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD write, nSize = 20;
	char computerName[20], userName[20], keyboardTypeStr[60], systemDirectory[MAX_PATH], windowsDirectory[MAX_PATH], computerVersionStr[20];
	char str[300];
	OSVERSIONINFO computerVersion;
	computerVersion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetSystemDirectory(systemDirectory, MAX_PATH);
	GetWindowsDirectory(windowsDirectory, MAX_PATH);
	GetComputerName(computerName, &nSize);
	GetUserName(userName, &nSize);
	GetVersionEx(&computerVersion);
	int keyboardType = GetKeyboardType(0);

	if (keyboardType == 4) 
		wsprintf(keyboardTypeStr, "Enhanced 101- or 102-key keyboards (and compatibles)");
	else if (keyboardType == 7) 
		wsprintf(keyboardTypeStr, "Japanese Keyboard");
	else if (keyboardType == 7)
		wsprintf(keyboardTypeStr, "Korean Keyboard");
	else if (keyboardType == 7)
		wsprintf(keyboardTypeStr, "Unknown type or HID keyboard");
	else
		wsprintf(keyboardTypeStr, "Unknown");

	if(computerVersion.dwMajorVersion == 10)
		wsprintf(computerVersionStr, "Windows 10");
	else if(computerVersion.dwMajorVersion == 6 && computerVersion.dwMinorVersion == 3)
		wsprintf(computerVersionStr, "Windows 8.1");
	else if (computerVersion.dwMajorVersion == 6 && computerVersion.dwMinorVersion == 1)
		wsprintf(computerVersionStr, "Windows 7");
	else if (computerVersion.dwMajorVersion == 8)
		wsprintf(computerVersionStr, "Windows Vista");
	else if (computerVersion.dwMajorVersion == 5 && computerVersion.dwMinorVersion == 1)
		wsprintf(computerVersionStr, "Windows XP");
	else
		wsprintf(computerVersionStr, "Unknown Windows");

	wsprintf(str, "Info about this PC\nPC name: %s\nUser name: %s\nWindows version: %s\nSystem directory: %s\nWindows directory: %s\nKeyboard type: %s\n"
		, computerName, userName, computerVersionStr, systemDirectory, windowsDirectory, keyboardTypeStr);
	WriteConsole(hOut, str, strlen(str), &write, NULL);
}