#include "vector2.h"

#include <math.h>

Vector2::Vector2()
    : m_x(0)
    , m_y(0)
{

}

Vector2::Vector2(float x, float y)
    : m_x(x)
    , m_y(y)
{

}

Vector2::~Vector2()
{
}

void Vector2::add(float x, float y)
{
    m_x += x;
    m_y += y;
}

void Vector2::add(const Vector2& v)
{
    add(v.getX(), v.getY());
}

void Vector2::normalize()
{
    float length = (float) getLength();
    m_x /= length;
    m_y /= length;
}

double Vector2::getLength()
{
    return sqrt(m_x * m_x + m_y * m_y);
}
