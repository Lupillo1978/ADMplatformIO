#include <Arduino.h>

#include <Config/PinConfig.h>

#include <Motor/MotorController.h>

bool MotorController::initialize()
{
    pinMode(
        PinConfig::MOTOR_DOSIFICADOR,
        OUTPUT
    );

    pinMode(
        PinConfig::MOTOR_ASPERSOR,
        OUTPUT
    );

    stopAll();

    return true;
}

void MotorController::update()
{

}

void MotorController::startDosificador()
{
    if (dosificadorRunning)
        return;

    digitalWrite(
        PinConfig::MOTOR_DOSIFICADOR,
        HIGH
    );

    dosificadorRunning = true;
}

void MotorController::stopDosificador()
{
    if (!dosificadorRunning)
        return;

    digitalWrite(
        PinConfig::MOTOR_DOSIFICADOR,
        LOW
    );

    dosificadorRunning = false;
}

void MotorController::startAspersor()
{
    if (aspersorRunning)
        return;

    digitalWrite(
        PinConfig::MOTOR_ASPERSOR,
        HIGH
    );

    aspersorRunning = true;
}

void MotorController::stopAspersor()
{
    if (!aspersorRunning)
        return;

    digitalWrite(
        PinConfig::MOTOR_ASPERSOR,
        LOW
    );

    aspersorRunning = false;
}

void MotorController::stopAll()
{
    stopDosificador();

    stopAspersor();
}

bool MotorController::isDosificadorRunning() const
{
    return dosificadorRunning;
}

bool MotorController::isAspersorRunning() const
{
    return aspersorRunning;
}

bool MotorController::isBusy() const
{
    return dosificadorRunning || aspersorRunning;
}