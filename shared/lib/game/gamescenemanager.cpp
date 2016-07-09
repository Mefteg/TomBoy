#include "gamescenemanager.h"

GameSceneManager::GameSceneManager(HardwareGateway* hardwareGateway)
    : BasicSceneManager(hardwareGateway)
{
    setCurrentScene(new LevelScene(this, m_hardwareGateway));
}

GameSceneManager::~GameSceneManager()
{
}
