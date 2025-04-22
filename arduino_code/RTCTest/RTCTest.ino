#include "RTClib.h"
#include "TimePoint.h"

RTC_DS3231 rtc;
int tankLight = 3;      // LED connected to digital pin 9
float intensity = 0.8;
// This array defines lighting profile
TimePoint timePoints[] = {TimePoint(0,0,0.0), TimePoint(9, 30, 0.2), TimePoint(14, 30, 0.2), TimePoint(15, 0, 0.9), TimePoint(22, 30, 0.9), TimePoint(23, 0, 0.0)};

int find_intensity(int hours, int mins){
  //low and high are 
  TimePoint low = TimePoint(0,0,0);
  TimePoint high = TimePoint(24,0,0);
  int totMins = mins + 60*hours;
  //Serial.println(totMins);
  //Serial.println(low.asMin());
  //Serial.println(high.asMin());

  for(int i=0; i<sizeof(timePoints); i++){
    //Serial.println(low.asMin());
    //Serial.println(timePoints[i].asMin());
    if(timePoints[i].asMin() < totMins){//set low 
      if(timePoints[i].asMin() > low.asMin()){
        low = timePoints[i];
      }

    } else if(timePoints[i].asMin() < high.asMin()){ //set high
      high = timePoints[i];
    }

    Serial.println("\n");
    
    //linear interpolation between high and low
    return low.getIntensity() + (high.getIntensity()-low.getIntensity())*(mins-low.asMin())/(high.asMin()-low.asMin());
  }
  
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

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));


  pinMode(tankLight, OUTPUT);
}

void loop () {
  // Get the current time from the RTC
  DateTime now = rtc.now();

  Serial.println(TimePoint(now.hour(), now.minute(), 0.0).asMin());
  
  //int inten = find_intensity(now.hour(), now.minute());
  //analogWrite(tankLight, inten);
  delay(1000);
}
