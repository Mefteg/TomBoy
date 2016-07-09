#ifndef __TB_GAMESCENEMANAGER__
#define __TB_GAMESCENEMANAGER__

#include "../api/scene/basicscenemanager.h"

#include "levelscene.h"

class GameSceneManager : public BasicSceneManager
{
public:
    GameSceneManager(HardwareGateway* hardwareGateway);
    virtual ~GameSceneManager();
};

#endif //__TB_GAMESCENEMANAGER__
