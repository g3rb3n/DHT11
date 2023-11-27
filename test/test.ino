#include <Arduino.h>
#include <unity.h>

#include "DHT11.h"

#ifdef UNIT_TEST

using namespace g3rb3n;

#define PIN D1

DHT11 dht(PIN);

void readsProperTemperature() 
{
  int v = 0;
  dht.temperature(v);
  TEST_ASSERT_INT_WITHIN(15, 25, v);
}

void readsProperHumidity() 
{
  int v = 0;
  dht.humidity(v);
  TEST_ASSERT_INT_WITHIN(20, 80, v);
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
