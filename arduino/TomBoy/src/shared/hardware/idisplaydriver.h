#ifndef __TB_IDISPLAYDRIVER__
#define __TB_IDISPLAYDRIVER__

#include "idriver.h"

class IDisplayDriver : public IDriver
{
public:
    virtual ~IDisplayDriver() {}

    virtual void    clearPixels() = 0;
    virtual void    applyPixels() = 0;

    virtual void    setPixel(unsigned int x, unsigned int y, bool bw) = 0;
};

#endif //__TB_IDISPLAYDRIVER__