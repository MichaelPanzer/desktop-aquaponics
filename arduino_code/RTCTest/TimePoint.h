#ifndef TimePoint_h
#define TimePoint_h

#include <Arduino.h>

class TimePoint{
  private:
    uint8_t PWM;
    uint16_t asMin(uint8_t hour, uint8_t min);
    uint16_t totMins;



  public:
    TimePoint(uint8_t hour, uint8_t min, float intensity);
    uint8_t getPWM(); 
    uint16_t getMins();

};

#endif