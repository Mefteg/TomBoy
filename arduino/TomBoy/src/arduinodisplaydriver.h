#ifndef __TB_ARDUINODISPLAYDRIVER__
#define __TB_ARDUINODISPLAYDRIVER__

#include "api/hardware/idisplaydriver.h"

class ArduinoDisplayDriver : public IDisplayDriver
{
public:
    ArduinoDisplayDriver();
    virtual ~ArduinoDisplayDriver() override;

    virtual bool    init() override;

    virtual void    clearPixels() override;
    virtual void    applyPixels() override;

    virtual void    setPixel(unsigned int x, unsigned int y, bool bw) override;
};

#endif //__TB_ARDUINODISPLAYDRIVER__
