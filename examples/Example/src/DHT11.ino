#include <DHT11.h>

DHT11 dht(D1);

void setup() 
{
    Serial.begin(230400);
    Serial.println();
}

void loop()
{
    int value;
    Serial.prinln(dht.temperature(value));
    Serial.println(value);
    Serial.prinln(dht.humidity(value));
    Serial.println(value);
}
