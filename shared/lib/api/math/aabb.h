#ifndef __TB_AABB__
#define __TB_AABB__

#include "vector2.h"

class AABB
{
public:
    AABB();
    AABB(const Vector2& min, const Vector2& max);
    virtual ~AABB();

    bool    isPointInside(const Vector2& point) const;
    bool    isColliding(const AABB& box) const;

    Vector2 getMin() const { return m_min; }
    Vector2 getMax() const { return m_max; }

    void    setMin(const Vector2& min) { m_min = min; }
    void    setMax(const Vector2& max) { m_max = max; }

protected:
    Vector2 m_min;
    Vector2 m_max;
};

#endif //__TB_AABB__
