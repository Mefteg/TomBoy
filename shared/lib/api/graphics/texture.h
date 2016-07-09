#ifndef __TB_TEXTURE__
#define __TB_TEXTURE__

class Texture
{
public:
    Texture(const bool* pixels, unsigned int width, unsigned int height);
    virtual ~Texture() {}

    virtual bool    getPixel(unsigned int x, unsigned int y) const;

protected:
    const bool*     m_pixels;
    unsigned int    m_width;
    unsigned int    m_height;
};

#endif //__TB_TEXTURE__
