#ifndef __TB_LEVELSCENE__
#define __TB_LEVELSCENE__

#include "../api/scene/basicscene.h"

#include "../api/graphics/image.h"

class LevelScene : public BasicScene
{
public:
    LevelScene(ISceneManager* sceneManager, HardwareGateway* hardwareGateway);
    virtual ~LevelScene();

    virtual bool    setup() override;
    virtual bool    update(float dt) override;

protected:
    Texture m_texturePlayer;
    Image   m_imagePlayer;
};

#endif //__TB_LEVELSCENE__
