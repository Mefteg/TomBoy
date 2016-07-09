#include "sprite.h"

Sprite::Sprite()
    : m_scene(nullptr)
    , m_x(0)
    , m_y(0)
    , m_width(4)
    , m_height(4)
    , m_image(0)
{

}

Sprite::Sprite(IScene* scene)
    : m_scene(scene)
    , m_x(0)
    , m_y(0)
    , m_width(4)
    , m_height(4)
    , m_image(0)
{

}

Sprite::Sprite(IScene* scene, const Image* image)
    : m_scene(scene)
    , m_x(0)
    , m_y(0)
    , m_width(4)
    , m_height(4)
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
        m_image->draw(renderer, m_x, m_y);
    }
}

void Sprite::setPosition(float x, float y)
{
    m_x = x;
    m_y = y;
}
