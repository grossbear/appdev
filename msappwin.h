#pragma once
#include <windows.h>

#define WIN_NAME_SIZE 256

///////////////////////////////////////////////////////////////////////////////
class AppWindow
{
public:
    AppWindow(int x, int y, int width, int height, int flags, const char * wname);
    ~AppWindow();
    bool WindowAvailable() const;

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    void ProcessEvents();

    void SetTitle(const char * title);

protected:
    bool Create(int x, int y, int width, int height, int flags);
    bool Destroy();

    HWND hWnd;

private:
    bool RegisterWndClass(HINSTANCE hInst);

    char winName[WIN_NAME_SIZE];
    char winClassName[WIN_NAME_SIZE];
};
///////////////////////////////////////////////////////////////////////////////
