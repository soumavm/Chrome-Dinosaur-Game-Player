#include <ESP32Servo.h>

//sets Voltage sensing pins, initializes voltage values for object tracking
const int lowerPin = 26, upperPin = 27;
const int lowerBound = 3100, lowerInvertBound = 1700, 
          upperBound = 2900, upperInvertBound = 1780;
          
// Stores the reference voltages at each voltage divider
int lowerResValue=0, upperResValue=0;

//used to detect if screen in inverted or not
bool bgWhite = true;
int delayCount=0;

//sets up which pin controls SG90 servo
Servo servo;
const byte servoGPIO = 25;

void setup() {
  //Serial.begin(115200);
  //Ataches servo to pin
  servo.attach(servoGPIO);
  servo.write(0);
}

void loop() {
  // Reading voltage divider voltages
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
      //simulates jump
      servo.write(7);
      delay(150);
      servo.write(0);

    }
    //checks to see if the upper photoresistor is triggerred off of an object, or the screen switching colours
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
