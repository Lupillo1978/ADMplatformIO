#include <Arduino.h>
#include <Core/FirmwareCore.h>

static bool firstFeedExecuted = false;

static uint32_t startupTime = 0;

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

    if (!feedingEngine.initialize(&motors))
    {
        Serial.println("ERROR: FeedingEngine initialization failed");
    }
    else
    {
        Serial.println("FeedingEngine initialized successfully");
    }

    if (!scheduler.initialize())
    {
        Serial.println("ERROR: Scheduler initialization failed");
    }
    else
    {
        Serial.println("Scheduler initialized successfully");
    }

    startupTime = millis();
}

void FirmwareCore::update()
{
    rtc.update();

    scheduler.update();

    feedingEngine.update();

    motors.update();

    if (!firstFeedExecuted)
    {
        if (millis() - startupTime >= 5000)
        {
            Serial.println();
            Serial.println("================================");
            Serial.println("STARTING TEST FEED");
            Serial.println("================================");

            feedingEngine.startFeed(8.0f);

            firstFeedExecuted = true;
        }
    }
}