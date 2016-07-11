#ifndef __TB_IRANDOMDRIVER__
#define __TB_IRANDOMDRIVER__

#include "idriver.h"

class IRandomDriver : public IDriver
{
public:
    virtual ~IRandomDriver() {}

    virtual void    setSeed(int seed) const = 0;
    virtual int     getBetween(int min, int max) const = 0;
};

#endif //__TB_IRANDOMDRIVER__