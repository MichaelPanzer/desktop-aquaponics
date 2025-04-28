#include "RTClib.h"
#include "TimePoint.h"

RTC_DS1307 rtc;
uint8_t tankLight = 3;      // LED connected to digital pin 3
uint8_t pump = 11;
uint8_t pumpStatus = LOW;
uint32_t previousTime = 0;
uint16_t onTime = 45;
uint16_t offTime = 85;



// This array defines lighting profile
TimePoint timePoints[] = {TimePoint(0,0,0.0), TimePoint(9, 30, 0.0), TimePoint(10, 0, 0.2), TimePoint(14, 30, 0.2), TimePoint(15, 0, 0.9), TimePoint(22, 30, 0.9), TimePoint(23, 0, 0.0)};
uint8_t n;

uint8_t findIntensity(uint8_t hour, uint8_t min, TimePoint points[], uint8_t n){ 
  TimePoint low = TimePoint(0,-1,0);
  TimePoint high = TimePoint(24,1,0);
  uint16_t totMins = min + 60*hour;

  //set low and high to the TimePoints above and below the current time
  for(uint8_t i=0; i<n; i++){
    if(points[i].getMins() < totMins){//set low 
      if(points[i].getMins() > low.getMins()){
        low = points[i];
      }
    } else if(points[i].getMins() < high.getMins()){ //set high
      high = points[i];
    }
  }

  //Linear interpolation to find the current intensity
  return low.getPWM() + (high.getPWM()-low.getPWM())*(totMins-low.getMins())/(high.getMins()-low.getMins());

}

void setup () {
  Serial.begin(9600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  n = sizeof(timePoints) / sizeof(timePoints[0]);

  pinMode(tankLight, OUTPUT);
  pinMode(pump, OUTPUT);
}

void loop () {
  // Get the current time from the RTC
  DateTime now = rtc.now();

  //Set light intenisty
  int inten = findIntensity(now.hour(), now.minute(), timePoints, n);
  analogWrite(tankLight, inten);

  Serial.print("hour :");
  Serial.print(now.hour());
  Serial.print(", minute: ");
  Serial.print(now.minute());
  Serial.print(", PWM value: ");
  Serial.print(inten);


  //Set pump status
  uint32_t deltaTime = now.unixtime()-previousTime;
  Serial.print(", delta time: ");
  Serial.print(deltaTime);


  if(pumpStatus == HIGH && (deltaTime) > onTime){
    pumpStatus = LOW;
    previousTime = now.unixtime();
  } else if(pumpStatus == LOW && (deltaTime) > offTime){
    pumpStatus = HIGH;
    previousTime = now.unixtime();
  }
  digitalWrite(pump, pumpStatus);

  Serial.print(", pump pin: ");
  Serial.println(pumpStatus);

  delay(500);
}
