#include "levelscene.h"

#include "assets.h"

#include "player.h"
#include "coin.h"

const unsigned short LevelScene::NB_VALID_COINS_START = 3;

LevelScene::LevelScene(ISceneManager* sceneManager, HardwareGateway* hardwareGateway)
    : BasicScene(sceneManager, hardwareGateway)
    , m_textureAssets(ASSETS, 32, 16)
    , m_imagePlayer(&m_textureAssets, 0, 0, 12, 4)
    , m_imageCoin(&m_textureAssets, 12, 0, 4, 4)
    , m_imageSpike(&m_textureAssets, 16, 0, 4, 4)
    , m_imageLife(&m_textureAssets, 0, 4, 6, 6)
    , m_player(0)
    , m_nbCoinsMax(10)
    , m_nbActiveCoins(0)
    , m_points(0)
{
}

LevelScene::~LevelScene()
{
}

bool LevelScene::setup()
{
    bool success = BasicScene::setup();

    // create the player
    m_player = CreatePlayer();

    // add the player to objects array
    m_objects.push_back(m_player);
     
    for (unsigned short i = 0; i < m_nbCoinsMax; ++i)
    {
        // create a new coin
        Coin* coin = CreateCoin();
        coin->setId(i);

        // add coin to objects array
        m_objects.push_back(coin);
        // add coin to coins array too
        m_coins.push_back(coin);

        // if there is not enough active coins to start the game
        if (m_coins.getSize() <= NB_VALID_COINS_START)
        {
            // set the coin active
            coin->setActive(true);
            ++m_nbActiveCoins;
        }
        else
        {
            // otherwise, set the coin inactive
            coin->setActive(false);
        }
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

    // if the player has enough points
    if (m_nbActiveCoins < m_nbCoinsMax && m_points % 5 == 0)
    {
        ++m_nbActiveCoins;

        // set a new coin active
        m_coins.at(m_nbActiveCoins)->setActive(true);
    }
}

void LevelScene::gameOver()
{
    m_sceneManager->setCurrentScene(new LevelScene(m_sceneManager, m_hardwareGateway));
}

unsigned short LevelScene::getNbActiveCoins() const
{
    return m_nbActiveCoins;
}

ArrayList<Coin*>& LevelScene::getCoins()
{
    return m_coins;
}

Player* LevelScene::CreatePlayer()
{
    Player* player = new Player(this, &m_imagePlayer);
    player->setSize(m_imagePlayer.getWidth(), m_imagePlayer.getHeight());
    player->reset();

    return player;
}

Coin* LevelScene::CreateCoin()
{
    Coin* coin = new Coin(this, &m_imageCoin, m_player);
    coin->setSize(m_imageCoin.getWidth(), m_imageCoin.getHeight());
    coin->reset();

    return coin;
}
