#ifndef __TB_BASICSCENE__
#define __TB_BASICSCENE__

#include "iscene.h"

#include "../hardware/hardwaregateway.h"

#include "../renderer/irenderer.h"

class BasicScene : public IScene
{
public:
    BasicScene(HardwareGateway* hardwareGateway);
    virtual ~BasicScene();

    virtual bool            setup() override;
    virtual bool            update(float dt) override;
    virtual bool            render() override;

    virtual IGameObject**   getGameObjects() const override;
    virtual unsigned int    getNbGameObjects() const override;

protected:
    HardwareGateway*        m_hardwareGateway;
    IRenderer*              m_renderer;
};

#endif //__TB_BASICSCENE__
