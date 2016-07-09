#include "levelscene.h"

#include "assets.h"

#include "player.h"

LevelScene::LevelScene(HardwareGateway* hardwareGateway)
    : BasicScene(hardwareGateway)
    , m_texturePlayer(ASSET_PLAYER, 4, 4)
    , m_imagePlayer(&m_texturePlayer, 0, 0, 4, 4)
{
}

LevelScene::~LevelScene()
{
}

bool LevelScene::setup()
{
    bool success = BasicScene::setup();

    Player* p0 = new Player(this, &m_imagePlayer);

    m_objects.push_back(p0);

    return success;
}
