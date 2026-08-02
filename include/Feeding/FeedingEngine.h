#ifndef FEEDING_ENGINE_H
#define FEEDING_ENGINE_H

#include <Arduino.h>

#include <Motor/MotorController.h>
#include <Feeding/FeedingState.h>

class FeedingEngine
{
public:

    bool initialize(MotorController* motors);

    void update();

    bool startFeed(float seconds);

    bool isBusy() const;

private:

    MotorController* motorController = nullptr;

    FeedingState state = FeedingState::IDLE;

    bool busy = false;

    float feedTime = 0;

    uint32_t stateStartTime = 0;
};

#endif