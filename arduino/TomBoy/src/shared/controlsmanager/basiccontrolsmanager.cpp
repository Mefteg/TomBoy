#include "basiccontrolsmanager.h"

BasicControlsManager::BasicControlsManager(IControlsDriver * controlsDriver)
    : m_controlsDriver(controlsDriver)
{

}

BasicControlsManager::~BasicControlsManager()
{

}

bool BasicControlsManager::isButtonPressed(IControlsDriver::ButtonControls button) const
{
    return m_controlsDriver->isButtonPressed(button);
}

float BasicControlsManager::getAxis(IControlsDriver::AxisControls axis) const
{
    return m_controlsDriver->getAxis(axis);
}
