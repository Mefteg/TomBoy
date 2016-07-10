#include "basicrenderer.h"

BasicRenderer::BasicRenderer(IDisplayDriver* displayDriver)
    : m_displayDriver(displayDriver)
{

}

BasicRenderer::~BasicRenderer()
{

}

void BasicRenderer::clearPixels()
{
    // simply use the driver
    m_displayDriver->clearPixels();
}

void BasicRenderer::applyPixels()
{
    // simply use the driver
    m_displayDriver->applyPixels();
}

void BasicRenderer::setPixel(unsigned int x, unsigned int y, Color color)
{
    // simply use the driver
    // use white as "transparent"
    if (color == Color_BLACK)
    {
        m_displayDriver->setPixel(x, y, color);
    }
}
