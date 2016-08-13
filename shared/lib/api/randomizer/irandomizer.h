#ifndef __TB_IRANDOMIZER__
#define __TB_IRANDOMIZER__

#include "../hardware/irandomdriver.h"

class IRandomizer
{
public:
    virtual ~IRandomizer() {}

    virtual void    setSeed(int seed) const = 0;
    virtual int     getBetween(int min, int max) const = 0;
};

#endif //__TB_IRANDOMIZER__