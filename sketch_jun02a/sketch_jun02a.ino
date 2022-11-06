#include <ESP32Servo.h>

const int lowerPin = 26, upperPin = 27;
const int darkBound = 2400, lightBound = 3000;
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

  servo.write(90);
  delay(1000);
  servo.write(0);
  
  
  delay(1000);
}
