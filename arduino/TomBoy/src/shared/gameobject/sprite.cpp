#include "sprite.h"

Sprite::Sprite()
: m_x(0)
, m_y(0)
, m_width(4)
, m_height(4)
, m_pixels(0)
{

}

Sprite::Sprite(const bool* pixels)
: m_x(0)
, m_y(0)
, m_width(4)
, m_height(4)
, m_pixels(pixels)
{

}

Sprite::~Sprite()
{

}

bool Sprite::update(float dt)
{
    return true;
}

void Sprite::draw(IRenderer* renderer) const
{
    if (!m_pixels)
    {
        return;
    }

    for (unsigned int i=0; i<m_height; ++i)
    {
        unsigned int screenLine = (unsigned int) m_y + i;
        unsigned int spriteLine = i * m_width;
        for (unsigned int j=0; j<m_width; ++j)
        {
            renderer->setPixel((unsigned int) m_x + j, screenLine, (IRenderer::Color) m_pixels[spriteLine + j]);
        }
    }
}

void Sprite::setPosition(float x, float y)
{
    m_x = x;
    m_y = y;
}
