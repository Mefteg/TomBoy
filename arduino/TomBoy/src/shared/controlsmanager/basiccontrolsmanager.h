#ifndef __TB_BASICCONTROLSMANAGER__
#define __TB_BASICCONTROLSMANAGER__

#include "icontrolsmanager.h"

class BasicControlsManager : public IControlsManager
{
public:
    BasicControlsManager(IControlsDriver* controlsDriver);
    virtual ~BasicControlsManager();

    virtual bool    isButtonPressed(IControlsDriver::ButtonControls button) const override;
    virtual float   getAxis(IControlsDriver::AxisControls axis) const override;

protected:
    IControlsDriver* m_controlsDriver;
};

#endif //__TB_BASICCONTROLSMANAGER__
