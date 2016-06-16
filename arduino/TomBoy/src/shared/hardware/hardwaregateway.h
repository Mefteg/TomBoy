#ifndef __TB_HARDWAREGATEWAY__
#define __TB_HARDWAREGATEWAY__

class IDisplayDriver;

class HardwareGateway
{
public:
    HardwareGateway();
    virtual ~HardwareGateway();

    IDisplayDriver* display;
};

#endif //__TB_HARDWAREGATEWAY__