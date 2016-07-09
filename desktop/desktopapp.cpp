#include "desktopapp.h"

#include "../shared/lib/api/tomboydefines.h"

#include "desktopdisplaydriver.h"
#include "desktopcontrolsdriver.h"

#include "../shared/lib/game/gamescenemanager.h"

DesktopApp::DesktopApp()
    : m_window(sf::VideoMode(SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3), "TomBoy") // width must be >= 116
{
    m_hardwareGateway.display   = new DesktopDisplayDriver(&m_window);
    m_hardwareGateway.controls  = new DesktopControlsDriver();

    m_sceneManager = new GameSceneManager(&m_hardwareGateway);
}

DesktopApp::~DesktopApp()
{
    delete m_sceneManager;

    delete m_hardwareGateway.controls;
    delete m_hardwareGateway.display;
}

bool DesktopApp::setup()
{
    bool success = true;

    success &= m_hardwareGateway.display->init();

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
        loopAgain |= m_sceneManager->updateCurrentScene(elapsedTime.asSeconds());
        // render scene
        loopAgain |= m_sceneManager->renderCurrentScene();
    }

    return loopAgain;
}