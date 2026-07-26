#include <Arduino.h>
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