#include "arduinorenderer.h"

#include "shared/iscene.h"

#include "lcdfunctions.h"

ArduinoRenderer::ArduinoRenderer()
{
    lcdBegin(); // This will setup our pins, and initialize the LCD
    updateDisplay(); // with displayMap untouched, SFE logo
    setContrast(40); // Good values range from 40-60
}

ArduinoRenderer::~ArduinoRenderer()
{

}

bool ArduinoRenderer::render(IScene* scene)
{
    clearDisplay(WHITE); // Begin by clearing the display

    IGameObject* object = scene->getGameObjects();
    object->draw(this);

    updateDisplay();

    return true;
}

void ArduinoRenderer::setPixel(int x, int y, Color color)
{
    SetPixel(x, y, color);
}
