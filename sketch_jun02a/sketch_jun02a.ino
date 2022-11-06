#include <ESP32Servo.h>

const int lowerPin = 26, upperPin = 27;
const int lowerDarkBound = 3500, lowerLightBound = 4000, 
          upperDarkBound = 2800, upperLightBound = 3100;
// variable for storing the potentiometer value
int lowerResValue, upperResValue;

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

  Serial.print("lower Val: ");
  Serial.println(lowerResValue);

  Serial.print("Upper Val: ");
  Serial.println(upperResValue);

  if(lowerResValue < 3900){
    Serial.println("HERE HERE HERE HERE ");
   }
  if(lowerResValue < lowerDarkBound || upperResValue < upperDarkBound){
    servo.write(15);
    delay(150);
    servo.write(0); 
  }
}
