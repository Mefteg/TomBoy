#ifndef __TB_HARDWAREGATEWAY__
#define __TB_HARDWAREGATEWAY__

#include "idisplaydriver.h"
#include "icontrolsdriver.h"
#include "irandomdriver.h"

class HardwareGateway
{
public:
    HardwareGateway();
    virtual ~HardwareGateway();

    IDisplayDriver*     display;
    IControlsDriver*    controls;
    IRandomDriver*      random;
};

#endif //__TB_HARDWAREGATEWAY__