#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */
#include <windows.h>

#endif /* _DLL_H_ */

DLLIMPORT BOOL PrintStrings (HANDLE hOut, ...);
DLLIMPORT BOOL PrintMsg (HANDLE hOut, LPCTSTR pMsg);
DLLIMPORT BOOL ConsolePrompt (LPCTSTR pPromptMsg, LPTSTR pResponse, DWORD MaxTchar, BOOL Echo);
