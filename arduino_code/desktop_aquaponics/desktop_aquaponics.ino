#include "RTClib.h"
#include "TimePoint.h"

RTC_DS1307 rtc;

//Pin assignments
uint8_t tankLight = 3;      
uint8_t bedLight = 5;
uint8_t pump = 11;

//status variables
bool pumpOn = true;
uint32_t previousTime = 0;

//pump timing
uint16_t onTime = 35;
uint16_t offTime = 60;


//TimePoint(hour, minute, intentisy [float from 0.0-1.0])

// Tank lighting profile
TimePoint tankPoints[] = {TimePoint(0,0,0.0), TimePoint(9, 30, 0.0), TimePoint(10, 0, 0.2), TimePoint(14, 30, 0.2), TimePoint(15, 0, 0.9), TimePoint(22, 30, 0.9), TimePoint(23, 30, 0.0)};
uint8_t nT;

//Grow bed lighting profile
TimePoint bedPoints[] = {TimePoint(0,0,0.0), TimePoint(9, 30, 0.0), TimePoint(10, 0, 0.7), TimePoint(22, 30, 0.7), TimePoint(23, 30, 0.0)};
uint8_t nB;

uint8_t intenT, intenB;
uint32_t deltaTime;

//Function linearly interpolates intensity from lighting profile array, returns PWM value of output pin 
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
  //Comparison is to mitigate 8 bit unsigned integer underflow errors
  if(high.getPWM() < low.getPWM()){
    return low.getPWM() - (low.getPWM()-high.getPWM())*(totMins-low.getMins()) / (high.getMins()-low.getMins());
  } else{
    return low.getPWM() + (high.getPWM()-low.getPWM())*(totMins-low.getMins()) / (high.getMins()-low.getMins());
  }

}

void setup () {
  Serial.begin(9600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  //Sets time if rtc not running
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  //Calculate the length of lighting proile arrays
  nT = sizeof(tankPoints) / sizeof(tankPoints[0]);
  nB = sizeof(bedPoints) / sizeof(bedPoints[0]);

  //Define pins
  pinMode(tankLight, OUTPUT);
  pinMode(bedLight, OUTPUT);
  pinMode(pump, OUTPUT);
}

void loop () {
  // Get the current time from the RTC
  DateTime now = rtc.now();

  //Set light intenisty
  intenT = findIntensity(now.hour(), now.minute(), tankPoints, nT);
  analogWrite(tankLight, intenT);
  intenB = findIntensity(now.hour(), now.minute(), bedPoints, nB);
  analogWrite(bedLight, intenB);

  Serial.print("hour :");
  Serial.print(now.hour());
  Serial.print(", minute: ");
  Serial.print(now.minute());
  Serial.print(", tank light: ");
  Serial.print(intenT);
  Serial.print(", bed light: ");
  Serial.print(intenB);

  //Set pump status
  deltaTime = now.unixtime()-previousTime;
  Serial.print(", delta time: ");
  Serial.print(deltaTime);

  if(pumpOn == true && deltaTime > onTime){
    pumpOn = false;
    previousTime = now.unixtime();
    digitalWrite(pump, LOW);
  } else if(pumpOn == false && deltaTime > offTime){
    pumpOn = true;
    previousTime = now.unixtime();
    digitalWrite(pump, HIGH);
  } 

  Serial.print(", pump on: ");
  Serial.println(pumpOn);

  delay(1000);
}
