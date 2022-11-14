/*
 *    Example-Code that emulates a DS18B20
 *
 *    Tested with:
 *    - https://github.com/PaulStoffregen/OneWire --> DS18x20-Example, atmega328@16MHz as Slave
 *    - DS9490R-Master, atmega328@16MHz as Slave
 */

#include "OneWireHub.h"
#include "DS18B20.h"  // Digital Thermometer, 12bit

const uint8_t led_PIN       = 13;         // the number of the LED pin
const uint8_t OneWire_PIN   = 8;

auto hub     = OneWireHub(OneWire_PIN);
auto sensorA = DS18B20(0x28, 0x0D, 0x01, 0x08, 0x0B, 0x02, 0x0A);    // Digital Thermometer
auto sensorB = DS18B20(0x28, 0x0D, 0x01, 0x08, 0x0B, 0x02, 0x0B);    // Digital Thermometer


bool blinking()
{
    const  uint32_t interval    = 500;          // interval at which to blink (milliseconds)
    static uint32_t nextMillis  = millis();     // will store next time LED will updated

    if (millis() > nextMillis)
    {
        nextMillis += interval;             // save the next time you blinked the LED
        static uint8_t ledState = LOW;      // ledState used to set the LED
        if (ledState == LOW)    ledState = HIGH;
        else                    ledState = LOW;
        digitalWrite(led_PIN, ledState);
        return 1;
    }
    return 0;
}


void setup()
{
    Serial.begin(115200);
    Serial.println("OneWire-Hub DS18B20 Temperature-Sensor");

    pinMode(led_PIN, OUTPUT);

    // Setup OneWire
    hub.attach(sensorA);
    hub.attach(sensorB);

    // Set const temperature
    sensorA.setTemp(21);

    Serial.println("config done");
}

void loop()
{
    // following function must be called periodically
    hub.poll();
    // this part is just for debugging (USE_SERIAL_DEBUG in OneWire.h must be enabled for output)
    if (hub.getError()) hub.printError();

    // Blink triggers the state-change
    if (blinking())
    {
        // Set temp
        static float temperature = 20.0;
        temperature += 0.1;
        if (temperature > 30.0) temperature = 20.0;
        sensorB.setTemp(temperature);
    }
}