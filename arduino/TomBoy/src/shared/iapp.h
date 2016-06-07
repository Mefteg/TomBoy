#ifndef __TB_IAPP__
#define __TB_IAPP__

class IScene;
class IRenderer;

class IApp
{
public:
    virtual ~IApp() {}

    virtual bool setup() = 0;
    virtual bool loop() = 0;

protected:
    IScene* m_scene;
    IRenderer* m_renderer;
};

#endif //__TB_IAPP__