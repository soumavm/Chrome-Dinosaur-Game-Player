#include <ESP32Servo.h>

const int lowerPin = 26, upperPin = 27;
const int lowerBound = 3100, lowerInvertBound = 1700, 
          upperBound = 2900, upperInvertBound = 1780;
// variable for storing the potentiometer value
int lowerResValue, upperResValue;
bool bgWhite = true;
int delayCount=0;

Servo servo;
const byte servoGPIO = 25;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  servo.attach(servoGPIO);
  servo.write(0);
}

void loop() {
  // Reading potentiometer value
  lowerResValue = analogRead(lowerPin);
  upperResValue = analogRead(upperPin);

//  Serial.print("lower Val: ");
//  Serial.println(lowerResValue);
//
//  Serial.print("Upper Val: ");
//  Serial.println(upperResValue);

  if(delayCount){
    delayCount--;  
  }
  
  if(bgWhite){
    if(lowerResValue < lowerBound || upperResValue < upperBound){
      servo.write(7);
      delay(150);
      servo.write(0);

    }
    if((lowerResValue < lowerBound) && (upperResValue < upperBound)){
      delayCount+=2;
    }
    if(delayCount>=4){
      bgWhite=false;
      delayCount=0;
    }
  }
  else{
    if(lowerResValue > lowerInvertBound || upperResValue > upperInvertBound){
      servo.write(7);
      delay(150);
      servo.write(0);
    }
    if((lowerResValue > lowerInvertBound) && (upperResValue > upperInvertBound)){
      delayCount+=2;
    }
    if(delayCount>=7){
      bgWhite=true;
      delayCount=0;
    }
  }
}
