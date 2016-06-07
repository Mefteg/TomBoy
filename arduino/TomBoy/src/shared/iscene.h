#ifndef __TB_SCENE__
#define __TB_SCENE__

#include "irenderer.h"

#include "gameobject/igameobject.h"

class IScene
{
public:
    virtual ~IScene() {};

    virtual bool            setup() = 0;
    virtual bool            update(float dt) = 0;

    virtual IGameObject*    getGameObjects() const = 0;
    virtual unsigned int    getNbGameObjects() const = 0;
};

#endif //__TB_SCENE__
