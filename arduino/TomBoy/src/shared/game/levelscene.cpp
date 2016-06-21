#include "levelscene.h"

#include "assets.h"

#include "player.h"

LevelScene::LevelScene(HardwareGateway* hardwareGateway)
    : BasicScene(hardwareGateway)
{
}

LevelScene::~LevelScene()
{
    delete [] m_defaultPixels;

    delete m_objects[0];
    delete[] m_objects;
}

bool LevelScene::setup()
{
    bool success = BasicScene::setup();

    m_objects = new IGameObject*[1];
    m_objects[0] = new Player(this, ASSET_PLAYER);

    return success;
}

IGameObject** LevelScene::getGameObjects() const
{
    return m_objects;
}

unsigned int LevelScene::getNbGameObjects() const
{
    return 1;
}
