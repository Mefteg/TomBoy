#ifndef __TB_ARDUINORENDERER__
#define __TB_ARDUINORENDERER__

#include "shared/irenderer.h"

class ArduinoRenderer : public IRenderer
{
public:
    ArduinoRenderer();
    virtual ~ArduinoRenderer() override;

    virtual bool    render(IScene* scene) override;

    virtual void    setPixel(unsigned int x, unsigned int y, Color color) override;
};

#endif //__TB_ARDUINORENDERER__
