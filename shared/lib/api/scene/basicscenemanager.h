#ifndef __TB_BASICSCENEMANAGER__
#define __TB_BASICSCENEMANAGER__

#include "iscenemanager.h"

#include "../hardware/hardwaregateway.h"

class BasicSceneManager : public ISceneManager
{
public:
    BasicSceneManager(HardwareGateway* hardwareGateway);
    virtual ~BasicSceneManager();

    virtual bool    updateCurrentScene(float dt);
    virtual bool    renderCurrentScene();

    virtual IScene* getCurrentScene() const;
    virtual void    setCurrentScene(IScene* scene);

protected:
    HardwareGateway*    m_hardwareGateway;
    IScene*             m_currentScene;
    IScene*             m_nextScene;
};

#endif //__TB_BASICSCENEMANAGER__
