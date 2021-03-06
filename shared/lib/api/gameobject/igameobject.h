#ifndef __TB_IGAMEOBJECT__
#define __TB_IGAMEOBJECT__

#include "../scene/iscene.h"
#include "../renderer/irenderer.h"

class IGameObject
{
public:
    virtual ~IGameObject() {};

    virtual bool update(float dt) = 0;
    virtual void draw(IRenderer* renderer) const = 0;

    virtual void reset() = 0;
};

#endif //__TB_IGAMEOBJECT__
