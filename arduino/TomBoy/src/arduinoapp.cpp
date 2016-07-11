#include "arduinoapp.h"

#include <Arduino.h>

#include "arduinodisplaydriver.h"
#include "arduinocontrolsdriver.h"
#include "arduinorandomdriver.h"

#include "game/gamescenemanager.h"

ArduinoApp::ArduinoApp()
    : m_lastTime(0)
{
    Serial.begin(9600);

    m_hardwareGateway.display   = new ArduinoDisplayDriver();
    m_hardwareGateway.controls  = new ArduinoControlsDriver();
    m_hardwareGateway.random    = new ArduinoRandomDriver();

    m_sceneManager = new GameSceneManager(&m_hardwareGateway);
}

ArduinoApp::~ArduinoApp()
{
    delete m_sceneManager;

    delete m_hardwareGateway.random;
    delete m_hardwareGateway.controls;
    delete m_hardwareGateway.display;
}

bool ArduinoApp::setup()
{
    bool success = true;

    success &= m_hardwareGateway.display->init();
    success &= m_hardwareGateway.controls->init();
    success &= m_hardwareGateway.random->init();

    return success;
}

bool ArduinoApp::loop()
{
    bool loopAgain = true;

    if (loopAgain)
    {
        unsigned long currentTime = millis();
        float elapsedTime = ((float) (currentTime - m_lastTime)) / 1000;
        m_lastTime = currentTime;
        // update scene
        loopAgain |= m_sceneManager->updateCurrentScene(elapsedTime);
        // render scene
        loopAgain |= m_sceneManager->renderCurrentScene();

        delay(10);
    }

    return loopAgain;
}
