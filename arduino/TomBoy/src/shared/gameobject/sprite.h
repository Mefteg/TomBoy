#ifndef __TB_SPRITE__
#define __TB_SPRITE__

#include "igameobject.h"

class Sprite : public IGameObject
{
public:
    Sprite();
    Sprite(const bool* pixels);
    virtual ~Sprite();

    virtual bool    update(float dt) override;
    virtual void    draw(IRenderer* renderer) const override;

    float           getX() const { return m_x; }
    float           getY() const { return m_y; }

    void            setPosition(float x, float y);

protected:
    float           m_x;
    float           m_y;
    unsigned int    m_width;
    unsigned int    m_height;

    const bool*     m_pixels;
};

#endif //__TB_SPRITE__
