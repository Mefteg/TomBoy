#ifndef __TB_ARDUINOAPP__
#define __TB_ARDUINOAPP__

#include "shared/iapp.h"

class ArduinoApp : public IApp
{
public:
    ArduinoApp();
    virtual ~ArduinoApp();

    virtual bool setup();
    virtual bool loop();

protected:
    unsigned long m_lastTime;
};

#endif //__TB_ARDUINOAPP__
