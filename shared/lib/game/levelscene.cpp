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

    m_objects.push_back(p0);

    return success;
}
