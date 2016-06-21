#ifndef __TB_ARDUINOCONTROLSDRIVER__
#define __TB_ARDUINOCONTROLSDRIVER__

#include "shared/hardware/icontrolsdriver.h"

class ArduinoControlsDriver : public IControlsDriver
{
public:
    ArduinoControlsDriver();
    virtual ~ArduinoControlsDriver();

    virtual bool    init() override;

    virtual bool    isButtonPressed(ButtonControls button) const override;
    virtual float   getAxis(AxisControls axis) const override;
};

#endif //__TB_ARDUINOCONTROLSDRIVER__
