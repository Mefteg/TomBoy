#include "TVoutdisplaydriver.h"

#include "api/tomboydefines.h"

TVoutDisplayDriver::TVoutDisplayDriver()
{

}

TVoutDisplayDriver::~TVoutDisplayDriver()
{

}

bool TVoutDisplayDriver::init()
{
    m_tv.begin(PAL, SCREEN_WIDTH, SCREEN_HEIGHT);

    return true;
}

void TVoutDisplayDriver::clearPixels()
{
    m_tv.clear_screen();
}

void TVoutDisplayDriver::applyPixels()
{

}

void TVoutDisplayDriver::setPixel(unsigned int x, unsigned int y, bool bw)
{
    m_tv.set_pixel(x, y, bw == 1 ? WHITE : BLACK);
}
