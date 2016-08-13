#include "coin.h"

#include "levelscene.h"
#include "player.h"

const float Coin::COIN_SPEED_MAX = 10.0f;

Coin::Coin()
    : Sprite()
    , m_id(-1)
    , m_active(false)
{
    reset();
}

Coin::Coin(IScene * scene)
    : Sprite(scene)
    , m_id(-1)
    , m_active(false)
{
    reset();
}

Coin::Coin(IScene * scene, const Image * pixels)
    : Sprite(scene, pixels)
    , m_id(-1)
    , m_active(false)
{
    reset();
}

Coin::Coin(IScene * scene, const Image * pixels, Player * player)
    : Sprite(scene, pixels)
    , m_id(-1)
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
            // add point
            LevelScene* scene = (LevelScene*)m_scene;
            scene->updatePoints(1);

            // replace
            reset();
        }
        // too low
        else if ((posY + m_height) > SCREEN_HEIGHT)
        {
            LevelScene* scene = (LevelScene*)m_scene;
            scene->gameOver();
        }
    }

    return true;
}

void Coin::draw(IRenderer * renderer) const
{
    if (m_active && m_position.getY() >= 0)
    {
        Sprite::draw(renderer);
    }
}

void Coin::reset()
{
    bool replace = true;
    while (replace)
    {
        const IRandomizer& randomizer = m_scene->getRandomizer();
        int posX = randomizer.getBetween(0, SCREEN_WIDTH - m_width);
        int posY = -((int)m_height + randomizer.getBetween(0, 50));

        m_position.setX((float) posX);
        m_position.setY((float) posY);

        replace = checkPosAndReplaceIfNecessary();
    }
}

bool Coin::checkPosAndReplaceIfNecessary()
{
    bool replace = false;

    float stepMin = 10;

    LevelScene* scene = (LevelScene*)m_scene;

    unsigned short nbActiveCoins = scene->getNbActiveCoins();
    ArrayList<Coin*>& coins = scene->getCoins();

    float posY = getY();

    for (short i = 0; i < nbActiveCoins; ++i)
    {
        const Coin* coin = coins.at(i);
        if (coin->getId() != m_id)
        {
            float currentCoinY = coin->getY();
            if (currentCoinY - stepMin - m_height < posY)
            {
                posY = currentCoinY - stepMin - m_height;
            }
        }
    }

    m_position.setY(posY);

    return replace;
}
