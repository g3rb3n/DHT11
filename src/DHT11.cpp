
#include <Arduino.h>
#include <DHT11.h>
#include <DHT11s.h>

DHT11::DHT11(uint8_t pin)
:
    pin(pin)
{
}

void DHT11::setup()
{
    pinMode (pin, OUTPUT);
    digitalWrite (pin, LOW); // bus down, send start signal
    delay (30); // delay greater than 18ms, so DHT11 start signal can be detected
    digitalWrite (pin, HIGH);
    delayMicroseconds (40); // Wait for DHT11 response
    pinMode (pin, INPUT);
}

bool DHT11::temperature(int& value){
  unsigned long buff[100];
  byte bits[50];
  byte bytes[5];
  bool ok = false;
  init_bus(this->pin);
  unsigned int r = read_pulses(buff, this->pin, 100, 1000000);
  r = decode_pulses(bits, buff, 50, r);
  decode_bytes(bytes, bits, 5);
  ok = check(bytes, 4);
  value = bytes[2];
  return ok;
}

bool DHT11::humidity(int& value){
  unsigned long buff[100];
  byte bits[50];
  byte bytes[5];
  bool ok = false;
  init_bus(this->pin);
  unsigned int r = read_pulses(buff, this->pin, 100, 1000000);
  r = decode_pulses(bits, buff, 50, r);
  decode_bytes(bytes, bits, 5);
  ok = check(bytes, 4);
  value = bytes[0];
}
