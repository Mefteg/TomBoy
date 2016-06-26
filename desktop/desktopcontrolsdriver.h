#ifndef __TB_DESKTOPCONTROLSDRIVER__
#define __TB_DESKTOPCONTROLSDRIVER__

#include "../shared/lib/api/hardware/icontrolsdriver.h"

class DesktopControlsDriver : public IControlsDriver
{
public:
    DesktopControlsDriver();
    virtual ~DesktopControlsDriver();

    virtual bool    init() override;

    virtual bool    isButtonPressed(ButtonControls button) const override;
    virtual float   getAxis(AxisControls axis) const override;
};

#endif //__TB_DESKTOPCONTROLSDRIVER__