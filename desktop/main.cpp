#include "shared/empty/emptyapp.h"
#include "desktopapp.h"

int main()
{
    EmptyApp app;
    //DesktopApp app;

    if (!app.setup())
    {
        return -1;
    }

    while (app.loop())
    {

    }

    return 0;
}
