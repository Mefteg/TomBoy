#include "player.h"

const float Player::PLAYER_SPEED_MAX = 20.0f;

Player::Player()
    : Sprite()
    , m_speedX(0.0f)
{
    reset();
}

Player::Player(IScene* scene)
    : Sprite(scene)
    , m_speedX(0.0f)
{
    reset();
}

Player::Player(IScene* scene, const Image* image)
    : Sprite(scene, image)
    , m_speedX(0.0f)
{
    reset();
}

bool Player::update(float dt)
{
    if (m_scene->getControlsManager().isButtonPressed(IControlsDriver::BUTTON_A))
    {
        reset();
    }

    m_speedX = m_scene->getControlsManager().getAxis(IControlsDriver::AXIS_X) * PLAYER_SPEED_MAX;

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

    return true;
}

void Player::reset()
{
    m_x = (SCREEN_WIDTH - m_width) / 2;
    m_y = SCREEN_HEIGHT - (m_height + 2);

    m_speedX = 0.0f;
}
