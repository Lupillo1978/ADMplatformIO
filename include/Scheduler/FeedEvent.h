#ifndef FEED_EVENT_H
#define FEED_EVENT_H

#include <Arduino.h>

struct FeedEvent
{

    uint16_t eventId;

    uint16_t minuteOfDay;

    uint16_t durationSeconds;

    bool executed;
};

#endif