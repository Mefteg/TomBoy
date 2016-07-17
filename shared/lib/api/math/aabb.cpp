#include "aabb.h"

AABB::AABB()
{
}

AABB::AABB(const Vector2 & min, const Vector2 & max)
    : m_min(min)
    , m_max(max)
{
}

AABB::~AABB()
{
}

bool AABB::isPointInside(const Vector2 & point) const
{
    float pX = point.getX();
    float pY = point.getY();
    return m_min.getX() <= pX && pX <= m_max.getX()
        && m_min.getY() <= pY && pY <= m_max.getY();
}

bool AABB::isColliding(const AABB & box) const
{
    const Vector2 bMin = box.getMin();
    const Vector2 bMax = box.getMax();
    return bMin.getX() < m_max.getX() && bMax.getX() > m_min.getX()
        && bMin.getY() < m_max.getY() && bMax.getY() > m_min.getY();
}
