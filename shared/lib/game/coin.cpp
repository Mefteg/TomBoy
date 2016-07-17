#include "coin.h"

#include "levelscene.h"
#include "player.h"

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

Coin::Coin(IScene * scene, const Image * pixels, Player * player)
    : Sprite(scene, pixels)
    , m_active(false)
    , m_player(player)
{
}

bool Coin::update(float dt)
{
    if (m_active)
    {
        float posY = m_position.getY();
        posY += COIN_SPEED_MAX * dt;
        m_position.setY(posY);

        // collision with player
        if (m_player && getAABB().isColliding(m_player->getAABB()))
        {
            LevelScene* scene = (LevelScene*) m_scene;
            scene->updatePoints(1);

            m_active = false;
        }
        // too low
        else if ((posY + m_height) > SCREEN_HEIGHT)
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
    m_position.setX(0);
    m_position.setY(0);

    m_active = false;
}
