#include <Arduino.h>

bool check(byte* bytes, unsigned int len){
  byte sum = 0;
  for (unsigned int i = 0 ; i < len ; ++i)
    sum += bytes[i];
   return sum == bytes[len];
}

unsigned int decode_pulses(byte* bits, unsigned long* buff, unsigned int len, unsigned int bufflen){
  unsigned int i = 0;
  for( ; i < len && i*2+3 < bufflen ; ++i){
    bits[i] = buff[i*2 + 3] > 50;
  }
  return i;
}

byte* decode_bytes(byte* bytes, byte* bits, unsigned int len){
  for(unsigned int i = 0 ; i < len ; ++i){
    bytes[i] = 0;
    for(unsigned int b = 0 ; b < 8 ; ++b){
      if (bits[i * 8 + b])
        bytes[i] |= (1 << (7-b));
    }
  }
  return bytes;
}

void init_bus(int pin){
  pinMode (pin, OUTPUT);
  digitalWrite (pin, LOW); // bus down, send start signal
  delay (30); // delay greater than 18ms, so DHT11 start signal can be detected
  digitalWrite (pin, HIGH);
  delayMicroseconds (40); // Wait for DHT11 response
  pinMode (pin, INPUT);
}

unsigned int read_pulses(unsigned long * buff, int pin, unsigned int num, unsigned long timeout){
  unsigned int received = digitalRead(pin);
  unsigned int previous = received;
  unsigned long lastEdge = micros();
  unsigned int pulseLength = 0;
  unsigned int idx = 0;
  while(true) {
    received = digitalRead(pin);
    // On edge
    if (received != previous){
      pulseLength = micros() - lastEdge;
      lastEdge = micros();
      previous = received;
      buff[idx] = pulseLength;
      ++idx;
      if (idx >= num)
        return idx;
    }
    if (micros() - lastEdge > timeout)
      return idx;
  }
}
