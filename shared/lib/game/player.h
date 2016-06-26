#ifndef __TB_PLAYER__
#define __TB_PLAYER__

#include "../api/gameobject/sprite.h"

class Player : public Sprite
{
public:
    Player();
    Player(IScene* scene);
    Player(IScene* scene, const bool* pixels);

    virtual bool    update(float dt) override;

protected:
    void    reset();

    float   m_speedX;
    float   m_speedY;
};

#endif //__TB_PLAYER__
