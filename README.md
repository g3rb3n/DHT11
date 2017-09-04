# DHT11 library for Arduino
A DHT11 driver for Arduino.

# Example
```
#include <DHT11.h>

DHT11 dht(D1);

void setup() 
{
}

void loop()
{
  float t = dht.temperature();
  float h = dht.humidity();
}
```
