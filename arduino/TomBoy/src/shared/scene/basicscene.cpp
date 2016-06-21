#include "basicscene.h"

#include "../renderer/basicrenderer.h"
#include "../controlsmanager/basiccontrolsmanager.h"

BasicScene::BasicScene(HardwareGateway* hardwareGateway)
    : m_hardwareGateway(hardwareGateway)
{

}

BasicScene::~BasicScene()
{
    delete m_controlsmanager;
    delete m_renderer;
}

bool BasicScene::setup()
{
    // init default renderer with the display driver
    m_renderer = new BasicRenderer(m_hardwareGateway->display);

    // init default controls manager with the controls driver
    m_controlsmanager = new BasicControlsManager(m_hardwareGateway->controls);

    return true;
}

bool BasicScene::update(float dt)
{
    IGameObject** objects = getGameObjects();
    const unsigned int nbGameObjects = getNbGameObjects();
    // update all gameobjects
    for (unsigned int i = 0; i < getNbGameObjects(); ++i)
    {
        objects[i]->update(dt);
    }
    return true;
}

bool BasicScene::render()
{
    // clear
    m_renderer->clearPixels();

    IGameObject** objects = getGameObjects();
    const unsigned int nbGameObjects = getNbGameObjects();
    // display all gameobjects
    for (unsigned int i = 0; i < nbGameObjects; ++i)
    {
        objects[i]->draw(m_renderer);
    }

    // apply
    m_renderer->applyPixels();

    return true;
}

IRenderer& BasicScene::getRenderer() const
{
    return *m_renderer;
}

IControlsManager& BasicScene::getControlsManager() const
{
    return *m_controlsmanager;
}

IGameObject ** BasicScene::getGameObjects() const
{
    return nullptr;
}

unsigned int BasicScene::getNbGameObjects() const
{
    return 0;
}
