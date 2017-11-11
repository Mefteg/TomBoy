#ifndef __TB_EMPTYDISPLAYDRIVER__
#define __TB_EMPTYDISPLAYDRIVER__

#include "../../../shared/lib/api/hardware/idisplaydriver.h"

class EmptyDisplayDriver : public IDisplayDriver
{
public:
    EmptyDisplayDriver() {};
    virtual ~EmptyDisplayDriver() override {};

    virtual bool    init() override {return true;};

    virtual void    clearPixels() override {};
    virtual void    applyPixels() override {};

    virtual void    setPixel(unsigned int x, unsigned int y, bool bw) override {};
};

#endif //__TB_EMPTYDISPLAYDRIVER__
