#include "arduinoapp.h"

#include <Arduino.h>

#include "lib/PCD8544/PCD8544displaydriver.h"
#include "arduinocontrolsdriver.h"
#include "arduinorandomdriver.h"

#include "game/gamescenemanager.h"

#ifdef DEBUG
#include "lib/monitoring/monitoring.h"
#endif //DEBUG

ArduinoApp::ArduinoApp()
    : m_lastTime(0)
{
    m_hardwareGateway.display   = new PCD8544DisplayDriver();
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

    #ifdef DEBUG
    Serial.begin(BAUDRATE);

    String message = String(Monitoring::FreeRam());
    Serial.println(message);
    #endif //DEBUG

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
