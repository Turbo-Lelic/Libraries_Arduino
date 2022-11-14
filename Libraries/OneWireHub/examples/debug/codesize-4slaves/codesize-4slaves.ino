/*
 *    Example-Code that emulates 4 sensors (2x ds2401, 2x ds18b20)
 *    --> attach sensors as needed
 *
 *    Tested with:
 *    - https://github.com/PaulStoffregen/OneWire on the other side as Master, atmega328@16MHz as Slave
 *    - DS9490R-Master, atmega328@16MHz as Slave
 */

#include "OneWireHub.h"

// include all libs to find errors
#include "DS2401.h"  // Serial Number
#include "DS18B20.h" // Digital Thermometer

const uint8_t led_PIN       = 13;         // the number of the LED pin
const uint8_t OneWire_PIN   = 8;

auto hub      = OneWireHub(OneWire_PIN);
auto ds18B20a = DS18B20(0x28, 0x0D, 0x01, 0x08, 0x0B, 0x02, 0x0A);     // Work - Digital Thermometer
auto ds18B20b = DS18B20(0x28, 0x0D, 0x01, 0x08, 0x0B, 0x02, 0x0B);
auto ds2401a  = DS2401( 0x01, 0x00, 0x0D, 0x24, 0x01, 0x00, 0x0A );    // Work - Serial Number
auto ds2401b  = DS2401( 0x01, 0x00, 0x0D, 0x24, 0x01, 0x00, 0x0B );


bool blinking()
{
    const  uint32_t interval    = 5000;          // interval at which to blink (milliseconds)
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
    pinMode(led_PIN, OUTPUT);
    // Setup OneWire
    ds18B20a.setTemp(10);
    hub.attach(ds18B20a);
    hub.attach(ds18B20b);
    hub.attach(ds2401a);
    hub.attach(ds2401b);
}

void loop()
{
    // following function must be called periodically
    hub.poll();

    // Blink triggers the state-change
    if (blinking())
    {
        static uint8_t temperature = 20;
        temperature += 1;
        if (temperature > 40) temperature = 10;
        ds18B20b.setTemp(temperature);
    }
}
