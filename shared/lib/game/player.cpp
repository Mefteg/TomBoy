#include "player.h"

const float Player::PLAYER_SPEED_MAX = 25.0f;

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

    float posX = m_position.getX() + (m_speedX * dt);
    if (posX < 0)
    {
        posX = 0;
        m_speedX *= -1;
    }
    else if (posX + m_width > SCREEN_WIDTH + 1)
    {
        posX = (float) (SCREEN_WIDTH - m_width);
        m_speedX *= -1;
    }
    m_position.setX(posX);

    return true;
}

void Player::reset()
{
    m_position.setX((float) (SCREEN_WIDTH - m_width) / 2);
    m_position.setY((float) SCREEN_HEIGHT - (m_height + 2));

    m_speedX = 0.0f;
}
