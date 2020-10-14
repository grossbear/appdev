#include <stdio.h>
#include "appbase.h"

///////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("AppBase programme\n");

    ApplicationBase * app = ApplicationBase::CreateSingleton();

    app->Init();
    app->Run();
    app->Release();

    delete (app);

    return 0;
}
///////////////////////////////////////////////////////////////////////////////
