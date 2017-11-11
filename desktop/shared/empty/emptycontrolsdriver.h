#ifndef __TB_EMPTYCONTROLSDRIVER__
#define __TB_EMPTYCONTROLSDRIVER__

#include "../../../shared/lib/api/hardware/icontrolsdriver.h"

class EmptyControlsDriver : public IControlsDriver
{
public:
    EmptyControlsDriver() {};
    virtual ~EmptyControlsDriver() {};

    virtual bool    init() override {return true;};

    virtual bool    isButtonPressed(ButtonControls button) const override {return false;};
    virtual float   getAxis(AxisControls axis) const override {return 0.0f;};
};

#endif //__TB_EMPTYCONTROLSDRIVER__
