#include "framework.h"
#include "lab3.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                 
WCHAR szWindowClass[MAX_LOADSTRING];   

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    BlackCatSee(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    BlackCatNotSee(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    OrangeCat(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    FluffyCat(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    BigDog(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MediumDog(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    SmallDog(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Parrot(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    BigPenguin(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    SmallPenguin(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    BoldCat(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Bobby(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB3));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CUSTOMICON));
    wcex.hCursor        = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_MYCURSOR));
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CUSTOMICON));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_BLACK_UCANSEE:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_BLACKCATSEE), hWnd, BlackCatSee);
                break;
            case ID_BLACK_ITSEESYOU:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_BLACKCATNOTSEE), hWnd, BlackCatNotSee);
                break;
            case ID_CAT_ORANGE:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ORANGECAT), hWnd, OrangeCat);
                break;
            case ID_CAT_BOLD:
                DialogBox(hInst, MAKEINTRESOURCE(IDB_BOLDCAT), hWnd, BoldCat);
                break;
            case ID_CAT_FLUFFY:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_FLUFFYCAT), hWnd, FluffyCat);
                break;
            case ID_DOG_BIG:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_BIGDOG), hWnd, BigDog);
                break;
            case ID_DOG_MEDIUM:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_MEDIUMDOG), hWnd, MediumDog);
                break;
            case ID_DOG_SMALL:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_SMALLDOG), hWnd, SmallDog);
                break;
            case ID_PENGUIN_SMALL:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_SMALLPENGUIN), hWnd, SmallPenguin);
                break;
            case ID_PENGUIN_BIG:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_BIGPENGUIN), hWnd, BigPenguin);
                break;
            case ID_BIRD_PARROT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_PARROT), hWnd, Parrot);
                break;
            case ID_BIRD_BLUE:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_BOBBY), hWnd, Bobby);
                break;
            case ID_CAT_CUTE:
                MessageBox(NULL,
                    (LPCWSTR)L"Male cats are more likely to be left-pawed, while female cats are more likely to be right-pawed.",
                    (LPCWSTR)L"Cute cat fact",MB_OK );
                break;
            case ID_CAT_SCARY:
                MessageBox(NULL,
                    (LPCWSTR)L"Cats’ rough tongues can lick a bone clean of any shred of meat.",
                    (LPCWSTR)L"Scary cat fact", MB_OK);
                break;
            case ID_DOG_INTERESTING:
                MessageBox(NULL,
                    (LPCWSTR)L"Dogs don’t sweat like we do.",
                    (LPCWSTR)L"Interesting dog fact", MB_OK);
                break;
            case ID_PENGUIN_WHOLESOME:
                MessageBox(NULL,
                    (LPCWSTR)L"Penguins give rocks to their loved ones. Not just any rocks, though male gentoo penguins search through piles of pebbles to find the smoothest, most perfect ones. When a penguin has selected his pebble, he presents it to his intended companion. If she approves, she puts the stone in her nest",
                    (LPCWSTR)L"Wholesome penguin fact", MB_OK);
                break;
            case ID_FILE_MOREABOUT:
            {
                int msgboxID = MessageBox(NULL,
                    (LPCWSTR)L"Do you want to know more about program?",
                    (LPCWSTR)L"More about...", MB_ICONQUESTION | MB_YESNOCANCEL);

                switch (msgboxID)
                {
                case IDYES:
                    ShellAbout(NULL, L"More about program", L"Program made by Striharchuk Anna", NULL);
                    break;
                }
            }
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK BlackCatSee(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK BlackCatNotSee(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK BigDog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK BoldCat(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK MediumDog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK SmallDog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Parrot(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK BigPenguin(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK SmallPenguin(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Bobby(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK OrangeCat(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK FluffyCat(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}