#ifndef __TB_DESKTOPRENDERER__
#define __TB_DESKTOPRENDERER__

#include "../arduino/TomBoy/src/shared/irenderer.h"

#include <SFML/Graphics.hpp>

class DesktopRenderer : public IRenderer
{
public:
    DesktopRenderer();
    DesktopRenderer(sf::RenderWindow* window);
    virtual ~DesktopRenderer() override;

    virtual bool    render(IScene* scene) override;

    virtual void    setPixel(int x, int y, Color color) override;

protected:
    void clearTexture();

    sf::Uint8*      m_pixels;

    sf::RenderWindow* m_window;
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
};

#endif //__TB_DESKTOPRENDERER__