#include "arduino_secrets.h"
#include "thingProperties.h"

/*
====================================================
 CloudLink ESP8266

 Arduino IoT Cloud
       ↓
    ESP8266
       ↓ UART 9600
    LPC2129

 Commands:
 R1ON
 R1OFF
 R2ON
 R2OFF
 R3ON
 R3OFF
 R4ON
 R4OFF
====================================================
*/

void setup()
{
    Serial.begin(9600);

    delay(1500);

    initProperties();

    ArduinoCloud.begin(ArduinoIoTPreferredConnection);

    setDebugMessageLevel(2);
    ArduinoCloud.printDebugInfo();
}


void loop()
{
    ArduinoCloud.update();
}


/*==================================================
   RELAY 1
==================================================*/

void onRelay1Change()
{
    if (relay1)
    {
        Serial.println("R1ON");
    }
    else
    {
        Serial.println("R1OFF");
    }
}


/*==================================================
   RELAY 2
==================================================*/

void onRelay2Change()
{
    if (relay2)
    {
        Serial.println("R2ON");
    }
    else
    {
        Serial.println("R2OFF");
    }
}


/*==================================================
   RELAY 3
==================================================*/

void onRelay3Change()
{
    if (relay3)
    {
        Serial.println("R3ON");
    }
    else
    {
        Serial.println("R3OFF");
    }
}


/*==================================================
   RELAY 4
==================================================*/

void onRelay4Change()
{
    if (relay4)
    {
        Serial.println("R4ON");
    }
    else
    {
        Serial.println("R4OFF");
    }
}
