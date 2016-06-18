#include "arduinodisplaydriver.h"

#include "lcdfunctions.h"

ArduinoDisplayDriver::ArduinoDisplayDriver()
{

}

ArduinoDisplayDriver::~ArduinoDisplayDriver()
{

}

bool ArduinoDisplayDriver::init()
{
    LcdBegin(); // This will setup our pins, and initialize the LCD
    UpdateDisplay(); // with displayMap untouched, SFE logo
    SetContrast(40); // Good values range from 40-60

    return true;
}

void ArduinoDisplayDriver::clearPixels()
{
    // WARNING
    // applyPixels must be called before calling this function again!
    ClearDisplay(WHITE);
}

void ArduinoDisplayDriver::applyPixels()
{
    UpdateDisplay();
    // WARNING
    // clearPixels must be called before calling this function again!
}

void ArduinoDisplayDriver::setPixel(unsigned int x, unsigned int y, bool bw)
{
    SetPixel(x, y, bw);
}
