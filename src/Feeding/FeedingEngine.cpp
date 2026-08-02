#include <Arduino.h>
#include <Feeding/FeedingEngine.h>

bool FeedingEngine::initialize(MotorController* motors)
{
    motorController = motors;

    state = FeedingState::IDLE;

    busy = false;

    feedTime = 0;

    stateStartTime = 0;

    return true;
}

bool FeedingEngine::startFeed(float seconds)
{
    if (busy)
        return false;

    feedTime = seconds;

    busy = true;

    state = FeedingState::START_SPRAYER;

    Serial.println("--------------------------------");
    Serial.println("NEW FEED STARTED");
    Serial.print("Feed Time: ");
    Serial.print(feedTime);
    Serial.println(" seconds");

    return true;
}

bool FeedingEngine::isBusy() const
{
    return busy;
}

void FeedingEngine::update()
{
    switch (state)
    {
        //-------------------------------------------------
        // ESPERANDO
        //-------------------------------------------------
        case FeedingState::IDLE:
        {
            break;
        }

        //-------------------------------------------------
        // ENCENDER ASPERSOR
        //-------------------------------------------------
        case FeedingState::START_SPRAYER:
        {
            Serial.println("ASPERSOR ON");

            motorController->startAspersor();

            stateStartTime = millis();

            state = FeedingState::WAIT_SPRAYER;

            break;
        }

        //-------------------------------------------------
        // ESPERAR 2 SEGUNDOS
        //-------------------------------------------------
        case FeedingState::WAIT_SPRAYER:
        {
            if (millis() - stateStartTime >= 2000)
            {
                state = FeedingState::START_DOSIFIER;
            }

            break;
        }

        //-------------------------------------------------
        // ENCENDER DOSIFICADOR
        //-------------------------------------------------
        case FeedingState::START_DOSIFIER:
        {
            Serial.println("DOSIFICADOR ON");

            motorController->startDosificador();

            stateStartTime = millis();

            state = FeedingState::RUNNING_DOSIFIER;

            break;
        }

        //-------------------------------------------------
        // DOSIFICANDO
        //-------------------------------------------------
        case FeedingState::RUNNING_DOSIFIER:
        {
            if (millis() - stateStartTime >= (uint32_t)(feedTime * 1000))
            {
                state = FeedingState::STOP_DOSIFIER;
            }

            break;
        }

        //-------------------------------------------------
        // APAGAR DOSIFICADOR
        //-------------------------------------------------
        case FeedingState::STOP_DOSIFIER:
        {
            Serial.println("DOSIFICADOR OFF");

            motorController->stopDosificador();

            stateStartTime = millis();

            state = FeedingState::WAIT_STOP_SPRAYER;

            break;
        }

        //-------------------------------------------------
        // ESPERAR 2 SEGUNDOS
        //-------------------------------------------------
        case FeedingState::WAIT_STOP_SPRAYER:
        {
            if (millis() - stateStartTime >= 2000)
            {
                state = FeedingState::STOP_SPRAYER;
            }

            break;
        }

        //-------------------------------------------------
        // APAGAR ASPERSOR
        //-------------------------------------------------
        case FeedingState::STOP_SPRAYER:
        {
            Serial.println("ASPERSOR OFF");

            motorController->stopAspersor();

            Serial.println("FEED FINISHED");
            Serial.println("--------------------------------");

            busy = false;

            state = FeedingState::IDLE;

            break;
        }

        default:
        {
            state = FeedingState::IDLE;
            break;
        }
    }
}