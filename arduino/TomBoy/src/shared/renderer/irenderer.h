#ifndef __TB_IRENDERER__
#define __TB_IRENDERER__

#include "../tomboydefines.h"

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

    virtual void    clearPixels() = 0;
    virtual void    applyPixels() = 0;

    virtual void    setPixel(unsigned int x, unsigned int y, Color color) = 0;
};

#endif //__TB_IRENDERER__
