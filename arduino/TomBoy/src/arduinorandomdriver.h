#ifndef __TB_ARDUINORANDOMDRIVER__
#define __TB_ARDUINORANDOMDRIVER__

#include "api/hardware/irandomdriver.h"

class ArduinoRandomDriver : public IRandomDriver
{
public:
    ArduinoRandomDriver();
    virtual ~ArduinoRandomDriver();

    virtual bool    init() override;

    virtual void    setSeed(int seed) const override;
    virtual int     getBetween(int min, int max) const override;
};

#endif //__TB_ARDUINORANDOMDRIVER__
