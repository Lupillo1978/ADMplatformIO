#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

//--------------------------------------------------
// Información del Firmware
//--------------------------------------------------

#define FIRMWARE_NAME      "AD&M AquaControl Node"
#define FIRMWARE_VERSION   "0.1.0"

//--------------------------------------------------
// Modo de operación
//--------------------------------------------------

#define DEVELOPMENT_MODE   true

//--------------------------------------------------
// Habilitar módulos
//--------------------------------------------------

#define USE_RTC           false
#define USE_LORA          false
#define USE_MOTORS        false

//--------------------------------------------------
// Tiempos del alimentador
//--------------------------------------------------

#define SPRAYER_DELAY_MS      2000
#define STOP_DELAY_MS         2000

#endif