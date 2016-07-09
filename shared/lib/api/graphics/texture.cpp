#include "texture.h"

Texture::Texture(const bool * pixels, unsigned int width, unsigned int height)
    : m_pixels(pixels)
    , m_width(width)
    , m_height(height)
{
}

bool Texture::getPixel(unsigned int x, unsigned int y) const
{
    bool pixel = m_pixels[y * m_width + x];
    return pixel;
    //return m_pixels[y * m_width + x];
}
