#ifndef __TB_BASICAPP__
#define __TB_BASICAPP__

#include "iapp.h"

#include "../hardware/hardwaregateway.h"

class BasicApp : public IApp
{
public:
    BasicApp();
    virtual ~BasicApp();

    virtual bool setup() override;
    virtual bool loop() override;

protected:
    HardwareGateway m_hardwareGateway;
    IScene*         m_scene;
};

#endif //__TB_BASICAPP__