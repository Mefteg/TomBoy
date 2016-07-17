#ifndef __TB_VECTOR2__
#define __TB_VECTOR2__

class Vector2
{
public:
    Vector2();
    Vector2(float x, float y);
    virtual ~Vector2();

    void    add(float x, float y);
    void    add(const Vector2& v);

    void    normalize();

    double  getLength();

    float   getX() const { return m_x; }
    float   getY() const { return m_y; }

    void    setX(float x) { m_x = x; }
    void    setY(float y) { m_y = y; }

protected:
    float m_x;
    float m_y;
};

#endif //__TB_VECTOR2__
