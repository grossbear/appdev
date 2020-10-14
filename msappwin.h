#pragma once
#include <windows.h>

///////////////////////////////////////////////////////////////////////////////
class AppWindow
{
public:
    AppWindow(int x, int y, int width, int height, const char * title);
    ~AppWindow();
    bool WindowAvailable() const;

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    void ProcessEvents();

protected:
    bool Create(int x, int y, int width, int height, const char * title);
    bool Destroy();

    HWND hWnd;

private:
    bool RegisterWndClass(HINSTANCE hInst);

};
///////////////////////////////////////////////////////////////////////////////
