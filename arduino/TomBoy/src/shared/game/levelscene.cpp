#include "levelscene.h"

#include "assets.h"

#include "player.h"

LevelScene::LevelScene()
{
    m_defaultPixels = new bool[16];

    m_defaultPixels[0] = 1;
    m_defaultPixels[1] = 1;
    m_defaultPixels[2] = 1;
    m_defaultPixels[3] = 1;

    m_defaultPixels[4] = 1;
    m_defaultPixels[5] = 0;
    m_defaultPixels[6] = 1;
    m_defaultPixels[7] = 1;

    m_defaultPixels[8] = 1;
    m_defaultPixels[9] = 1;
    m_defaultPixels[10] = 0;
    m_defaultPixels[11] = 1;

    m_defaultPixels[12] = 1;
    m_defaultPixels[13] = 1;
    m_defaultPixels[14] = 1;
    m_defaultPixels[15] = 1;

    m_object = new Player(ASSET_PLAYER);
}

LevelScene::~LevelScene()
{
    delete [] m_defaultPixels;
    delete m_object;
}

bool LevelScene::setup()
{
    return true;
}

bool LevelScene::update(float dt)
{
    m_object->update(dt);
    return true;
}

IGameObject* LevelScene::getGameObjects() const
{
    return m_object;
}

unsigned int LevelScene::getNbGameObjects() const
{
    return 1;
}
