#include "arduinocontrolsdriver.h"

#include <Arduino.h>

#define PIN_BUTTON_A 4
#define PIN_BUTTON_B 2

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
    float delta = 0;

    // read joystick values (x and y axis)

    return delta;
}
