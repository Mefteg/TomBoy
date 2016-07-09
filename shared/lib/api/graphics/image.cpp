#include "image.h"

Image::Image(const Texture * texture, unsigned int originX, unsigned int originY, unsigned int width, unsigned int height)
    : m_texture(texture)
    , m_originX(originX)
    , m_originY(originY)
    , m_width(width)
    , m_height(height)
{
}

IRenderer::Color Image::getPixel(unsigned int x, unsigned int y) const
{
    return (IRenderer::Color) m_texture->getPixel(m_originX + x, m_originY + y);
}

void Image::draw(IRenderer* renderer, unsigned int screenPosX, unsigned int screenPosY) const
{
    for (unsigned int i = 0; i < m_height; ++i)
    {
        for (unsigned int j = 0; j < m_width; ++j)
        {
            renderer->setPixel(screenPosX + j, screenPosY + i, getPixel(j, i));
        }
    }
}
