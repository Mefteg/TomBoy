#include "desktopdisplaydriver.h"

#include "../shared/lib/api/tomboydefines.h"

#include "../shared/lib/microprofile/microprofile.h"

DesktopDisplayDriver::DesktopDisplayDriver(sf::RenderWindow* window)
    : m_pixels(0)
{
    m_window = window;

    m_pixels = new sf::Uint8[SCREEN_WIDTH * SCREEN_HEIGHT * 4];
}

DesktopDisplayDriver::~DesktopDisplayDriver()
{
    delete[] m_pixels;
}

bool DesktopDisplayDriver::init()
{
    m_texture = sf::Texture();
    m_texture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

    m_sprite.setTexture(m_texture, true);
    m_sprite.setScale(sf::Vector2f(3, 3));

    return true;
}

void DesktopDisplayDriver::clearPixels()
{
    // WARNING
    // applyPixels must be called before calling this function again!
    m_window->clear();

    clearTexture();
}

void DesktopDisplayDriver::applyPixels()
{
    MICROPROFILE_SCOPEI("DesktopDisplayDriver", "applyPixels", MP_YELLOW);

    m_texture.update(m_pixels);
    m_window->draw(m_sprite);

    m_window->display();
    // WARNING
    // clearPixels must be called before calling this function again!
}

void DesktopDisplayDriver::setPixel(unsigned int x, unsigned int y, bool bw)
{
    unsigned int id = (y * SCREEN_WIDTH + x) * 4;
    if (id < SCREEN_WIDTH * SCREEN_HEIGHT * 4)
    {
        if (bw) // if black
        {
            m_pixels[id] = sf::Color::Black.r;
            m_pixels[id + 1] = sf::Color::Black.g;
            m_pixels[id + 2] = sf::Color::Black.b;
            m_pixels[id + 3] = sf::Color::Black.a;
        }
        else // else white
        {

            m_pixels[id] = sf::Color::White.r;
            m_pixels[id + 1] = sf::Color::White.g;
            m_pixels[id + 2] = sf::Color::White.b;
            m_pixels[id + 3] = sf::Color::White.a;
        }
    }
}

void DesktopDisplayDriver::clearTexture()
{
    for (unsigned int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 4; i += 4)
    {
        m_pixels[i] = sf::Color::White.r;
        m_pixels[i + 1] = sf::Color::White.g;
        m_pixels[i + 2] = sf::Color::White.b;
        m_pixels[i + 3] = sf::Color::White.a;
    }

    m_texture.update(m_pixels);
}
