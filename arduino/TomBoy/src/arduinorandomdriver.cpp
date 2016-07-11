#include "arduinorandomdriver.h"

#include <Arduino.h>

ArduinoRandomDriver::ArduinoRandomDriver()
{
}

ArduinoRandomDriver::~ArduinoRandomDriver()
{
}

bool ArduinoRandomDriver::init()
{
    randomSeed(0);
    return true;
}

void ArduinoRandomDriver::setSeed(int seed) const
{
    if (seed == 0)
    {
        randomSeed(analogRead(0));
    }
    else
    {
        randomSeed(seed);
    }
}

int ArduinoRandomDriver::getBetween(int min, int max) const
{
    if (max >= min)
    {
        return random(min, max);
    }
    else
    {
        return 0;
    }
}
