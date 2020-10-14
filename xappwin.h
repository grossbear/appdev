#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
class AppWindow
{
public:
    AppWindow(int x, int y, int width, int height, const char * title);
    ~AppWindow();

    bool WindowAvailable() const;

    void ProcessEvents();

protected:
    bool Create(int x, int y, int width, int height, const char * title);
    bool Destroy();

    Display * display;
    Window winId;

    bool uname_ok;
    Atom WM_DELETE_WINDOW; 

};
///////////////////////////////////////////////////////////////////////////////
