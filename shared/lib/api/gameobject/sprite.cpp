#include "sprite.h"

Sprite::Sprite()
    : m_scene(nullptr)
    , m_x(0)
    , m_y(0)
    , m_width(0)
    , m_height(0)
    , m_image(0)
{

}

Sprite::Sprite(IScene* scene)
    : m_scene(scene)
    , m_x(0)
    , m_y(0)
    , m_width(0)
    , m_height(0)
    , m_image(0)
{

}

Sprite::Sprite(IScene* scene, const Image* image)
    : m_scene(scene)
    , m_x(0)
    , m_y(0)
    , m_width(0)
    , m_height(0)
    , m_image(image)
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
    if (m_image)
    {
        m_image->draw(renderer, (unsigned int) m_x, (unsigned int) m_y);
    }
}

void Sprite::reset()
{
}

void Sprite::setPosition(float x, float y)
{
    m_x = x;
    m_y = y;
}

void Sprite::setSize(unsigned int w, unsigned int h)
{
    m_width = w;
    m_height = h;
}
