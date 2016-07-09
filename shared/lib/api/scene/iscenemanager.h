#ifndef __TB_ISCENEMANAGER__
#define __TB_ISCENEMANAGER__

#include "iscene.h"

class ISceneManager
{
public:
    virtual ~ISceneManager() {};

    virtual bool    updateCurrentScene(float dt) = 0;
    virtual bool    renderCurrentScene() = 0;

    virtual IScene* getCurrentScene() const = 0;
    virtual void    setCurrentScene(IScene* scene) = 0;
};

#endif //__TB_ISCENEMANAGER__
