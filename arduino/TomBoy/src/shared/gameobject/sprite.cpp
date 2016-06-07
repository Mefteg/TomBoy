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

    for (int i=0; i<m_height; ++i)
    {
        int screenLine = m_y + i;
        int spriteLine = i * m_width;
        for (int j=0; j<m_width; ++j)
        {
            renderer->setPixel(screenLine, m_x + j, (IRenderer::Color) m_pixels[spriteLine + j]);
        }
    }
}

void Sprite::setPosition(float x, float y)
{
    m_x = x;
    m_y = y;
}
