#include "desktoprandomdriver.h"

#include <stdlib.h>
#include <time.h>

DesktopRandomDriver::DesktopRandomDriver()
{
}

DesktopRandomDriver::~DesktopRandomDriver()
{
}

bool DesktopRandomDriver::init()
{
    setSeed(0);
    return true;
}

void DesktopRandomDriver::setSeed(int seed) const
{
    if (seed == 0)
    {
        srand(time(NULL));
    }
    else
    {
        srand(seed);
    }
}

int DesktopRandomDriver::getBetween(int min, int max) const
{
    if (max >= min)
    {
        return (rand() % (max - min)) + min;
    }
    else
    {
        return 0;
    }
}
