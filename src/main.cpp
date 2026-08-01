#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>

#include "FeedProgram.h"
#include <Application/Application.h>

Application app;

void setup()
{
     Serial.begin(115200);

    app.initialize();
}

void loop()
{
    app.update();
}