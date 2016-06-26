#ifndef __TB_LEVELSCENE__
#define __TB_LEVELSCENE__

#include "../api/scene/basicscene.h"

class IGameObject;

class LevelScene : public BasicScene
{
public:
    LevelScene(HardwareGateway* hardwareGateway);
    virtual ~LevelScene();

    virtual bool setup() override;

protected:
    bool*           m_defaultPixels;
};

#endif //__TB_LEVELSCENE__
