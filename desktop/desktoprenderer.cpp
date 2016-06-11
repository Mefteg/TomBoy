#include "desktoprenderer.h"

#include "../../../../arduino/TomBoy/src/shared/iscene.h"

DesktopRenderer::DesktopRenderer()
    : m_window(nullptr)
{

}

DesktopRenderer::DesktopRenderer(sf::RenderWindow* window)
    : m_pixels(0)
{
    m_window = window;

    m_pixels = new sf::Uint8[SCREEN_WIDTH * SCREEN_HEIGHT * 4];

    m_texture = sf::Texture();
    m_texture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

    m_sprite.setTexture(m_texture, true);
    m_sprite.setScale(sf::Vector2f(3, 3));
}

DesktopRenderer::~DesktopRenderer()
{
    IRenderer::~IRenderer();

    delete[] m_pixels;
}

bool DesktopRenderer::render(IScene* scene)
{
    if (m_window)
    {
        // draw the sprite
        m_window->clear();
        {
            clearTexture();

            IGameObject* object = scene->getGameObjects();
            object->draw(this);

            m_texture.update(m_pixels);
            m_window->draw(m_sprite);
        }
        
        m_window->display();
    }
    return true;
}

void DesktopRenderer::setPixel(unsigned int x, unsigned int y, Color color)
{
    unsigned int id = (y * SCREEN_WIDTH + x) * 4;
    if (id < SCREEN_WIDTH * SCREEN_HEIGHT * 4)
    {
        if (color == Color::WHITE)
        {
            m_pixels[id]        = sf::Color::White.r;
            m_pixels[id + 1]    = sf::Color::White.g;
            m_pixels[id + 2]    = sf::Color::White.b;
            m_pixels[id + 3]    = sf::Color::White.a;
        }
        else
        {
            m_pixels[id]        = sf::Color::Black.r;
            m_pixels[id + 1]    = sf::Color::Black.g;
            m_pixels[id + 2]    = sf::Color::Black.b;
            m_pixels[id + 3]    = sf::Color::Black.a;
        }
    }
}

void DesktopRenderer::clearTexture()
{
    for (unsigned int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 4; i += 4)
    {
        m_pixels[i]     = sf::Color::White.r;
        m_pixels[i + 1] = sf::Color::White.g;
        m_pixels[i + 2] = sf::Color::White.b;
        m_pixels[i + 3] = sf::Color::White.a;
    }

    m_texture.update(m_pixels);
}