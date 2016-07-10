#include "coin.h"

const float Coin::COIN_SPEED_MAX = 10.0f;

Coin::Coin()
    : Sprite()
    , m_active(false)
{
    reset();
}

Coin::Coin(IScene * scene)
    : Sprite(scene)
    , m_active(false)
{
    reset();
}

Coin::Coin(IScene * scene, const Image * pixels)
    : Sprite(scene, pixels)
    , m_active(false)
{
    reset();
}

bool Coin::update(float dt)
{
    if (m_active)
    {
        m_y += COIN_SPEED_MAX * dt;

        // collision with player
        if (false)
        {

        }
        // too low
        else if ((m_y + m_height) > SCREEN_HEIGHT)
        {
            m_active = false;
        }
    }

    return true;
}

void Coin::draw(IRenderer * renderer) const
{
    if (m_active)
    {
        Sprite::draw(renderer);
    }
}

void Coin::reset()
{
    m_x = 0;
    m_y = 0;

    m_active = false;
}
