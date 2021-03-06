#ifndef __TB_IMAGE__
#define __TB_IMAGE__

#include "../renderer/irenderer.h"

#include "texture.h"

class Image
{
public:
    Image(const Texture* texture, unsigned int originX, unsigned int originY,  unsigned int width, unsigned int height);
    virtual ~Image() {}

    virtual void                draw(IRenderer* renderer, unsigned int screenPosX, unsigned int screenPosY) const;

    virtual IRenderer::Color    getPixel(unsigned int x, unsigned int y) const;

    unsigned int                getWidth() const { return m_width; }
    unsigned int                getHeight() const { return m_height; }

protected:
    const Texture*  m_texture;
    unsigned int    m_originX;
    unsigned int    m_originY;
    unsigned int    m_width;
    unsigned int    m_height;
};

#endif //__TB_IMAGE__
