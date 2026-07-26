#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>
#include <Scheduler/FeedEvent.h>

class Scheduler
{
public:

    bool initialize();

    void update();

    bool loadProgram(
        FeedEvent* events,
        uint16_t count
    );

    void resetDay();

    FeedEvent* getPendingEvent(
        uint16_t currentMinute
    );

private:

    static const uint16_t MAX_EVENTS = 300;

    FeedEvent program[MAX_EVENTS];

    uint16_t totalEvents = 0;
};

#endif