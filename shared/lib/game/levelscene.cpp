#include "levelscene.h"

#include "assets.h"

#include "player.h"

LevelScene::LevelScene(ISceneManager* sceneManager, HardwareGateway* hardwareGateway)
    : BasicScene(sceneManager, hardwareGateway)
    , m_textureAssets(ASSETS, 32, 16)
    , m_imagePlayer(&m_textureAssets, 0, 0, 12, 4)
    , m_imageCoin(&m_textureAssets, 12, 0, 4, 4)
    , m_imageSpike(&m_textureAssets, 16, 0, 4, 4)
    , m_imageLife(&m_textureAssets, 0, 4, 6, 6)
{
}

LevelScene::~LevelScene()
{
}

bool LevelScene::setup()
{
    bool success = BasicScene::setup();

    Player* p0 = new Player(this, &m_imagePlayer);
    p0->setSize(m_imagePlayer.getWidth(), m_imagePlayer.getHeight());
    p0->reset();

    m_objects.push_back(p0);

    return success;
}

bool LevelScene::update(float dt)
{
    bool success = BasicScene::update(dt);

    if (m_controlsmanager->isButtonPressed(IControlsDriver::BUTTON_B))
    {
        m_sceneManager->setCurrentScene(new LevelScene(m_sceneManager, m_hardwareGateway));
    }

    return success;
}
