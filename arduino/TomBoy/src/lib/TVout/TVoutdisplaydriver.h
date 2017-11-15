#ifndef __TB_TVOUTDISPLAYDRIVER__
#define __TB_TVOUTDISPLAYDRIVER__

#include "api/hardware/idisplaydriver.h"

#include "TVout.h"

class TVoutDisplayDriver : public IDisplayDriver
{
public:
    TVoutDisplayDriver();
    virtual ~TVoutDisplayDriver() override;

    virtual bool    init() override;

    virtual void    clearPixels() override;
    virtual void    applyPixels() override;

    virtual void    setPixel(unsigned int x, unsigned int y, bool bw) override;

private:
    TVout m_tv;
};

#endif //__TB_TVOUTDISPLAYDRIVER__
