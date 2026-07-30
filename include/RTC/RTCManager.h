#ifndef RTC_MANAGER_H
#define RTC_MANAGER_H

#include <Arduino.h>
#include <RTClib.h>

struct TimeInfo
{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;

    uint16_t minuteOfDay;

    uint32_t unixTime;
};

class RTCManager
{
public:

    bool begin();

    void update();

    bool isValid() const;

    TimeInfo getTime() const;

private:

    RTC_DS3231 rtc;

    DateTime now;

    TimeInfo currentTime;

    bool valid = false;
};

#endif