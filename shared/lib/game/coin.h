#ifndef __TB_COIN__
#define __TB_COIN__

#include "../api/gameobject/sprite.h"

class Player;

class Coin : public Sprite
{
public:
    Coin();
    Coin(IScene* scene);
    Coin(IScene* scene, const Image* pixels);
    Coin(IScene* scene, const Image* pixels, Player* player);

    virtual bool    update(float dt) override;
    virtual void    draw(IRenderer* renderer) const override;

    virtual void    reset() override;

    virtual bool    isActive(bool active) const { return m_active; }
    virtual void    setActive(bool active) { m_active = active; }

protected:

    static const float COIN_SPEED_MAX;

    bool    m_active;

    Player* m_player;
};

#endif //__TB_COIN__
