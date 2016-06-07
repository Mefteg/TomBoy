#include "desktopapp.h"

#include "../arduino/TomBoy/src/shared/tomboydefines.h"

#include "../arduino/TomBoy/src/shared/game/levelscene.h"
#include "desktoprenderer.h"

DesktopApp::DesktopApp()
    : m_window(sf::VideoMode(SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3), "TomBoy") // width must be >= 116
{
    m_scene = new LevelScene();
    m_renderer = new DesktopRenderer(&m_window);
}

DesktopApp::~DesktopApp()
{
    delete m_renderer;
    delete m_scene;
}

bool DesktopApp::setup()
{
    return m_scene->setup();
}

bool DesktopApp::loop()
{
    bool loopAgain = true;

    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
            loopAgain = false;
        }
    }

    if (loopAgain)
    {
        sf::Time elapsedTime = m_clock.restart();
        // update scene
        loopAgain |= m_scene->update(elapsedTime.asSeconds());
        // render scene
        loopAgain |= m_renderer->render(m_scene);
    }

    return loopAgain;
}