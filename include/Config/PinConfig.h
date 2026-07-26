#ifndef PINCONFIG_H
#define PINCONFIG_H

#include <Arduino.h>

/*
=========================================================
AD&M AquaControl
Asignación oficial de pines del hardware
=========================================================
*/

namespace PinConfig
{

    //--------------------------------------------------
    // LoRa SX1276
    //--------------------------------------------------

    constexpr uint8_t LORA_MOSI   = 23;
    constexpr uint8_t LORA_MISO   = 19;
    constexpr uint8_t LORA_SCK    = 18;

    constexpr uint8_t LORA_SS     = 5;
    constexpr uint8_t LORA_RESET  = 14;
    constexpr uint8_t LORA_DIO0   = 26;

    //--------------------------------------------------
    // RTC DS3231
    //--------------------------------------------------

    constexpr uint8_t RTC_SDA     = 21;
    constexpr uint8_t RTC_SCL     = 22;

    //--------------------------------------------------
    // Motores
    //--------------------------------------------------

    constexpr uint8_t MOTOR_DOSIFICADOR = 27;
    constexpr uint8_t MOTOR_ASPERSOR    = 25;

    //--------------------------------------------------
    // Indicadores
    //--------------------------------------------------

    constexpr uint8_t STATUS_LED = 2;

    //--------------------------------------------------
    // Botón de servicio
    //--------------------------------------------------

    constexpr uint8_t SERVICE_BUTTON = 0;

    //--------------------------------------------------
    // Entradas analógicas
    //--------------------------------------------------

    constexpr uint8_t BATTERY_ADC = 34;

    constexpr uint8_t CURRENT_ADC = 35;

    //--------------------------------------------------
    // Expansión futura
    //--------------------------------------------------

    constexpr uint8_t EXPANSION1 = 32;

    constexpr uint8_t EXPANSION2 = 33;

}

#endif