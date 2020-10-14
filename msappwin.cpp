#include <stdio.h>
#include "msappwin.h"
#include "appbase.h"

#define WIN_CLASS_NAME "AppWindowClass"

///////////////////////////////////////////////////////////////////////////////
AppWindow::AppWindow(int x, int y, int width, int height, const char * title):
hWnd(NULL)
{
    Create(x, y, width, height, title);
}

///////////////////////////////////////////////////////////////////////////////
AppWindow::~AppWindow()
{
    Destroy();
}

///////////////////////////////////////////////////////////////////////////////
bool AppWindow::WindowAvailable() const
{
    return hWnd != NULL;
}

///////////////////////////////////////////////////////////////////////////////
void AppWindow::ProcessEvents()
{
    MSG msg;
    if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))    // Is There A Message Waiting?
    {
        //printf("Process Events\n");
        TranslateMessage(&msg);                 // Translate The Message
        DispatchMessage(&msg);                  // Dispatch The Message
    }
}

///////////////////////////////////////////////////////////////////////////////
bool AppWindow::Create(int x, int y, int width, int height, const char * title)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    if (!RegisterWndClass(hInstance))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION|MB_OK);
        return false;
    }

    DWORD dwStyle = WS_VISIBLE | WS_OVERLAPPEDWINDOW;
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
        WIN_CLASS_NAME,
        title,
        dwStyle,
		x, //CW_USEDEFAULT
		y, //CW_USEDEFAULT
		width,
		height,
		NULL,
        NULL,
        hInstance,
        NULL);
    return true;

    if (hWnd == NULL)
    {
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION|MB_OK);
		return false;
	}

    // Setting Window Params
    ShowWindow(hWnd, SW_SHOW);
    SetForegroundWindow(hWnd);
    SetFocus(hWnd);

    return true;
}

///////////////////////////////////////////////////////////////////////////////
bool AppWindow::Destroy()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    if(hWnd)
    {
        DestroyWindow( hWnd );
        UnregisterClass( WIN_CLASS_NAME, hInstance );
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
bool AppWindow::RegisterWndClass(HINSTANCE hInstance)
{
    WNDCLASSEX wc; // A properties struct of our window
    // Zero out the struct and set the stuff we want to modify  
	memset(&wc,0,sizeof(wc));

    wc.cbSize       = sizeof(WNDCLASSEX);
    wc.style        = CS_OWNDC;
    // This is where we will send messages to
	wc.lpfnWndProc  = AppWindow::WndProc;
	wc.hInstance    = hInstance;
	wc.hbrBackground= (HBRUSH)(COLOR_WINDOW+1);
                       //(HBRUSH) GetStockObject (BLACK_BRUSH);
	wc.lpszClassName= WIN_CLASS_NAME;
    wc.hCursor      = LoadCursor(NULL, IDC_ARROW);
    // Load a standard icon
	wc.hIcon        = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm      = LoadIcon(NULL, IDI_APPLICATION);

    return RegisterClassEx(&wc);;
}

///////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK AppWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    ApplicationBase * app = ApplicationBase::GetSingleton();

    switch(message)
    {
        case WM_QUIT:
            printf("quit\n");
            //PostQuitMessage(0);
            //app->CloseWindow();
            break;

        case WM_CREATE:
            printf("create\n");
            break;

        case WM_SIZE:
            app->SetWindowSize((int)LOWORD(lParam), (int)HIWORD(lParam));
            break;

        case WM_DESTROY:
            printf("destroy\n");
            break;

        case WM_CLOSE:
            printf("close\n");
            app->CloseWindow();
            break;

        case WM_KEYDOWN:
            switch (wParam)
            {
            case VK_ESCAPE:
                printf("escape\n");
                PostQuitMessage(0);
                return 0;
            }
            return 0;

        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
