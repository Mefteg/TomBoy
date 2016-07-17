#ifndef __TB_LEVELSCENE__
#define __TB_LEVELSCENE__

#include "../api/scene/basicscene.h"

#include "../api/graphics/image.h"

class Coin;

class LevelScene : public BasicScene
{
public:
    LevelScene(ISceneManager* sceneManager, HardwareGateway* hardwareGateway);
    virtual ~LevelScene();

    virtual bool    setup() override;
    virtual bool    update(float dt) override;

    void            updatePoints(unsigned short points);
    void            gameOver();

protected:
    Texture m_textureAssets;
    Image   m_imagePlayer;
    Image   m_imageCoin;
    Image   m_imageSpike;
    Image   m_imageLife;

    ArrayList<Coin*>    m_coins;

    unsigned int        m_points;
};

#endif //__TB_LEVELSCENE__
