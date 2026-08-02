#include "RTC/RTCManager.h"

bool RTCManager::begin()
{
    valid = rtc.begin();

    if(valid)
    {
        update();
    }

    return valid;
}

void RTCManager::update()
{
    if(!valid)
        return;

    now = rtc.now();

    currentTime.hour = now.hour();

    currentTime.minute = now.minute();

    currentTime.second = now.second();

    currentTime.minuteOfDay =
        currentTime.hour * 60 +
        currentTime.minute;

    currentTime.unixTime =
        now.unixtime();
}

bool RTCManager::isValid() const
{
    return valid;
}

TimeInfo RTCManager::getTime() const
{
    return currentTime;
}