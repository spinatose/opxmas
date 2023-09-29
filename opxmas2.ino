#include <DS3231.h>
#include <Wire.h>

int relayPin = 8;
int _currSecs = 0 ;
int _runTime = 300 ; // 28800 ; // secs
int _offTime = 600 ; //57600 ; // secs
DS3231 rtc  ;
RTCDateTime dt;

void setup() 
{ 

  // Initialize the rtc object
  rtc.begin();

  // Setup relay connection
  pinMode(relayPin, OUTPUT);
} 

void loop()
{
  dt = rtc.getDateTime();
  int hrNow = dt.hour ;
  
  if (hrNow > 16 || hrNow < 2){
    digitalWrite(relayPin, HIGH);
  }
  else {
    digitalWrite(relayPin, LOW);
  }
  
  delay(1000); 
}

void printTime()
{
  dt = rtc.getDateTime();

  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
}
