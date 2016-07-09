#include "basicapp.h"

BasicApp::BasicApp()
{
    // create drivers
    // create scene manager
}

BasicApp::~BasicApp()
{
    // delete scene manager
    // delete drivers
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
