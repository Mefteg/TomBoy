#include "desktopapp.h"

#include "../arduino/TomBoy/src/shared/tomboydefines.h"

#include "desktopdisplaydriver.h"
#include "desktopcontrolsdriver.h"

#include "../arduino/TomBoy/src/shared/game/levelscene.h"

DesktopApp::DesktopApp()
    : m_window(sf::VideoMode(SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3), "TomBoy") // width must be >= 116
{
    m_hardwareGateway.display   = new DesktopDisplayDriver(&m_window);
    m_hardwareGateway.controls  = new DesktopControlsDriver();

    m_scene = new LevelScene(&m_hardwareGateway);
}

DesktopApp::~DesktopApp()
{
    delete m_scene;

    delete m_hardwareGateway.controls;
    delete m_hardwareGateway.display;
}

bool DesktopApp::setup()
{
    bool success = true;

    success &= m_hardwareGateway.display->init();

    success &= m_scene->setup();

    return success;
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
        loopAgain |= m_scene->render();
    }

    return loopAgain;
}