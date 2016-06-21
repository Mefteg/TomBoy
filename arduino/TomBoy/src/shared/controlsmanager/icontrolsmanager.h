#ifndef __TB_ICONTROLSMANAGER__
#define __TB_ICONTROLSMANAGER__

#include "../hardware/icontrolsdriver.h"

class IControlsManager
{
public:
    virtual ~IControlsManager() {}

    virtual bool    isButtonPressed(IControlsDriver::ButtonControls button) const = 0;
    virtual float   getAxis(IControlsDriver::AxisControls axis) const = 0;
};

#endif //__TB_IRENDERER__
