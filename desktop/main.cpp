#include "desktopapp.h"

int main()
{
    DesktopApp app;

    if (!app.setup())
    {
        return -1;
    }

    while (app.loop())
    {

    }

    return 0;
}
