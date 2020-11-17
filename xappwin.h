#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
class AppWindow
{
public:
    AppWindow(int x, int y, int width, int height, int flgs, const char * wname);
    ~AppWindow();

    bool WindowAvailable() const;

    void ProcessEvents();

protected:
    bool Create(int x, int y, int width, int height, int flags, const char * wname);
    bool Destroy();

    Display * display;
    Window winId;

    bool uname_ok;
    Atom wmDeleteWindow; 
    Atom wmState;
    Atom wmStateHidden;
    Atom wmStateFullscreen;
    Atom wmStateFocused;
    Atom wmStateMaxHori;
    Atom wmStateMaxVert;
};
///////////////////////////////////////////////////////////////////////////////
