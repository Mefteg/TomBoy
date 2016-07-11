#ifndef __TB_DESKTOPRANDOMDRIVER__
#define __TB_DESKTOPRANDOMDRIVER__

#include "../shared/lib/api/hardware/irandomdriver.h"

class DesktopRandomDriver : public IRandomDriver
{
public:
    DesktopRandomDriver();
    virtual ~DesktopRandomDriver();

    virtual bool    init() override;

    virtual void    setSeed(int seed) const override;
    virtual int     getBetween(int min, int max) const override;
};

#endif //__TB_DESKTOPRANDOMDRIVER__