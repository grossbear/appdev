#include "xappwin.h"
#include "appbase.h"

///////////////////////////////////////////////////////////////////////////////
AppWindow::AppWindow(int x, int y, int width, int height, const char * title):
display(NULL), winId(0)
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
    return winId != 0;
}

///////////////////////////////////////////////////////////////////////////////
bool AppWindow::Create(int x, int y, int width, int height, const char * title)
{
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        return false;
    }

    int defScreenId = DefaultScreen(display);
    Window rootWinId = RootWindow(display, defScreenId);
    
    int borderWidth = 1;
    unsigned long borderColor = BlackPixel(display, defScreenId);
    unsigned long backgroundColor = WhitePixel(display, defScreenId);

    // Creating simple X window
    winId = XCreateSimpleWindow(
            display,
            rootWinId,
            x,
            y,
            width,
            height,
            borderWidth,
            borderColor,
            backgroundColor);

    XSelectInput(display, winId, ExposureMask | KeyPressMask);
    XMapWindow(display, winId);

    XStoreName(display, winId, title);
 
    WM_DELETE_WINDOW = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, winId, &WM_DELETE_WINDOW, 1);

    return true;
}

///////////////////////////////////////////////////////////////////////////////
bool AppWindow::Destroy()
{
    XDestroyWindow(display, winId);
    XCloseDisplay(display);
    
    display = NULL;
    winId = 0;

    return true;
}

///////////////////////////////////////////////////////////////////////////////
void AppWindow::ProcessEvents()
{
    XEvent event;
    XNextEvent(display, &event);

    switch(event.type)
    {
        case Expose:
        break;

        case KeyPress:
        {
            char buffer[256] = {0};
            KeySym keysym;
            int len = XLookupString(&event.xkey,
                                    buffer,
                                    sizeof(buffer),
                                    &keysym,
                                    NULL);

            if (keysym == XK_Escape)
            {
                ApplicationBase * app = ApplicationBase::GetSingleton();
                app->CloseWindow();
            }
        }
        break;

        case ClientMessage:
        {
            unsigned int clientMsgId = 
                static_cast<unsigned int>(event.xclient.data.l[0]);
            if (clientMsgId == WM_DELETE_WINDOW)
            {
                ApplicationBase * app = ApplicationBase::GetSingleton();
                app->CloseWindow();
            }
        }
        break;
    } 

}

///////////////////////////////////////////////////////////////////////////////
