#include "player.h"

Player::Player()
    : Sprite()
    , m_speedX(5.0f)
    , m_speedY(5.0f)
{

}

Player::Player(const bool* pixels)
    : Sprite(pixels)
    , m_speedX(5.0f)
    , m_speedY(5.0f)
{

}

bool Player::update(float dt)
{
    m_x += m_speedX * dt;
    if (m_x < 0)
    {
        m_x = 0;
        m_speedX *= -1;
    }
    else if (m_x + m_width > SCREEN_WIDTH + 1)
    {
        m_x = SCREEN_WIDTH - m_width;
        m_speedX *= -1;
    }

    m_y += m_speedY * dt;
    if (m_y < 0)
    {
        m_y = 0;
        m_speedY *= -1;
    }
    else if (m_y + m_height > SCREEN_HEIGHT + 1)
    {
        m_y = SCREEN_HEIGHT - m_height;
        m_speedY *= -1;
    }

    return true;
}
