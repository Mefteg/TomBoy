#include "arduinocontrolsdriver.h"

#include <Arduino.h>

#define PIN_BUTTON_A 4
#define PIN_BUTTON_B 2
#define PIN_AXIS_X 0 // A0
#define PIN_AXIS_Y 1 // A1

ArduinoControlsDriver::ArduinoControlsDriver()
{

}

ArduinoControlsDriver::~ArduinoControlsDriver()
{

}

bool ArduinoControlsDriver::init()
{
    pinMode(PIN_BUTTON_A, INPUT);
    pinMode(PIN_BUTTON_B, INPUT);

    return true;
}

bool ArduinoControlsDriver::isButtonPressed(ButtonControls button) const
{
    switch (button)
    {
    case BUTTON_A:
        return digitalRead(PIN_BUTTON_A);;
    case BUTTON_B:
        return digitalRead(PIN_BUTTON_B);;
    }

    return false;
}

float ArduinoControlsDriver::getAxis(AxisControls axis) const
{
    // read joystick values (x and y axis)
    switch (axis) {
        case AXIS_X:
        return analogAxisValueToFloat(analogRead(PIN_AXIS_X));
        case AXIS_Y:
        return -analogAxisValueToFloat(analogRead(PIN_AXIS_Y));
    }
}

float ArduinoControlsDriver::analogAxisValueToFloat(unsigned int value) const
{
    float ratio = -(((float) value) - 512.0f) / 256;
    if (ratio > -0.1f && ratio < 0.1f)
    {
        ratio = 0;
    }

    if (ratio < -1)
    {
        ratio = -1;
    }
    else if (ratio > 1)
    {
        ratio = 1;
    }

    return ratio;
}
