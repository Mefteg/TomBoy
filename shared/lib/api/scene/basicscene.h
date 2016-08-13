#ifndef __TB_BASICSCENE__
#define __TB_BASICSCENE__

#include "iscene.h"

#include "iscenemanager.h"
#include "../hardware/hardwaregateway.h"

class BasicScene : public IScene
{
public:
    BasicScene(ISceneManager* sceneManager, HardwareGateway* hardwareGateway);
    virtual ~BasicScene();

    virtual bool            setup() override;
    virtual bool            update(float dt) override;
    virtual bool            render() override;

    virtual IRenderer&          getRenderer() const override;
    virtual IControlsManager&   getControlsManager() const override;
    virtual IRandomizer&        getRandomizer() const override;

    virtual ArrayList<IGameObject*>&    getGameObjects() override;
    virtual unsigned int                getNbGameObjects() const override;

protected:
    ISceneManager*          m_sceneManager;
    HardwareGateway*        m_hardwareGateway;

    IRenderer*              m_renderer;
    IControlsManager*       m_controlsmanager;
    IRandomizer*            m_randomizer;

    ArrayList<IGameObject*> m_objects;
};

#endif //__TB_BASICSCENE__
