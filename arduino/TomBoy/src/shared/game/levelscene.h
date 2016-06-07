#ifndef __TB_LEVELSCENE__
#define __TB_LEVELSCENE__

#include "../iscene.h"

class IGameObject;

class LevelScene : public IScene
{
public:
    LevelScene();
    virtual ~LevelScene();

    virtual bool setup() override;
    virtual bool update(float dt) override;

    virtual IGameObject*    getGameObjects() const override;
    virtual unsigned int    getNbGameObjects() const override;

protected:
    IGameObject*    m_object;
    bool*           m_defaultPixels;
};

#endif //__TB_LEVELSCENE__
