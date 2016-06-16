#ifndef __TB_LEVELSCENE__
#define __TB_LEVELSCENE__

#include "../scene/basicscene.h"

class IGameObject;

class LevelScene : public BasicScene
{
public:
    LevelScene(HardwareGateway* hardwareGateway);
    virtual ~LevelScene();

    virtual bool setup() override;

    virtual IGameObject**   getGameObjects() const override;
    virtual unsigned int    getNbGameObjects() const override;

protected:
    IGameObject**   m_objects;
    bool*           m_defaultPixels;
};

#endif //__TB_LEVELSCENE__
