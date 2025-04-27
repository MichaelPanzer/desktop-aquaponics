#include "RTClib.h"
#include "TimePoint.h"

RTC_DS3231 rtc;
int tankLight = 3;      // LED connected to digital pin 3
// This array defines lighting profile
TimePoint timePoints[] = {TimePoint(0,0,0.0), TimePoint(9, 30, 0.2), TimePoint(14, 30, 0.2), TimePoint(15, 0, 0.9), TimePoint(22, 30, 0.9), TimePoint(23, 0, 0.0)};

int findIntensity(uint8_t hour, uint8_t min, TimePoint points[]){ 
  TimePoint low = TimePoint(0,0,0);
  TimePoint high = TimePoint(24,0,0);
  uint16_t totMins = min + 60*hour;

  //set low and high to the TimePoints above and below the current time
  for(int i=0; i<6; i++){
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

  if (! rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }


  pinMode(tankLight, OUTPUT);
}

void loop () {
  // Get the current time from the RTC
  DateTime now = rtc.now();

  uint8_t inten = findIntensity(now.hour(), now.minute(), timePoints);
  analogWrite(tankLight, inten);

  Serial.print("hour :");
  Serial.print(now.hour());
  Serial.print(", minute: ");
  Serial.print(now.minute());
  Serial.print(", PWM value: ");
  Serial.println(inten);

  delay(3000);
}
