#include "desktopcontrolsdriver.h"

#include <SFML/Window/Keyboard.hpp>

const sf::Keyboard::Key KEY_BUTTON_A        = sf::Keyboard::A;
const sf::Keyboard::Key KEY_BUTTON_B        = sf::Keyboard::S;

const sf::Keyboard::Key KEY_BUTTON_LEFT     = sf::Keyboard::Left;
const sf::Keyboard::Key KEY_BUTTON_RIGHT    = sf::Keyboard::Right;
const sf::Keyboard::Key KEY_BUTTON_UP       = sf::Keyboard::Up;
const sf::Keyboard::Key KEY_BUTTON_DOWN     = sf::Keyboard::Down;

DesktopControlsDriver::DesktopControlsDriver()
{

}

DesktopControlsDriver::~DesktopControlsDriver()
{

}

bool DesktopControlsDriver::init()
{
    return true;
}

bool DesktopControlsDriver::isButtonPressed(ButtonControls button) const
{
    switch (button)
    {
    case BUTTON_A:
        return sf::Keyboard::isKeyPressed(KEY_BUTTON_A);
    case BUTTON_B:
        return sf::Keyboard::isKeyPressed(KEY_BUTTON_B);
    }

    return false;
}

float DesktopControlsDriver::getAxis(AxisControls axis) const
{
    float delta = 0;

    switch (axis)
    {
    case AXIS_X:
        delta += sf::Keyboard::isKeyPressed(KEY_BUTTON_LEFT) ? -1 : 0;
        delta += sf::Keyboard::isKeyPressed(KEY_BUTTON_RIGHT) ? 1 : 0;
        break;
    case AXIS_Y:
        delta += sf::Keyboard::isKeyPressed(KEY_BUTTON_UP) ? -1 : 0;
        delta += sf::Keyboard::isKeyPressed(KEY_BUTTON_DOWN) ? 1 : 0;
        break;
    }

    return delta;
}
