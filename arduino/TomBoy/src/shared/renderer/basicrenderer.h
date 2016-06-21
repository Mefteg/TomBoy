#ifndef __TB_BASICRENDERER__
#define __TB_BASICRENDERER__

#include "irenderer.h"

class BasicRenderer : public IRenderer
{
public:
    BasicRenderer(IDisplayDriver* displayDriver);
    virtual ~BasicRenderer();

    virtual void    clearPixels() override;
    virtual void    applyPixels() override;

    virtual void    setPixel(unsigned int x, unsigned int y, Color color) override;

protected:
    IDisplayDriver* m_displayDriver;
};

#endif //__TB_BASICRENDERER__
