#include <DHT11.h>
#include <DHT11s.h>

#include <Arduino.h>

DHT11::DHT11(const char pin){
  this->pin = pin;
}

void setup()
{
    pinMode (pin, OUTPUT);
    digitalWrite (pin, LOW); // bus down, send start signal
    delay (30); // delay greater than 18ms, so DHT11 start signal can be detected
    digitalWrite (pin, HIGH);
    delayMicroseconds (40); // Wait for DHT11 response
    pinMode (pin, INPUT);
}

int DHT11::temperature(){
  unsigned long buff[100];
  byte bits[50];
  byte bytes[5];
  bool ok = false;
  init_bus(this->pin);
  unsigned int r = read_pulses(buff, this->pin, 100, 1000000);
  r = decode_pulses(bits, buff, 50, r);
  decode_bytes(bytes, bits, 5);
  ok = check(bytes, 4);
  if (!ok)
    return 0;
  return bytes[2];
}

int DHT11::humidity(){
  unsigned long buff[100];
  byte bits[50];
  byte bytes[5];
  bool ok = false;
  init_bus(this->pin);
  unsigned int r = read_pulses(buff, this->pin, 100, 1000000);
  r = decode_pulses(bits, buff, 50, r);
  decode_bytes(bytes, bits, 5);
  ok = check(bytes, 4);
  if (!ok)
    return 0;
  return bytes[0];
}
