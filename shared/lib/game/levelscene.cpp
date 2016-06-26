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
}

bool LevelScene::setup()
{
    bool success = BasicScene::setup();

    Player* p0 = new Player(this, ASSET_PLAYER);
    Player* p1 = new Player(this, ASSET_PLAYER);
    p1->setPosition(30, 10);

    m_objects.push_back(p0);
    m_objects.push_back(p1);

    return success;
}
