#ifndef __TB_SPRITE__
#define __TB_SPRITE__

#include "igameobject.h"

#include "../graphics/image.h"

class Sprite : public IGameObject
{
public:
    Sprite();
    Sprite(IScene* scene);
    Sprite(IScene* scene, const Image* image);
    virtual ~Sprite();

    virtual bool    update(float dt) override;
    virtual void    draw(IRenderer* renderer) const override;

    virtual void    reset() override;

    float           getX() const { return m_x; }
    float           getY() const { return m_y; }
    unsigned int    getWidth() const { return m_width; }
    unsigned int    getHeight() const { return m_height; }

    void            setPosition(float x, float y);
    void            setSize(unsigned int w, unsigned int h);

protected:
    IScene*         m_scene;

    float           m_x;
    float           m_y;
    unsigned int    m_width;
    unsigned int    m_height;

    const Image*    m_image;
};

#endif //__TB_SPRITE__
