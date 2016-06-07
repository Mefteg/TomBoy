#ifndef __TB_IRENDERER__
#define __TB_IRENDERER__

#include "tomboydefines.h"

class IScene;

class IRenderer
{
public:
    enum Color
    {
        WHITE = 0,
        BLACK
    };

    virtual ~IRenderer() {}

    virtual bool    render(IScene* scene) = 0;

    virtual void    setPixel(int x, int y, Color color) = 0;

};

#endif //__TB_IRENDERER__
