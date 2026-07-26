#ifndef FIRMWARECORE_H
#define FIRMWARECORE_H

#include <RTC/RTCManager.h>
#include <Motor/MotorController.h>
#include <Scheduler/Scheduler.h>


class FirmwareCore
{
public:

    void initialize();

    void update();

private:

    RTCManager rtc;

    MotorController motors;

    Scheduler scheduler;
};

#endif