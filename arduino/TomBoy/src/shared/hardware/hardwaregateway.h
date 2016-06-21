#ifndef __TB_HARDWAREGATEWAY__
#define __TB_HARDWAREGATEWAY__

class IDisplayDriver;
class IControlsDriver;

class HardwareGateway
{
public:
    HardwareGateway();
    virtual ~HardwareGateway();

    IDisplayDriver*     display;
    IControlsDriver*    controls;
};

#endif //__TB_HARDWAREGATEWAY__