#ifndef _DHT11_H
#define _DHT11_H

#include <Arduino.h>

class DHT11
{

  private:
    int pin;

  public:
    DHT11(uint8_t pin);

    void setup();
    
    bool temperature(int& value);
    bool humidity(int& value);
};
#endif
