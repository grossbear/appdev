#pragma once

///////////////////////////////////////////////////////////////////////////////
enum ButtonType
{
    BTYPE_LBUTTON,
    BTYPE_RBUTTON,
    BTYPE_MBUTTON,
};
///////////////////////////////////////////////////////////////////////////////

class AppWindow;
///////////////////////////////////////////////////////////////////////////////
class ApplicationBase
{
public:
    static ApplicationBase * CreateSingleton();
    static ApplicationBase * GetSingleton();
    virtual ~ApplicationBase();

    virtual void Init();
    virtual void Release();
    void Run();

    virtual void Render();

    virtual void OnCloseWindow();
    virtual void OnSetWindowSize(int x, int y);
    virtual void OnDraw();

    virtual void OnKeyDown(unsigned char key);
    virtual void OnKeyUp(unsigned char key);
    virtual void OnWindowActive(bool active);

    virtual void OnMouseMove(int x, int y);
    virtual void OnMouseMove(ButtonType btype, int x, int y);
    virtual void OnMouseButtonDown(ButtonType btype, int x, int y);
    virtual void OnMouseButtonUp(ButtonType btype, int x, int y);
    virtual void OnMouseButtonDblClk(ButtonType btype, int x, int y);

protected:
    ApplicationBase();

    static ApplicationBase * app;

private:
    bool running;
    AppWindow * window;
};
///////////////////////////////////////////////////////////////////////////////
