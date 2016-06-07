#ifndef __TB_PLAYER__
#define __TB_PLAYER__

#include "../gameobject/sprite.h"

class Player : public Sprite
{
public:
    Player();
    Player(const bool* pixels);

    virtual bool    update(float dt) override;

protected:
    float   m_speedX;
    float   m_speedY;
};

#endif //__TB_PLAYER__
