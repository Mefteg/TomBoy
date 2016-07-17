#include "levelscene.h"

#include "assets.h"

#include "player.h"
#include "coin.h"

LevelScene::LevelScene(ISceneManager* sceneManager, HardwareGateway* hardwareGateway)
    : BasicScene(sceneManager, hardwareGateway)
    , m_textureAssets(ASSETS, 32, 16)
    , m_imagePlayer(&m_textureAssets, 0, 0, 12, 4)
    , m_imageCoin(&m_textureAssets, 12, 0, 4, 4)
    , m_imageSpike(&m_textureAssets, 16, 0, 4, 4)
    , m_imageLife(&m_textureAssets, 0, 4, 6, 6)
    , m_points(0)
{
}

LevelScene::~LevelScene()
{
}

bool LevelScene::setup()
{
    bool success = BasicScene::setup();

    Player* player = new Player(this, &m_imagePlayer);
    player->setSize(m_imagePlayer.getWidth(), m_imagePlayer.getHeight());
    player->reset();

    m_objects.push_back(player);
     
    for (unsigned short i = 0; i < 2; ++i)
    {
        int posX = m_hardwareGateway->random->getBetween(0, SCREEN_WIDTH);

        Coin* coin = new Coin(this, &m_imageCoin, player);
        coin->setSize(m_imageCoin.getWidth(), m_imageCoin.getHeight());
        coin->reset();
        coin->setPosition(posX, m_imageCoin.getHeight());
        coin->setActive(true);

        m_objects.push_back(coin);
        m_coins.push_back(coin);
    }

    return success;
}

bool LevelScene::update(float dt)
{
    bool success = BasicScene::update(dt);

    if (m_controlsmanager->isButtonPressed(IControlsDriver::BUTTON_B))
    {
        gameOver();
    }

    return success;
}

void LevelScene::updatePoints(unsigned short points)
{
    m_points += points;
}

void LevelScene::gameOver()
{
    m_sceneManager->setCurrentScene(new LevelScene(m_sceneManager, m_hardwareGateway));
}
