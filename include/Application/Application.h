#ifndef APPLICATION_H
#define APPLICATION_H

#include <Core/FirmwareCore.h>

class Application
{
public:

    void initialize();

    void update();

private:

    FirmwareCore core;


};

#endif