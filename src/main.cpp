/***************************************************************************
 *
 * AD&M AquaControl
 * Firmware Base
 *
 * Archivo : main.cpp
 *
 * Descripción:
 * Punto de entrada principal del firmware.
 *
 ***************************************************************************/

#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>

/***********************************************************************
 * Constantes
 ***********************************************************************/

const char* FIRMWARE_NAME    = "AD&M AquaControl Node";
const char* FIRMWARE_VERSION = "0.1.0";

/**************************************************************************
* RTC
**************************************************************************/

RTC_DS3231 rtc;

DateTime now;

/***********************************************************************
 * Prototipos de funciones
 ***********************************************************************/

void initializeSystem();
void printSystemInfo();
void initializeRTC();
void updateRTC();


/***********************************************************************
 * SETUP
 ***********************************************************************/

void setup()
{
    Serial.begin(115200);

    delay(1000);

    initializeSystem();

    printSystemInfo();
}

/***********************************************************************
 * LOOP
 ***********************************************************************/

void loop()
{
    /*
        Aquí irá el ciclo principal del alimentador.

        En las siguientes etapas agregaremos:

        - RTC
        - Programación
        - Motores
        - LoRa
    */

     updateRTC();

    delay(10);
}

/***********************************************************************
 * Inicialización general
 ***********************************************************************/

void initializeSystem()
{
    Serial.println();
    Serial.println("Inicializando sistema...");
    Serial.println();

    initializeRTC();
    // En futuras etapas:
    //
    // RTC
    // LoRa
    // Motores
    // Storage
}

/***********************************************************************
 * Información del firmware
 ***********************************************************************/

void printSystemInfo()
{
    Serial.println("========================================");
    Serial.println(FIRMWARE_NAME);
    Serial.println("========================================");

    Serial.print("Firmware Version : ");
    Serial.println(FIRMWARE_VERSION);

    Serial.println();

    Serial.println("Sistema listo.");

    Serial.println("Esperando inicialización de módulos...");

    Serial.println();
}

void initializeRTC()
{
    Serial.print("RTC................");

    if (!rtc.begin())
    {
        Serial.println("ERROR");
        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("OK");
}

void updateRTC()
{
    static uint32_t previousMillis = 0;

    if (millis() - previousMillis < 1000)
        return;

    previousMillis = millis();

    now = rtc.now();

    uint16_t minuteOfDay =
        now.hour() * 60 +
        now.minute();

    Serial.print(now.hour());
    Serial.print(":");

    if (now.minute() < 10)
        Serial.print("0");

    Serial.print(now.minute());
    Serial.print(":");

    if (now.second() < 10)
        Serial.print("0");

    Serial.print(now.second());

    Serial.print("    MinuteOfDay = ");

    Serial.println(minuteOfDay);
}