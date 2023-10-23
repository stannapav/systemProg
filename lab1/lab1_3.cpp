#include<windows.h>

using namespace std;
int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	COORD cord;
	DWORD toRead = 1, read, write;
	INPUT_RECORD inputRec;
	char keyOut[300], mouseOut[100];
	bool shift = false, alt = false, ctrl = false;

	DWORD fdwOldMode, fdwNewMode;
	GetConsoleMode(hIn, &fdwOldMode);
	fdwNewMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | 
		ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT;
	SetConsoleMode(hIn, fdwNewMode);

	ReadConsoleInput(hIn, &inputRec, toRead, &read);	
	while ((int)inputRec.Event.KeyEvent.uChar.AsciiChar != 27)
	{
		cord.X = 0;
		cord.Y = 0;
		ReadConsoleInput(hIn, &inputRec, toRead, &read);
		SetConsoleCursorPosition(hOut, cord);

		if (inputRec.EventType == KEY_EVENT)
		{ 
			FillConsoleOutputCharacter(hOut, ' ', 80, cord, &write);

			if (inputRec.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED)
				alt = true;
			else
				alt = false;

			if (inputRec.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED)
				ctrl = true;
			else
				ctrl = false;

			if (inputRec.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED)
				shift = true;
			else
				shift = false;

			wsprintf(keyOut, "Shift: %u Ctrl: %u Alt: %u\nKey pressed: %u\nVirtual key code:%u\nKeyboard key code: %u\nUnicode hex and symbol: %#x - %c\n",
				shift, ctrl, alt,
				inputRec.Event.KeyEvent.bKeyDown,
				inputRec.Event.KeyEvent.wVirtualKeyCode,
				inputRec.Event.KeyEvent.wVirtualScanCode,
				inputRec.Event.KeyEvent.uChar.UnicodeChar,
				inputRec.Event.KeyEvent.uChar.UnicodeChar);
			WriteConsole(hOut, keyOut, strlen(keyOut), &write, NULL);
		}

		if (inputRec.EventType == MOUSE_EVENT) 
		{
			cord.X = 0;
			cord.Y = 6;
			SetConsoleCursorPosition(hOut, cord);

			wsprintf(mouseOut, "Mouse position: [%i, %i]",
				inputRec.Event.MouseEvent.dwMousePosition.X,
				inputRec.Event.MouseEvent.dwMousePosition.Y);
			WriteConsole(hOut, mouseOut, strlen(mouseOut), &write, NULL);
		}
	}

	SetConsoleMode(hIn, fdwOldMode);
	return 0;
}