#include <DHT11.h>

DHT11 dht(D1);

void setup() 
{
  Serial.begin(230400);
  Serial.println();
}

void loop()
{
  Serial.prinln(dht.temperature());
  Serial.prinln(dht.humidity());
}
