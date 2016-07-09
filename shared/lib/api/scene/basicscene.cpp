#include "basicscene.h"

#include "../renderer/basicrenderer.h"
#include "../controlsmanager/basiccontrolsmanager.h"

BasicScene::BasicScene(ISceneManager* sceneManager, HardwareGateway* hardwareGateway)
    : m_sceneManager(sceneManager)
    , m_hardwareGateway(hardwareGateway)
{

}

BasicScene::~BasicScene()
{
    delete m_controlsmanager;
    delete m_renderer;

    // delete all objects
    const unsigned int nbGameObjects = m_objects.getSize();
    for (unsigned int i = 0; i < nbGameObjects; ++i)
    {
        delete m_objects.at(i);
    }
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
    const unsigned int nbGameObjects = m_objects.getSize();
    // update all gameobjects
    for (unsigned int i = 0; i < nbGameObjects; ++i)
    {
        m_objects.at(i)->update(dt);
    }
    return true;
}

bool BasicScene::render()
{
    // clear
    m_renderer->clearPixels();

    const unsigned int nbGameObjects = m_objects.getSize();
    // display all gameobjects
    for (unsigned int i = 0; i < nbGameObjects; ++i)
    {
        m_objects.at(i)->draw(m_renderer);
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

ArrayList<IGameObject*>& BasicScene::getGameObjects()
{
    return m_objects;
}

unsigned int BasicScene::getNbGameObjects() const
{
    return m_objects.getSize();
}
