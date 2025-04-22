#ifndef TimePoint_h
#define TimePoint_h

#include <Arduino.h>

class TimePoint{
  private:
    int hour;
    int min;
    float intensity;
  public:
    TimePoint(int hour, int min, float intensity);
    int asMin();
    int getIntensity(); 
    float testIntensity();
};

#endif