#ifndef __TB_PCD8544DISPLAYDRIVER__
#define __TB_PCD8544DISPLAYDRIVER__

#include "api/hardware/idisplaydriver.h"

class PCD8544DisplayDriver : public IDisplayDriver
{
public:
    PCD8544DisplayDriver();
    virtual ~PCD8544DisplayDriver() override;

    virtual bool    init() override;

    virtual void    clearPixels() override;
    virtual void    applyPixels() override;

    virtual void    setPixel(unsigned int x, unsigned int y, bool bw) override;
};

#endif //__TB_PCD8544DISPLAYDRIVER__
