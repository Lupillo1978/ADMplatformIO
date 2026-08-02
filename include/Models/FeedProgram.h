#ifndef FEED_PROGRAM_H
#define FEED_PROGRAM_H

#include <Arduino.h>

/*
==========================================================
 AD&M AquaControl
 FeedProgram.h

 Modelo de datos oficial del alimentador.

 Este archivo define la estructura que será utilizada por:

 - AquaGraph
 - LoRa
 - Memoria Flash (Preferences)
 - Firmware del ESP32

 Todos los módulos deberán utilizar exactamente estas
 estructuras.
==========================================================
*/

//----------------------------------------------------------
// Configuración
//----------------------------------------------------------

constexpr uint16_t MAX_EVENTS = 500;

//----------------------------------------------------------
// Tipos de acción
//----------------------------------------------------------

enum FeedAction : uint8_t
{
    ACTION_FEED_NORMAL     = 1,
    ACTION_SPRAYER_ONLY    = 2,
    ACTION_DOSIFIER_ONLY   = 3,
    ACTION_TEST_MOTORS     = 4
};

//----------------------------------------------------------
// Evento individual
//----------------------------------------------------------

struct FeedEvent
{
    uint16_t eventId;          // Identificador único

    uint16_t minuteOfDay;      // Minuto del día (0-1439)

    uint16_t durationSeconds;  // Tiempo del dosificador

    uint8_t action;            // Acción

    uint8_t reserved;          // Reservado para uso futuro
};

//----------------------------------------------------------
// Encabezado de programación
//----------------------------------------------------------

struct ProgramHeader
{
    uint16_t programId;

    uint8_t version;

    uint8_t nodeId;

    uint16_t totalEvents;

    uint32_t creationDate;

    uint16_t crc;
};

//----------------------------------------------------------
// Programación completa
//----------------------------------------------------------

struct FeedProgram
{
    ProgramHeader header;

    FeedEvent events[MAX_EVENTS];
};


#endif