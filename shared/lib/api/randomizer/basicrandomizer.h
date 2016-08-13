#ifndef __TB_BASICRANDOMIZER__
#define __TB_BASICRANDOMIZER__

#include "irandomizer.h"

class BasicRandomizer : public IRandomizer
{
public:
    BasicRandomizer(IRandomDriver* randomDriver);
    virtual ~BasicRandomizer();

    virtual void    setSeed(int seed) const override;
    virtual int     getBetween(int min, int max) const override;

protected:
    IRandomDriver*  m_randomDriver;
};

#endif //__TB_BASICRANDOMIZER__