#ifndef __TB_ICONTROLSDRIVER__
#define __TB_ICONTROLSDRIVER__

#include "idriver.h"

class IControlsDriver : public IDriver
{
public:
    enum ButtonControls
    {
        BUTTON_A,
        BUTTON_B
    };

    enum AxisControls
    {
        AXIS_X,
        AXIS_Y
    };

    virtual ~IControlsDriver() {}

    virtual bool    isButtonPressed(ButtonControls button) const = 0;

    /*! \brief  Return a value between -1 and 1.
        \param  axis    Wanted axis (x or y).
        \return A value between -1 and 1.
    */
    virtual float   getAxis(AxisControls axis) const = 0;
};

#endif //__TB_ICONTROLSDRIVER__