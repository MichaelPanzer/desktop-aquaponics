#include "TimePoint.h"

TimePoint::TimePoint(int hour, int min, float intensity) {
  hour = hour;
  min = min;
  intensity = intensity;
}

int TimePoint::asMin() {
  Serial.println(hour);
  Serial.println(min);
  Serial.println(60*hour + min);
  Serial.println("\n");
  return 60*hour + min;
}

int TimePoint::getIntensity() {
  return intensity*255.0;
}

float TimePoint::testIntensity() {
  return intensity;
}