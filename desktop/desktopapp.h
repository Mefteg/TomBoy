#ifndef __TB_DESKTOPAPP__
#define __TB_DESKTOPAPP__

#include "../arduino/TomBoy/src/shared/app/basicapp.h"

#include <SFML/Graphics.hpp>

class DesktopApp : public BasicApp
{
public:
    DesktopApp();
    virtual ~DesktopApp();

    virtual bool setup() override;
    virtual bool loop() override;

protected:
    sf::RenderWindow        m_window;
    sf::Clock               m_clock;
};

#endif //__TB_DESKTOPAPP__