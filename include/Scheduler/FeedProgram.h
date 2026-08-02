#ifndef FEEDPROGRAM_H
#define FEEDPROGRAM_H

#include <Arduino.h>

struct FeedProgram
{
    bool enabled;

    uint8_t hour;

    uint8_t minute;

    float durationSeconds;

    bool executedToday;
};

#endif