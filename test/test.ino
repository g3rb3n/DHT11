#include <Arduino.h>
#include <unity.h>

#include "DS18B20.h"

#ifdef UNIT_TEST

using namespace g3rb3n;

#define PIN D1

DHT11 dht(PIN);

void readsProperTemperature() 
{
  float t = ds.temperature();
  TEST_ASSERT_FLOAT_WITHIN(20, 21, t);
}

void readsProperHumidity() 
{
  float t = ds.humidity();
  TEST_ASSERT_FLOAT_WITHIN(50, 50, t);
}

void setup() 
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);
  UNITY_BEGIN();
}

void loop() 
{
  uint8_t count = 100;
  while(--count)
  {
    RUN_TEST(readsProperTemperature);
    RUN_TEST(readsProperHumidity);
  }
  UNITY_END();
}

#endif
