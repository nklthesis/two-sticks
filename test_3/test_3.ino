// Sketch successfully tested on Arduino Uno Rev3.

// LICENCE
// Luca Giacolini
// www.lucagiacolini.com
// University College of London, Interactive Architecture Lab
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)

#include <Servo.h>
Servo servo;          // Define bottom servo 0-180
Servo servo1;         // Define top servo 0-180

int sensorPin = A3;   //sensor pin
int med;
int avVal = 0;


void setup() {
  
  delay(1000);
  servo.attach(2);
  servo1.attach(4); 
  //set initial position   
  servo.write(180);
  servo1.write(40);
  
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  //calibration routine
  sensorSetup();
}

void loop() {

  sensorRead();
  
  if(avVal > (med+10))
  {
    servo.write(80);
    servo1.write(80);
      delay(100);
  }
  
  else if ((avVal < (med+10))&&(avVal > (med-10)))
  {
    servo.write(180);
    servo1.write(40);   
      delay(100); 
  }

  else if(avVal < (med-10))
  {
    servo.write(120);
    servo1.write(110);
      delay(100);
  }

}
