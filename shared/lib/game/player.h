#ifndef __TB_PLAYER__
#define __TB_PLAYER__

#include "../api/gameobject/sprite.h"

class Player : public Sprite
{
public:
    Player();
    Player(IScene* scene);
    Player(IScene* scene, const Image* pixels);

    virtual bool    update(float dt) override;

    virtual void    reset() override;

protected:

    static const float PLAYER_SPEED_MAX;

    float   m_speedX;
};

#endif //__TB_PLAYER__
