#include "arduinoapp.h"

#include <Arduino.h>

#include "shared/game/levelscene.h"
#include "arduinorenderer.h"

ArduinoApp::ArduinoApp()
    : m_lastTime(0)
{
    Serial.begin(9600);

    m_scene = new LevelScene();
    m_renderer = new ArduinoRenderer();
}

ArduinoApp::~ArduinoApp()
{
    delete m_renderer;
    delete m_scene;
}

bool ArduinoApp::setup()
{
    return m_scene->setup();
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
        //loopAgain |= m_scene->update(0.016f);
        loopAgain |= m_scene->update(elapsedTime);
        // render scene
        loopAgain |= m_renderer->render(m_scene);

        delay(10);
    }

    return loopAgain;
}
