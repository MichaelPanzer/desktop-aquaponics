#include "TimePoint.h"

TimePoint::TimePoint(uint8_t hour, uint8_t min, float intensity) {
  this->PWM = intensity*255;
  this->totMins = asMin(hour, min);
}

uint16_t TimePoint::asMin(uint8_t hour, uint8_t min) {
  return 60*hour + min;
}

uint8_t TimePoint::getPWM() {
  return PWM;
}

uint16_t TimePoint::getMins() {
  return totMins;
}

