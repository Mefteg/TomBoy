#include "emptyapp.h"

#include <iostream>

#include "../../../shared/lib/api/tomboydefines.h"

#include "emptydisplaydriver.h"
#include "emptycontrolsdriver.h"
#include "../../desktoprandomdriver.h"

#include "../../../shared/lib/game/gamescenemanager.h"

#include "../../../shared/lib/microprofile/microprofile.h"

EmptyApp::EmptyApp()
    : m_currentFrame(1)
    , m_nbFramesMax(10)
{
    m_hardwareGateway.display   = new EmptyDisplayDriver();
    m_hardwareGateway.controls = new EmptyControlsDriver();
    m_hardwareGateway.random  = new DesktopRandomDriver();

    m_sceneManager = new GameSceneManager(&m_hardwareGateway);
}

EmptyApp::~EmptyApp()
{
    delete m_sceneManager;

    delete m_hardwareGateway.random;
    delete m_hardwareGateway.controls;
    delete m_hardwareGateway.display;
}

bool EmptyApp::setup()
{
    bool success = true;

    success &= m_hardwareGateway.display->init();
    success &= m_hardwareGateway.random->init();

    return success;
}

bool EmptyApp::loop()
{
    bool loopAgain = true;

    std::cout << "Frame: " << m_currentFrame << "/" << m_nbFramesMax << std::endl;

    {
        MICROPROFILE_SCOPEI("EmptyApp", "loop", MP_YELLOW);

        // update scene
        loopAgain |= m_sceneManager->updateCurrentScene(0.0f);
        // render scene
        loopAgain |= m_sceneManager->renderCurrentScene();
    }

    MicroProfileFlip(nullptr);

    ++m_currentFrame;

    return loopAgain && (m_currentFrame <= m_nbFramesMax);
}
