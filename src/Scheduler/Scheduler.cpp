#include <Scheduler/Scheduler.h>

bool Scheduler::initialize()
{
    totalEvents = 0;

    return true;
}

void Scheduler::update()
{
}

bool Scheduler::loadProgram(
    FeedEvent *events,
    uint16_t count)
{
    if (count > MAX_EVENTS)
    {
        return false;
    }

    for (uint16_t i = 0; i < count; i++)
    {
        program[i] = events[i];

        program[i].executed = false;
    }

    totalEvents = count;

    return true;
}

void Scheduler::resetDay()
{
     for (uint16_t i = 0; i < totalEvents; i++)
    {
        program[i].executed = false;
    }
}

FeedEvent* Scheduler::getPendingEvent(
    uint16_t currentMinute
)
{
    for (uint16_t i = 0; i < totalEvents; i++)
    {
        if (
            program[i].minuteOfDay == currentMinute &&
            !program[i].executed
        )
        {
            return &program[i];
        }
    }

    return nullptr;
}