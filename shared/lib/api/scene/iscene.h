#ifndef __TB_SCENE__
#define __TB_SCENE__

#include "../renderer/irenderer.h"
#include "../controlsmanager/icontrolsmanager.h"

#include "../utils/arraylist.h"

#include "../gameobject/igameobject.h"

class IGameObject;

class IScene
{
public:
    virtual ~IScene() {};

    virtual bool            setup() = 0;
    virtual bool            update(float dt) = 0;
    virtual bool            render() = 0;

    virtual IRenderer&          getRenderer() const = 0;
    virtual IControlsManager&   getControlsManager() const = 0;

    virtual ArrayList<IGameObject*>&    getGameObjects() = 0;
    virtual unsigned int                getNbGameObjects() const = 0;
};

#endif //__TB_SCENE__
