#ifndef __TB_EMPTYAPP__
#define __TB_EMPTYAPP__

#include "../../../shared/lib/api/app/basicapp.h"

class EmptyApp : public BasicApp
{
public:
    EmptyApp();
    virtual ~EmptyApp();

    virtual bool setup() override;
    virtual bool loop() override;

protected:
    unsigned int m_currentFrame;
    unsigned int m_nbFramesMax;
};

#endif //__TB_EMPTYAPP__
