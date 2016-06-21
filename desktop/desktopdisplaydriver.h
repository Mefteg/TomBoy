#ifndef __TB_DESKTOPDISPLAYDRIVER__
#define __TB_DESKTOPDISPLAYDRIVER__

#include "../arduino/TomBoy/src/shared/hardware/idisplaydriver.h"

#include <SFML/Graphics.hpp>

class DesktopDisplayDriver : public IDisplayDriver
{
public:
    DesktopDisplayDriver(sf::RenderWindow* window);
    virtual ~DesktopDisplayDriver() override;

    virtual bool    init() override;

    virtual void    clearPixels() override;
    virtual void    applyPixels() override;

    virtual void    setPixel(unsigned int x, unsigned int y, bool bw) override;

protected:
    void            clearTexture();

    sf::Uint8*      m_pixels;

    sf::RenderWindow* m_window;
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
};

#endif //__TB_DESKTOPDISPLAYDRIVER__