#include "basicscenemanager.h"

BasicSceneManager::BasicSceneManager(HardwareGateway* hardwareGateway)
    : m_hardwareGateway(hardwareGateway)
    , m_currentScene(0)
    , m_nextScene(0)
{
}

BasicSceneManager::~BasicSceneManager()
{
    if (m_nextScene)
    {
        delete m_nextScene;
    }

    delete m_currentScene;
}

bool BasicSceneManager::updateCurrentScene(float dt)
{
    if (m_nextScene)
    {
        delete m_currentScene;
        m_currentScene = m_nextScene;
        m_nextScene = 0;

        return m_currentScene->setup();
    }
    else
    {
        return m_currentScene->update(dt);
    }
}

bool BasicSceneManager::renderCurrentScene()
{
    return m_currentScene->render();
}

IScene * BasicSceneManager::getCurrentScene() const
{
    return m_currentScene;
}

void BasicSceneManager::setCurrentScene(IScene * scene)
{
    m_nextScene = scene;
}
