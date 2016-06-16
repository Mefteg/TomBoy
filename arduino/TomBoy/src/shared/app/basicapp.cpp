#include "basicapp.h"

BasicApp::BasicApp()
{
    // create drivers
}

BasicApp::~BasicApp()
{
    delete m_scene;
}

bool BasicApp::setup()
{
    // give drivers to m_hardwareGateway
    return true;
}

bool BasicApp::loop()
{
    // update the scene
    // render the scene
    return true;
}
