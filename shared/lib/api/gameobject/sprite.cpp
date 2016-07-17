#include "sprite.h"

Sprite::Sprite()
    : m_scene(nullptr)
    , m_width(0)
    , m_height(0)
    , m_image(0)
{

}

Sprite::Sprite(IScene* scene)
    : m_scene(scene)
    , m_width(0)
    , m_height(0)
    , m_image(0)
{

}

Sprite::Sprite(IScene* scene, const Image* image)
    : m_scene(scene)
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
        m_image->draw(renderer, (unsigned int) m_position.getX(), (unsigned int) m_position.getY());
    }
}

void Sprite::reset()
{
}

AABB Sprite::getAABB() const
{
    Vector2 max(m_position);
    max.add((float) m_width, (float) m_height);
    return AABB(m_position, max);
}

void Sprite::setPosition(float x, float y)
{
    m_position.setX(x);
    m_position.setY(y);
}

void Sprite::setSize(unsigned int w, unsigned int h)
{
    m_width = w;
    m_height = h;
}
