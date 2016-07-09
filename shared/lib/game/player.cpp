#include "player.h"

Player::Player()
    : Sprite()
    , m_speedX(5.0f)
    , m_speedY(5.0f)
{

}

Player::Player(IScene* scene)
    : Sprite(scene)
    , m_speedX(5.0f)
    , m_speedY(5.0f)
{

}

Player::Player(IScene* scene, const bool* pixels)
    : Sprite(scene, pixels)
    , m_speedX(5.0f)
    , m_speedY(5.0f)
{

}

bool Player::update(float dt)
{
    if (m_scene->getControlsManager().isButtonPressed(IControlsDriver::BUTTON_A))
    {
        reset();
    }

    if (m_scene->getControlsManager().isButtonPressed(IControlsDriver::BUTTON_B))
    {
        reset();
    }

    m_speedX = m_scene->getControlsManager().getAxis(IControlsDriver::AXIS_X) * 5.0f;
    m_speedY = m_scene->getControlsManager().getAxis(IControlsDriver::AXIS_Y) * 5.0f;

    m_x += m_speedX * dt;
    if (m_x < 0)
    {
        m_x = 0;
        m_speedX *= -1;
    }
    else if (m_x + m_width > SCREEN_WIDTH + 1)
    {
        m_x = (float) (SCREEN_WIDTH - m_width);
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
        m_y = (float)(SCREEN_HEIGHT - m_height);
        m_speedY *= -1;
    }

    return true;
}

void Player::reset()
{
    m_x = 0;
    m_y = 0;

    m_speedX = 5.0f;
    m_speedY = 5.0f;
}
