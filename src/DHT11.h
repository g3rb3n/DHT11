#ifndef _DHT11_H
#define _DHT11_H

class DHT11 {

  public:
    DHT11(const char pin);

    void setup();
    
    int temperature();
    int humidity();
  private:
    int pin;
};
#endif
