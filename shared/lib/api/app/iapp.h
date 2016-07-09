#ifndef __TB_IAPP__
#define __TB_IAPP__

class ISceneManager;
class IRenderer;

class IApp
{
public:
    virtual ~IApp() {}

    virtual bool    setup() = 0;
    virtual bool    loop() = 0;
};

#endif //__TB_IAPP__