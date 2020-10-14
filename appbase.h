#pragma once

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

    void CloseWindow();
    void SetWindowSize(int x, int y);

protected:
    ApplicationBase();

    static ApplicationBase * app;

private:
    bool running;
    AppWindow * window;
};
///////////////////////////////////////////////////////////////////////////////
