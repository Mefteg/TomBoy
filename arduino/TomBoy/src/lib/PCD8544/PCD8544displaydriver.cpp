#include "PCD8544displaydriver.h"

#include "lcdfunctions.h"

PCD8544DisplayDriver::PCD8544DisplayDriver()
{

}

PCD8544DisplayDriver::~PCD8544DisplayDriver()
{

}

bool PCD8544DisplayDriver::init()
{
    LcdBegin(); // This will setup our pins, and initialize the LCD
    UpdateDisplay(); // with displayMap untouched, SFE logo
    SetContrast(40); // Good values range from 40-60

    return true;
}

void PCD8544DisplayDriver::clearPixels()
{
    // WARNING
    // applyPixels must be called before calling this function again!
    ClearDisplay(WHITE);
}

void PCD8544DisplayDriver::applyPixels()
{
    UpdateDisplay();
    // WARNING
    // clearPixels must be called before calling this function again!
}

void PCD8544DisplayDriver::setPixel(unsigned int x, unsigned int y, bool bw)
{
    SetPixel(x, y, bw);
}
