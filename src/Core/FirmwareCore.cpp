#include <Arduino.h>
#include <Core/FirmwareCore.h>

void FirmwareCore::initialize()
{
    if (!rtc.begin())
    {
        Serial.println("ERROR: RTC initialization failed");
    }
    else
    {
        Serial.println("RTC initialized successfully");
    }

    if (!motors.initialize())
    {
        Serial.println("ERROR: MotorController initialization failed");
    }
    else
    {
        Serial.println("MotorController initialized successfully");
    }

    if (!scheduler.initialize())
    {
        Serial.println("ERROR: Scheduler initialization failed");
    }
    else
    {
        Serial.println("Scheduler initialized successfully");
    }
}

void FirmwareCore::update()
{
    rtc.update();

    scheduler.update();

    motors.update();

    switch (feederState)
    {
    case FeederState::IDLE:
        break;

    case FeederState::START_SPRAYER:
        break;

    case FeederState::START_DOSIFIER:
        break;

    case FeederState::STOP_DOSIFIER:
        break;

    case FeederState::STOP_SPRAYER:
        break;
    }
}