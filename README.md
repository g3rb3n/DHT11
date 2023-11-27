# DHT11 library for Arduino
A DHT11 driver for Arduino.

# Example
```
#include <Arduino.h>
#include "DHT11.h"

DHT11 dht(D1);

void setup() 
{
    Serial.begin(230400);
    Serial.println();
    dht.setup();
}

void loop()
{
    int value;
    Serial.prinln(dht.temperature(value));
    Serial.println(value);
    Serial.prinln(dht.humidity(value));
    Serial.println(value);
}

```
